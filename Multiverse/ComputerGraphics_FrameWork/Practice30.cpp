#include "pch.h"
#include "Practice30.h"


CPractice30::CPractice30()
{
}


CPractice30::~CPractice30()
{
}

void CPractice30::initialize()
{
	for (int i = 0; i < SNOW_NUM; ++i)
	{
		snow[i].x = (GLfloat)(rand() % 1200 - 600);
		snow[i].z = (GLfloat)(rand() % 1200 - 600);
		snow[i].y = (GLfloat)(rand() % 700);
		snow[i].speed = (GLfloat)(rand() % 4 + 2);
	}
}

void CPractice30::Render()
{
	// 조명
	if (NomalizeOn)
		glEnable(GL_NORMALIZE);
	else
		glDisable(GL_NORMALIZE);
	glShadeModel(GL_FLAT);
	glFrontFace(GL_CCW);
	glEnable(GL_LIGHTING);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
	glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, 0.0);
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, 0.0);

	glPushMatrix(); {
		glTranslated(0, 200, 0);
		glPushMatrix(); {
			glColor3d(1, 0, 0);
			glRotated(45, 0, 1, 0);
			glTranslated(0, 0, 700);
			glutSolidCone(10, 30, 20, 20);
			glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
			glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
			glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
			glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
		}glPopMatrix();
		glPushMatrix(); {
			glColor3d(0, 1, 0);
			glRotated(135, 0, 1, 0);
			glTranslated(0, 0, 700);
			glutSolidCone(10, 30, 20, 20);
			glLightfv(GL_LIGHT1, GL_AMBIENT, ambientLight);
			glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseLight);
			glLightfv(GL_LIGHT1, GL_SPECULAR, specular);
			glLightfv(GL_LIGHT1, GL_POSITION, lightPos);
		}glPopMatrix();
		glPushMatrix(); {
			glColor3d(0, 0, 1);
			glRotated(225, 0, 1, 0);
			glTranslated(0, 0, 700);
			glutSolidCone(10, 30, 20, 20);
			glLightfv(GL_LIGHT2, GL_AMBIENT, ambientLight);
			glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuseLight);
			glLightfv(GL_LIGHT2, GL_SPECULAR, specular);
			glLightfv(GL_LIGHT2, GL_POSITION, lightPos);
		}glPopMatrix();
		glPushMatrix(); {
			glColor3d(1, 0, 1);
			glRotated(315, 0, 1, 0);
			glTranslated(0, 0, 700);
			glutSolidCone(10, 30, 20, 20);
			glLightfv(GL_LIGHT3, GL_AMBIENT, ambientLight);
			glLightfv(GL_LIGHT3, GL_DIFFUSE, diffuseLight);
			glLightfv(GL_LIGHT3, GL_SPECULAR, specular);
			glLightfv(GL_LIGHT3, GL_POSITION, lightPos);
		}glPopMatrix();
	}glPopMatrix();
	if (light0on)
		glEnable(GL_LIGHT0);
	else
		glDisable(GL_LIGHT0);
	if (light1on)
		glEnable(GL_LIGHT1);
	else
		glDisable(GL_LIGHT1);
	if (light2on)
		glEnable(GL_LIGHT2);
	else
		glDisable(GL_LIGHT2);
	if (light3on)
		glEnable(GL_LIGHT3);
	else
		glDisable(GL_LIGHT3);

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientLight);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseLight);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
	glMateriali(GL_FRONT, GL_SHININESS, 64);

	// 피라미드
	glPushMatrix(); {
		glTranslated(0, -200, 0);
		glColor3d(0.6, 0.6, 0.6);
		glBegin(GL_POLYGON); {
			glVertex3d(600, 0, -600);
			glVertex3d(-600, 0, -600);
			glVertex3d(-600, 0, 600);
			glVertex3d(600, 0, 600);
		}glEnd();
		glPushMatrix(); {
			glTranslated(300, 0, 0);
			glColor3f(0, 1, 0);
			glBegin(GL_POLYGON); {
				glVertex3d(100, 0, -100);
				glVertex3d(-100, 0, -100);
				glVertex3d(-100, 0, 100);
				glVertex3d(100, 0, 100);
			}glEnd();
			glPushMatrix(); {
				glRotated(90, 0, 1, 0);
				glTranslated(0, 0, 100);
				glRotated(-30, 1, 0, 0);
				glBegin(GL_POLYGON); {
					if (NomalizeOn)
						glNormal3f(0, 0, 1);
					glVertex3d(0, 200, 0);
					glVertex3d(-100, 0, 0);
					glVertex3d(100, 0, 0);
				}glEnd();
			}glPopMatrix();
			glPushMatrix(); {
				glRotated(180, 0, 1, 0);
				glTranslated(0, 0, 100);
				glRotated(-30, 1, 0, 0);
				glBegin(GL_POLYGON); {
					if (NomalizeOn)
						glNormal3f(0, 0, 1);
					glVertex3d(0, 200, 0);
					glVertex3d(-100, 0, 0);
					glVertex3d(100, 0, 0);
				}glEnd();
			}glPopMatrix();
			glPushMatrix(); {
				glRotated(270, 0, 1, 0);
				glTranslated(0, 0, 100);
				glRotated(-30, 1, 0, 0);
				glBegin(GL_POLYGON); {
					if (NomalizeOn)
						glNormal3f(0, 0, 1);
					glVertex3d(0, 200, 0);
					glVertex3d(-100, 0, 0);
					glVertex3d(100, 0, 0);
				}glEnd();
			}glPopMatrix();
			glPushMatrix(); {
				glRotated(0, 0, 1, 0);
				glTranslated(0, 0, 100);
				glRotated(-30, 1, 0, 0);
				glBegin(GL_POLYGON); {
					if (NomalizeOn)
						glNormal3f(0, 0, 1);
					glVertex3d(0, 200, 0);
					glVertex3d(-100, 0, 0);
					glVertex3d(100, 0, 0);
				}glEnd();
			}glPopMatrix();
			glTranslated(0, 170, 0);
			glPushMatrix(); {
				glTranslated(PyramidBigX, 0, PyramidBigZ);
				glutSolidSphere(50, 20, 20);
				glPushMatrix(); {
					glTranslated(PyramidSmallX, 0, PyramidSmallZ);
					glutSolidSphere(20, 20, 20);
				}glPopMatrix();
			}glPopMatrix();
		}glPopMatrix();
		glPushMatrix(); {
			glTranslated(-300, 0, 0);
			glColor3f(0, 1, 0);
			glBegin(GL_POLYGON); {
				glVertex3d(100, 0, -100);
				glVertex3d(-100, 0, -100);
				glVertex3d(-100, 0, 100);
				glVertex3d(100, 0, 100);
			}glEnd();
			glPushMatrix(); {
				glRotated(90, 0, 1, 0);
				glTranslated(0, 0, 100);
				glRotated(-30, 1, 0, 0);
				glBegin(GL_POLYGON); {
					if (NomalizeOn)
						glNormal3f(0, 0, 1);
					glVertex3d(0, 200, 0);
					glVertex3d(-100, 0, 0);
					glVertex3d(100, 0, 0);
				}glEnd();
			}glPopMatrix();
			glPushMatrix(); {
				glRotated(180, 0, 1, 0);
				glTranslated(0, 0, 100);
				glRotated(-30, 1, 0, 0);
				glBegin(GL_POLYGON); {
					if (NomalizeOn)
						glNormal3f(0, 0, 1);
					glVertex3d(0, 200, 0);
					glVertex3d(-100, 0, 0);
					glVertex3d(100, 0, 0);
				}glEnd();
			}glPopMatrix();
			glPushMatrix(); {
				glRotated(270, 0, 1, 0);
				glTranslated(0, 0, 100);
				glRotated(-30, 1, 0, 0);
				glBegin(GL_POLYGON); {
					if (NomalizeOn)
						glNormal3f(0, 0, 1);
					glVertex3d(0, 200, 0);
					glVertex3d(-100, 0, 0);
					glVertex3d(100, 0, 0);
				}glEnd();
			}glPopMatrix();
			glPushMatrix(); {
				glRotated(0, 0, 1, 0);
				glTranslated(0, 0, 100);
				glRotated(-30, 1, 0, 0);
				glBegin(GL_POLYGON); {
					if (NomalizeOn)
						glNormal3f(0, 0, 1);
					glVertex3d(0, 200, 0);
					glVertex3d(-100, 0, 0);
					glVertex3d(100, 0, 0);
				}glEnd();
			}glPopMatrix();
			glTranslated(0, 170, 0);
			glPushMatrix(); {
				glTranslated(PyramidBigX, 0, PyramidBigZ);
				glutSolidSphere(50, 20, 20);
				glPushMatrix(); {
					glTranslated(PyramidSmallX, 0, PyramidSmallZ);
					glutSolidSphere(20, 20, 20);
				}glPopMatrix();
			}glPopMatrix();
		}glPopMatrix();
	}glPopMatrix();

	glPushMatrix(); {
		glColor3f(1, 1, 1);
		for (int i = 0; i < SNOW_NUM; ++i)
		{
			glPushMatrix(); {
				glTranslated(snow[i].x, snow[i].y, snow[i].z);
				glutSolidSphere(10, 20, 20);
			}glPopMatrix();
		}
	}glPopMatrix();

}

