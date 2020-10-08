#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
   // select driver and mode that supports multiple background colors
   int gdriver = EGA, gmode = EGAHI, errorcode;
   int bkcol, maxcolor,x,y, Px, Py;
   char msg[100];
   printf("Enter the coordinates of pixel:");
   scanf("//d //d",&Px,&Py);
   // initialize graphics and local variables
   initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");
   // read result of initialization
   errorcode = graphresult();

   // an error occurred 	
   if (errorcode != grOk) {   
      printf("Graphics error: //s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   // terminate with an error code 
              
   }
   // maximum color index supported 
   maxcolor = getmaxcolor();
   
   // for centering text messages 
   settextjustify(CENTER_TEXT, CENTER_TEXT);

   x = getmaxx() / 2;
   y = getmaxy() / 2;

   // loop through the available colors 
   setbkcolor(14);
   for (bkcol=0; bkcol<=maxcolor; bkcol++) {

      // clear the screen
      cleardevice();

      // select a new background color 
      setbkcolor(bkcol);

      // output a messsage 
      if (bkcol == WHITE)

        setcolor(BLACK);
      // calling putpixel to create a pixel on screen with MAGENTA color
	  putpixel(Px, Py, MAGENTA);
      getch();
   }
   // closegraph function closes the graphics mode and deallocates all memory allocated by graphics system 
   closegraph();
   return 0;
}
