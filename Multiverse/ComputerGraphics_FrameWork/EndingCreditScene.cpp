#include "pch.h"
#include "EndingCreditScene.h"


EndingCreditScene::EndingCreditScene()
{
}


EndingCreditScene::~EndingCreditScene()
{
}

void EndingCreditScene::initialize()
{
	// 글자
	func.TextColorListSet(0, 1, 1, 1);
	func.TextColorListSet(1, 0.9, 0.5, 0.8);
	func.TextColorListSet(2, 0.5, 0.8, 0.9);
	func.TextColorListSet(3, 0.9, 0.8, 0.5);
	func.TextColorListSet(4, 0, 0, 0);

	// 별
	StarColorListSet(0, 1, 1, 1);
	StarColorListSet(1, 0, 0, 0);
	StarColorListSet(2, 0.9, 0.6, 0.8);
	StarColorListSet(3, 0, 0, 0);
	StarColorListSet(4, 0.6, 0.8, 0.9);
	StarColorListSet(5, 0, 0, 0);
	StarColorListSet(6, 0.9, 0.8, 0.6);
	StarColorListSet(7, 0, 0, 0);

	for (int i = 0; i < MAXSTAR; ++i)
	{
		StarArr[i].x = -512 + rand() % 1024;
		StarArr[i].y = -384 + rand() % 768;
		StarArr[i].colorState = rand() % MAXSTARCOLOR;
		StarArr[i].rgb = func.GetTextList(StarArr[i].colorState);
		StarArr[i].percentage = (GLdouble)(rand()%100) / 100;
		StarArr[i].size = rand() % 3 + 2;
	}
}

void EndingCreditScene::Render()
{
	// 배경
	for (int i = 0; i < MAXSTAR; ++i)
	{
		glPushMatrix(); {
			glColor3d(StarArr[i].rgb.r, StarArr[i].rgb.g, StarArr[i].rgb.b);
			glTranslated(StarArr[i].x, StarArr[i].y, 1350);
			glutSolidSphere(StarArr[i].size, 10, 10);
		}glPopMatrix();
	}
	glClear(GL_DEPTH_BUFFER_BIT);


	// 글자
	glPushMatrix(); {
		glRotated(RotateX, 1, 0, 0);
		glTranslated(0, TraslateY, 0);
		func.TextPrint("Multivers", 300, false, true);
		glTranslated(0, -450, 0);
		func.TextColorSet("0000000112222112222");
		func.TextPrint("Team : BoDongBoDong", 100, true, true);
		glTranslated(0, -300, 0);
		func.TextColorSet("0000000011111");
		func.TextPrint("Sound : Bodam", 100, true, true);
		glTranslated(0, -300, 0);
		func.TextColorSet("000000000022222222");
		func.TextPrint("Graphic : DongSeok", 100, true, true);
		glTranslated(0, -300, 0);
		func.TextPrint("Class : Computer Graphics", 100, false, true);
		glTranslated(0, -300, 0);
		func.TextColorSet("00000000333333");
		func.TextPrint("Made by FivluX", 100, true, true);
	}glPopMatrix();
}

void EndingCreditScene::Reshape(int w, int h)
{
}

void EndingCreditScene::Timer(int value)
{
	if (State != 2)
	{
		switch (State)
		{
		case 0:
			TraslateY += 5;
			if (TraslateY > 780)
				State = 1;
			break;
		case 1:
			RotateX += 1;
			if (RotateX >= 0)
				State = 2;
			break;
		}
	}

	for (int i = 0; i < MAXSTAR; ++i)
	{
		StarArr[i].rgb = func.ColorChange(StarColorList, StarArr[i].colorState, (StarArr[i].colorState + 1) % MAXSTARCOLOR, StarArr[i].percentage);
		StarArr[i].percentage += 0.01;
		if (StarArr[i].percentage > 1)
		{
			StarArr[i].percentage = 0;
			StarArr[i].colorState = (StarArr[i].colorState + 1) % MAXSTARCOLOR;
		}
	}

}

void EndingCreditScene::Keyboard(unsigned char key, int x, int y)
{
}

void EndingCreditScene::SpecialKeyboard(int key, int x, int y)
{
}

void EndingCreditScene::Mouse(int button, int state, int x, int y)
{
}
