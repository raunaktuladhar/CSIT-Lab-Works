import java.util.Scanner;

public class Array {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the size of an array: ");
        int n = scanner.nextInt();
        int[] array = new int[n];

        System.out.println("Enter the elements of an array: ");

        for(int i=0; i<array.length; i++){
            array[i] = scanner.nextInt();
        }

        System.out.println("\nElements of an array are: ");

        for(int x : array){
            System.out.println(x);
        }        

        int max = array[0];
        int min = array[0];
        int sum = 0;

        for (int num : array) {
            if (num > max) {
                max = num;
            }
            if (num < min) {
                min = num;
            }
            sum += num;
        }

        double average = (double) sum / n;

        System.out.println("\nMaximum number: " + max);
        System.out.println("Minimum number: " + min);
        System.out.println("Average: " + average);

        scanner.close();
    }
}
