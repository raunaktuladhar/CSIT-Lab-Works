using Microsoft.AspNetCore.Mvc;

namespace Qno6.Controllers
{
    public class HomeController : Controller
    {
        // GET: Home/Index
        public IActionResult Index()
        {
            return View();
        }

        // POST: Home/Index (Dummy POST endpoint for demonstration)
        [HttpPost]
        public IActionResult Index(string name, string email)
        {
            if (string.IsNullOrEmpty(name) || string.IsNullOrEmpty(email))
            {
                ViewBag.ErrorMessage = "Please fill in all fields.";
                return View();
            }

            // Form submitted successfully
            ViewBag.SuccessMessage = "Form submitted successfully!";
            return View();
        }
    }
}