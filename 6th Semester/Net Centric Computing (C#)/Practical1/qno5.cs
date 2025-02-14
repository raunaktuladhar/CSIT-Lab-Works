using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Practical1
{
    class Shape
    {
        // Instance variables
        private int length;
        private int breadth;
        private int height;

        // Default constructor: Sets all values to zero
        public Shape()
        {
            length = 0;
            breadth = 0;
            height = 0;
        }

        // Constructor with two parameters: Sets length and breadth
        public Shape(int length, int breadth)
        {
            this.length = length;
            this.breadth = breadth;
            height = 0; // Default value for height
        }

        // Constructor with three parameters: Sets length, breadth, and height
        public Shape(int length, int breadth, int height)
        {
            this.length = length;
            this.breadth = breadth;
            this.height = height;
        }

        // Method to calculate the area of the rectangle
        public void calcAreaRectangle()
        {
            int area = length * breadth;
            Console.WriteLine($"Area of the rectangle (length: {length}, breadth: {breadth}) is: {area}");
        }

        // Method to calculate the volume of the box
        public void calcVolumeBox()
        {
            int volume = length * breadth * height;
            Console.WriteLine($"Volume of the box (length: {length}, breadth: {breadth}, height: {height}) is: {volume}");
        }
    }
}
