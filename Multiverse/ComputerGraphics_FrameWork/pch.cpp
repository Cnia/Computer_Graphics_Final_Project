#include "pch.h"

void TextPrint(char Text[], GLdouble WordSize, RGB TextColor)
{
	WordData WordDataArray[TextFileWordNum];
	// 파일읽어오기
	FILE* fin = fopen("File_Data/Word.txt", "r");
	for (int i = 0; i < TextFileWordNum; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			for (int k = 0; k < 9; ++k)
				fscanf(fin, "%1d", &WordDataArray[i].word[j][k]);
		}
		fscanf(fin, "%d", &WordDataArray[i].width);
		WordDataArray[i].widthGap = (9 - WordDataArray[i].width) / 2;
	}
	fclose(fin);

	GLdouble PixelSize = WordSize / 9;
	int TextLength = strlen(Text);

	GLdouble TextWidth = 0;
	GLint index[1000];
	for (int i = 0; i < TextLength; ++i)
	{
		if ('A' <= Text[i] && Text[i] <= 'Z')
		{
			index[i] = Text[i] - 'A';
			TextWidth += WordDataArray[index[i]].width;
		}
	}
	TextWidth += TextLength - 1;
	TextWidth *= PixelSize;

	GLdouble FirstWordWidthGap;
	FirstWordWidthGap = WordDataArray[index[0]].widthGap * PixelSize;

	glPushMatrix(); {
		glColor3d(TextColor.r, TextColor.g, TextColor.b);
		glTranslated(-(TextWidth / 2) + PixelSize - FirstWordWidthGap, WordSize / 2 - PixelSize, 0);

		for (int k = 0; k < TextLength; ++k)
		{
			for (int i = 0; i < 9; ++i)
			{
				glPushMatrix(); {
					glTranslated(0, PixelSize * -i, 0);
					for (int j = 0; j < 9; ++j)
					{
						glPushMatrix(); {
							glTranslated(PixelSize * j, 0, 0);
								if (WordDataArray[index[k]].word[i][j] == 1)
									glutSolidCube(PixelSize);
						}glPopMatrix();
					}
				}glPopMatrix();
			}
			if (k != TextLength - 1)
				glTranslated((WordDataArray[index[k]].width - WordDataArray[index[k + 1]].widthGap + 2) * PixelSize, 0, 0);
			
		}
	}glPopMatrix();
}
