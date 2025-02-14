using System;
using System.Runtime.InteropServices;

namespace Practical1
{
    class Calculation
    {
        public virtual void solve1()
        {
            Console.WriteLine("method of superclass");
        }
        public virtual void solve2(int x, int y)
        {
            Console.WriteLine("sum is " + (x + y));
        }
    }
    class Solution : Calculation
    {
        public override void solve1()
        {
            //calling super class overriden method
            base.solve1();
            Console.WriteLine("method of subclass");
        }
        public override void solve2(int x, int y)
        {
            base.solve2(x, y);
            Console.WriteLine("diff is " + (x - y));
        }
    }

}
