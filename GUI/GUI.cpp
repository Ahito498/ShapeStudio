#include "GUI.h"
#include "math.h"
#define pi 3.141592653589793238462643383279502884197
GUI::GUI()
{

	width = 1300;
	height = 700;
	wx = 5;
	wy = 5;


	StatusBarHeight = 50;
	ToolBarHeight = 50;
	MenuIconWidth = 80;
	DrawColor = BLACK;	//default Drawing color
	FillColor = YELLOW;	//default Filling color
	MsgColor = WHITE;		//Messages color
	BkGrndColor = WHITE;	//Background color
	HighlightColor = MAGENTA;	//This color should NOT be used to draw shapes. use it for highlight only
	StatusBarColor = PURPLE;
	PenWidth = 3;	//default width of the shapes frames


	//Create the output window
	pWind = CreateWind(width, height, wx, wy);
	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - PAINT ^ ^ PLAY - - - - - - - - - -");

	CreateDrawToolBar();
    CreateDrawToolBar2();
	CreateStatusBar();
}




//======================================================================================//
//								Input Functions										//
//======================================================================================//
void GUI::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string GUI::GetSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if( Label.size() > 0)	
				Label.resize(Label.size() - 1);
			else
				Key = '\0';		
		else
			Label += Key;
		PrintMessage(Label);
	}
}

color GUI::parseColor(const string& colorStr) {
    int r, g, b;
    sscanf_s(colorStr.c_str(), "RGB(%d %d %d)", &r, &g, &b);
    return color(r, g, b);
}

//This function reads the position where the user clicks to determine the desired operation
operationType GUI::GetUseroperation() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	//[1] If user clicks on the Toolbar
	if (y >= 0 && y < ToolBarHeight)
	{
		//Check whick Menu icon was clicked
		//==> This assumes that menu icons are lined up horizontally <==
		int ClickedIconOrder = (x / MenuIconWidth);
		//Divide x coord of the point clicked by the menu icon width (int division)
		//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on
		switch (ClickedIconOrder)
		{
		case ICON_RECT: return DRAW_RECT;
		case ICON_TRI: return DRAW_TRI;
		case ICON_LINE: return DRAW_LINE;
        case ICON_CIRC: return DRAW_CIRC;
        case ICON_SQ:   return DRAW_SQ;
        case ICON_OVAL: return Draw_OVAL;
        case ICON_HEX: return DRAW_HEX;
        case ICON_COLOR: return CHNG_DRAW_CLR;
        case ICON_DEL: return DEL;
        case ICON_paint: return CHNG_FILL_CLR;
        case ICON_SEL: return SELECT;
        case ICON_ROT: return ROTATE;
        case ICON_RESIZE: return RESIZE;
        case ICON_COPY:  return COPY;
        case ICON_PASTE: return PASTE;
        case ICON_EXIT: return EXIT;

		default: return EMPTY;	//A click on empty place in desgin toolbar
		}
	}
    if (x >= 0 && x < 50)
    {
        //Check whick Menu icon was clicked
        //==> This assumes that menu icons are lined up horizontally <==
        int ClickedIconOrder2 = ((y / 40) - 1);
        //Divide x coord of the point clicked by the menu icon width (int division)
        //if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on
        switch (ClickedIconOrder2)
        {
        case ICON_RECT: return DRAW_RECT;
        case ICON_TRI: return DRAW_TRI;
        case ICON_LINE: return DRAW_LINE;
        case ICON_CIRC: return DRAW_CIRC;
        case ICON_SQ:   return DRAW_SQ;
        case ICON_OVAL: return Draw_OVAL;
        case ICON_HEX: return DRAW_HEX;
        case ICON_COLOR: return CHNG_DRAW_CLR;
        case ICON_DEL: return DEL;
        case ICON_paint: return CHNG_FILL_CLR;
        case ICON_SEL: return SELECT;
        case ICON_ROT: return ROTATE;
        case ICON_RESIZE: return RESIZE;
        case ICON_COPY:  return COPY;
        case ICON_PASTE: return PASTE;
        case ICON_EXIT: return EXIT;

        default: return EMPTY;	//A click on empty place in desgin toolbar
        }
    }

	//[2] User clicks on the drawing area
	if (y >= ToolBarHeight && y < height - StatusBarHeight)
	{
		return DRAWING_AREA;
	}
    if (y >= 60 && y < ToolBarHeight - StatusBarHeight)
    {
        return DRAWING_AREA;
    }
	//[3] User clicks on the status bar
	return STATUS;

}
////////////////////////////////////////////////////



