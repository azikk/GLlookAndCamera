#include"stdafx.h"
#include "Camera.h"
#include <GL/freeglut.h>
#include<math.h>
#include<iostream>
using namespace std;

Camera::Camera(){
	cameraPosX = 0;
	cameraPosY = 0;
	cameraPosZ = 3; //相机位置
	cameraFrontX = 0;
	cameraFrontY = 0;
	cameraFrontZ = -1;
	cameraUpX = 0;
	cameraUpY = 1;
	cameraUpZ = 0;
	cameraRightX = 1;
	cameraRightY = 0;
	cameraRightZ = 0;
	//cameraRight = glm::normalize(glm::cross(cameraFront, cameraUp));
	//cameraRightX = 
	//float x1, y1, z1;
/*	cameraRightX = cameraPosY*cameraFrontZ - cameraPosZ*cameraFrontY;//y*b.z - z*b.y;
	cameraRightY = cameraPosZ*cameraFrontX - cameraPosX*cameraFrontZ;//z*b.x - x*b.z;
	cameraRightZ = cameraPosX*cameraFrontY - cameraPosY*cameraFrontX;//x*b.y - y*b.x;

	float base = pow(cameraRightX, 2) + pow(cameraRightY, 2) + pow(cameraRightZ, 2);

	cameraRightX = cameraRightX / pow(base, (float)0.5);
	cameraRightY = cameraRightY / pow(base, (float)0.5);
	cameraRightZ = cameraRightZ / pow(base, (float)0.5);
	*/

}

//移动
void Camera::moveForward(GLfloat const distance){
	//cameraPosX += distance*cameraFrontX;
	//cameraPosY += distance*cameraFrontY;
	//cameraPosZ += distance*cameraFrontZ;
	cameraPosZ -= distance;
	cameraLookat();
}
void Camera::moveBack(GLfloat const distance){
	//cameraPosX -= distance*cameraFrontX;
	//cameraPosY -= distance*cameraFrontY;
	//cameraPosZ -= distance*cameraFrontZ;
	cameraPosZ += distance;
	cameraLookat();
}

void Camera::moveRight(GLfloat const distance){
	cameraPosX += distance*cameraRightX;
	cameraPosY += distance*cameraRightY;
	cameraPosZ += distance*cameraRightZ;
	cameraLookat();
}
void Camera::moveLeft(GLfloat const distance){
	cameraPosX -= distance*cameraRightX;
	cameraPosY -= distance*cameraRightY;
	cameraPosZ -= distance*cameraRightZ;
	cameraLookat();
}


void Camera::rotate(int x, int y){
	if (x < 320) {
		if (y < 320) {
			cameraFrontX =- x / 3;
			cameraFrontY = y / 3;
		}
		else if (y >= 320) {
			cameraFrontX = -x / 3;
			cameraFrontY = -y / 3;
		}
	}
	else if (x >= 320) {
		if (y < 320) {
			cameraFrontX = x / 3;
			cameraFrontY = y / 3;
		}
		else if (y >= 320) {
			cameraFrontX = x / 3;
			cameraFrontY = -y / 3;
		}
	}
	cout << x << " " << y << endl;
	cameraLookat();
}


void Camera::cameraLookat(){

	gluLookAt(cameraPosX, cameraPosY, cameraFrontZ,
		cameraPosX + cameraFrontX, cameraPosY + cameraFrontY, cameraPosZ+cameraFrontZ,
		cameraUpX, cameraUpY, cameraUpZ);
	glutPostRedisplay();
	//cout << cameraPosX << " " << cameraPosY << " " << cameraPosZ << endl;
}