/**
 *  \file       app.c
 *  \brief      Source file for the application program
 *	Write your application code in this file.
 *
 */

#include "app.h"

int main()
{
  appInit();
  gfxSetWindow(0,0,239,319);
  gfxFillRGB(WHITE);
  gfxDrawString(20,30, "Welcome to Phi Education\n",enGfxFont_8X16,BLACK, WHITE);

  while(1);
  return 0;
}
