#include "Graph.h"
#include "../GUI/GUI.h"

Graph::Graph()
{
	shapeCount = 0;
	selectedShape = nullptr;
}

Graph::~Graph()
{
}

//==================================================================================//
//						shapes Management Functions								//
//==================================================================================//


int Graph::getShapeCount() {
    return shapeCount;
}
//Add a shape to the list of shapes
void Graph::Addshape(shape* pShp)
{
	//Add a new shape to the shapes list
	if(shapeCount<maxShapeCount)
		shapesList[shapeCount++] = pShp;
}
////////////////////////////////////////////////////////////////////////////////////


//Draw all shapes on the user interface
void Graph::Draw(GUI* pUI) const
{
    pUI->ClearDrawArea();
    if (shapeCount > 0)
    {
        for (int i = 0;i < shapeCount; i++)
        {
            if (shapesList[i] != nullptr)
            {
                shapesList[i]->Draw(pUI);
            }
        }
    }
}
////////////////////////////////////////////////////


//shape* Graph::Getshape(int x, int y) const
//{
//	//If a shape is found return a pointer to it.
//	//if this point (x,y) does not belong to any shape return NULL
//
//
//	///Add your code here to search for a shape given a point x,y	
//
//	return nullptr;
//}

/////////////////////////////////////////////////////////AAA//////////////////////////

void Graph::Save(ofstream& outfile) {
    for (int i = 0; i < shapeCount; ++i) {
        shape* shapePointer = shapesList[i]; // Access each shape using the index
        //shapePointer->Save(outfile);
    }
}

void Graph::load(ifstream& inputfile) {

    // Do nothing.

}
bool Graph::SelectShapeAt(int x, int y)
{
    for (int i = 0; i < shapeCount; ++i)
    {
        /*shapesList[i]->SetSelected(false);*/
        if (shapesList[i]->IsPointInside(x, y))
        {
            shapesList[i]->SetSelected(true);
            return true;
        }
    }
    return false;
}


shape* Graph::Getshape(int x, int y) const
{
    for (int i = 0; i < shapeCount; ++i)
    {
        if (shapesList[i]->IsPointInside(x, y)&& shapesList[i] !=nullptr)
        {
            return shapesList[i];
        }
    }
    return nullptr;
}

shape** Graph::GetShapesList()
{
    return shapesList;
}




int Graph::GetShapeCount() const
{
    return shapeCount;
}

int Graph::UpdateShapeCount(int x)
{
    return shapeCount=x;
}
////////////////////////////////////////////////////////////////
void Graph::SetCopyCount(shape* shape) 
{
    for (int i = 0; i < shapeCount;i++)
    {
        if (shapesList[i] == shape)
            CopyCount++;
    }
}
int Graph::GetCopyCount()
{
    return CopyCount;
}

shape** Graph::GetCopiedShapesList()
{
    return CopiedShapesList;
}


