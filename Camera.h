#include<GL\freeglut.h>


class Camera{

private:
	GLfloat cameraPosX, cameraPosY, cameraPosZ; // ��ͷ����
	GLfloat cameraFrontX, cameraFrontY, cameraFrontZ;  //���ŵķ��� ���Ǻ�Pront�����λ��
	GLfloat cameraRightX, cameraRightY, cameraRightZ; //�����ƶ���׼��λ
	GLfloat cameraUpX, cameraUpY, cameraUpZ; // ���ϵķ���

public:
	Camera();
	void moveForward(GLfloat const distance);
	void moveBack(GLfloat const distance);
	void moveRight(GLfloat const distance);
	void moveLeft(GLfloat const distance);
	void rotate(int x, int y);
	void cameraLookat();

};