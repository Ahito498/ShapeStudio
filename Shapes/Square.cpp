#include "Square.h"
SQ::SQ(Point P1, Point P2, GfxInfo shapeGfxInfo, int Pinwidth) : shape(shapeGfxInfo)
{
    point1 = P1;
    point2 = P2;
    pw = Pinwidth;

}

SQ::~SQ() {}

void SQ::Draw(GUI* pUI) const
{
    //Call Output::DrawRect to draw a Square on the screen	
    pUI->DrawSQ(point1, point2, ShpGfxInfo, pw);
}

bool SQ::IsPointInside(int x, int y) const
{
   
    
    int sideLength = abs(point2.x - point1.x);

    // Calculate min and max for both x and y
    int minX = point1.x;
    int maxX = point1.x + sideLength;
    int minY = point1.y;
    int maxY = point1.y + sideLength;

    return (x >= minX && x <= maxX && y >= minY && y <= maxY);
}

void SQ::Rotate()
{}

void SQ::Resize(double ratio)
{
    // center of the shape
    int centerX = (point1.x + point2.x) / 2;
    int centerY = (point1.y + point2.y) / 2;

    // Resize the shape based on the given ratio
    point1.x = centerX + (point1.x - centerX) * ratio;
    point1.y = centerY + (point1.y - centerY) * ratio;
    point2.x = centerX + (point2.x - centerX) * ratio;
    point2.y = centerY + (point2.y - centerY) * ratio;
}

shape* SQ::Duplicate() const
{
    return new SQ(*this);
}

void SQ::Move(int newX, int newY)
{
    int sideLength = abs(point2.x - point1.x);
    int y2 = point1.y + sideLength;
    // Calculate the current center of the square
    Point currentCenter;
    currentCenter.x = (point1.x + point2.x) / 2;
    currentCenter.y = (point1.y + y2) / 2;

    // Calculate the displacement vector
    int dx = newX - currentCenter.x;
    int dy = newY - currentCenter.y;

    // Move both corners by the displacement
    point1.x += dx;
    point1.y += dy;
    point2.x += dx;
    point2.y += dy;
}

