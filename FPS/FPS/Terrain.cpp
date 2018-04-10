/*
* Terrain.cpp
*/

#include "Terrain.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
using namespace terrain;

Terrain::Terrain(){

}

Terrain::~Terrain(){
	
}

bool Terrain::loadHeightfield(string fileName){
	ifstream inFile(fileName, ios::binary);
	int fileLength;

	if(!inFile){
		cout << "Error: could not open " << fileName << "!" << endl;
		return false;
	}

	if(terrainData != NULL)
		if(!terrainData->empty())
			terrainData->clear();

	inFile.seekg(0, ios::end);	// Going to end of file...
	fileLength = (int)inFile.tellg();// ...to find out its length...

	if(fileLength > 0){
		terrainData = unique_ptr<vector<unsigned char>>(new vector<unsigned char>(fileLength));
	}
	if(terrainData == NULL)
		return false;

	inFile.seekg(0, ios::beg);	// ...then going back to the start.

	for(int index = 0; index < fileLength && !inFile.eof(); index++){
		terrainData->at(index) = inFile.get();
	}

	inFile.close();
	terrainSize = (int)sqrt((double)fileLength);

	return true;
}

void Terrain::setScale(float x, float y, float z){
	xScale = x;
	yScale = y;
	zScale = z;
}

const vector<unsigned char> Terrain::getTerrainData(){
	return *terrainData;
}

float Terrain::getHeight(int xPos, int zPos){
	if(inBounds(xPos/(int)xScale, zPos/(int)zScale))
		return((float)(getHeightColour(xPos/(int)xScale, zPos/(int)zScale)) * yScale);

	return 0;
}

unsigned char Terrain::getHeightColour(int xPos, int zPos){
	if(inBounds(xPos/(int)xScale, zPos/(int)zScale))
		return(terrainData->at((zPos * terrainSize) + xPos));

	return 1;
}

int Terrain::getTerrainSize(){
	return terrainSize;
}

float Terrain::getXScale(){
	return xScale;
}

float Terrain::getYScale(){
	return yScale;
}

float Terrain::getZScale(){
	return zScale;
}

bool Terrain::inBounds(int xPos, int zPos){
	if(xPos < terrainSize && zPos < terrainSize && xPos > 0 && zPos > 0)
		return true;

	return false;
}