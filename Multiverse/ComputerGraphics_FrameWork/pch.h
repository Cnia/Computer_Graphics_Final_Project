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

#define TextFileWordNum 26

struct RGB {
	GLdouble r, g, b;
};

struct WordData {
	GLint word[9][9];
	GLint width;
	GLint widthGap;
};

void TextPrint(char Text[], GLdouble WordSize, RGB TextColor);