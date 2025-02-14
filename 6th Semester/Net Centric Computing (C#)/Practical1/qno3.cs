using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Practical1
{
    class Calculate
    {
        // Data members (fields)
        private int num1;
        private int num2;

        // Method to set the values of num1 and num2
        public void SetCalc(int n1, int n2)
        {
            num1 = n1;
            num2 = n2;
        }

        // Method to calculate the sum of num1 and num2 and display the result
        public void CalcSum()
        {
            int sum = num1 + num2;
            Console.WriteLine($"Sum of {num1} and {num2} is: {sum}");
        }

        // Method to calculate the multiplication of num1 and num2 and return the result
        public int CalcMulti()
        {
            return num1 * num2;
        }

        // Method to calculate the difference between num1 and num2 and display the result
        public void CalcDifference()
        {
            int difference = num1 - num2;
            Console.WriteLine($"Difference between {num1} and {num2} is: {difference}");
        }
    }
}
