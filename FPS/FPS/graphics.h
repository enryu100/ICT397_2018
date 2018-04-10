/**
* graphics.h
* 
* Author: Brandon Lim
*
* Contains all of the functionality required to render objects. Encapsulating SDL to
* achieve this.
*/
#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SDL/SDL.h>
#include <vector>
#include "Events.h"
#include "Types.h"

namespace graphics{

	class Model;

	/**
	* @class GraphicsEngine
	* @brief A class that renders objects in a game to the screen.
	*
	* The GraphicsEngine class is responsible for displaying the terrain and all of the in-
	* game objects with a heightfield and a set of models associated with said objects.
	* Presently, it is also responsible for polling events due to the nature of SDL, though
	* this is something that should be changed if possible.
	*
	* @author Brandon Lim
	*
	* @todo Implement the models to allow for player and enemies to appear.
	*/
	class GraphicsEngine{
	public:
		/**
		* The constructor for a GraphicsEngine object.
		* Initialises the window size.
		*/
		GraphicsEngine();
		/**
		* The destructor for a GraphicsEngine object.
		*/
		~GraphicsEngine();
		
		/**
		* @brief Initialises the engine and view.
		* @param modelFiles - a list of file names for the models
		* @param textureFiles - a list of file names for the textures
		*
		* init initialises the engine's components - the window, OpenGL context, models,
		* and textures. Model and texture data are loaded in with the file names provided
		* as arguments.
		*/
		void init(std::vector<std::string> modelFiles, std::vector<std::string> textureFiles);
		/**
		* @brief Displays the game world and its contents from a camera view.
		* @param camX - The x-co-ordinate of the camera's position in the game space.
		* @param camY - The y-co-ordinate of the camera's position in the game space.
		* @param camZ - The z-co-ordinate of the camera's position in the game space.
		* @param lookX - The x-co-ordinate of the point in the game space the camera is
		* looking at.
		* @param lookY - The y-co-ordinate of the point in the game space the camera is
		* looking at.
		* @param lookZ - The z-co-ordinate of the point in the game space the camera is
		* looking at.
		* @param upX - The x value of the vector that defines "up" for the camera.
		* @param upY - The y value of the vector that defines "up" for the camera.
		* @param upZ - The z value of the vector that defines "up" for the camera.
		*
		* display uses camera co-ordinates to create a view of the game world and draws the
		* world's objects to the view.
		*/
		void display(double camX, double camY, double camZ, double lookX, double lookY, double lookZ, double upX, double upY, double upZ);
		/**
		* @brief Polls for input from the user.
		* @return gameEvent - All of the new input
		*
		* pollEvents polls for any user input, adds any new input to an event object, then
		* returns it to the calling function. This should not be the responsibility of a
		* graphics engine, but it's unavoidable for now.
		*/
		events::gameEvent pollEvents();
		/**
		* \fn setScales
		* @brief sets scale variables for heightmap
		* @param scal the y-axis scale
		* @param xzscal the z- and x-axis scale
		*/
		void setScales(float scal, float xzscal);
		/**
		* @brief Retrives data for a heightfield.
		* @param data - The heightfield data.
		*
		* getHeightfieldData gets the data for a heightfield so that it can be drawn in the
		* display function. This should only be called when loading the heightfield for the
		* first time, or when a new heightfield needs to be displayed.
		*/
		void getHeightfieldData(const std::vector<unsigned char> data);

	private:
		/// The window context.
		SDL_Window* window;
		/// The width of the user's screen. Currently hard-coded.
		int screenWidth;
		/// The height of the user's screen. Currently hard-coded.
		int screenHeight;
		/// The heightfield data.
		std::vector<unsigned char> heightfieldData;
		/// The texture ID used for texturing the heightfield.
		GLuint terrainTexID;
		/// Scale data for heightfield
		float scale, xzscale;
		/// Boolean for whether a texture is being applied
		bool textureMap;
		/// The models of the game's objects.
		std::vector<Model> models;

		/**
		* @brief Draws the terrain on to the screen.
		*
		* drawTerrain uses the heightfield data to draw the world's terrain to the screen.
		*/
		void drawTerrain();
		/**
		* @brief Draws the game's models to the screen.
		*
		* drawModels uses the model data to draw all of the game's objects to the screen.
		*/
		void drawModels();

		/**
		* @brief Gets a texture from a file.
		* @param fileName - The name of the file containing the texture
		* @return GLuint - The ID of the texture
		*
		* getTexture loads a texture from a file (only .bmp at the moment) and returns its
		* ID for use in the engine.
		*/
		GLuint getTexture(const char* fileName);
	};

	/**
	* @struct ModelData
	* @brief Holds vertex, UV, and normal data for a model.
	*
	* This struct is a simple container for a model's data - vertices, UV co-ordinates, and
	* normals.
	*/
	struct ModelData{
		std::vector<types::Vector3D> vertices;
		std::vector<types::Vector2D> uvs;
		std::vector<types::Vector3D> normals;
	};

	/**
	* @class Model
	* @brief A class that stores model data and all data relating to it.
	*
	* The Model class is responsible for holding all of the data required to display a model
	* in a virtual 3D space.
	*
	* @author Brandon Lim
	*/
	class Model{
	public:
		/**
		* The constructor for a Model object.
		*/
		Model(){};
		/**
		* The destructor for a model object.
		*/
		~Model(){};

		/**
		* @brief Loads all data for the model.
		* @param modelFile - The file name for the model data
		*
		* loadData loads the model's data from a file using the object file loader. This
		* gives it limitations, but it should suffice currently.
		*/
		bool loadData(std::string modelFile);
		/**
		* @brief Gets the model data.
		* @return const ModelData& - A structure containing the model data
		*
		* getData simply returns the model's vertex, UV, and normal data to the calling
		* function.
		*/
		const ModelData& getData(){return data;};
		/**
		* @brief Gets the current position of the model.
		* @return const Vector3D& - A vector containing the model's position
		*
		* getModelPos simply returns the model's current position to the calling function.
		*/
		const types::Vector3D& getModelPos(){return modelPos;};
		/**
		* @brief Sets a new position for the model.
		* param newPos - The new position
		*
		* setModelPos sets the model's position to the position supplied.
		*/
		void setModelPos(const types::Vector3D& newPos){modelPos = newPos;};

	private:
		/// The position of the model.
		types::Vector3D modelPos;
		/// The model data.
		ModelData data;
	};
}
