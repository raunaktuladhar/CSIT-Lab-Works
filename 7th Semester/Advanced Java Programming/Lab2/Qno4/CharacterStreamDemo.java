// package filehandling;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class CharacterStreamDemo {
    public static void main(String[] args) throws IOException{
        FileWriter fw = new FileWriter("xyz.txt");
        fw.write("Raunak Tuladhar");
        fw.close();

        FileReader fr = new FileReader("xyz.txt");
        int ch;
        while ((ch = fr.read()) != -1) {
            System.out.println((char) ch);
        }
        fr.close();
    }
}
