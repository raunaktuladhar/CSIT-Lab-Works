public abstract class Vehicle{
    // Encapsulation
    private String brand;

    // getter
    public String getBrand() {
        return brand;
    }

    // setter
    public void setBrand(String brand) {
        this.brand = brand;
    }

    // Abstraction
    public abstract void startEngine();
    
}