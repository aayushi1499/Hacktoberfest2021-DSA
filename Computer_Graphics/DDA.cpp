// EXP 3 - C program for DDA line generation
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

void DDA(int Lx1, int Lx2, int Ly1, int Ly2) {
	
    float x,y,dx,dy,step,x_inc,y_inc;
    int i;
    dx=Lx2-Lx1;
    dy=Ly2-Ly1;
    
    // calculate steps required for generating pixels
    step = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 

    x_inc=dx/step;
    y_inc=dy/step;
    x=Lx1;
    y=Ly1;

    for(i=0;i<step;i++) 
	{
		putpixel(x+300,y+300,YELLOW);
		x=x+x_inc;
		y=y+y_inc;
		i+=1;
    }
}

int main(){
    int graphicdriver=DETECT,graphicmode; 
    char driver[1000] = "c:\\turboc3\\bgi";
    
    int Lx1,Lx2,Ly1,Ly2;
    printf("enter the end points of the line\n");
    scanf("%d %d %d %d",&Lx1,&Ly1,&Lx2,&Ly2);

    // initgraph initializes the graphics system by loading a graphics driver from disk.
    initgraph(&graphicdriver,&graphicmode,driver);
    DDA(Lx1,Lx2,Ly1,Ly2);
    getch();
    closegraph();
    return 0;
}
