#pragma once
#include "Shape.h"

class Line : public shape
{
private:
	Point Corner1;
	Point Corner2;
    int pw;
public:
	Line(Point, Point, GfxInfo shapeGfxInfo, int Pinwidth);
	virtual ~Line();
	virtual void Draw(GUI* pUI) const;
    virtual bool IsPointInside(int x, int y) const override;
    virtual void Rotate() override;
    virtual void Resize(double ratio) override;
    virtual shape* Duplicate() const override;
    virtual void Move(int newX, int newY) override;
};
