#pragma once

#include "Shape.h"

class polygon : public shape
{
private:
    Point center;   //Center of the Polygon
    int numVertices;        //Number of vertices
    int radius;     //Distance from center to any vertex
    int pw;     //width of the pen
    Point* vertices;  //Array of vertices for the polygon

public:
    polygon(Point Center, int Radius,int numVetices, GfxInfo shapeGfxInfo, int Pinwidth);
    virtual ~polygon();
    virtual void Draw(GUI* pUI) const override;
    virtual bool IsPointInside(int x, int y) const override;
    virtual void Rotate() override;
    virtual void Resize(double ratio) override;
    virtual shape* Duplicate() const override;
    virtual void Move(int newX, int newY) override;
};
