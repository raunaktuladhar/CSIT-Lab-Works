public class Calculator{

    // method overloading
    public int sum(int a, int b){
        System.out.println("This is Calculator");
        return (a+b);
    }

    public double sum(double a, double b){
        return (a+b);
    }

    public int sum(int a, int b, int c){
        return (a+b+c);
    }

    public static void main(String[] args) {
        Calculator c = new Calculator();
        System.out.println(c.sum(5, 2));
        System.out.println(c.sum(5.5, 2.2));
        System.out.println(c.sum(1, 2, 3));
    }
}