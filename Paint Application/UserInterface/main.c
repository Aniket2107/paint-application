
#include "app.h"
#include "gameEngine.h"

PFbyte windowID, canvasID, widget1ID, widget2ID, widget3ID, widget4ID, widget5ID, widget6ID;
PFdword i, j, a1, b1, a2, b2;
char shape = 'f';
int cnt = 0;

PFdword sqroot(PFdword r); // Function to find square root of a PFdword type variable
void freeHandBtnEventHandler(void);
void lineBtnEventHandler(void);
void circleBtnEventHandler(void);
void rectangleBtnEventHandler(void);
void saveBtnEventHandler(void);
void homeScreen(void);
void clearscreenBtnEventHandler(void);
void canvasEventHandler(void);

static WindowCfg window1 =
    {
        {"Window 1",
         {0, 0},
         {240, 320},
         WHITE,
         enBooleanFalse},
        NULL};

static CanvasCfg Canvas =
    {
        {"Canvas",
         {0, 43},
         {240, 280},
         WHITE,
         enBooleanTrue},
        canvasEventHandler,
        "",
        enGfxFont_8X16,
        WHITE,
        0};

static WidgetCfg freeHandBtnWidget =
    {
        {"Freehand button widget",
         {0, 0},
         {40, 43},
         WHITE,
         enBooleanTrue},
        freeHandBtnEventHandler,
        "  FH",
        enGfxFont_8X16,
        BLACK,
        0};

static WidgetCfg lineBtnWidget =
    {
        {"Line button widget",
         {40, 0},
         {40, 43},
         WHITE,
         enBooleanTrue},
        lineBtnEventHandler,
        "",
        enGfxFont_8X16,
        BLACK,
        0};

static WidgetCfg circleBtnWidget =
    {
        {"Circle button widget",
         {80, 0},
         {40, 43},
         WHITE,
         enBooleanTrue},
        circleBtnEventHandler,
        "",
        enGfxFont_8X16,
        BLACK,
        0};

static WidgetCfg rectangleBtnWidget =
    {
        {"Rectangle button widget",
         {120, 0},
         {40, 43},
         WHITE,
         enBooleanTrue},
        rectangleBtnEventHandler,
        "",
        enGfxFont_8X16,
        BLACK,
        0};

static WidgetCfg clearscreenBtnWidget =
    {
        {"Clearscreen button widget",
         {160, 0},
         {36, 43},
         WHITE,
         enBooleanTrue},
        clearscreenBtnEventHandler,
        " CLS",
        enGfxFont_8X16,
        BLACK,
        0};

static WidgetCfg saveBtnWidget =
    {
        {"Save button widget",
         {196, 0},
         {44, 43},
         WHITE,
         enBooleanTrue},
        saveBtnEventHandler,
        "",
        enGfxFont_8X16,
        BLACK,
        0};

int main()
{

    appInit();
    gameEngineInit();
    gfxSetColor(BLACK);
    gfxSetPenSize(2);

    // creating widgets
    createWindow(&windowID, &window1);
    createCanvas(windowID, &canvasID, &Canvas);
    createWidget(windowID, &widget1ID, &freeHandBtnWidget);
    createWidget(windowID, &widget2ID, &lineBtnWidget);
    createWidget(windowID, &widget3ID, &circleBtnWidget);
    createWidget(windowID, &widget4ID, &rectangleBtnWidget);
    createWidget(windowID, &widget5ID, &clearscreenBtnWidget);
    createWidget(windowID, &widget6ID, &saveBtnWidget);

    homeScreen();

    while (1)
    {
        if (touchAvailable(&i, &j) == enBooleanTrue)
        {
            windowEventHandler(windowID, i, j);
        }
    }
    return 0;
}

PFdword sqroot(PFdword r)
{

    if (r == 0 || r == 1)
        return r;

    PFdword start = 1, end = r / 2, mid, res, sqr;

    while (start <= end)
    {

        mid = (start + end) / 2;
        sqr = mid * mid;

        if (sqr == r)
        {
            return mid;
        }

        if (sqr < r)
        {
            start = mid + 1;
            res = mid;
        }

        else
        {
            end = mid - 1;
        }
    }
    return res;
}

void freeHandBtnEventHandler(void)
{
    shape = 'f';
}

void lineBtnEventHandler(void)
{
    shape = 'l';
}

void circleBtnEventHandler(void)
{
    shape = 'c';
}

void rectangleBtnEventHandler(void)
{
    shape = 'r';
}

void saveBtnEventHandler(void)
{
    gfxDrawString(10, 54, "SAVED", enGfxFont_8X16, BLACK, WHITE);
}

void homeScreen(void)
{
    setWindow(windowID);
    gfxDrawLine(76, 5, 44, 39);
    gfxDrawCircle(100, 21, 17);
    gfxDrawRectangle(124, 4, 156, 39);
    gfxDrawString(201, 14, "SAVE", enGfxFont_8X16, BLACK, WHITE);
}

void clearscreenBtnEventHandler(void)
{
    gfxFillArea(2, 45, 238, 318, WHITE);
}

void canvasEventHandler(void)
{

    switch (shape)
    {
    case 'f':
        gfxDrawPixels(i, j);
        while (touchAvailable(&a1, &b1) == enBooleanTrue)
        {
            if (b1 >= 45)
            {
                gfxDrawPixels(a1, b1);
            }
        }
        break;
    case 'l':
        while (touchAvailable(&a2, &b2) == enBooleanTrue)
        {
            if (b2 >= 45)
            {
                a1 = a2;
                b1 = b2;
            }
        }
        if ((i != a1 || j != b1) && b1 >= 45)
        {
            gfxDrawLine(i, j, a1, b1);
        }
        break;
    case 'c':
        while (touchAvailable(&a2, &b2) == enBooleanTrue)
        {
            if (b2 >= 45)
            {
                a1 = a2;
                b1 = b2;
            }
        }
        if ((i != a1 || j != b1) && b1 >= 45)
        {
            PFdword radius, tmp = ((i - a1) * (i - a1)) + ((j - b1) * (j - b1));
            radius = sqroot(tmp);
            // if (i - radius >= 0 && i + radius >= 249 && j - radius >= 42 && j + radius <= 320) {}
            if (j - radius >= 45)
            {
                gfxDrawCircle(i, j, radius);
            }
        }

        break;
    case 'r':
        while (touchAvailable(&a2, &b2) == enBooleanTrue)
        {
            if (b2 >= 45)
            {
                a1 = a2;
                b1 = b2;
            }
        }
        if ((i != a1 && j != b1) && b1 >= 45)
        {
            gfxDrawRectangle(i, j, a1, b1);
        }
        break;
    default:
        break;
    }
}