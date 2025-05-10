import java.util.InputMismatchException;
import java.util.Scanner;

public class DivisionHandler {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        try {
            System.out.print("Enter first integer: ");
            int num1 = scanner.nextInt();

            System.out.print("Enter second integer: ");
            int num2 = scanner.nextInt();
            int result = num1 / num2;
            System.out.println("Result = " + result);
        }
        catch (InputMismatchException e) {
            System.out.println("Error: Please enter only integers.");
        }
        catch (ArithmeticException e) {
            System.out.println("Error: Cannot divide by zero.");
        }
        finally {
            scanner.close();
        }
    }
}
