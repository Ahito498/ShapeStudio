#include "Hexagon.h"
#include "..\GUI\GUI.h"
#include "math.h"
#define pi 3.141592653589793238462643383279502884197

polygon::polygon(Point Center, int Radius,int numVertices, GfxInfo shapeGfxInfo, int Pinwidth) : shape(shapeGfxInfo)
{
    center = Center;
    radius = Radius;
    this->pw = Pinwidth;
    this->numVertices = numVertices;

    vertices = new Point[numVertices];

    // Calculate the vertices of the hexagon
    for (int i = 0; i < numVertices; ++i)
    {
        vertices[i].x = center.x + radius * cos(i * 2 * pi / numVertices);
        vertices[i].y = center.y + radius * sin(i * 2 * pi / numVertices);
    }
}

polygon::~polygon()
{
    delete[] vertices;
}

void polygon::Draw(GUI* pUI) const
{
    // Call GUI::DrawHexagon to draw a hexagon on the screen
    pUI->DrawPolygon(vertices, numVertices, ShpGfxInfo, pw);
}

bool polygon::IsPointInside(int x, int y) const
{
    // Check if the point is within the bounding circle
    int dx = x - center.x;
    int dy = y - center.y;
    if (dx * dx + dy * dy > radius * radius) {
        return false;
    }
    // Further check using point-in-polygon (ray-casting) if necessary
    // Implement additional logic if needed for more precise boundary checks
    return true; // Simplified to circle bound for performance
}


void polygon::Rotate()
{
    // Rotate the polygon by 90 degrees around its center
    for (int i = 0; i < numVertices; ++i)
    {
        int dx = vertices[i].x - center.x;
        int dy = vertices[i].y - center.y;

        // Apply rotation transformation
        int new_x = center.x - dy;
        int new_y = center.y + dx;

        vertices[i].x = new_x;
        vertices[i].y = new_y;
    }
}

void polygon::Resize(double ratio)
{
    //calculating center of the polygon
    int centerX = 0, centerY = 0;
    for (int i = 0; i < numVertices; ++i)
    {
        centerX += vertices[i].x;
        centerY += vertices[i].y;
    }
    centerX /= numVertices;
    centerY /= numVertices;

    //Resizte the polygon based on the given ratio
    for (int i = 0; i < numVertices; ++i)
    {
        vertices[i].x = centerX + (vertices[i].x - centerX) * ratio;
        vertices[i].y = centerY + (vertices[i].y - centerY) * ratio;
    }
}

shape* polygon::Duplicate() const
{
    polygon* newPolygon = new polygon(*this); // Create a new polygon using the copy constructor

    // Deep copy the vertices array
    newPolygon->vertices = new Point[numVertices];
    for (int i = 0; i < numVertices; ++i)
    {
        newPolygon->vertices[i] = this->vertices[i];
    }

    return newPolygon;
}

void polygon::Move(int newX, int newY)
{
    // Calculate the displacement
    int dx = newX - center.x;
    int dy = newY - center.y;

    // Move each vertex by the displacement amount
    for (int i = 0; i < numVertices; ++i)
    {
        vertices[i].x += dx;
        vertices[i].y += dy;
    }

    // Update the center to the new position
    center.x = newX;
    center.y = newY;
}
