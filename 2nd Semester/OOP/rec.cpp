//WAP to find the area of rectangle using class
#include<iostream>
using namespace std;

class Rectangle
{
	public:
		float length;
		float breath;
	void getvalue()
	{
		cout<<"Enter length and breath of rec";
		cin>>length>>breath;
	}
	int calcArea()
	{
		return (length* breath);
	}
};

int main()
{
	Rectangle R;
	//R.getvalue();
	R.length=5;
	R.breath=4;
	cout<<"Area of rectangle is "<<R.calcArea();
	return 0;
}
