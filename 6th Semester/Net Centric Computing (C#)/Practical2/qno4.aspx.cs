using System;
using System.Data.SqlClient;

namespace Project2
{
    public partial class WebForm2 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            // Page load logic (if required)
        }

        // When the submit button is clicked, control will come here
        protected void btn_sub(object sender, EventArgs e)
        {
            // Extracting form fields
            string id = uid.Text;
            string username = uname.Text;
            string password = pass.Text;
            string repassword = repass.Text;

            // For radio button, checkbox, and dropdown we need validation
            string gender = "";
            if (rb1.Checked)
            {
                gender += "Male"; // or rb1.Text if you want to use the label text
            }
            else
            {
                gender += "Female"; // or rb2.Text if you want to use the label text
            }

            string faculty = "";
            if (cb1.Checked)
            {
                faculty += "CSIT ";
            }
            if (cb2.Checked)
            {
                faculty += "BIM ";
            }
            if (cb3.Checked)
            {
                faculty += "BCA ";
            }
            if (cb4.Checked)
            {
                faculty += "BBA ";
            }

            string country = "";
            if (coun.SelectedValue == "")
            {
                country = "no value";
            }
            else
            {
                country += coun.SelectedValue;
            }

            // Database connection
            try
            {
                string cs = "Data Source=DESKTOP-7322JPE\\RAUNAK;Initial Catalog=Info;Integrated Security=True";
                SqlConnection conn = new SqlConnection(cs);
                conn.Open();
                string insQuery = "insert into tbl_registration values(@ID, @Username, @Password, @Repassword, @Gender, @Course, @Country)";
                SqlCommand sc = new SqlCommand(insQuery, conn);

                // Adding parameters to prevent SQL Injection
                sc.Parameters.AddWithValue("@ID", id);
                sc.Parameters.AddWithValue("@Username", username);
                sc.Parameters.AddWithValue("@Password", password);
                sc.Parameters.AddWithValue("@Repassword", repassword);
                sc.Parameters.AddWithValue("@Gender", gender);
                sc.Parameters.AddWithValue("@Course", faculty);
                sc.Parameters.AddWithValue("@Country", country);

                int res = sc.ExecuteNonQuery();
                if (res > 0)
                {
                    Console.WriteLine("Data inserted");
                }
                
            }
            catch (SqlException s)
            {
                Console.WriteLine(s);
            }
        }
    }
}
