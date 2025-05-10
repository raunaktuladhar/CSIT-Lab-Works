// Final Class
final class FinalExample {
    final int LIMIT = 100; // Final Variable

    final void showMessage() { // Final Method
        System.out.println("This is a final method in a final class.");
    }
}
// Base Class (for inheritance)
class Animal {
    Animal() {
        System.out.println("Animal constructor called.");
    }
    void speak() {
        System.out.println("Animals can make sounds.");
    }
}
// Single Inheritance
class Dog extends Animal {
    Dog() {
        super(); // Calls Animal constructor
        System.out.println("Dog constructor called.");
    }
    void speak() {
        super.speak(); // Calls Animal's speak()
        System.out.println("Dogs bark.");
    }
}
// Multilevel Inheritance
class Puppy extends Dog {
    Puppy() {
        System.out.println("Puppy constructor called.");
    }
    void cry() {
        System.out.println("Puppy cries.");
    }
}
// Hierarchical Inheritance
class Cat extends Animal {
    Cat() {
        System.out.println("Cat constructor called.");
    }
    void speak() {
        System.out.println("Cats meow.");
    }
}
public class InheritanceDemo {
    public static void main(String[] args) {
        System.out.println("=== Single & Multilevel Inheritance ===");
        Puppy myPuppy = new Puppy();
        myPuppy.speak();
        myPuppy.cry();
        System.out.println("\n=== Hierarchical Inheritance ===");
        Cat myCat = new Cat();
        myCat.speak();
        System.out.println("\n=== Final Keyword Demo ===");
        FinalExample finalObj = new FinalExample();
        System.out.println("Final variable LIMIT = " + finalObj.LIMIT);
        finalObj.showMessage();
    }
}
