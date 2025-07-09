import java.io.FileOutputStream;
import java.io.ObjectOutputStream;

public class StdSerialize {
    public static void main(String[] args) {
        Student s = new Student(1, "Raunak");

        try{
            FileOutputStream fos = new FileOutputStream("student.ser");
            ObjectOutputStream oos = new ObjectOutputStream(fos);
            oos.writeObject(s);
            fos.close();
            oos.close();
        }

        catch(Exception e){
            e.printStackTrace();
        }
    }
}
