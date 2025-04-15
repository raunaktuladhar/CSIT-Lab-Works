#include<iostream>
using namespace std;
class Sum
{
	public:
		int x,y;
		
	Sum(int x,int y)
	{
		cout<<" sum of two number is "<<x+y;
	}
};
int main()
{
	Sum s(5,5);
	return 0;
	
}
