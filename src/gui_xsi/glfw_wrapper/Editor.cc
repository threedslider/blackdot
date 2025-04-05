/* 
This file is part of Blackdot
Copyright (C) 2024-2025 Laurent Le Flem

This program is free software: you can redistribute it and/or modify it under 
the terms of the GNU General Public License as published by the Free Software Foundation, 
either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. 
If not, see <https://www.gnu.org/licenses/>.
*/



#include <iostream>
#include "Editor.hpp"


void mouseButtonCallback(GLFWwindow* Window, int button, int action, int mods)
{
	/*
	mouse.posx=x;
	mouse.posy=Height-y;
	mouse.button=button;
	mouse.state=state;
	mouse.active=-1;
	mouse.Alt=mouse.Shift=mouse.Ctrl=0;
	mouse.Left=mouse.Right=0;
	mouse.None=1;
	*/

	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {

		double mouseX, mouseY;
		glfwGetCursorPos(Window, &mouseX, &mouseY);

		int width, height;
		glfwGetWindowSize(Window, &width, &height);

		mouseY = height - mouseY;

		Blackdot::Mouse(mouseX, mouseY);


	}

	switch (button)
	{

	case GLFW_MOUSE_BUTTON_LEFT:
		Blackdot::Editor::mouse.Left = 1;
		break;
	case GLFW_MOUSE_BUTTON_RIGHT:
		Blackdot::Editor::mouse.Right = 1;
		break;
	}

}

Blackdot::Mouse Blackdot::Editor::mouse;

namespace Blackdot
{


Editor::Editor()
{
	mouse.active = mouse.button = mouse.clicx = mouse.clicy = -1;
	mouse.MouseIs = mouse.posx = mouse.posy = mouse.state = mouse.x = mouse.y = -1;
	mouse.Alt = mouse.Shift = mouse.Ctrl = 0;
	mouse.x = mouse.y = 0;
	
}

Editor::~Editor()
{
}

void Editor::InitGL(int w, int h, char* title)
{
	if (!glfwInit()) {
        std::cerr << "Cannot for the initialization of GLFW" << std::endl;
        exit(EXIT_FAILURE);
    }

    
    window = glfwCreateWindow(w, h, title, NULL, NULL);
    if (!window) {
        std::cerr << "Cannot create the window for GLFW" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);



    
   

    
	glClearColor(.6, .6, .6, 1);
	//Width = w;
	//Height = h;

	//int width, height;
	//glfwGetWindowSize(window, &width, &height);

	vs.Init(w, h);

	glfwSetMouseButtonCallback(window, mouseButtonCallback);

	glEnable(GL_DEPTH_TEST); 

}

void Editor::Key(unsigned char key, int x, int y)
{
	switch(key)
	{
	case '-':vs.ZoomOut(1);
		break;
	case '+':vs.ZoomIn(1);
		break;

		//vue 3 XYZ
	case '7':vs.ResetRotate(2);
		break;
	case '1':vs.ResetRotate(1);
		break;
	case '3':vs.ResetRotate(0);
		break;

	case '4':vs.Rotate(1, -5);
		break;
	case '6':vs.Rotate(1, 5);
		break;
	case '8':vs.Rotate(0, -5);
		break;
	case '2':vs.Rotate(0, 5);
		break;

	case 's':objectsystem.DeleteVertexSelect();
		break;
	case 'd':objectsystem.DeleteAllVertex();
		break;
	case 'a':objectsystem.CancelFace();
		break;


	case 27:exit(0);
		break;
	}
}

/*
void Editor::KeySpec(int key, int x, int y)
{
	switch(key)
	{
	case GLUT_KEY_F12:	vs.InvSolo();		//inverse le mode Solo ou 4 vues
		break;

	case GLUT_KEY_F1:	vs.SetWinSolo(1);	//met la vue 1 en solo
		break;	
	case GLUT_KEY_F2:	vs.SetWinSolo(2);	//met la vue 2 en solo
		break;
	case GLUT_KEY_F3:	vs.SetWinSolo(3);	//idem 3
		break;
	case GLUT_KEY_F4:	vs.SetWinSolo(4);	//idem 4
		break;
	
	case GLUT_KEY_F5:	vs.SetRendu(POINT);
		break;
	case GLUT_KEY_F6:	vs.SetRendu(LINE);
		break;
	case GLUT_KEY_F7:	vs.SetRendu(FILL);
		break;
	case GLUT_KEY_F8:	vs.InvCullFace();
		break;

	case GLUT_KEY_INSERT:
		break;
	default:
		break;
	}

}
*/


void Editor::Mouse(int x, int y)
{
	mouse.clicx=mouse.x;			
	mouse.clicy=mouse.y;			

	mouse.x=x;						
	mouse.y=Height-y;				

	
	vs.Mouse(mouse.x, mouse.y);		
}

void Editor::Reshape(int w, int h)
{
	if(h == 0) h = 1;

	Width=w;
	Height=h;

	vs.Reshape(w, h);	//la on avertis ViewportSystem des nouvelle dimmension
}

void Editor::DrawRun()
{
	while (!glfwWindowShouldClose(window)) {

		Draw();
		int width, height;
		glfwGetWindowSize(window, &width, &height);

		if (height == 0) height = 1;

		Width = width;
		Height = height;

		vs.Reshape(width, height);
		
		glfwPollEvents();
	}

	glfwTerminate();
}

void Editor::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	glClearColor(.6,.6,.6, 1);


