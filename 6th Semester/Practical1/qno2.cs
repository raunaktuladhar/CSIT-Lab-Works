using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Practical1
{
    class Calculator
    {
        // Overloaded method for adding two integers
        public int Add(int a, int b)
        {
            return a + b;
        }

        // Overloaded method for adding three integers
        public int Add(int a, int b, int c)
        {
            return a + b + c;
        }

        // Overloaded method for adding two double values
        public double Add(double a, double b)
        {
            return a + b;
        }
    }
}
