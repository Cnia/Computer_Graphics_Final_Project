#pragma once
#include "Scene.h"

#define BigRadius 200
#define SmallRadius 100
#define SNOW_NUM 200

struct Snow {
	GLdouble x;
	GLdouble y;
	GLdouble z;
	GLdouble speed;
};

class CPractice30 :
	public CScene
{
private:
	// 조명
	GLfloat ambientLight[4] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat diffuseLight[4] = { 0.6f, 0.6f, 0.6f, 1.0f };
	GLfloat specular[4] = { 1.0f, 1.0f, 1.0f, 1.0f };

	GLfloat lightPos[4] = { 0, 0, 0, 1.0f };
	GLfloat specref[4] = { 0.2f, 0.2f, 0.2f, 1.0f };

	// 조명 조작
	bool light0on = true;
	bool light1on = true;
	bool light2on = true;
	bool light3on = true;
	bool AllLighton = true;
	bool NomalizeOn = true;

	// 조형물
	GLdouble PyramidBigDegree = 0;
	GLdouble PyramidBigX;
	GLdouble PyramidBigZ;
	GLdouble PyramidSmallDegree = 180;
	GLdouble PyramidSmallX;
	GLdouble PyramidSmallZ;

	Snow snow[SNOW_NUM];
public:
	CPractice30();
	virtual ~CPractice30();

	virtual void initialize();
	virtual void Render();
	virtual void Reshape(int w, int h);
	virtual void Timer(int value);

	virtual void Keyboard(unsigned char key, int x, int y);
	virtual void SpecialKeyboard(int key, int x, int y);
	virtual void Mouse(int button, int state, int x, int y);
};