//======================================================================================//
//								Output Functions										//
//======================================================================================//

window* GUI::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(BkGrndColor);
	pW->SetPen(BkGrndColor, 1);
	pW->DrawRectangle(0, ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateStatusBar() const
{
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}
///////////////////////////////////////////////////////////////////////////////////////////////
void GUI::SetCrntDrawColor(color x) {

    DrawColor = x;
}

void GUI::SetCrntFillColor(color x) {
    FillColor = x;
}

//////////////////////////////////////////////////////////////////////////////////////////
void GUI::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateDrawToolBar() 
{

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu icon
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuIcon
	string MenuIconImages[DRAW_ICON_COUNT];
	MenuIconImages[ICON_CIRC] = "images\\MenuIcons\\Menu_Circ.jpg";
    MenuIconImages[ICON_LINE] = "images\\MenuIcons\\Menu_Line.jpg";
	MenuIconImages[ICON_RECT] = "images\\MenuIcons\\Menu_Rect.jpg";
	MenuIconImages[ICON_TRI] = "images\\MenuIcons\\Menu_Tri.jpg";
    MenuIconImages[ICON_SQ] = "images\\MenuIcons\\Menu_squ.jpg";
    MenuIconImages[ICON_OVAL] = "images\\MenuIcons\\Menu_oval.jpg";
    MenuIconImages[ICON_HEX] = "images\\MenuIcons\\Menu_hexagon.jpg";
    MenuIconImages[ICON_COLOR] = "images\\MenuIcons\\Menu_colorpalette.jpg";
    MenuIconImages[ICON_DEL] = "images\\MenuIcons\\Menu_delete.jpg";
    MenuIconImages[ICON_paint] = "images\\MenuIcons\\Menu_paintbucket.jpg";
    MenuIconImages[ICON_SEL] = "images\\MenuIcons\\Menu_select.jpg";
    MenuIconImages[ICON_ROT]= "images\\MenuIcons\\Rotate_Icon.jpg";
    MenuIconImages[ICON_RESIZE] = "images\\MenuIcons\\Resize.jpg";
    MenuIconImages[ICON_COPY] = "images\\MenuIcons\\Copy.jpg";
    MenuIconImages[ICON_PASTE] = "images\\MenuIcons\\Paste.jpg";
	MenuIconImages[ICON_EXIT] = "images\\MenuIcons\\Menu_Exit.jpg";
    //MenuIconImages[ICON_PENCOLOR] = "images\\MenuIcons\\pencolor.jpg";


	//TODO: Prepare images for each menu icon and add it to the list

	//Draw menu icon one image at a time
	for (int i = 0; i < DRAW_ICON_COUNT; i++)
		pWind->DrawImage(MenuIconImages[i], i * MenuIconWidth, 0, MenuIconWidth, ToolBarHeight);



	//Draw a line under the toolbar
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateDrawToolBar2()
{

    //You can draw the tool bar icons in any way you want.
    //Below is one possible way
    int iconWidth = ToolBarHeight;
    int iconHeight = 40;
    //First prepare List of images for each menu icon
    //To control the order of these images in the menu, 
    //reoder them in UI_Info.h ==> enum DrawMenuIcon
    string MenuIconImages[DRAW_ICON_COUNT2];
    MenuIconImages[ICON_SENTBACK] = "images\\MenuIcons\\Sendtoback.jpg";
    MenuIconImages[ICON_STICK] = "images\\MenuIcons\\stickimage.jpg";
    MenuIconImages[ICON_SAVE] = "images\\MenuIcons\\Save.jpg";
    MenuIconImages[ICON_LOAD] = "images\\MenuIcons\\load.jpg";
    //MenuIconImages[ICON_PENCOLOR] = "images\\MenuIcons\\pencolor.jpg";


    //TODO: Prepare images for each menu icon and add it to the list

    //Draw menu icon one image at a time
    for (int i = 0; i < DRAW_ICON_COUNT2; i++) {
        pWind->DrawImage(MenuIconImages[i], 0, ((i + 1) * iconHeight), iconWidth, iconHeight);
    }


    //Draw a line under the toolbar
}
//////////////////////////////////////////////////////////////////////////////////////////



void GUI::ClearDrawArea() const
{
	pWind->SetPen(BkGrndColor, 1);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(50, ToolBarHeight, width, height - StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////


void GUI::setFill(bool state)
{ 
    fillingState = state;
}

bool GUI::getFill() const
{
    return fillingState;
}
void GUI::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(MsgColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, height - (int)(0.75 * StatusBarHeight), msg);
}
//////////////////////////////////////////////////////////////////
color GUI::GetPalet() const             ///****
{   
    window* win = CreateWind(300,300,0,0);
    string img ="images\\MenuIcons\\colorPalette.jpg";
    string img2 = "images\\MenuIcons\\NoFill.jpg";
    win->DrawImage(img,0,0,300,250);
    win->DrawImage(img2, 0, 250, 300, 50);
    int x, y;
    color NoFill = BISQUE;
    win->WaitMouseClick(x, y);
    color clr = win->GetColor(x, y);
    
    delete win;
    return clr;
}

///////////////////////////////////////////////////////////////////
void GUI::SetCurrentDrawColor(color newColor)//******
{
    DrawColor = newColor;
}
/////////////////////////////////////////////////////////////////
void GUI::SetCurrentFillColor(color newColorf)//*******
{
    FillColor=newColorf;
}


/// //////////////////////////
void GUI::ShowColorPalette() const
{
    color selectedcolor = GetPalet();
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntDrawColor() const	//get current drwawing color
{
	return DrawColor;/////////*******************/////////////**************************
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntFillColor() const	//get current filling color
{
	return FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int GUI::getCrntPenWidth() const		//get current pen width
{
	return PenWidth;
}

//======================================================================================//
//								shapes Drawing Functions								//
//======================================================================================//

void GUI::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, int pw) const
{
	color DrawingClr;
	if (RectGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, pw);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y,style);

}

void GUI::DrawSQ(Point p1, Point p2, GfxInfo SQGfxInfo, int pw) const
{
    int sideLength = abs(p2.x - p1.x); //side length of the square
                                                             
    //int x2 = p1.x + sideLength;     //Define the bottom right corner to use the DrawRectangle 
    int y2 = p1.y + sideLength;      //operation to Draw the square.


    color DrawingClr;           //determine the dtawing color
    if (SQGfxInfo.isSelected)       //shape is selected
        DrawingClr = HighlightColor;
    else
        DrawingClr = SQGfxInfo.DrawClr;

    pWind->SetPen(DrawingClr, pw);        //set the pen of drawing



    drawstyle style;        //determine the fill style
    if (SQGfxInfo.isFilled)
    {
        style = FILLED;
        pWind->SetBrush(SQGfxInfo.FillClr);
    }
    else
    {
        style = FRAME;
    }

   pWind->DrawRectangle(p1.x, p1.y, p2.x, y2, style);        //draw a square using rectangle function
    /*pWind->DrawLine(p1.x,p1.y,p2.x,p1.y);
    pWind->DrawLine(p2.x,p1.y,p2.x,y2);
   1 pWind->DrawLine(p1.x,y2,p2.x,y2);
    x pWind->DrawLine(p1.x,p1.y,p1.x,y2); p1.x,y2  p2.x,y2 */
}

void GUI::DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, int pw) const
{
	color DrawingClr;
	if (LineGfxInfo.isSelected)  // shape is selected
		DrawingClr = HighlightColor; // shape should be drawn highlighted
	else
		DrawingClr = LineGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, pw); // Set Drawing color & width

	drawstyle style;
	if (LineGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(LineGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);
}

void GUI::DrawCircle(Point center, int radius, GfxInfo CircleGfxInfo, int pw) const
{
    color DrawingClr;
    if (CircleGfxInfo.isSelected)  // shape is selected
        DrawingClr = HighlightColor; // shape should be drawn highlighted
    else
        DrawingClr = CircleGfxInfo.DrawClr;

    pWind->SetPen(DrawingClr, CircleGfxInfo.BorderWdth); // Set Drawing color & width

    drawstyle style;
    if (CircleGfxInfo.isFilled)
    {
        style = FILLED;
        pWind->SetBrush(CircleGfxInfo.FillClr);
    }
    else
        style = FRAME;

    pWind->DrawCircle(center.x, center.y, radius, style);
}
void GUI::DrawTriangle(Point Vertex1, Point Vertex2, Point Vertex3, GfxInfo TriangleGfxInfo, int pw) const
{
    color DrawingClr;
    if (TriangleGfxInfo.isSelected)  // shape is selected
        DrawingClr = HighlightColor; // shape should be drawn highlighted
    else
        DrawingClr = TriangleGfxInfo.DrawClr;

    pWind->SetPen(DrawingClr, pw); // Set Drawing color & width

    drawstyle style;
    if (TriangleGfxInfo.isFilled)
    {
        style = FILLED;
        pWind->SetBrush(TriangleGfxInfo.FillClr);
    }
    else
        style = FRAME;

    pWind->DrawTriangle(Vertex1.x, Vertex1.y, Vertex2.x, Vertex2.y, Vertex3.x, Vertex3.y, style);
}
void GUI::DrawPolygon(Point* vertices, int VerticesCount, GfxInfo PolygonGfxInfo, int pw) const
{
    color DrawingClr;
    if (PolygonGfxInfo.isSelected)  // shape is selected
        DrawingClr = HighlightColor; // shape should be drawn highlighted
    else
        DrawingClr = PolygonGfxInfo.DrawClr;

    pWind->SetPen(DrawingClr, pw); // Set Drawing color & width

    drawstyle style;
    if (PolygonGfxInfo.isFilled)
    {
        style = FILLED;
        pWind->SetBrush(PolygonGfxInfo.FillClr);
    }
    else
        style = FRAME;

    /*// Calculate the vertices of the hexagon
    int x[6], y[6];
    for (int i = 0; i < 6; ++i)
    {
        x[i] = center.x + radius * cos(i * pi / 3);
        y[i] = center.y + radius * sin(i * pi / 3);
    }

    pWind->DrawPolygon(x, y, 6, style);*/
    

    //Draw polygon
    int* x = new int[VerticesCount];
    int* y = new int[VerticesCount];

    for (int i = 0; i < VerticesCount; i++)
    {
        x[i] = vertices[i].x;
        y[i] = vertices[i].y;
    }
    pWind->DrawPolygon(x, y, VerticesCount, style);

    delete[] x;
    delete[] y;

}

void GUI::DrawOval(Point Corner1, Point Corner2, GfxInfo OvalGfxInfo, int pw) const
{
    color DrawingClr;
    if (OvalGfxInfo.isSelected)  // shape is selected
        DrawingClr = HighlightColor; // shape should be drawn highlighted
    else
        DrawingClr = OvalGfxInfo.DrawClr;

    pWind->SetPen(DrawingClr, pw); // Set Drawing color & width

    drawstyle style;
    if (OvalGfxInfo.isFilled)
    {
        style = FILLED;
        pWind->SetBrush(OvalGfxInfo.FillClr);
    }
    else
        style = FRAME;

    // The bounding box of the oval is defined by the rectangle with corners Corner1 and Corner2
    pWind->DrawEllipse(Corner1.x, Corner1.y, Corner2.x, Corner2.y, style);
}


//////////////////////////////////////////////////////////////////////////////////////////
GUI::~GUI()
{
	delete pWind;
}

