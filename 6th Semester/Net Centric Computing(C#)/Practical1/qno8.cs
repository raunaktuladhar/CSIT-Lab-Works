using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Practical1
{
    class Box
    {
        int length;
        int breadth;
        int height;

        public Box(int length, int breadth, int height)
        {
            this.length = length;
            this.breadth = breadth;
            this.height = height;
        }

        public void getVol()
        {
            Console.WriteLine("The Volume of box is " + (length * breadth * height));
        }
    }

    class SmallBox : Box
    {
        int weight;

        public SmallBox(int length, int breadth, int height, int weight) : base(length, breadth, height)
        {
            this.weight = weight;
        }

        public int getWeight()
        {
            return weight;
        }
    }
}
