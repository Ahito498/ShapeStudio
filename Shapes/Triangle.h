#pragma once
#include "shape.h"

class Triangle : public shape
{
private:
    Point Corner1; // First vertex of the triangle
    Point Corner2; // Sescond vertex of the triangle
    Point Corner3; // Third vertex of the triangle
    int pw; 
public:
    Triangle(Point v1, Point v2, Point v3, GfxInfo shapeGfxInfo, int Pinwidth);
    virtual ~Triangle();

    virtual void Draw(GUI* pUI) const;
    virtual bool IsPointInside(int x, int y) const override;
    virtual void Rotate() override;
    virtual void Resize(double ratio) override;
    virtual shape* Duplicate() const override;
    virtual void Move(int newX, int newY) override;
};


