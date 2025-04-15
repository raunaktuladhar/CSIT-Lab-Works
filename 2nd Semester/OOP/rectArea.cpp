//WAP to calculate area of rectangle
#include<iostream>
using namespace std;

class Rectangle
{
	public:
		float length;
		float breath;
	void getvalue()
	{
		cout<<"Enter the length and breath of rectangle";
		cin>>length>>breath;
	}
	int calcArea()
	{
		return(length*breath);
	}
};

int main()
{
	Rectangle R1;
	R1.getvalue();
	float area;
	
	area=R1.calcArea();
	cout<<"Area of rectangle is "<<area;
	return 0;
}
