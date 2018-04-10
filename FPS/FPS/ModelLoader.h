/**
* ObjLoader.h
*
* Author: Brandon Lim
* Version 2.0
* Date: 10/4/2017
* This simply uses the assimp model-loading library to load model data.
*/
#pragma once

#include <vector>
#include "Types.h"

namespace loader{
	/**
	* @brief Loads a model file and retrieves information pertaining to 3D models.
	* @param path - The path of the file to be opened
	* @param outVertices - A list of vertex co-ordinates for a 3D model
	* @return bool - true if the file loaded properly, false if not
	*
	* loadObj is a very simple loader for models from model files. The file is opened
	* and the data retrieved, then put into the list of data passed by reference
	* from a model object.
	*/
	bool loadObj(const char* path, std::vector<types::Vector3D> & outVertices);
}
