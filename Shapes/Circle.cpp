#include "Circle.h"
#include <fstream>


Circle::Circle(Point c, int r, GfxInfo shapeGfxInfo, int Pinwidth) : shape(shapeGfxInfo)
{
    center = c;
    radius = r;
    pw = Pinwidth;
}

Circle::~Circle()
{}

void Circle::Draw(GUI* pUI) const
{
   
    pUI->DrawCircle(center, radius, ShpGfxInfo, pw);
}

bool Circle::IsPointInside(int x, int y) const
{
   
    int dx = x - center.x;
    int dy = y - center.y;
    return (dx * dx + dy * dy) <= (radius * radius);
}

void Circle::Rotate()
{}

void Circle::Resize(double ratio)
{
    radius = radius * ratio;
}

shape* Circle::Duplicate() const
{
    return new Circle(*this);
}

void Circle::Move(int newX, int newY)
{
    center.x = newX;
    center.y = newY;

}


//void Circle::Save(std::ofstream& outFile) {
//    outFile << "Circle " << center.x << " " << center.y << " " << radius << " ";
//    outFile << "RGB( " << static_cast<int>(ShpGfxInfo.DrawClr.ucRed) << " "
//        << static_cast<int>(ShpGfxInfo.DrawClr.ucGreen) << " "
//        << static_cast<int>(ShpGfxInfo.DrawClr.ucBlue) << " ) ";
//
//    if (ShpGfxInfo.isFilled) {
//        outFile << "RGB( " << static_cast<int>(ShpGfxInfo.FillClr.ucRed) << " "
//            << static_cast<int>(ShpGfxInfo.FillClr.ucGreen) << " "
//            << static_cast<int>(ShpGfxInfo.FillClr.ucBlue) << " ) ";
//    }
//    else {
//        outFile << "No_fill ";
//    }
//
//    outFile << ShpGfxInfo.BorderWdth << std::endl;
//
//
//
//
//
//
//void Circle::Load(string line) {
//    istringstream iss(line);
//    int radius, drawR, drawG, drawB, fillR, fillG, fillB, borderWdth;
//    string dummyS;
//
//    iss >> center.x >> center.y >> radius;
//    this->radius = radius;
//
//    iss >> dummyS >> drawR >> drawG >> drawB;
//    ShpGfxInfo.DrawClr = color(drawR, drawG, drawB);
//
//    
//    iss >> dummyS;
//    if (dummyS == "No_fill") {
//        ShpGfxInfo.isFilled = false;
//        ShpGfxInfo.FillClr = YELLOW;  
//    }
//    else {
//        ShpGfxInfo.isFilled = true;
//        iss >> fillR >> fillG >> fillB; 
//        ShpGfxInfo.FillClr = color(fillR, fillG, fillB);
//    }
//
//   
//    iss >> borderWdth;
//    ShpGfxInfo.BorderWdth = pw;
//    ShpGfxInfo.isSelected = false;
//}
