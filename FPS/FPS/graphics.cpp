#include "graphics.h"
#include <iostream>
#include <string>
#include "ModelLoader.h"

using namespace std;
using namespace graphics;
using namespace events;

GraphicsEngine::GraphicsEngine(){
	window = nullptr;
	screenWidth = 1024;
	screenHeight = 720;
	textureMap = false;
}

GraphicsEngine::~GraphicsEngine(){
}

void GraphicsEngine::init(vector<string> modelFiles, vector<string> textureFiles){
	SDL_GLContext context;

	//seed the random
	srand(time(NULL));

	for(unsigned int index = 0; index < modelFiles.size(); index++){
		Model newModel;
		if(newModel.loadData(modelFiles[index])){
			models.push_back(newModel);
			cout << modelFiles[index] << " has been loaded!" << endl;
			float temp1 = rand() % 3000, temp2 = rand() % 100 + 100, temp3 = rand() % 3000;
			types::Vector3D modPos = types::Vector3D(temp1, temp2, temp3);
			models[index].setModelPos(modPos);
		}
	}

	// Initialise SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	//Create window. Hard-coded values will be changed when everything works.
	window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_OPENGL);
	//SDL_SetRelativeMouseMode(SDL_TRUE);
	SDL_ShowCursor(0);

	if(window == nullptr)
		exit(1); // A bit brash, but gets the job done

	context = SDL_GL_CreateContext(window);

	if(context == nullptr)
		exit(1);

	glewExperimental = true;
	if(glewInit() != GLEW_OK)
		return;

	glEnable(GL_TEXTURE_2D);

	texturePaths = textureFiles;
	for(unsigned int i = 0; i < textureFiles.size(); i++){
		cout << terrainTexID[i] << endl;
		terrainTexID[i] = getTexture(textureFiles[i].c_str());
		cout << terrainTexID[i] << endl;
	}

	colorSurface[0] = SDL_LoadBMP(texturePaths[0].c_str());
	cout << "surface loaded: " << texturePaths[0] << endl;
	colorSurface[1] = SDL_LoadBMP(texturePaths[1].c_str());
	cout << "surface loaded: " << texturePaths[1] << endl;
	colorSurface[2] = SDL_LoadBMP(texturePaths[2].c_str());
	cout << "surface loaded: " << texturePaths[2] << endl;

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, screenWidth, screenHeight);
	gluPerspective(45.0, 1.0, 0.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

void GraphicsEngine::display(double camX, double camY, double camZ, double lookX, double lookY, double lookZ, double upX, double upY, double upZ){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	gluLookAt(camX, camY, camZ, lookX, lookY, lookZ, upX, upY, upZ);

	drawTerrain();
	drawModels();

	SDL_GL_SwapWindow(window);
}

gameEvent GraphicsEngine::pollEvents(){
	SDL_Event eventSDL;
	gameEvent eventGame;

	while(SDL_PollEvent(&eventSDL)){
		eventGame.hasEvents = true;

		switch(eventSDL.type){
		case SDL_QUIT:
			eventGame.hasQuit = true;
			break;
		case SDL_MOUSEMOTION:
			eventGame.mouseX = eventSDL.motion.x;
			eventGame.mouseY = eventSDL.motion.y;
			break;
		case SDL_KEYDOWN:
			eventGame.keysPressed.push_back((char)eventSDL.key.keysym.sym);
			eventGame.keyDown = true;
			break;
		default:
			break;
		}
	}

	SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);
		SDL_WarpMouseInWindow(window, screenWidth/2, screenHeight/2);
	SDL_EventState(SDL_MOUSEMOTION, SDL_ENABLE);

	return eventGame;
}

void GraphicsEngine::setScales(float scal, float xzscal){
	scale = scal;
	xzscale = xzscal;
}

void GraphicsEngine::getHeightfieldData(const vector<unsigned char> data){
	heightfieldData = data;
}

void GraphicsEngine::toggleWireframe(){
	if(wireframe){
		//wireframe on, turn it off
		glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
	} else {
		//wireframe off, turn it on
		glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
	}
	wireframe = !wireframe;
}

void GraphicsEngine::closeWindow(){

	SDL_DestroyWindow(window);
}

GLuint GraphicsEngine::getTexture(const char* fileName){
	GLuint texID;
	SDL_Surface* surface = SDL_LoadBMP(fileName);
	if(surface != NULL)
		cout << fileName << " has been loaded!" << endl;
	
	glGenTextures(1, &texID);
	glBindTexture(GL_TEXTURE_2D, texID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB, GL_UNSIGNED_BYTE, surface->pixels);
	glBindTexture(GL_TEXTURE_2D, 0);

	SDL_FreeSurface(surface);

	return texID;
}



