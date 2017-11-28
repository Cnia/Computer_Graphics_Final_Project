#pragma once

// OpenGL
#include <gl/glut.h>

// C++
#include <iostream>
#include <algorithm>
#include <time.h>
#include <cmath>
#include <string>
#include <fstream>

#define WindowWidth 1024
#define WindowHeight 768

#define Radian 0.017453292519943

struct RGB {
	GLdouble r, g, b;
};

struct WordData {
	GLint word[12][9];
	GLdouble width;
};