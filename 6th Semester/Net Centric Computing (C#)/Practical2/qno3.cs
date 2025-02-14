using System;
using System.Data.SqlClient;

namespace Project2
{
    class Crud
    {
        public void createTable()
        {
            try
            {
                string cs = "Data Source=DESKTOP-7322JPE\\RAUNAK;Initial Catalog=Info;Integrated Security=true;";

                SqlConnection conn = new SqlConnection(cs);
                conn.Open();
                Console.WriteLine("Server Connected");

                string tblQuery = "create table tbl_registration (ID int primary key," +
                                    "Username varchar(50), Password varchar(50), Repassword varchar(50)," +
                                    "Gender varchar(50), Course varchar(50), Country varchar(50))";

                SqlCommand sc = new SqlCommand(tblQuery, conn);
                sc.ExecuteNonQuery();
                Console.WriteLine("Table Created");
                conn.Close();
            }

            catch (SqlException s)
            {
                Console.WriteLine(s);
            }
        }

        public void insertData()
        {
            try
            {
                string cs = "Data Source=DESKTOP-7322JPE\\RAUNAK;Initial Catalog=Info;Integrated Security=true;";

                SqlConnection conn = new SqlConnection(cs);
                conn.Open();

                Console.WriteLine("Enter your ID: ");
                string id = Console.ReadLine();

                Console.WriteLine("Enter your Username: ");
                string uname = Console.ReadLine();

                Console.WriteLine("Enter your Password: ");
                string pass = Console.ReadLine();

                Console.WriteLine("Enter Re-Password: ");
                string repass = Console.ReadLine();

                Console.WriteLine("Enter your Gender: ");
                string gen = Console.ReadLine();

                Console.WriteLine("Enter your Course: ");
                string course = Console.ReadLine();

                Console.WriteLine("Enter your Country: ");
                string coun = Console.ReadLine();

                string insQuery = "insert into tbl_registration" +
                                    "values(@ID, @Username, @Password, @Repassword, @Gender, @Course, @Country)";

                SqlCommand sc = new SqlCommand(insQuery, conn);

                sc.Parameters.AddWithValue("ID", id);
                sc.Parameters.AddWithValue("Username", uname);
                sc.Parameters.AddWithValue("Password", pass);
                sc.Parameters.AddWithValue("Repassword", repass);
                sc.Parameters.AddWithValue("Gender", gen);
                sc.Parameters.AddWithValue("Course", course);
                sc.Parameters.AddWithValue("Country", coun);

                int res = sc.ExecuteNonQuery();

                if(res > 0)
                {
                    Console.WriteLine(res + " data inserted");
                }
                conn.Close();
            }

            catch (SqlException s)
            {
                Console.WriteLine(s);
            }
        }
        
        public void updateData()
        {
            try
            {
                string cs = "Data Source=DESKTOP-7322JPE\\RAUNAK;Initial Catalog=Info;Integrated Security=true;";
                SqlConnection conn = new SqlConnection(cs);
                conn.Open();

                Console.WriteLine("Enter ID of person for which you want to update record");
                string upid = Console.ReadLine();
                Console.WriteLine("Enter new Username");
                string upname = Console.ReadLine();
                Console.WriteLine("Enter new Course");
                string upcourse = Console.ReadLine();

                string upQuery = "update tbl_registration set Username=@Username, Course = @Course where id=@id";
                SqlCommand sc = new SqlCommand(upQuery, conn);
                sc.Parameters.AddWithValue("@username", upname);
                sc.Parameters.AddWithValue("@faculty", upcourse);
                sc.Parameters.AddWithValue("@id", upid);

                int res = sc.ExecuteNonQuery();
                if (res > 0)
                {
                    Console.WriteLine(res + " data updated");
                }
            }
            catch (SqlException s) {
                Console.WriteLine(s);
            }
        }

        public void displayData()
        {
            try
            {
                string cs = "Data Source=DESKTOP-7322JPE\\RAUNAK;Initial Catalog=Info;Integrated Security=true;";
                SqlConnection conn = new SqlConnection(cs);
                conn.Open();

                string disQuery = "select * from tbl_registration";
                SqlCommand sc = new SqlCommand(disQuery, conn);
                SqlDataReader sd = sc.ExecuteReader();

                while (sd.Read())
                {
                    Console.WriteLine("ID: " + sd["ID"]);
                    Console.WriteLine("Username: " + sd["Username"]);
                    Console.WriteLine("Password: " + sd["Password"]);
                    Console.WriteLine("Repassword: " + sd["Repassword"]);
                    Console.WriteLine("Gender: " + sd["Gender"]);
                    Console.WriteLine("Course: " + sd["Course"]);
                    Console.WriteLine("Country: " + sd["Country"]);
                    Console.WriteLine("--------------------------------");
                }
            }

            catch (Exception s) {
                Console.WriteLine(s);
            }
        }
        
    }

    public class Program
    {
        static void Main(string[] args)
        {
            Crud ce = new Crud();
            ce.createTable();
            //ce.insertData();
            //ce.deleteData();
            //ce.updateData();
            //ce.displayData();
        }
    }
    
}
