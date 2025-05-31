#include "Oval.h"
#include "..\GUI\GUI.h"

Oval::Oval(Point P1, Point P2, GfxInfo shapeGfxInfo, int Pinwidth) : shape(shapeGfxInfo)
{
    Corner1 = P1;
    Corner2 = P2;
    pw = Pinwidth;
}

Oval::~Oval()
{}

void Oval::Draw(GUI* pUI) const
{
    // Call GUI::DrawOval to draw an oval on the screen	
    pUI->DrawOval(Corner1, Corner2, ShpGfxInfo, pw);
}

bool Oval::IsPointInside(int x, int y) const
{
    // Calculate the semi-major and semi-minor axes
    double a = std::abs(Corner2.x - Corner1.x) / 2.0;
    double b = std::abs(Corner2.y - Corner1.y) / 2.0;
    double centerX = (Corner1.x + Corner2.x) / 2.0;
    double centerY = (Corner1.y + Corner2.y) / 2.0;

    // Check if the point is inside the ellipse using the ellipse equation
    double dx = x - centerX;
    double dy = y - centerY;
    return ((dx * dx) / (a * a) + (dy * dy) / (b * b)) <= 1.0;
}

void Oval::Rotate()
{
    // Calculate the center of the oval
    Point center;
    center.x = (Corner1.x + Corner2.x) / 2;
    center.y = (Corner1.y + Corner2.y) / 2;

    // Rotate Corner1
    int dx = Corner1.x - center.x;
    int dy = Corner1.y - center.y;
    Corner1.x = center.x - dy;
    Corner1.y = center.y + dx;

    // Rotate Corner2
    dx = Corner2.x - center.x;
    dy = Corner2.y - center.y;
    Corner2.x = center.x - dy;
    Corner2.y = center.y + dx;

}

void Oval::Resize(double ratio)
{

    // Calculate the center of the oval
    Point center;
    center.x = (Corner1.x + Corner2.x) / 2;
    center.y = (Corner1.y + Corner2.y) / 2;


    // Resize the oval based on given ratio
    Corner1.x = center.x + (Corner1.x - center.x) * ratio;
    Corner1.y = center.y + (Corner1.y - center.y) * ratio;
    Corner2.x = center.x + (Corner2.x - center.x) * ratio;
    Corner2.y = center.y + (Corner2.y - center.y) * ratio;
}

shape* Oval::Duplicate() const
{
    return new Oval(*this);
}

void Oval::Move(int newX, int newY)
{
    // Calculate the current center of the oval
    Point currentCenter;
    currentCenter.x = (Corner1.x + Corner2.x) / 2;
    currentCenter.y = (Corner1.y + Corner2.y) / 2;

    // Calculate the displacement vector
    int dx = newX - currentCenter.x;
    int dy = newY - currentCenter.y;

    // Move both corners by the displacement
    Corner1.x += dx;
    Corner1.y += dy;
    Corner2.x += dx;
    Corner2.y += dy;
}
