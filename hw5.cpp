// hw5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <GL\freeglut.h>
#include<GL\glu.h>
#include<math.h>
#include<time.h>
#include "Camera.h"

#define Radius 2

static Camera camera;
void drawcube() {
	
	glBegin(GL_QUADS);

	//front  red
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.05f, 0.05f, 0.05f);
	glVertex3f(0.05f, 0.05f, -0.05f);
	glVertex3f(-0.05f, 0.05f, -0.05f);
	glVertex3f(-0.05f, 0.05f, 0.05f);

	//bottom  green
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.05f, 0.05f, -0.05f);
	glVertex3f(0.05f, -0.05f, -0.05f);
	glVertex3f(-0.05f, -0.05f, -0.05f);
	glVertex3f(-0.05f, 0.05f, -0.05f);

	//top  blue  
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.05f, 0.05f, 0.05f);
	glVertex3f(0.05f, -0.05f, 0.05f);
	glVertex3f(-0.05f, -0.05f, 0.05f);
	glVertex3f(-0.05f, 0.05f, 0.05f);

	//behind  purple
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(0.05f, -0.05f, -0.05f);
	glVertex3f(0.05f, -0.05f, 0.05f);
	glVertex3f(-0.05f, -0.05f, 0.05f);
	glVertex3f(-0.05f, -0.05f, -0.05f);

	//left  ao
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-0.05f, -0.05f, 0.05f);
	glVertex3f(-0.05f, 0.05f, 0.05f);
	glVertex3f(-0.05f, 0.05f, -0.05f);
	glVertex3f(-0.05f, -0.05f, -0.05f);

	//right  yellow
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.05f, 0.05f, 0.05f);
	glVertex3f(0.05f, 0.05f, -0.05f);
	glVertex3f(0.05f, -0.05f, -0.05f);
	glVertex3f(0.05f, -0.05f, 0.05f);

	glEnd();
}

void drawOrtho() {
	glClearColor(1.0, 0.6, 0.6, 1.0);
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// save previous matrix which contains the
	//settings for the perspective projection
	glPushMatrix();
	//glFrustum(-1, 1, -1, 1, 1, 1.5);
	glOrtho(-1, 1, -1, 1, 1, 1.5);
	//glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//glPushMatrix();

	glTranslatef(0.5, -0.5, -1.5);
	drawcube();
	
	glPopMatrix();

	

	glutSwapBuffers();
}


void drawFrustum() {
	glClearColor(1.0, 0.6, 0.6, 1.0);
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// save previous matrix which contains the
	//settings for the perspective projection
	glPushMatrix();
	glFrustum(-1, 1, -1, 1, 1, 1.5);
	//glOrtho(-1, 1, -1, 1, 1, 1.5);
	//glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//glPushMatrix();

	glTranslatef(0.5, -0.5, -1.5);
	drawcube();

	glPopMatrix();

	glutSwapBuffers();
}

void drawLookAt() {
	glClearColor(1.0, 0.6, 0.6, 1.0);
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// save previous matrix which contains the
	//settings for the perspective projection
	glPushMatrix();
	//glOrtho(-1, 1, -1, 1, -29, 29);
	glFrustum(-1, 1, -1, 1, 1, 30);
	
	//glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
//	glPushMatrix();

	gluLookAt(sin(clock() / 1000.0)*Radius, 0, cos(clock() / 1000.0)*Radius, //相机位置设定
		0, 0, 0,  //图像中心设置
		1, 1, 0); //头顶方向

	drawcube();

	glPopMatrix();
	glutSwapBuffers();

	glutPostRedisplay();
	
}

void FPSfunc() {
	glClearColor(1.0, 0.6, 0.6, 1.0);
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glPushMatrix();
	glFrustum(-1, 1, -1, 1, 0, 3);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	camera.cameraLookat();//生成了一个look at

	drawcube();

	glPopMatrix();
	glutSwapBuffers();

	//glutPostRedisplay();

}

int mouseX, mouseY;
void MouseFunc(int x, int y) {
	mouseX = x;
	mouseY = y;
	camera.rotate(x, y);
}

void processNormalKeys(unsigned char key, int x, int y)
{

	switch (key)
	{
	case 100: camera.moveRight(0.1) ; //d
		break;
	case 119: camera.moveForward(0.1); 
		break; //w
	case 115:camera.moveBack(0.1);
		break; //s
	case 97: camera.moveLeft(0.1);
		break;//a
	}
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 640);

	glutCreateWindow("draw");

	glutDisplayFunc(FPSfunc);
	glutKeyboardFunc(processNormalKeys);
	//glutPassiveMotionFunc(MouseFunc);

	glutMainLoop();
	return 0;
}