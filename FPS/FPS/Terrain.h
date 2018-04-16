/*
* Terrain.h
*
* Author: Brandon
* Purpose: to encapsulate and manage the data required to render a terrain in 3D space.
*/
#pragma once

#include <memory>
#include <vector>
#include "gameObject.h"

namespace terrain{
	/**
	* @class Terrain
	* @brief A class that encapsulates and provides access to heightfield data.
	*
	* The Terrain class is responsible for loading heightfield data from a file and
	* storing it, providing scaling as well for its use in a game.
	*
	* @author Brandon Lim
	*/
	class Terrain : public GameObject{
	public:
		/**
		* The constructor for a Terrain object.
		*/
		Terrain();
		/**
		* The destructor for a Terrain object.
		*/
		~Terrain();

		/**
		* @brief Loads a heightfield from a file.
		* @param fileName - The name of the heightfield file
		* @return bool - true if heightfield was loaded, false if not
		*
		* loadHeightField loads heightfield data from a raw image file.
		*/
		bool loadHeightfield(std::string fileName);
		/**
		* @brief Sets the scale for the terrain.
		* @param x - The scaling factor along the x-axis
		* @param y - The sclaing factor along the y-axis
		* @param z - The scaling factor along the z-axis
		*
		* setScale sets the terrain scale along the x, y, and z axes with x, y, and z
		* respectively.
		*/
		void setScale(float x, float y, float z);
		/**
		* @brief Gets the terrain data.
		* @return const vector<unsigned char> - The terrain data
		*
		* getTerrainData simply returns a constant reference to the heightfield data.
		*/
		const std::vector<unsigned char> getTerrainData();
		/**
		* @brief Gets the terrain size.
		* @return int - The terrain's size (width or length)
		*
		* getTerrainSize simply returns the width/length of the heightmap, as the width
		* and length are (or should be) equal.
		*/
		int getTerrainSize();
		/**
		* @brief Gets the terrain's scaling factor along the x-axis.
		* @return float - The scaling factor
		*
		* getXScale simply gets the x-axis scaling factor for the heightfield.
		*/
		float getXScale();
		/**
		* @brief Gets the terrain's scaling factor along the y-axis.
		* @return float - The scaling factor
		*
		* getYScale simply gets the y-axis scaling factor for the heightfield.
		*/
		float getYScale();
		/**
		* @brief Gets the terrain's scaling factor along the z-axis.
		* @return float - The scaling factor
		*
		* getZScale simply gets the z-axis scaling factor for the heightfield.
		*/
		float getZScale();
		/**
		* @brief Gets the height of the terrain at a specified co-ordinate.
		* @param xPos - The x-value of the co-ordinate
		* @param zPos - The z-value of the co-ordinate
		* @return float - The height at the co-ordinate
		*
		* getHeight gets the height value at a specified co-ordinate in the heightfield.
		*/
		float getHeight(int xPos, int zPos);

	private:
		/// The heightfield data.
		std::unique_ptr<std::vector<unsigned char>> terrainData;
		/// The x-axis scaling factor.
		float xScale;
		/// The y-axis scaling factor.
		float yScale;
		/// The z-axis scaling factor.
		float zScale;
		/// The width/length of the terrain.
		int terrainSize;

		/**
		* @brief Checks if an XZ co-ordinate is within the bounds of the heightfield's
		* elements.
		* @param xPos - The x-value of the co-ordinate being checked
		* @param zPos - The z-value of the co-ordinate being checked
		* @return bool - true if the co-ordinate is within the heightfield, false if not
		*
		* inBounds checks a co-ordinate on the XZ plane to see if it is within the
		* heightfield's boundaries.
		*/
		bool inBounds(int xPos, int zPos);
		/**
		* @brief Gets the colour of the terrain at a specified co-ordinate.
		* @param xPos - The x-value of the co-ordinate
		* @param zPos - The z-value of the co-ordinate
		* @return unsigned char - The colour at the co-ordinate
		*
		* getHeightColour is a function only used for a simple colouring of the
		* heightfield, using the colour each point has from the image file.
		*/
		unsigned char getHeightColour(int xPos, int zPos);
	};
}
