#pragma once
#include "Scene.h"
class MainScene :
	public CScene
{
private:
public:
	MainScene();
	virtual ~MainScene();

	virtual void initialize();
	virtual void Render();
	virtual void Reshape(int w, int h);
	virtual void Timer(int value);

	virtual void Keyboard(unsigned char key, int x, int y);
	virtual void SpecialKeyboard(int key, int x, int y);
	virtual void Mouse(int button, int state, int x, int y);
};

