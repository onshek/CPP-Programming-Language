#ifndef _RECTANGLE_H
#define _RECTANGLE_H
#include "Point.h"

class Rectancle : public Point {
public:
	void initRectangle(float x, float y, float w, float h) {
		initPoint(x, y);
		this->w = w;
		this->h = h;
	}
	float getW() const { return w; }
	float getH() const { return h; }
private:
	float w, h;
};
#endif