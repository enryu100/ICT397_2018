#include "ModelLoader.h"
#include <Assimp/Importer.hpp>
#include <Assimp/scene.h>
#include <Assimp/postprocess.h>

using namespace loader;
using namespace std;
using namespace types;

bool loader::loadObj(const char* path, vector<Vector3D> & outVertices){
	Assimp::Importer modelLoader;

	const aiScene* scene = modelLoader.ReadFile(path, aiProcess_CalcTangentSpace | aiProcess_Triangulate | aiProcess_JoinIdenticalVertices | aiProcess_SortByPType);
	if(!scene)
		return false;

	if(scene->mNumMeshes > 0){
		for(unsigned i = 0; i < scene->mNumMeshes; i++){
			for(unsigned j = 0; j < scene->mMeshes[i]->mNumVertices; j++){
				outVertices.push_back(Vector3D(scene->mMeshes[i]->mVertices[j].x, scene->mMeshes[i]->mVertices[j].y, scene->mMeshes[i]->mVertices[j].z));
			}
		}
	}

	return true;
}