import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class ByteStreamDemo{
    public static void main(String[] args) throws IOException {
        
        FileOutputStream fileOutputStream = new FileOutputStream("abc.txt", true);
        fileOutputStream.write("Hello World".getBytes());

        fileOutputStream.close();

        FileInputStream fis = new FileInputStream("abc.txt");

        int c;
        while ((c = fis.read()) != -1) {
            System.out.print((char) c);
        }

        fis.close();
    }
}