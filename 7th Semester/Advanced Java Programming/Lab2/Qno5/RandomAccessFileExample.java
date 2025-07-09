import java.io.RandomAccessFile;
import java.io.IOException;

public class RandomAccessFileExample {
    public static void main(String[] args) {
        try {
            // Create a RandomAccessFile object in "rw" (read/write) mode
            RandomAccessFile file = new RandomAccessFile("data.txt", "rw");

            // Write the string "Hello World" to the file
            file.writeUTF("Hello World");

            // Move the file pointer to the beginning
            file.seek(0);

            // Read and display the content
            String content = file.readUTF();
            System.out.println("File content: " + content);

            // Close the file
            file.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
