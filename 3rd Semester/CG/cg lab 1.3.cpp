#include<graphics.h>

#include<conio.h>

#include<stdio.h>

int main()

{

int x,y,x_mid,y_mid,radius,dp;

int gm,gd=DETECT;



initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

printf("*********** MID POINT Circle drawing algorithm ********\n\n");

printf("\nEnter the coordinates of center: ");

scanf("%d%d",&x_mid,&y_mid);

printf("\n Now enter the radius: ");

scanf("%d",&radius);

x=0;

y=radius;

dp=1-radius;

while(x<=y){

putpixel(x_mid+x,y_mid+y,YELLOW);

putpixel(x_mid+y,y_mid+x,YELLOW);

putpixel(x_mid-y,y_mid+x,YELLOW);

putpixel(x_mid-x,y_mid+y,YELLOW);

putpixel(x_mid-x,y_mid-y,YELLOW);

putpixel(x_mid-y,y_mid-x,YELLOW);

putpixel(x_mid+y,y_mid-x,YELLOW);

putpixel(x_mid+x,y_mid-y,YELLOW);

if(dp<0) {

dp+=(2*x)+1;

}

else{

dp+=(2*x)-(2*y)+1;

y=y-1;

}

x=x+1;

}

getch();

}
