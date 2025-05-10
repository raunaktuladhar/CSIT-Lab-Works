## Implement a Java program that demonstrates the three key OOP principles: Abstraction, Encapsulation, and Inheritance.

### Problem Statement:
**You are developing a Vehicle Management System. The system should support different types of vehicles like Cars and Bikes while following OOP principles.**

### Tasks:

>1. **Abstraction:** <br>Create an abstract class Vehicle with the following:   
    ● String brand (Encapsulated, use getter/setter)   
    ● An abstract method void startEngine();
>2. **Inheritance:**   
    ● Create two classes, Car and Bike, that inherit from Vehicle.   
    ● Implement the startEngine() method in both subclasses with a unique message. 
>3. **Encapsulation:**   
    ● The brand field in Vehicle should be private, and accessible via public getter/setter methods.

### Files:

>* **Vehicle.java:** Contains the parent class Vehicle
>* **Bike.java:** Contains the child class Bike which is inherited by its parent class Vehicle
>* **Car.java:** Contains the child class Car which is inherited by its parent class Vehicle
>* **VehicleDemo.java:** Contains the main function of the program

