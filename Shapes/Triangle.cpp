#include "Triangle.h"

Triangle::Triangle(Point v1, Point v2, Point v3, GfxInfo shapeGfxInfo, int Pinwidth) : shape(shapeGfxInfo)
{
    Corner1 = v1;
    Corner2 = v2;
    Corner3 = v3;
    pw = Pinwidth;
}

Triangle::~Triangle()
{}

void Triangle::Draw(GUI* pUI) const
{
    // Call Output::DrawTriangle to draw a triangle on the screen
    pUI->DrawTriangle(Corner1, Corner2, Corner3, ShpGfxInfo, pw);
}

bool Triangle::IsPointInside(int x, int y) const
{
    // Use the barycentric coordinate method to determine if the point is inside the triangle
    double denominator = (Corner2.y - Corner3.y) * (Corner1.x - Corner3.x) + (Corner3.x - Corner2.x) * (Corner1.y - Corner3.y);
    double a = ((Corner2.y - Corner3.y) * (x - Corner3.x) + (Corner3.x - Corner2.x) * (y - Corner3.y)) / denominator;
    double b = ((Corner3.y - Corner1.y) * (x - Corner3.x) + (Corner1.x - Corner3.x) * (y - Corner3.y)) / denominator;
    double c = 1.0 - a - b;

    return (a >= 0) && (b >= 0) && (c >= 0); // If all are positive, the point is inside the triangle
}

void Triangle::Rotate()
{   
    //center of the triangle
    Point Center;
    Center.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
    Center.y = (Corner1.y + Corner2.y + Corner3.y) / 3;

    //Function that rotate the points arroun center
     auto RotatePoint = [&Center](Point& corner)
     {
        int dx = corner.x - Center.x;
        int dy = corner.y - Center.y;

        int newX = Center.x - dy;
        int newY = Center.y + dx;

        corner.x = newX;
        corner.y = newY;
      };

    RotatePoint(Corner1);
    RotatePoint(Corner2);
    RotatePoint(Corner3);
}

void Triangle::Resize(double ratio)
{
    // Center of the Triangle
    int centerX = (Corner1.x + Corner2.x + Corner3.x) / 3;
    int centerY = (Corner1.y + Corner2.y + Corner3.y) / 3;

    // Resize the Triangle
    Corner1.x = centerX + (Corner1.x - centerX) * ratio;
    Corner1.y = centerY + (Corner1.y - centerY) * ratio;
    Corner2.x = centerX + (Corner2.x - centerX) * ratio;
    Corner2.y = centerY + (Corner2.y - centerY) * ratio;
    Corner3.x = centerX + (Corner3.x - centerX) * ratio;
    Corner3.y = centerY + (Corner3.y - centerY) * ratio;
}

shape* Triangle::Duplicate() const
{
    return new Triangle(*this);
}

void Triangle::Move(int newX, int newY)
{
    // Calculate the current centroid of the triangle
    int currentCenterX = (Corner1.x + Corner2.x + Corner3.x) / 3;
    int currentCenterY = (Corner1.y + Corner2.y + Corner3.y) / 3;

    // Calculate the displacement (difference between the new and current centroid)
    int dx = newX - currentCenterX;
    int dy = newY - currentCenterY;

    // Move each corner by the displacement amount
    Corner1.x += dx;
    Corner1.y += dy;
    Corner2.x += dx;
    Corner2.y += dy;
    Corner3.x += dx;
    Corner3.y += dy;
}
