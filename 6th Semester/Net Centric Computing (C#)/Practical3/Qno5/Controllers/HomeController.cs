using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Qno5.Models;

namespace Qno5.Controllers
{
    public class HomeController : Controller
    {
        // GET: Home
        public IActionResult Index()
        {
            // Get values from cookies and query string if available
            string cookieValue = Request.Cookies["UserInfo"];
            string queryStringValue = Request.Query["user"];
            string hiddenFieldValue = TempData["HiddenField"]?.ToString();

            var model = new StateModel
            {
                Name = cookieValue ?? queryStringValue ?? hiddenFieldValue ?? "No Data"
            };

            return View(model);
        }

        // POST: Home
        [HttpPost]
        public IActionResult Index(string name, string age, string source)
        {
            // Store data in the requested state management mechanism
            if (source == "cookie")
            {
                // Save data to a cookie
                Response.Cookies.Append("UserInfo", name);
            }
            else if (source == "queryString")
            {
                // Redirect with query string
                return RedirectToAction("Index", new { user = name });
            }
            else if (source == "hiddenField")
            {
                // Store data in TempData (used for hidden fields in the form)
                TempData["HiddenField"] = name;
            }

            // Pass the model to the view with the data
            var model = new StateModel { Name = name, Age = age };
            return View(model);
        }
    }
}