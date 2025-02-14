using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Practical1
{
    class Car
    {
        // Properties (Encapsulation)
        public string Make { get; set; }
        public string Model { get; set; }
        public int Year { get; set; }

        // Constructor (Initialization)
        public Car(string make, string model, int year)
        {
            Make = make;
            Model = model;
            Year = year;
        }

        // Method (Functionality)
        public void StartEngine()
        {
            Console.WriteLine("The engine of the " + Make + " " + Model + " has started.");
        }

        public void DisplayCarInfo()
        {
            Console.WriteLine($"Car Information: {Year} {Make} {Model}");
        }
    }
}
