import java.io.Serializable;

public class Student implements Serializable{
    public int id;
    public String name;

    public Student(int id, String name){
        this.id = id;
        this.name = name;
    }

    @Override
    public String toString() {
        return "Name: " + name + ", ID: " + id;
    }
}