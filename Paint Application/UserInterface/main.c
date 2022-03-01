
#include "app.h"
#include "gameEngine.h"



PFbyte windowID, canvasID, widget1ID, widget2ID, widget3ID, widget4ID, widget5ID, widget6ID;
PFdword x,y,a,b,val=10;
int idx=0;

// Function to find square root of a PFdword type variable
PFdword sqroot(PFdword r) {

    if (r==0 || r==1) return r;
 
    PFdword start=1, end=r/2 , mid, res, sqr;

    while (start<=end) {
        mid=(start + end)/2;
        sqr=mid*mid;

        if (sqr==r) return mid;

        if (sqr<r) {
            start=mid + 1;
            res=mid;
        }

        else end=mid - 1;
    }
    return res;
}

void freeHandBtnEventHandler(void) {
    idx=1;
}
    
void lineBtnEventHandler(void) {
    idx=2;
}

void circleBtnEventHandler(void) {
    idx=3;
}
    
void rectangleBtnEventHandler(void) {
    idx=4;
}

void saveBtnEventHandler(void) {
    gfxDrawString(val,50,"SAVED",enGfxFont_8X16,BLACK,WHITE);
    // val+=50;
}
    
void homeScreen(void) {
    setWindow(windowID);
    gfxDrawLine(42,36,72,4);
    gfxDrawCircle(95,20,16);
    gfxDrawRectangle(118,4,148,36);	
    gfxDrawString(197,12,"SAVE",enGfxFont_8X16,BLACK,WHITE);
} 

void clearscreenBtnEventHandler(void) {
	homeScreen();
    // val=10;
	while(1) {
		if(touchAvailable(&x,&y)==enBooleanTrue) windowEventHandler(windowID,x,y);
	}
}

void canvasEventHandler(void) {
/* the edge cases such as handling of shapes and pixels are not drawn on the buttons are commented here because we wanted to 
   see about the problems but we will use them in the final build and please have the look at the edge cases as well whether 
   if they are correct.
*/
    switch(idx) 
    {
        case 1:
            gfxDrawPixels(x,y);
	    	while(touchAvailable(&a,&b)==enBooleanTrue) {
                // if(b>=42) {}
                gfxDrawPixels(a,b);
            }
            break;
        case 2:
            while(touchAvailable(&a,&b)==enBooleanTrue) {}
            // if((x!=a || y!=b) && b>=42) {}
			gfxDrawLine(x,y,a,b);
            break;
        case 3:
            while(touchAvailable(&a,&b)==enBooleanTrue) {}
            // if((x!=a || y!=b) && b>=42) {}
            PFdword radius,tmp=((a-x)*(a-x))+((b-y)*(b-y));
	    	radius=sqroot(tmp);
            // if(y-radius>=42 && y+radius<=319 && x-radius>=0 && x+radius>=239) {}
		    gfxDrawCircle(x,y,radius);
            break;
        case 4:
            while(touchAvailable(&a,&b)==enBooleanTrue) {}
            // if((x!=a && y!=b) && b>=42) {}
			gfxDrawRectangle(x,y,a,b);
            break;
        default :
            break;
    }
}


static WindowCfg window1= 
{
    {
        "Window 1",
        {0,0},
        {240,320},
        WHITE,
        enBooleanFalse
    },
    NULL
};

static CanvasCfg Canvas=
{
    {
        "Canvas",
        {0,40},
        {240,280},
        WHITE,
        enBooleanTrue
    },
    canvasEventHandler,
    "",
    enGfxFont_8X16,
    WHITE,
    0
};

static WidgetCfg freeHandBtnWidget=
{
    {
        "Freehand button widget",
        {0,0},
        {38,40},
        WHITE,
        enBooleanTrue
    },
    freeHandBtnEventHandler,
    "  FH",
    enGfxFont_8X16,
    BLACK,
    0
};

static WidgetCfg lineBtnWidget=
{
    {
        "Line button widget",
        {38,0},
        {38,40},
        WHITE,
        enBooleanTrue
    },
    lineBtnEventHandler,
    "",
    enGfxFont_8X16,
    BLACK,
    0
};

static WidgetCfg circleBtnWidget=
{
    {
        "Circle button widget",
        {76,0},
        {38,40},
        WHITE,
        enBooleanTrue
    },
    circleBtnEventHandler,
    "",
    enGfxFont_8X16,
    BLACK,
    0
};

static WidgetCfg rectangleBtnWidget=
{
    {
        "Rectangle button widget",
        {114,0},
        {38,40},
        WHITE,
        enBooleanTrue
    },
    rectangleBtnEventHandler,
    "",
    enGfxFont_8X16,
    BLACK,
    0
};


static WidgetCfg clearscreenBtnWidget=
{
    {
        "Clearscreen button widget",
        {152,0},
        {38,40},
        WHITE,
        enBooleanTrue
    },
    clearscreenBtnEventHandler,
    " CLS",
    enGfxFont_8X16,
    BLACK,
    0
};

static WidgetCfg saveBtnWidget=
{
    {
        "Save button widget",
        {192,0},
        {48,40},
        WHITE,
        enBooleanTrue
    },
    saveBtnEventHandler,
    "",
    enGfxFont_8X16,
    BLACK,
    0
};


int main()
{

	appInit();						
	gameEngineInit();	
    gfxSetColor(BLACK);	
	
    // creating widgets
	createWindow(&windowID,&window1);
	createCanvas(windowID,&canvasID,&Canvas);
	createWidget(windowID,&widget1ID,&freeHandBtnWidget);
	createWidget(windowID,&widget2ID,&lineBtnWidget);
    createWidget(windowID,&widget3ID,&circleBtnWidget);
    createWidget(windowID,&widget4ID,&rectangleBtnWidget);
	createWidget(windowID,&widget5ID,&clearscreenBtnWidget);
    createWidget(windowID,&widget6ID,&saveBtnWidget);


	homeScreen();							

	while(1) {
		if(touchAvailable(&x,&y) == enBooleanTrue) {
			windowEventHandler(windowID, x, y);	
		}
	}

    return 0;
}
