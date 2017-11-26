#include "pch.h"
#include "GLFramework.h"


// ��ü �� ������ ������ ��ũ����

// ���� �� ���̿��� ��ɾ� ���ĵ���
// �����ӿ�ũ�� ���� ��ɾ� ��ġ�� �ȵ�

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