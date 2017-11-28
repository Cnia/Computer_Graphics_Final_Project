#pragma once

#define TextFileWordNum 67

class TextFunction
{
private:
	WordData WordDataArray[TextFileWordNum];

	RGB TextColorList[10];
	RGB TextColor[100];
public:
	TextFunction();
	virtual ~TextFunction();

	virtual void TextPrint(char Text[], GLdouble WordSize, bool ColorChange, bool Cube);
	virtual void TextColorListSet(int num, GLdouble R, GLdouble G, GLdouble B);
	virtual void TextColorSet(char color[]);
	virtual RGB GetTextList(int num) { return TextColorList[num]; }
	virtual RGB ColorChange(RGB* ColorList, int prevNum, int nextNum, GLdouble per) {
		RGB rgb;
		rgb.r = (ColorList + prevNum)->r * (1.0 - per) + (ColorList + nextNum)->r * per;
		rgb.g = (ColorList + prevNum)->g * (1.0 - per) + (ColorList + nextNum)->g * per;
		rgb.b = (ColorList + prevNum)->b * (1.0 - per) + (ColorList + nextNum)->b * per;
		return rgb;
	}
};

