#pragma once
#include "Shape.h"
#include <fstream>

using namespace std;

//forward decl
class GUI;	

//A class that is responsible on everything related to shapes
class Graph
{
	enum { maxShapeCount = 1000 };
private:
	shape* shapesList[maxShapeCount]; //a container to hold all shapes							   
	int shapeCount;			// Actual number of shapes stored in the list
	shape* selectedShape;	//pointer to the currently selected shape
    shape* CopiedShapesList[maxShapeCount];  //container to hold copied shapes
    int CopyCount = 0;

public:										
	Graph();
	~Graph();
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	void Draw(GUI* pUI) const;			//Draw the graph (draw all shapes)
	shape* Getshape(int x, int y) const; //Search for a shape given a point inside the shape
    shape** GetShapesList();        //made for any function that apply an operation on any shape
    int GetShapeCount() const;  // made for any function that add or delete shapes
    int UpdateShapeCount(int x);//intially made for Delete function

    ///////////////////////////////Copy functions///////////////////////////////////////////////////
    void SetCopyCount(shape* shape);
    int GetCopyCount();
    shape** GetCopiedShapesList();
    int getShapeCount();

     
     
    // ///////////////////////////////////////////////////////////////////////////////
	void Save(ofstream& outfile);	//Save all shapes to a file
	void load(ifstream& inputfile);	//Load all shapes from a file
    bool SelectShapeAt(int x, int y);
    /////
};
