using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Practical1
{
    class Number
    {
        // Instance variables
        private int x;
        private int y;

        // Default constructor (sets x and y to 0)
        public Number()
        {
            x = 0;
            y = 0;
        }

        // Parameterized constructor (sets x and y to specific values)
        public Number(int xValue, int yValue)
        {
            x = xValue;
            y = yValue;
        }

        // Method to find and display even numbers between x and y
        public void FindEven()
        {
            Console.WriteLine($"Even numbers between {x} and {y}:");
            for (int i = x; i <= y; i++)
            {
                if (i % 2 == 0)
                {
                    Console.Write(i + " ");
                }
            }
            Console.WriteLine(); // To move to the next line after displaying results
        }

        // Method to find and display odd numbers between x and y
        public void FindOdd()
        {
            Console.WriteLine($"Odd numbers between {x} and {y}:");
            for (int i = x; i <= y; i++)
            {
                if (i % 2 != 0)
                {
                    Console.Write(i + " ");
                }
            }
            Console.WriteLine(); // To move to the next line after displaying results
        }
    }
}
