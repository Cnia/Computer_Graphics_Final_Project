#include "pch.h"
#include "TextFunction.h"


TextFunction::TextFunction()
{
	// 파일읽어오기
	FILE* fin = fopen("File_Data/Word.txt", "r");
	for (int i = 0; i < TextFileWordNum; ++i)
	{
		for (int j = 0; j < 12; ++j)
		{
			for (int k = 0; k < 9; ++k)
				fscanf(fin, "%1d", &WordDataArray[i].word[j][k]);
		}
		fscanf(fin, "%lf", &WordDataArray[i].width);
	}
	fclose(fin);
}


TextFunction::~TextFunction()
{
}

void TextFunction::TextPrint(char Text[], GLdouble WordSize, bool ColorChange, bool Cube)
{
	GLdouble PixelSize = WordSize / 9;
	int TextLength = strlen(Text);

	GLdouble TextWidth = 0;
	GLint index[1000];
	for (int i = 0; i < TextLength; ++i)
	{
		if ('A' <= Text[i] && Text[i] <= 'Z')
			index[i] = Text[i] - 'A';
		else if ('a' <= Text[i] && Text[i] <= 'z')
			index[i] = 26 + Text[i] - 'a';
		else if ('0' <= Text[i] && Text[i] <= '9')
			index[i] = 52 + Text[i] - '0';
		else if (Text[i] == ' ')
			index[i] = 62;
		else if (Text[i] == ':')
			index[i] = 63;
		else if (Text[i] == '!')
			index[i] = 64;
		else if (Text[i] == '?')
			index[i] = 65;
		else if (Text[i] == '.')
			index[i] = 66;
		TextWidth += WordDataArray[index[i]].width;
	}
	TextWidth += TextLength - 1;
	TextWidth *= PixelSize;

	glPushMatrix(); {
		glColor3d(TextColor[0].r, TextColor[0].g, TextColor[0].b);
		glTranslated(-(TextWidth / 2) + PixelSize, WordSize / 2 - PixelSize, 0);

		glPushMatrix(); {
			for (int k = 0; k < TextLength; ++k)
			{
				if (ColorChange)
					glColor3d(TextColor[k].r, TextColor[k].g, TextColor[k].b);
				for (int i = 0; i < 12; ++i)
				{
					glPushMatrix(); {
						glTranslated(0, PixelSize * -i, 0);
						for (int j = 0; j < 9; ++j)
						{
							glPushMatrix(); {
								glTranslated(PixelSize * j, 0, 0);
								if (WordDataArray[index[k]].word[i][j] == 1)
								{
									if (Cube)
										glutSolidCube(PixelSize);
									else
									{
										GLdouble HalfPixelSize = PixelSize / 2;
										glBegin(GL_QUADS); {
											glVertex2d(HalfPixelSize, HalfPixelSize);
											glVertex2d(-HalfPixelSize, HalfPixelSize);
											glVertex2d(-HalfPixelSize, -HalfPixelSize);
											glVertex2d(HalfPixelSize, -HalfPixelSize);
										}glEnd();
									}
								}
							}glPopMatrix();
						}
					}glPopMatrix();
				}
				if (k != TextLength - 1)
					glTranslated((WordDataArray[index[k]].width + 1) * PixelSize, 0, 0);
			}
		}glPopMatrix();
	}glPopMatrix();
}

void TextFunction::TextColorListSet(int num, GLdouble R, GLdouble G, GLdouble B)
{
	TextColorList[num].r = R;
	TextColorList[num].g = G;
	TextColorList[num].b = B;
}

void TextFunction::TextColorSet(char color[])
{
	GLint length = strlen(color);
	for (int i = 0; i < length; ++i)
		TextColor[i] = TextColorList[color[i] - '0'];
}