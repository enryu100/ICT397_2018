/**
* @class lua_Script.h
* @brief A class that deals with all lua files
*
* The lua class is responsible for loading, running and assigning values from lua files
*
* @author Brandon Lim
* @todo possible read in object type parameters if necessary
*/


#ifndef LUA_SCRIPT_H
#define LUA_SCRIPT_H

//For calling functions from a lua file simply call Load and close when done with the file
//For setting variables from a file use Load to open the file, close to close the file and Read_Variable_(var type) to assign variables

extern "C"{
	#include "Lua\lua.h"
	#include "Lua\lualib.h"
	#include "Lua\lauxlib.h"
}
//#include "Lua\luabind\luabind.hpp"
#include <string>
using namespace std;
class lua_Script
{
public:
		/**
        *@brief default constructer for Lua, assigns a newstate/libs
         */
	lua_Script(void);
		/**
        *@brief default deconstructer for Date
         */
	~lua_Script(void);
		/**
         *@brief Loads in a lua file
         *@return void
		 *@param filename - const char*
         */
	void Load(const char* fileName);
		/**
         *@brief closes the lua file
         *@return void
         */
	void Close();
		/**
         *@brief Reads in an int from a lua file
         *@return int
		 *@param varName - const char*
         */
	int Read_Variable_Int(const char* varName);
		/**
         *@brief Reads in a string from a lua file
         *@return string
		 *@param varName - const char*
         */
	string Read_Variable_String(const char* varName);

private:
	lua_State*L;

	//int Read_Variable_Int(const char* varName);
};

#endif // lua_Script_h