void GraphicsEngine::drawTerrain(){
	// Square root because the actual size is all of the elements. This is, of course, assuming that the heightfield has the same dimensions for width and height.
	int terrainSize = (int)sqrt((double)heightfieldData.size());
	unsigned char heightColour;
	float height;
	float texLeft, texBottom, texTop;
	

	glBindTexture(GL_TEXTURE_2D, terrainTexID[1]);

	for(int zVal = 0; zVal < terrainSize; zVal++){
		glBegin(GL_TRIANGLE_STRIP);
		for(int xVal = 0; xVal < terrainSize; xVal++){

			//calc texture coords
			texLeft = (float)xVal/terrainSize;
			texBottom = (float)zVal/terrainSize;
			texTop = (float)(zVal + 1)/terrainSize;

			heightColour = heightfieldData.at((zVal * terrainSize) + xVal);
			//glColor3ub(heightColour, heightColour, heightColour);
			glTexCoord2f(texLeft, texBottom);
			height = (float)(heightColour * scale) - 350.0f;
			setColor(texLeft, texBottom, height);
			glVertex3f((float)xVal * xzscale, height, (float)zVal * xzscale);

			if((zVal + 1) < terrainSize){
				heightColour = heightfieldData.at(((zVal + 1) * terrainSize) + xVal);
				//glColor3ub(heightColour, heightColour, heightColour);
				glTexCoord2f(texLeft, texTop);
				height = (float)(heightColour * scale) - 350.0f;
				setColor(texLeft, texBottom, height);
				glVertex3f((float)xVal * xzscale, height, (float)(zVal + 1) * xzscale);
			}
		}
		glEnd();
	}

	glBindTexture(GL_TEXTURE_2D, 0);
}

void GraphicsEngine::drawModels(){
	ModelData modelInfo;
	types::Vector3D modelPos;

	for(unsigned index = 0; index < models.size(); index++){
		modelInfo = models[index].getData();
		modelPos = models[index].getModelPos();



		glBegin(GL_TRIANGLE_STRIP);
		for(unsigned vertIndex = 0; vertIndex < modelInfo.vertices.size(); vertIndex++){
			glVertex3f(modelInfo.vertices[vertIndex].x + modelPos.x, modelInfo.vertices[vertIndex].y + modelPos.y, modelInfo.vertices[vertIndex].z + modelPos.z); 
		}
		glEnd();
	}
}

SDL_Color GraphicsEngine::getpixel(SDL_Surface *surface, int x, int y)
{
	const Uint8 &bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

	Uint32 result = 0;

    switch(bpp)
	{
		case 1:
			result = *p;
			break;
		case 2:
			result = *(Uint16 *)p;
			break;
		case 3:
			if(SDL_BYTEORDER == SDL_BIG_ENDIAN){
				result = (p[0] << 16 | p[1] << 8 | p[2]);
			}
			else{
				result = (p[0] | p[1] << 8 | p[2] << 16);
			}
			break;
		case 4:
			result = *(Uint32 *)p;
			break;
		default:
			result = 0;       /* shouldn't happen, but avoids warnings */
			break;
    }

	SDL_Color theKey;
	SDL_GetRGB(result, surface->format, &theKey.r, &theKey.g, &theKey.b);
	
	return theKey;
}

void GraphicsEngine::setColor(float xpos, float zpos, float height){
	GLuint red, green, blue;
	SDL_Color rgbAtPoint;
	int terrainSize = (int)sqrt((double)heightfieldData.size());
	float x= (xpos/xzscale)/terrainSize, z = (zpos/xzscale)/terrainSize;
	
	//adjust coords to texture's sizing

	if(height < -83.0f){// lowest elevation, soil texture
		float xA = x*colorSurface[0]->w, zA = z*colorSurface[0]->h;
		rgbAtPoint = getpixel(colorSurface[0], (int)xA, (int)zA);
		red = rgbAtPoint.r;
		green = rgbAtPoint.g;
		blue = rgbAtPoint.b;
	} else if(height < -73.0f){// middle elevation, grass texture
		float xA = x*colorSurface[1]->w, zA = z*colorSurface[1]->h;
		rgbAtPoint = getpixel(colorSurface[1], (int)xA, (int)zA);
		red = rgbAtPoint.r;
		green = rgbAtPoint.g;
		blue = rgbAtPoint.b;
	} else {//highest elevation, stone texture
		float xA = x*colorSurface[2]->w, zA = z*colorSurface[2]->h;
		rgbAtPoint = getpixel(colorSurface[2], (int)xA, (int)zA);
		red = rgbAtPoint.r;
		green = rgbAtPoint.g;
		blue = rgbAtPoint.b;
	}

	glColor3ub(red, green, blue);
	return;
}

bool Model::loadData(string modelFile){
	return loader::loadObj(modelFile.c_str(), data.vertices);
}