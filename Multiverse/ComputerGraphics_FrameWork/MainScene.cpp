#include "pch.h"
#include "MainScene.h"


MainScene::MainScene()
{
}


MainScene::~MainScene()
{
}

void MainScene::initialize()
{
}

void MainScene::Render()
{
	RGB textColor;
	textColor.r = 1;
	textColor.g = 0;
	textColor.b = 0;

	TextPrint("ABC", 100, textColor);
}

void MainScene::Reshape(int w, int h)
{
}

void MainScene::Timer(int value)
{
}

void MainScene::Keyboard(unsigned char key, int x, int y)
{
}

void MainScene::SpecialKeyboard(int key, int x, int y)
{
}

void MainScene::Mouse(int button, int state, int x, int y)
{
}
