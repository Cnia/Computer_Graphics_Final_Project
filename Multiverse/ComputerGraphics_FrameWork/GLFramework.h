#pragma once 

using namespace std;

class CScene;

class CGLFramework
{
public:
	CGLFramework();
	~CGLFramework();

	void Initialize(int argc
		, char *argv[]
		, int width, int height
		, int x, int y
		, const char* caption
		, int DisplayMode = GLUT_DOUBLE | GLUT_RGBA
	);

	void Run();

	void DrawScene();

	void Render();

	void Reshape(int w, int h);

	void Timer(int value);

	void Keyboard(unsigned char key, int x, int y);
	void SpecialKeyboard(int key, int x, int y);
	void Mouse(int button, int state, int x, int y);
	void MouseMotion(int x, int y);
	void MousePassiveMotion(int x, int y);

	using KeyboardFunc = void(*)(unsigned char, int, int);
	using SpecialKeyboardFunc = void(*)(int, int, int);
	using MouseFunc = void(*)(int, int, int, int);
	using MouseMotionFunc = void(*)(int, int);
	using MousePassiveMotionFunc = void(*)(int, int);

	void RegisterKeyboardFunction(KeyboardFunc keyboad) { fnKeyboard = keyboad; }
	void RegisterSpecialKeyboardFunction(SpecialKeyboardFunc specialKeyboard) { fnSpecialKeyboard = specialKeyboard; }
	void RegisterMouseFunction(MouseFunc mouse) { fnMouse = mouse; }
	void RegisterMouseMotionFunction(MouseMotionFunc mousemotion) { fnMouseMotion = mousemotion; }
	void RegisterMousePassiveMotionFunction(MousePassiveMotionFunc mousepassivemotion) { fnMousePassiveMotion = mousepassivemotion; }

	using DrawFunc = void(*)();
	using ReshapeFunc = void(*)(int, int);
	using TimerFunc = void(*)(int);

	void RegisterDrawFunction(DrawFunc draw) { fnDraw = draw; }
	void RegisterReshapeFunction(ReshapeFunc reshape) { fnReshape = reshape; }
	void RegisterTimerFunction(TimerFunc timer) { fnTimer = timer; }

	void CameraReset()
	{
		CameraX = 0;
		CameraY = 0;
		CameraZ = 0;
		CameraMoveSpeed = 10;

		CameraRotateDegreeX = 0;
		CameraRotateDegreeY = 0;
		CameraRotateDegreeZ = 0;
		IsCameraRotateX = false;
		IsCameraRotateY = false;
		IsCameraRotateZ = false;
		CameraRotateSpeed = 1;
		CameraRotateDirection = CameraRotateSpeed;
	}

	void Bind()
	{
		glutDisplayFunc(fnDraw);	// 출력 함수의 지정
		glutReshapeFunc(fnReshape);
		glutTimerFunc(m_fps, fnTimer, 1);
		glutKeyboardFunc(fnKeyboard);
		glutSpecialFunc(fnSpecialKeyboard);
		glutMouseFunc(fnMouse);
		glutMotionFunc(fnMouseMotion);
	}

	void ChangeScene(CScene* newScene);

private:
	DrawFunc	fnDraw{ nullptr };
	ReshapeFunc fnReshape{ nullptr };
	TimerFunc	fnTimer{ nullptr };

	KeyboardFunc				fnKeyboard{ nullptr };
	SpecialKeyboardFunc			fnSpecialKeyboard{ nullptr };
	MouseFunc					fnMouse{ nullptr };
	MouseMotionFunc				fnMouseMotion{ nullptr };
	MousePassiveMotionFunc		fnMousePassiveMotion{ nullptr };

	int			m_fps = 16;

	float CameraX = 0;
	float CameraY = 0;
	float CameraZ = 0;
	float CameraMoveSpeed = 10;

	int CameraRotateDegreeX = 0;
	int CameraRotateDegreeY = 0;
	int CameraRotateDegreeZ = 0;
	bool IsCameraRotateX = false;
	bool IsCameraRotateY = false;
	bool IsCameraRotateZ = false;
	int CameraRotateSpeed = 1;
	int CameraRotateDirection = CameraRotateSpeed;

	CScene*		m_CurrScene{ nullptr };
};