#pragma once
#include "Shape.h"

class SQ : public shape
{
private:
    Point point1;
    Point point2;
    int pw;
public:
    SQ(Point, Point, GfxInfo shapeGfxInfo, int Pinwidth);
    virtual ~SQ();
    virtual void Draw(GUI* pUI) const;
    virtual bool IsPointInside(int x, int y) const override;
    virtual void Rotate() override;
    virtual void Resize(double ratio) override;
    virtual shape* Duplicate() const override;
    virtual void Move(int newX, int newY) override;
};