#include "Rect.h"

Rect::Rect(Point P1, Point P2, GfxInfo shapeGfxInfo, int Pinwidth):shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
    pw = Pinwidth;
}

Rect::~Rect()
{}

void Rect::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawRect(Corner1, Corner2, ShpGfxInfo, pw);
}
bool Rect::IsPointInside(int x, int y) const
{
    // Check if (x, y) is inside the rectangle defined by Corner1 and Corner2
    return (x >= Corner1.x && x <= Corner2.x && y >= Corner1.y && y <= Corner2.y);
}

void Rect::Rotate()
{
    // Calculate the center of the rectangle
    Point center;
    center.x = (Corner1.x + Corner2.x) / 2;
    center.y = (Corner1.y + Corner2.y) / 2;

    // Calculate the original corner points relative to the center
    Point Corners[4];

    Corners[0] = { Corner1.x, Corner1.y }; // Top-left corner
    Corners[1] = { Corner1.x, Corner2.y }; // Bottom-left corner
    Corners[2] = { Corner2.x, Corner2.y }; // Bottom-right corner
    Corners[3] = { Corner2.x, Corner1.y }; // Top-right corner

    // Rotate each corner 90 degrees around the center
    for (int i = 0; i < 4; ++i)
    {
        int dx = Corners[i].x - center.x;
        int dy = Corners[i].y - center.y;

        Corners[i].x = center.x - dy;
        Corners[i].y = center.y + dx;
    }

    // Reassign the rotated corners to the rectangle
    Corner1 = Corners[0];
    Corner2 = Corners[2]; // Diagonally opposite corner
}

void Rect::Resize(double ratio)
{
    //Center of the rectangle
    int centerX = (Corner1.x + Corner2.x) / 2;
    int centerY = (Corner1.y + Corner2.y) / 2;

    // Rsize the ractangle based on the given  ratio
    Corner1.x = centerX + (Corner1.x - centerX) * ratio;
    Corner1.y = centerY + (Corner1.y - centerY) * ratio;
    Corner2.x = centerX + (Corner2.x - centerX) * ratio;
    Corner2.y = centerY + (Corner2.y - centerY) * ratio;
}

shape* Rect::Duplicate() const
{
    return new Rect(*this);
}

void Rect::Move(int newX, int newY)
{
    // Calculate the current center of the rectangle
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