	vs.LoadOrtho();
	
	//Msg();			


	
	if(vs.GetSolo()==SINGLE_VIEWPORT)
	{
			vs.LoadViewportSolo();
			DrawScene();
	}
	else		
	{
		for(int i=1; i <=4; i++)
		{
			vs.LoadViewport(i);
			DrawScene();
		
		}
	}


	vs.DrawContour();	

	
	glfwSwapBuffers(window);
}

void Editor::DrawScene()
{
	objectsystem.Draw();				
	//DrawAxes();
}
/*
void Editor::Msg()
{
	if(mouse.state==GLUT_DOWN)
	{
		if(mouse.Alt  && mouse.Shift && mouse.Right)
		{
			vs.ZoomIn((mouse.y-mouse.posy)*.001);
			glutPostRedisplay();
		}
		else if(mouse.Alt && mouse.Right)
		{
			vs.Rotate(X, -(mouse.y-mouse.posy)*.1);	
			vs.Rotate(Y, (mouse.x-mouse.posx)*.1);
			glutPostRedisplay();
		}
		else if(mouse.Alt && mouse.Left)
		{
			vs.Centre(&mouse);
			glutPostRedisplay();
		}
		else if(mouse.Ctrl && mouse.Right)
		{
			objectsystem.SelectVertex(&mouse, vs.GetViewport());
		}
		else if(mouse.Ctrl && mouse.Left)
		{
			objectsystem.AddFace(&mouse, vs.GetViewport());
		}
		else if(mouse.Shift && mouse.Left)
		{
			objectsystem.TranslateVertex(&mouse, vs.GetViewport());
			glutPostRedisplay();
		}
		else if(mouse.Shift && mouse.Right)
		{
			vs.DrawRect(&mouse);	//il faudra plus tard la mettre en fin de fonction de dessin dans DrawScene
			objectsystem.SelectRectVertex(&mouse, vs.GetViewport());
			String(10, 40, "Mouse posx %i posy %i", mouse.posx, mouse.posy);
			String(10, 55, "Mouse x %i y %i", mouse.x, mouse.y);
			glutPostRedisplay();
		}
		else if(mouse.Right	&& mouse.None)
		{
			objectsystem.AnnuleFace();
			objectsystem.DeSelectAllVertex();
		}
		else if(mouse.Left && mouse.None)
		{
			objectsystem.AddVertex(&mouse,vs.GetViewport());
		}
	}
}

void Editor::ResetMouse()
{
	mouse.button=-1;
	mouse.state=-1;
	mouse.active=-1;
	mouse.Alt=mouse.Shift=mouse.Ctrl=0;
	mouse.Left=mouse.Right=0;
	mouse.None=1;
}*/

}
