import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;

public class ReadObject {
    public static void main(String[] args) {
        try{
            FileInputStream fis = new FileInputStream("student.ser");
            ObjectInputStream ois = new ObjectInputStream(fis);
            Student s = (Student) ois.readObject();
            System.out.println("Object Deserialized: " + s);
            fis.close();
            ois.close();
        }
        catch(IOException | ClassNotFoundException e){
            e.printStackTrace();
        }
    }
}
