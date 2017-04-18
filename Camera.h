#include<GL\freeglut.h>


class Camera{

private:
	GLfloat cameraPosX, cameraPosY, cameraPosZ; // 镜头方向
	GLfloat cameraFrontX, cameraFrontY, cameraFrontZ;  //看着的方向 这是和Pront的相对位置
	GLfloat cameraRightX, cameraRightY, cameraRightZ; //左右移动标准单位
	GLfloat cameraUpX, cameraUpY, cameraUpZ; // 向上的方向

public:
	Camera();
	void moveForward(GLfloat const distance);
	void moveBack(GLfloat const distance);
	void moveRight(GLfloat const distance);
	void moveLeft(GLfloat const distance);
	void rotate(int x, int y);
	void cameraLookat();

};