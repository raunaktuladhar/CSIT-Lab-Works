// C++ program to calculate the average marks of two students

#include <iostream>
using namespace std;

class Student {

   public:
    double marks;

    // constructor to initialize marks
    Student(double m) {
        marks = m;
    }
};

// function that has objects as parameters
void calculateAverage(Student s1, Student s2) {

    // calculate the average of marks of s1 and s2 
    double average = (s1.marks + s2.marks) / 2;

   cout << "Average Marks = " << average << endl;

}

int main() {
    Student student1(88.0), student2(56.0);
    
    cout<<" First student mark :"<<student1.marks<<endl;
    cout<<" Second student mark :"<<student2.marks<<endl;


  // pass the objects as arguments
   calculateAverage(student1, student2);

    return 0;
}
