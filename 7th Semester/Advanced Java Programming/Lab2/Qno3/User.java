public class User extends Thread{
    private Printer printer;
    private String userName;

    public User(Printer printer, String name){
        this.printer = printer;
        this.userName = name;
    }

    public void run(){
        printer.printDocument(userName);
    }

    public static void main(String[] args) {
        Printer printer = new Printer();
        User u1 = new User(printer, "User 1");
        User u2 = new User(printer, "User 2");
        User u3 = new User(printer, "User 3");

        u1.start();
        u2.start();
        u3.start();
    }
}
