#include "shape.h"

class Circle : public shape
{
private:
    Point center; // Center of the circle
    int radius;   // Radius of the circle
    int pw;
public:
    Circle(Point c, int r, GfxInfo shapeGfxInfo, int Pinwidth);
    virtual ~Circle();
    virtual void Draw(GUI* pUI) const;
    virtual bool IsPointInside(int x, int y) const override;
    void Rotate();
    void Resize(double ratio);
    virtual shape* Duplicate() const override;
    void Load(string line);  
    void Save(std::ofstream& outFile);
    virtual void Move(int newX, int newY) override;
};


