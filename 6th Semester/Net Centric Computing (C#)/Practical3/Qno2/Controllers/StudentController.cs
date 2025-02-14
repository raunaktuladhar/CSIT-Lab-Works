using Microsoft.AspNetCore.Mvc;
using Qno2.Models;
using System.Collections.Generic;

namespace Qno2.Controllers
{
    public class StudentController : Controller
    {
        public IActionResult Index()
        {
            var students = new List<Student>
            {
                new Student { Id = 1, Name = "Raunak", Department = "CSIT" },
                new Student { Id = 2, Name = "Shrisha", Department = "BIT" },
                new Student { Id = 3, Name = "Binay", Department = "BIM" }
            };

            return View(students);
        }
    }
}