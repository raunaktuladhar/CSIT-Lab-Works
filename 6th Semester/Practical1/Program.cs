using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Practical1
{
    internal class Program
    {
        static void Main(string[] args)
        {

            // qno1

            // Creating an object of the Car class using the constructor
            //Car myCar = new Car("Toyota", "Corolla", 2021);

            // Accessing properties
            //Console.WriteLine("Car Make: " + myCar.Make);
            //Console.WriteLine("Car Model: " + myCar.Model);
            //Console.WriteLine("Car Year: " + myCar.Year);

            // Calling method to start the engine
            //myCar.StartEngine();

            // Calling method to display car info
            //myCar.DisplayCarInfo();


            // qno2

            //Calculator calc = new Calculator();

            // Using overloaded methods
            //Console.WriteLine(calc.Add(5, 10));             // Calls Add(int, int)
            //Console.WriteLine(calc.Add(5, 10, 15));         // Calls Add(int, int, int)
            //Console.WriteLine(calc.Add(5.5, 10.5));         // Calls Add(double, double)


            // qno3

            // Create instances of the Calculate class
            //Calculate calc1 = new Calculate();
            //Calculate calc2 = new Calculate();

            // Set values for the first instance
            //calc1.SetCalc(10, 5);

            // Call the methods for the first instance
            //calc1.CalcSum();         // Sum of 10 and 5
            //Console.WriteLine($"Multiplication result: {calc1.CalcMulti()}");  // Multiplication of 10 and 5
            //calc1.CalcDifference();  // Difference between 10 and 5

            // Set values for the second instance
            //calc2.SetCalc(20, 8);

            // Call the methods for the second instance
            //calc2.CalcSum();         // Sum of 20 and 8
            //Console.WriteLine($"Multiplication result: {calc2.CalcMulti()}");  // Multiplication of 20 and 8
            //calc2.CalcDifference();  // Difference between 20 and 8


            // qno4

            // Create instances of the Number class
            //Number num1 = new Number(); // Default constructor (x=0, y=0)
            //Number num2 = new Number(5, 15); // Parameterized constructor (x=5, y=15)

            // Invoke the methods for the first instance (num1)
            //num1.FindEven(); // No range, as both are initialized to 0
            //num1.FindOdd();

            // Invoke the methods for the second instance (num2)
            //num2.FindEven(); // Even numbers between 5 and 15
            //num2.FindOdd();  // Odd numbers between 5 and 15


            //qno5

            // Create an object for rectangle using the constructor with two parameters
            //Shape rectangle = new Shape(5, 10);  // Length = 5, Breadth = 10
            //rectangle.calcAreaRectangle();        // Calculate and display area of rectangle

            // Create an object for box using the constructor with three parameters
            //Shape box = new Shape(5, 10, 20);    // Length = 5, Breadth = 10, Height = 20
            //box.calcVolumeBox();                  // Calculate and display volume of box


            //qno6

            // Create an object of SalaryInfo and pass employee and salary details
            SalaryInfo emp1 = new SalaryInfo(101, "John Doe", "Male", "1234 Elm St, City, Country", "Software Engineer", 550000);

            // Display employee details
            emp1.DisplayEmployeeDetails();

            // Calculate and display tax and final salary
            emp1.CalcTax();

            Console.WriteLine(); // Empty line for clarity

            // Create another object of SalaryInfo with a higher salary
            SalaryInfo emp2 = new SalaryInfo(102, "Jane Smith", "Female", "5678 Oak St, City, Country", "Manager", 950000);

            // Display employee details
            emp2.DisplayEmployeeDetails();

            // Calculate and display tax and final salary
            emp2.CalcTax();


            // qno7.1

            // --- Demonstrating Single Level Inheritance ---
            //Console.WriteLine("Single Level Inheritance:");
            //Dog dog = new Dog();
            //dog.Speak();  // Inherited method from Animal
            //dog.Bark();   // Method from Dog class

            //Console.WriteLine("\n--- Demonstrating Multilevel Inheritance ---");

            // --- Demonstrating Multilevel Inheritance ---
            Puppy puppy = new Puppy();
            puppy.Speak();  // Inherited method from Animal
            puppy.Bark();   // Inherited method from Dog
            puppy.Play();   // Method from Puppy class


            // qno8

            //Console.WriteLine("--Demonstration of base keyword--");

            //SmallBox sb1 = new SmallBox(10,5,2,200);
            //sb1.getVol();

            //int wt1 = sb1.getWeight();
            //Console.WriteLine("The weight of the box is "+wt1);


            // qno9

            //Console.WriteLine("--Demonstration of method overriding--");
            //Solution sol1 = new Solution();
            //sol1.solve1();
            //sol1.solve2(50, 20);
        }
    }
}
 