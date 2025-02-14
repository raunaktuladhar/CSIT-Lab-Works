using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Practical1
{
    class Animal
    {
        public void Speak()
        {
            Console.WriteLine("Animal speaks");
        }
    }

    // Single Level Inheritance
    // Derived class from Animal
    class Dog : Animal
    {
        public void Bark()
        {
            Console.WriteLine("Dog barks");
        }
    }

    // Multilevel Inheritance
    // Derived class from Dog (which already inherits from Animal)
    class Puppy : Dog
    {
        public void Play()
        {
            Console.WriteLine("Puppy plays");
        }
    }

}
