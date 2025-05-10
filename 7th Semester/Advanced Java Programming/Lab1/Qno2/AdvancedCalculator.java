// inherited from Calculator.java
public class AdvancedCalculator extends Calculator{
    public int sum(int a, int b){
        System.out.println("This is advanced calculator");
        return (a+b);
    }

    public static void main(String[] args) {
        AdvancedCalculator ac = new AdvancedCalculator();

        // method overriding
        System.out.println(ac.sum(2, 3));
        System.out.println(ac.sum(5.5, 5.5));
        System.out.println(ac.sum(5, 3, 2));
    }
}
