#include "pch.h"
#include "GLFramework.h"


// 전체 씬 관리는 프레임 워크에서

// 씬과 씬 사이에는 명령어 겹쳐도됨
// 프레임워크와 씬은 명령어 겹치면 안됨

using namespace std;

namespace
{
	CGLFramework framework;
}

void main(int argc, char *argv[])
{
	framework.Initialize(argc, argv, WindowWidth, WindowHeight, 100, 100, "Framework", GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	framework.RegisterKeyboardFunction([](unsigned char key, int x, int y) {framework.Keyboard(key, x, y); });
	framework.RegisterSpecialKeyboardFunction([](int key, int x, int y) {framework.SpecialKeyboard(key, x, y); });
	framework.RegisterMouseFunction([](int button, int state, int x, int y) {framework.Mouse(button, state, x, y); });
	framework.RegisterMouseMotionFunction([](int x, int y) {framework.MouseMotion(x, y); });
	framework.RegisterMousePassiveMotionFunction([](int x, int y) {framework.MousePassiveMotion(x, y); });

	framework.RegisterDrawFunction([]() {framework.DrawScene(); });
	framework.RegisterReshapeFunction([](int w, int h) {framework.Reshape(w, h); });
	framework.RegisterTimerFunction([](int val) {framework.Timer(val); });

	framework.Bind();
	framework.Run();
}