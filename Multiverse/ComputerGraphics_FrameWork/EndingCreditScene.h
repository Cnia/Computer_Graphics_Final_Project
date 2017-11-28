#pragma once
#include "Scene.h"
#include "TextFunction.h"

#define MAXSTAR 300
#define MAXSTARCOLOR 8

struct Star {
	GLdouble x, y;
	RGB rgb;
	GLint colorState;
	GLdouble percentage;
	GLdouble size;
};

class EndingCreditScene :
	public CScene
{
private:
	// 배경
	Star StarArr[MAXSTAR];
	RGB StarColorList[MAXSTARCOLOR];

	// 글자
	GLdouble RotateX = -35;
	GLdouble TraslateY = -1200;
	GLint State = 0;

	TextFunction func;
public:
	EndingCreditScene();
	virtual ~EndingCreditScene();

	virtual void initialize();
	virtual void Render();
	virtual void Reshape(int w, int h);
	virtual void Timer(int value);

	virtual void Keyboard(unsigned char key, int x, int y);
	virtual void SpecialKeyboard(int key, int x, int y);
	virtual void Mouse(int button, int state, int x, int y);

	virtual void StarColorListSet(int num, GLdouble R, GLdouble G, GLdouble B)
	{
		StarColorList[num].r = R;
		StarColorList[num].g = G;
		StarColorList[num].b = B;
	}
};

