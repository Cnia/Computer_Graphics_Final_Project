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

#define WindowWidth 800
#define WindowHeight 600

#define Radian 0.017453292519943

#define TextFileWordNum 3

struct RGB {
	GLdouble r, g, b;
};

struct WordData {
	char word[9][9];
	GLint width;
	GLint widthGap;
};

void TextPrint(char Text[], GLdouble WordSize, RGB TextColor)
{
	WordData WordDataArray[TextFileWordNum];
	std::ifstream inFile("File_Data/Word.txt");
	for (int i = 0; i < TextFileWordNum; ++i)
	{
		for (int j = 0; j < 9; ++j)
			inFile.getline(WordDataArray[i].word[j], sizeof(WordDataArray[i].word[j]));
		inFile >> WordDataArray[i].width;
		WordDataArray[i].widthGap = (9 - WordDataArray[i].width) / 2;
	}
	inFile.close();

	GLdouble PixelSize = WordSize / 9;
	int TextLength = strlen(Text);
	GLdouble FirstWordWidthGap;
	if ('A' <= Text[0] && Text[0] <= 'Z')
		FirstWordWidthGap = WordDataArray[Text[0] - 'A'].widthGap;

	GLdouble TextWidth = 0;
	for (int i = 0; i < TextLength; ++i)
	{
		if ('A' <= Text[i] && Text[i] <= 'Z')
			TextWidth += WordDataArray[Text[i] - 'A'].width;
	}
	TextWidth += TextLength - 1;
	TextWidth *= PixelSize;

	glPushMatrix(); {
		glColor3d(TextColor.r, TextColor.g, TextColor.b);
		glTranslated(-(TextWidth / 2) + PixelSize - (FirstWordWidthGap * PixelSize * 2), WordSize / 2 - PixelSize, 0);

		for (int k = 0; k < TextLength; ++k)
		{
			for (int i = 0; i < 9; ++i)
			{
				glPushMatrix(); {
					glTranslated(0, PixelSize * 2 * i, 0);
					for (int j = 0; j < 9; ++j)
					{
						glPushMatrix(); {
							glTranslated(PixelSize * 2 * j, 0, 0);
							if (WordDataArray[k].word[i][j] == 1)
								glutSolidCube(PixelSize);
						}glPopMatrix();
					}
				}glPopMatrix();
			}
			if (k != TextLength - 1)
				glTranslated((WordDataArray[k].width - WordDataArray[k + 1].widthGap + 1) * PixelSize * 2, 0, 0);
		}
	}glPopMatrix();
}