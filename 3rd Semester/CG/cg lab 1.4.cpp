#include<stdio.h>

#include<graphics.h>

#include<math.h>

#include<dos.h>

#include<graphics.h>

int main()

{

int gd=DETECT,gm;

int h,k,x,y,a,b;

float d1,d2;

printf("Enter center:");

scanf("%d%d",&h,&k);

printf("Enter values for a and b:");

scanf("%d%d",&a,&b);

initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

x=0;

y=b;

d1=b*b+a*a/4-a*a*b;

while(a*a*y>=b*b*x){

putpixel(h+x,k-y,WHITE);

putpixel(h-x,k+y,WHITE);

putpixel(h+x,k+y,WHITE);

putpixel(h-x,k-y,WHITE);

if(d1<=0){

d1=d1+b*b*(2*x+3);

x+=1;

}else{

d1=d1+b*b*(2*x+3)+a*a*(2-2*y);

x+=1;

y-=1;

}
}
d2 = (x+0.5)*(x+0.5)*b*b+(y-1)*(y-1)*a*a-a*a*b*b;
while(y>=0){
	putpixel(h+x, k-y, WHITE);
	putpixel(h-x, k+y, WHITE);
	putpixel(h+x, k+y, WHITE);
	putpixel(h-x, k-y, WHITE);
	if(d2<=0){
		d2 = d2+b*b*(2*x+2)+a*a*(3-2*y);
		x+=1;
		y-=1;
	}else{
		d2 = d2 + (3-2*y)*a*a;
		y-=1;
	}
}
getch();
return 0;
}
