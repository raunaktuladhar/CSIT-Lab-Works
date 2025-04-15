#include<iostream>
using namespace std;

class Test
{
	public:
		int a,b;
		void getval()		
		{
			cout<<"Enter the value of a and b";
			cin>>a>>b;
		}
		int sum()
		{
			return (a+b);
		}
};
int main()
{
	Test t;
	int s=0;
	t.getval();
	s=t.sum();
	cout<<"Output is "<<s;
	return 0;
}
