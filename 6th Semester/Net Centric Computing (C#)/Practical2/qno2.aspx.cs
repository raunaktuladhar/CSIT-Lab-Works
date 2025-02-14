using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Project2
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void btn_add_click(object sender, EventArgs e)
        {
            if (ValidateInput(out int firstNumber, out int secondNumber))
            {
                out1.Text = (firstNumber + secondNumber).ToString();
            }
        }

        protected void btn_sub_click(object sender, EventArgs e)
        {
            if (ValidateInput(out int firstNumber, out int secondNumber))
            {
                out1.Text = (firstNumber - secondNumber).ToString();
            }
        }

        protected void btn_prime_click(object sender, EventArgs e)
        {
            if (ValidateInput(out int firstNumber, out int secondNumber))
            {
                StringBuilder primes = new StringBuilder();
                for (int i = secondNumber; i <= firstNumber; i++)
                {
                    if (IsPrime(i))
                    {
                        primes.Append(i + " ");
                    }
                }
                out1.Text = primes.ToString();
            }
        }

        private bool ValidateInput(out int firstNumber, out int secondNumber)
        {
            out1.Text = ""; // Clear previous result
            if (!int.TryParse(inp1.Text, out firstNumber))
            {
                out1.Text = "Invalid input for the first number.";
                secondNumber = 0;
                return false;
            }
            if (!int.TryParse(inp2.Text, out secondNumber))
            {
                out1.Text = "Invalid input for the second number.";
                return false;
            }
            if (firstNumber <= secondNumber)
            {
                out1.Text = "First number must be greater than the second number.";
                return false;
            }
            return true;
        }

        private bool IsPrime(int number)
        {
            if (number < 2) return false;
            for (int i = 2; i <= Math.Sqrt(number); i++)
            {
                if (number % i == 0)
                    return false;
            }
            return true;
        }
    }
}