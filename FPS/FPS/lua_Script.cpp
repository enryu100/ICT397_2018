#include "lua_Script.h"


lua_Script::lua_Script(void)
{
	L=luaL_newstate();
	luaL_openlibs(L);
}


lua_Script::~lua_Script(void)
{
}
//loads a lua file
void lua_Script::Load(const char* fileName){
	luaL_dofile(L, fileName);
}

void lua_Script::Close(){
	lua_close(L);
}

//reads in a int from a lua file
int lua_Script::Read_Variable_Int(const char* varName){
	lua_settop(L,0);
	lua_getglobal(L, varName);
	int intVar = (int)lua_tonumber(L, 1);
	lua_pop(L, 1);
	return(intVar);
}
//reads in a string from a lua file
string lua_Script::Read_Variable_String(const char* varName){
	lua_settop(L,0);
	lua_getglobal(L, varName);
	string stringVar = (string)lua_tostring(L, 1);
	lua_pop(L, 1);
	return(stringVar);
}
//commented out until I remember is we need any other datatypes
/*
int lua_Script::Read_Variable_Int(const char* varName){
	lua_settop(L,0);
	lua_getglobal(L, varName);
	int intVar = (int)lua_tostring(L, 1);
	lua_pop(L, 1);
	return(intVar);
}
*/