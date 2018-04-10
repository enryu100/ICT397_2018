#define GLFW_DLL

#include <iostream>
#include <math.h>
#include <gl/glut.h>
#include <gl/glfw.h>
#include "myMath.h"
#include "vector2D.h"
#include "movement.h"
#include "waypoint.h"

using namespace std;

bool running;
int mouseX=0;
int mouseY=0;
int width=800,height=600;
vector2D targetPos(500,500); //targets moveto position 
vector2D targetXZ(10,10);  //targets xy position
vector2D targetVel(0,62);    //targets initial velocity
vector2D pursuerXZ(590,590); //pursuers xy position
vector2D pursuerVel(1,1);   //pursuers initial velocity
waypoint<vector2D> waypoints;
vector2D curWaypoint;
int curwayPointNo;
 bool chase;

void  myinit (void)
{
 glClearColor (0.0, 0.0, 0.0, 0.0);
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
 glOrtho(0,width,height,0,-1.0,1.0);
 curwayPointNo=0;
 waypoints.addWaypoint(vector2D(10,10));
 waypoints.addWaypoint(vector2D(250,10));
 waypoints.addWaypoint(vector2D(250,250));
 waypoints.addWaypoint(vector2D(10,250));
 curWaypoint=waypoints.getWaypoint(0);
 chase=false;
}
 
void  display(double deltaT)
{
 glClear(GL_COLOR_BUFFER_BIT );	// Clear The Screen And The Depth Buffer
 glColor3ub(255, 255, 255);
 glRecti(targetXZ[0], targetXZ[1], targetXZ[0]+20, targetXZ[1]+20);     //render target as a rectangle
 glColor3ub(255, 0, 0);
 glRecti(pursuerXZ[0], pursuerXZ[1], pursuerXZ[0]+20, pursuerXZ[1]+20); //render pursuer as a rect
 glFlush();
}

void GLFWCALL mouseAction(int button, int action)
{
    if(button==GLFW_MOUSE_BUTTON_LEFT && action ==GLFW_PRESS)
	{
		pursuerXZ.set(mouseX,mouseY);   //changes targets position to where the mouse is clicked
		chase=false;
	}
}

void GLFWCALL mouse(int x, int y)
{
 mouseX=x;
 mouseY=y;
}
 
void GLFWCALL  kb(int kbq, int action )
{

	switch(kbq)
	{
		case GLFW_KEY_ESC:
			running=false;
			break;
	}
}

int main()
{

 bool done=false;
 double time0,time1;
 double frequency=0.05;  //frequency of logic update - every 20ms
   glfwInit();
     if( !glfwOpenWindow( width,height, 0,0,0,0, 0,0, GLFW_WINDOW) )
     {
        glfwTerminate();
        return 0;
     }
 myinit();	
// glfwSetWindowSizeCallback( myReshape );
 glfwEnable( GLFW_KEY_REPEAT );
 // Set key callback function
 glfwSetKeyCallback( kb );
 glfwSetMousePosCallback( mouse );
 glfwSetMouseButtonCallback(mouseAction);
 // Set tile
 glfwSetWindowTitle( "patrollong chase example 2D" );
 running = GL_TRUE;
 time0=glfwGetTime();
 /*****************  game loop ****************************************/  
   do
   { 
    time1=glfwGetTime();
      while(((float)time1 - time0) > frequency)
	  {  //update player ai
		  if(!chase)
		  {
             if(moveTo(targetXZ,curWaypoint,targetVel,time1-time0))
		     { 
			   if(curwayPointNo==waypoints.getNumWaypoints()-1)
				 curwayPointNo=0;
			   else
		         curwayPointNo++;
		      curWaypoint=waypoints.getWaypoint(curwayPointNo);
		     }
		  }
       if(seeTarget(targetXZ,pursuerXZ,targetVel,100,180))
	   {
		   chase=true;
	   }
	   if(chase==true)
	   {
	     moveTo(targetXZ,pursuerXZ,targetVel,time1-time0,5);
	   }

       time0+=frequency;
   	  }
	  if(((float)time1 - time0) > frequency)
	     time0 = time1 - frequency;
	display(time1-time0);  //render
	glfwSwapBuffers();
    // Check if the window was closed
    running = running && glfwGetWindowParam( GLFW_OPENED );	
   }while(running);

  glfwTerminate();
/**************** end game loop  *************************************/
getchar();






}