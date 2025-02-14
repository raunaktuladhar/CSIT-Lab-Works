using Microsoft.AspNetCore.Mvc;
using Qno1.Models;
using System.Collections.Generic;

namespace Qno1.Controllers
{
    public class StudentController : Controller
    {
        public IActionResult Index()
        {
            var students = new List<Student>
            {
                new Student { Id = 1, Name = "Raunak", Age = 21, Gender = "Male", Department = "CSIT" },
                new Student { Id = 2, Name = "Bigyan", Age = 20, Gender = "Male", Department = "BCA" },
                new Student { Id = 3, Name = "Swosti", Age = 19, Gender = "Male", Department = "BIT" }
            };

            return View(students);
        }
    }
}
