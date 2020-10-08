#include <graphics.h>
#include <dos.h>
#include <math.h>
#include <stdlib.h>
#define MAX 100000
int main()
{
	//graphicmode is Graphics mode which is a computer display mode that generates image using pixels
    //DETECT is a macro defined in "graphics.h" header file.
	int graphicdriver=DETECT,graphicmode; 
    char driver[1000] = "c:\\turboc3\\bgi";
    
    //initgraph initializes the graphics system by loading a graphics driver from disk.
	initgraph(&graphicdriver,&graphicmode,driver);
	int Px, Py, Lx1, Ly1, Lx2, Ly2;
	//enter the coordinates of the point
    printf("\nEnter the coordinates of the point to check where it lies:"); 
    scanf("%d %d", &Px, &Py);
    //enter the coordinates of the line
	printf("\nEnter the coordinates of the line:"); 
	scanf("%d %d %d %d", &Lx1, &Ly1, &Lx2, &Ly2);
	//calculate the slope and intercept values of the line
	float slope;
	
	if(Lx2 - Lx1 == 0)
		slope = MAX;
	else
		slope = float(Ly2 - Ly1)/(Lx2 - Lx1);
	
	int intercept = (Ly1 - round(slope * Lx1));
	printf("\nEquation of line connecting the points (%d,%d) and (%d,%d)",Lx1, Ly1, Lx2, Ly2);
	if (slope == MAX)
		printf("\n\t x = %d\n", Lx1);
	else
		printf("\n\t y = %.2f x %c %d\n",slope, (intercept<0?' ':'+'), intercept);

    //to check if the point lies on the line
    //if we round slope here, we might face stair effect as in reality the point needs to be placed on the line but for decimal values the answer might vary for y
    if(round(slope * Px) + intercept == Py)
    	printf("\n The point (%d,%d) lies on the line",Px,Py);
    else
	{
		printf("\n The point (%d,%d) lies in ",Px,Py);
		//to compare the point wrt to line
	    //the object closer to origin is considered at top i.e. if point is closer to origin it is top, if line closert to origin than line is upper
	    //(linex, liney) point on the line taken for comparison
	    int linex = Px;
	    int liney = round(slope * Px) + intercept;
	     //UPPER / LOWER
		if(( liney > Py )&&( slope != MAX ))	
			printf("Upper");
	    else if( slope != MAX )	
			printf("Lower");
	
	    //LEFT / RIGHT
	    liney = Py;
	    linex = round(( liney - intercept ) / slope);
	    if(( linex > Px  )&&( slope != 0 ))
			printf(" Left of the line"); 	
	    else if( slope != 0 )	
			printf(" Right of the line");	
	}
	putpixel(Px+200,Py+200,WHITE);
	setcolor(14); //set color of line i.e. magenta
	line(Lx1+200,Ly1+200,Lx2+200,Ly2+200);
    getch();
    //closegraph function closes the graphics mode and deallocates all memory allocated by graphics system 
    closegraph(); 
}
