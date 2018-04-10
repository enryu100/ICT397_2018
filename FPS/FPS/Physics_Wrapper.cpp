#include "Physics_Wrapper.h"


Physics_Wrapper::Physics_Wrapper(void)
{
	collisionConfiguration = new btDefaultCollisionConfiguration();
	dispatcher = new	btCollisionDispatcher(collisionConfiguration);
	overlappingPairCache = new btDbvtBroadphase();
	solver = new btSequentialImpulseConstraintSolver;
	dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher,overlappingPairCache,solver,collisionConfiguration);
}

//helloWorld example has gravity btVector3(0, -10, 0);
void Physics_Wrapper::SetGravity(double ygravity){
	dynamicsWorld->setGravity(btVector3(0, ygravity, 0));
}

void Physics_Wrapper::CreateRigidBodyRectangle(int height, int width, int length, int massi, int xpos, int ypos, int zpos, int xInertia, int yInertia, int zInertia){
	//btScalar origen, btScalar mass, btVector3 dimension, btVector3 localInertia
	//box shape, dimensions are 50 by 50 by 50? might get doubled since hello world says 100
	//height = 50, width =50, length =50;
	//massi = 0
	//xpos =0, ypos = -56, zpos = 0
	//all inertia =0
	btCollisionShape* groundShape = new btBoxShape(btVector3(btScalar(width),btScalar(height),btScalar(length)));
	collisionShapes.push_back(groundShape);
	btTransform groundTransform;
	groundTransform.setIdentity();

	//put this as a thingy that goes into the method
	//sets the origon of the cube at 0, -56, 0
	groundTransform.setOrigin(btVector3(xpos,ypos,zpos));
	//mass of the cube, also have this be passed in
	btScalar mass(massi);

	bool isDynamic = (mass !=0.f);
	//inertia  towards an x, y, z direction?
	//needs a mass to have inertia
	btVector3 localInertia (xInertia, yInertia, zInertia);

	if (isDynamic)
			groundShape->calculateLocalInertia(mass,localInertia);

	btDefaultMotionState* myMotionState = new btDefaultMotionState(groundTransform);
	btRigidBody::btRigidBodyConstructionInfo rbInfo(mass,myMotionState,groundShape,localInertia);
	btRigidBody* body = new btRigidBody(rbInfo);

	dynamicsWorld->addRigidBody(body);

}

void Physics_Wrapper::CreateRigidBodySphere(int radius, int massi, int xpos, int ypos, int zpos, int xInertia, int yInertia, int zInertia){
	//int mass, int radius
	//sphere 1 by 1
	/*
	int radius = 1;
	int masss =1.f;
	int xpos = 2, ypos = 16, zpos =0;
	int xInertia=0, yInertia=0, zInertia=0;
	*/
	btCollisionShape* sphereShape = new btSphereShape(btScalar(radius));
	collisionShapes.push_back(sphereShape);
	
	btTransform groundTransform;
	groundTransform.setIdentity();

	//put this as a thingy that goes into the method
	//sets the origon of the sphere at 0, -56, 0
	groundTransform.setOrigin(btVector3(xpos,ypos,zpos));
	//mass of the cube, also have this be passed in
	
	btScalar mass(massi);

	bool isDynamic = (mass !=0.f);
	//inertia  towards an x, y, z direction?
	//needs a mass to have inertia
	btVector3 localInertia (xInertia, yInertia, zInertia);

	if (isDynamic)
			sphereShape->calculateLocalInertia(mass,localInertia);

	btDefaultMotionState* myMotionState = new btDefaultMotionState(groundTransform);
	btRigidBody::btRigidBodyConstructionInfo rbInfo(mass,myMotionState,sphereShape,localInertia);
	btRigidBody* body = new btRigidBody(rbInfo);
	
	dynamicsWorld->addRigidBody(body);

}


void Physics_Wrapper::Run(){
		for (int i=0;i<150;i++)
	{
		dynamicsWorld->stepSimulation(1.f/60.f,10);
		
		//print positions of all objects
		for (int j=dynamicsWorld->getNumCollisionObjects()-1; j>=0 ;j--)
		{
			btCollisionObject* obj = dynamicsWorld->getCollisionObjectArray()[j];
			btRigidBody* body = btRigidBody::upcast(obj);
			btTransform trans;
			if (body && body->getMotionState())
			{
				body->getMotionState()->getWorldTransform(trans);

			} else
			{
				trans = obj->getWorldTransform();
			}
			printf("world pos object %d = %f,%f,%f\n",j,float(trans.getOrigin().getX()),float(trans.getOrigin().getY()),float(trans.getOrigin().getZ()));
		}
	}
}

float Physics_Wrapper::GetXorigen(int i){
	if(i<dynamicsWorld->getNumCollisionObjects()){
			btCollisionObject* obj = dynamicsWorld->getCollisionObjectArray()[i];
			btRigidBody* body = btRigidBody::upcast(obj);
			btTransform trans;
			trans = obj ->getWorldTransform();
			return(trans.getOrigin().getX());
	}
}

float Physics_Wrapper::GetYorigen(int i){
	if(i<dynamicsWorld->getNumCollisionObjects()){
			btCollisionObject* obj = dynamicsWorld->getCollisionObjectArray()[i];
			btRigidBody* body = btRigidBody::upcast(obj);
			btTransform trans;
			trans = obj ->getWorldTransform();
			return(trans.getOrigin().getY());
	}
}

float Physics_Wrapper::GetZorigen(int i){
	if(i<dynamicsWorld->getNumCollisionObjects()){
			btCollisionObject* obj = dynamicsWorld->getCollisionObjectArray()[i];
			btRigidBody* body = btRigidBody::upcast(obj);
			btTransform trans;
			trans = obj ->getWorldTransform();
			return(trans.getOrigin().getZ());
	}
}

Physics_Wrapper::~Physics_Wrapper(void)
{
	delete dynamicsWorld;

	//delete solver
	delete solver;

	//delete broadphase
	delete overlappingPairCache;

	//delete dispatcher
	delete dispatcher;

	delete collisionConfiguration;

	//next line is optional: it will be cleared by the destructor when the array goes out of scope
	collisionShapes.clear();
}
