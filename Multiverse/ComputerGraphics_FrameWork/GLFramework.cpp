#include "pch.h"

#include "Scene.h"
#include "MainScene.h"
#include "Practice30.h"

#include "GLFramework.h"

CGLFramework::CGLFramework()
{
}


CGLFramework::~CGLFramework()
{
}

void CGLFramework::Initialize(int argc, char * argv[], int width, int height, int x, int y, const char * caption, int DisplayMode)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(DisplayMode); // 디스플레이 모드 설정
	glutInitWindowSize(width, height); // 윈도우의 크기 지정
	glutInitWindowPosition(x, y); // 윈도우의 위치지정
	glutCreateWindow(caption); // 윈도우 생성 (윈도우 이름)
	srand(time(NULL));

	m_CurrScene = new MainScene{};
	m_CurrScene->initialize();
}

void CGLFramework::Run() { glutMainLoop(); }

void CGLFramework::DrawScene()
{
	glClearColor(0.f, 0.f, 0.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH);
	glLoadIdentity();

	Render();

	glutSwapBuffers();
}

void CGLFramework::Render()
{
	if (m_CurrScene) m_CurrScene->Render();
}

void CGLFramework::Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
	gluPerspective(60.0f, (double)w / (double)h, 1, 4000);

	glTranslatef(-CameraX, -CameraY, -2000 + CameraZ);
	glRotatef(CameraRotateDegreeX, 1, 0, 0);
	glRotatef(CameraRotateDegreeY, 0, 1, 0);
	glRotatef(CameraRotateDegreeZ, 0, 0, 1);

	glMatrixMode(GL_MODELVIEW);

	if (m_CurrScene) m_CurrScene->Reshape(w, h);
	glEnable(GL_DEPTH_TEST);
	glutPostRedisplay();
}

void CGLFramework::Timer(int value)
{
	if (IsCameraRotateX)
		CameraRotateDegreeX = (CameraRotateDegreeX + CameraRotateDirection) % 360;
	if (IsCameraRotateY)
		CameraRotateDegreeY = (CameraRotateDegreeY + CameraRotateDirection) % 360;
	if (IsCameraRotateZ)
		CameraRotateDegreeZ = (CameraRotateDegreeZ + CameraRotateDirection) % 360;
	Reshape(WindowWidth, WindowHeight);

	if (m_CurrScene) m_CurrScene->Timer(value);
	glutTimerFunc(m_fps, fnTimer, 1);
}

void CGLFramework::Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
	case 'W':
		CameraY += CameraMoveSpeed;
		break;
	case 's':
	case 'S':
		CameraY -= CameraMoveSpeed;
		break;
	case 'a':
	case 'A':
		CameraX -= CameraMoveSpeed;
		break;
	case 'd':
	case 'D':
		CameraX += CameraMoveSpeed;
		break;
	case '=':
		CameraZ += CameraMoveSpeed;
		break;
	case '-':
		CameraZ -= CameraMoveSpeed;
		break;
	case 'x':
	case 'X':
		IsCameraRotateX = !IsCameraRotateX;
		break;
	case 'y':
	case 'Y':
		IsCameraRotateY = !IsCameraRotateY;
		break;
	case 'z':
	case 'Z':
		IsCameraRotateZ = !IsCameraRotateZ;
		break;
	case 'c':
	case 'C':
		CameraRotateDirection *= -1;
		break;
	case 'i':
	case 'I':
		CameraReset();
		break;
	default:
		if (m_CurrScene) m_CurrScene->Keyboard(key, x, y);
	}
	Reshape(WindowWidth, WindowHeight);
	glutPostRedisplay();
}

void CGLFramework::SpecialKeyboard(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_F10:
		ChangeScene(new CPractice30{});
		m_CurrScene->initialize();
		break;
	default:
		if (m_CurrScene) m_CurrScene->SpecialKeyboard(key, x, y);
	}
	glutPostRedisplay();
}

void CGLFramework::Mouse(int button, int state, int x, int y)
{
	if (m_CurrScene) m_CurrScene->Mouse(button, state, x, y);
	glutPostRedisplay();
}

void CGLFramework::MouseMotion(int x, int y)
{
	if (m_CurrScene) m_CurrScene->MouseMotion(x, y);
	glutPostRedisplay();
}

void CGLFramework::MousePassiveMotion(int x, int y)
{
	if (m_CurrScene) m_CurrScene->MousePassiveMotion(x, y);
	glutPostRedisplay();
}

void CGLFramework::ChangeScene(CScene * newScene)
{
	CameraReset();
	auto old = m_CurrScene;
	m_CurrScene = newScene;
	delete old;
}
