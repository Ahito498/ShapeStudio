#include "Line.h"

Line::Line(Point P1, Point P2, GfxInfo shapeGfxInfo,int Pinwidth) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
    pw = Pinwidth;
}

Line::~Line()
{}

void Line::Draw(GUI* pUI) const
{

	pUI->DrawLine(Corner1, Corner2, ShpGfxInfo,pw);
}

bool Line::IsPointInside(int x, int y) const
{
    // Calculate the distance from the point to the line using point-line distance formula
    double lengthSquared = (Corner2.x - Corner1.x) * (Corner2.x - Corner1.x) + (Corner2.y - Corner1.y) * (Corner2.y - Corner1.y);
    if (lengthSquared == 0) return false; // Corner1 and Corner2 are the same point
    double t = ((x - Corner1.x) * (Corner2.x - Corner1.x) + (y - Corner1.y) * (Corner2.y - Corner1.y)) / lengthSquared;
    if (t < 0.0 || t > 1.0) return false; // Not within the line segment bounds

    // Projection falls on the segment, check the distance to the line
    double projectionX = Corner1.x + t * (Corner2.x - Corner1.x);
    double projectionY = Corner1.y + t * (Corner2.y - Corner1.y);
    double distanceSquared = (x - projectionX) * (x - projectionX) + (y - projectionY) * (y - projectionY);
    return distanceSquared < (pw * pw); // Check if within tolerance of line width
}

void Line::Rotate()
{
    //The midpoint of the Line
    Point center;
    center.x = (Corner1.x + Corner2.x) / 2;
    center.y = (Corner1.y + Corner2.y) / 2;

    //Rotate Corner1 point

    int dx = Corner1.x - center.x;
    int dy = Corner1.y - center.y;

    Corner1.x = center.x - dy;
    Corner1.y = center.y + dx;

    //Rotate Corner2 point

    dx = Corner2.x - center.x;
    dy = Corner2.y - center.y;
    Corner2.x = center.x - dy;
    Corner2.y = center.y + dx;

}

void Line::Resize(double ratio)
{
    // Calculating center of the line
    int centerX = (Corner1.x + Corner2.x) / 2;
    int centerY = (Corner1.y + Corner2.y) / 2;

    // Resize the line based on given ratio
    Corner1.x = centerX + (Corner1.x - centerX) * ratio;
    Corner1.y = centerY + (Corner1.y - centerY) * ratio;
    Corner2.x = centerX + (Corner2.x - centerX) * ratio;
    Corner2.y = centerY + (Corner2.y - centerY) * ratio;
}

shape* Line::Duplicate() const
{
    return new Line(*this);
}

void Line::Move(int newX, int newY)
{
    //calculating the length of half the line then add it's length to place of the first corner to move to desired place then  subtract it from thew clicked place to get the new corner 1
    int dx = newX - (Corner1.x + (Corner2.x - Corner1.x) / 2);
    int dy = newY - (Corner1.y + (Corner2.y - Corner1.y) / 2);

    // Apply the displacement to both corners of the line
    Corner1.x += dx;
    Corner1.y += dy;
    Corner2.x += dx;
    Corner2.y += dy;
}
