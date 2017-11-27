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
	textColor.r = 0.9;
	textColor.g = 0.5;
	textColor.b = 0.8;
	TextPrint("Score :                                        ", 100, textColor);
	textColor.r = 0.5;
	textColor.g = 0.9;
	textColor.b = 0.8;
	TextPrint("           2501?!                           ", 100, textColor);
	textColor.r = 0.9;
	textColor.g = 0.8;
	textColor.b = 0.5;
	TextPrint("                             Press Any Key...    ", 100, textColor);
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