void CPractice30::Reshape(int w, int h)
{
}

void CPractice30::Timer(int value)
{
	PyramidBigDegree += 2;
	if (PyramidBigDegree >= 360)
		PyramidBigDegree -= 360;
	PyramidBigX = sin(Radian * PyramidBigDegree) * BigRadius;
	PyramidBigZ = cos(Radian * PyramidBigDegree) * BigRadius;

	PyramidSmallDegree -= 3;
	if (PyramidSmallDegree <= 0)
		PyramidSmallDegree += 360;
	PyramidSmallX = sin(Radian * PyramidSmallDegree) * SmallRadius;
	PyramidSmallZ = cos(Radian * PyramidSmallDegree) * SmallRadius;

	// 눈
	for (int i = 0; i < SNOW_NUM; ++i)
	{
		snow[i].y -= snow[i].speed;
		if (snow[i].y < -200)
			snow[i].y = 700;
	}
}

void CPractice30::Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case '1':
		light0on = !light0on;
		break;
	case '2':
		light1on = !light1on;
		break;
	case '3':
		light2on = !light2on;
		break;
	case '4':
		light3on = !light3on;
		break;
	case '5':
		AllLighton = !AllLighton;
		light0on = AllLighton;
		light1on = AllLighton;
		light2on = AllLighton;
		light3on = AllLighton;
		break;
	case '6':
		NomalizeOn = !NomalizeOn;
		break;
	}
}

void CPractice30::SpecialKeyboard(int key, int x, int y)
{
}

void CPractice30::Mouse(int button, int state, int x, int y)
{
}
