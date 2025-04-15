#include<stdio.h>

#include <conio.h>

#include<graphics.h>

int main(){

int x,y,x1,y1,x2,y2,p,dx,dy;

int gd=DETECT,gm;

initgraph(&gd,&gm,"C:\\TurboC3\\BGI");

printf("\nEnter the x-coordinate of the first point :");

scanf("%d",&x1);

printf("\n Enter the y-coordinate of the first point :");

scanf("%d",&y1);

printf("\n Enter the x-coordinate of the second point :");

scanf("%d", &x2);

printf("\n Enter the y-coordinate of the second point :");

scanf("%d", &y2);

x=x1;

y=y1;

dx=x2-x1;

dy=y2-y1;

putpixel(x,y,2);

p=(2*dy-dx);

while(x<=x2){

x++;

if(p<0)

p=p+2*dy;

else

p=p+(2*dy)-(2*dx);

putpixel(x,y,7);

}

getch();

closegraph();

return 0;

}
