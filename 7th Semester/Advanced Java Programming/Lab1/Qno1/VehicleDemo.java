// main class
public class VehicleDemo {
    public static void main(String[] args) {
        Vehicle v1 = new Car();
        v1.setBrand("Suzuki");
        System.out.println("Car Brand: " + v1.getBrand());
        v1.startEngine();

        System.out.print("\n");

        Vehicle v2 = new Car();
        v2.setBrand("Honda");
        System.out.println("Car Brand: " + v2.getBrand());
        v2.startEngine();
    }
}
