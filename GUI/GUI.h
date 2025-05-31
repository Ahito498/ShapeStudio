#pragma once
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"
#include <string>
using namespace std;
struct Point	//To be used for shapes points
{
	int x, y,r;
};

struct GfxInfo	//Graphical info common for all shapes (you may add more members)
{
	color DrawClr;	//Draw color of the shape.
	color FillClr;	//Fill color of the shape.
	bool isFilled;	//shape Filled or not.
	int BorderWdth;	//Width of shape borders.
	bool isSelected;	//true if the shape is selected.
};

class GUI
{
	enum MenuIcon //The icons of the menu (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here
		ICON_LINE,        // Line icon in the menu 
		ICON_RECT,		// Recangle icon in menu
		ICON_TRI,	   // Triangle icon in menu
        ICON_CIRC,    // Circle icon in menu
        ICON_SQ,      //Square icon in menu
        ICON_OVAL,    // Oval icon in the menu 
        ICON_HEX,     //Hexagon icon in the menu 
        ICON_COLOR,    //icon color palette
        //ICON_PENCOLOR,      //Change pen color
        ICON_DEL,    //icon delet 
        ICON_paint,  //Icon paintbucket
        ICON_SEL,    //Icon select the shape 
        ICON_ROT,
        ICON_RESIZE,
        ICON_COPY,
        ICON_PASTE,
		//TODO: Add more icons names here

		ICON_EXIT,		//Exit icon

		DRAW_ICON_COUNT		//no. of menu icons ==> This should be the last line in this enum
           // no.2 of menu icons 
	};
    enum DRAW_ICON_COUNT2 {
        ICON_SENTBACK, // Icon  sent it to back 
        ICON_STICK,    // Icon stick an image to the shape 
        ICON_SAVE,     // Icon Save 
        ICON_LOAD,     //Icon Load 
        DRAW_ICON_COUNT2
    };

	int	width, height,	//Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuIconWidth;		//Width of each icon in toolbar menu
	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes
    bool fillingState=false;
	/// Add more members if needed
	window* pWind;

public:

	GUI();

	// Input Functions  ---------------------------
	void GetPointClicked(int& x, int& y) const;//Get coordinate where user clicks
	string GetSrting() const;	 //Returns a string entered by the user
	operationType GetUseroperation() const; //Read the user click and map to an operation

	// Output Functions  ---------------------------
	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar();	//creates Draw mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
    void CreateDrawToolBar2();    //create the 2nd status bar
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
    color parseColor(const string& colorStr);
    void SetCrntDrawColor(color);
    void SetCrntFillColor(color);

	// -- shapes Drawing functions
    void DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, int pw) const;  //Draw a Line   GfxInfo is struct to define color,fill,bord width and if it selected  
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, int pw) const;  //Draw a rectangle
    void DrawTriangle(Point Vertex1, Point Vertex2, Point Vertex3, GfxInfo TriangleGfxInfo, int pw) const; //Draw Triangle 
    void DrawCircle(Point center, int radius, GfxInfo CircleGfxInfo, int pw) const;   //Draw Circle
    void DrawSQ(Point p1, Point p2, GfxInfo SQGfxInfo, int pw) const;         //Draw a square (recently added)
    void DrawOval(Point Corner1, Point Corner2, GfxInfo OvalGfxInfo, int pw) const;  //Draw a Oval
    void DrawPolygon(Point* vertices, int vertexCount, GfxInfo PolygonGfxInfo, int pw) const; // Draw Hexagon 
    color GetPalet() const; // change the color 

	///Make similar functions for drawing all other shapes.

    void setFill(bool state);//make the shapes filled
    bool getFill() const;
	void PrintMessage(string msg) const;	//Print a message on Status bar
    void SetCurrentDrawColor(color newColor);   //set the new pen color******
    void SetCurrentFillColor(color newColor);   //set the new filling color*****
    void ShowColorPalette() const;
	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width


	~GUI();
};

