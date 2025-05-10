## Implement a Java program that demonstrates method overloading (compile-time polymorphism) and method overriding (runtime polymorphism).

### Problem Statement:
**You are developing a Calculator application that can perform various operations. The calculator should support different ways of calculating the sum of numbers (method overloading) and different types of calculations based on the calculator 
type (method overriding).**

### Tasks:

>1. Method Overloading:   
Create a class Calculator with multiple sum methods:   
    ● sum(int a, int b) - Adds two integers.   
    ● sum(double a, double b) - Adds two doubles.   
    ● sum(int a, int b, int c) - Adds three integers.   
Create a main method to call each of these methods. <br><br>
>2. Method Overriding:   
    ● Create a class AdvancedCalculator that extends Calculator.   
    ● Override the sum(int a, int b) method to include a custom message. 
>3. Polymorphism:   
    ● In the main method, demonstrate runtime polymorphism by using a reference of type Calculator pointing to an AdvancedCalculator object.

### Files:

>* **Calculator.java:** Contains the parent class Calculator with method overloading
>* **AdvancedCalculator.java:** Contains the child class AdvancedCalculator with method overriding