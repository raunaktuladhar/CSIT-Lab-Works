#include<iostream>
#include<stdlib.h>
using namespace std;
const int MAX_SIZE = 100;
struct stack{
	int item[MAX_SIZE];
	int top;
};
void createEmpty(stack &s){
	s.top = -1;
}
bool isEmpty(const stack &s){
	return (s.top == 1);
}
bool isFull(const stack &s){
	return (s.top == MAX_SIZE-1);
}
void push(stack &s, int value){
	if(isFull(s)){
		cout<<"Stack is full. Can't push element.";
	}
	else{
		s.top++;
		s.item[s.top] = value;
		cout<<"Pushed element: "<<value;
	}
}
void pop(stack &s){
	if(isEmpty(s)){
		cout<<"Stack is empty. Can't pop element."<<endl;
		
	}
	else{
		int popped = s.item[s.top];
		s.top--;
		cout<<"Popped element: "<<popped<<endl;
	}
}
void peek(const stack &s){
	if(isEmpty(s)){
		cout<<"Stack is empty."<<endl;
	}
	else{
		int topElement = s.item[s.top];
		cout<<"Top element: "<<topElement;
	}
}
void traverse(const stack &s){
	if(isEmpty(s)){
		cout<<"Stack is Empty."<<endl;
	}
	else{
		cout<<"Stack elements: ";
		for(int i=0; i<=s.top; i++){
			cout<<s.item[i]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	stack s;
	int choice, value;
	createEmpty(s);
	cout<<"Choose one of the following options: "<<endl;
	cout<<"1. Create an Empty Stack."<<endl;
	cout<<"2. Make an Empty Stack."<<endl;
	cout<<"3. Push operation."<<endl;
	cout<<"4. Pop operation."<<endl;
	cout<<"5. Peek operation."<<endl;
	cout<<"6. Traverse stack."<<endl;
	cout<<"7. Exit."<<endl<<endl;
	do{
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice){
			case 1:
				createEmpty(s);
				cout<<"Stack created.";
				break;
				case 2:
					createEmpty(s);
					cout<<"Stack made empty."<<endl;
					break;
					case 3:
						cout<<"Enter the value to push: ";
						cin>>value;
						push(s, value);
						break;
						case 4:
							pop(s);
							break;
							case 5:
								peek(s);
								break;
								case 6:
									traverse(s);
									break;
									case 7:
										cout<<"Exiting program."<<endl;
										exit(0);
										default:
											cout<<"Invalid choice. Please try again.";
		}
		cout<<endl;
	}
	while(true);
	return 0;
}
