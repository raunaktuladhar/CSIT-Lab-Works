using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Practical1
{
    public class EmployeeDetails
    {
        // Data members
        protected int empId;
        protected string empName;
        protected string empGender;
        protected string empAddress;
        protected string empPosition;

        // Constructor to set the employee details
        public EmployeeDetails(int id, string name, string gender, string address, string position)
        {
            empId = id;
            empName = name;
            empGender = gender;
            empAddress = address;
            empPosition = position;
        }

        // Method to display the employee details
        public void DisplayEmployeeDetails()
        {
            Console.WriteLine("Employee ID: " + empId);
            Console.WriteLine("Employee Name: " + empName);
            Console.WriteLine("Employee Gender: " + empGender);
            Console.WriteLine("Employee Address: " + empAddress);
            Console.WriteLine("Employee Position: " + empPosition);
        }
    }

    // Subclass SalaryInfo inheriting from EmployeeDetails
    public class SalaryInfo : EmployeeDetails
    {
        // Data member for salary
        private double salary;

        // Constructor to set the salary value along with employee details
        public SalaryInfo(int id, string name, string gender, string address, string position, double salary)
            : base(id, name, gender, address, position)
        {
            this.salary = salary;
        }

        // Method to calculate the tax and final salary after tax
        public void CalcTax()
        {
            double taxRate = 0.0;
            double taxAmount = 0.0;
            double finalSalary = salary;

            // Determine the tax rate based on the salary
            if (salary <= 400000)
            {
                taxRate = 0.01; // 1% tax
            }
            else if (salary > 400000 && salary <= 800000)
            {
                taxRate = 0.10; // 10% tax
            }
            else
            {
                taxRate = 0.20; // 20% tax
            }

            // Calculate the tax amount
            taxAmount = salary * taxRate;

            // Subtract tax from salary to get the final salary
            finalSalary = salary - taxAmount;

            // Display tax and final salary
            Console.WriteLine($"Salary: {salary:C}");
            Console.WriteLine($"Tax Deducted: {taxAmount:C}");
            Console.WriteLine($"Final Salary after Tax: {finalSalary:C}");
        }
    }


}
