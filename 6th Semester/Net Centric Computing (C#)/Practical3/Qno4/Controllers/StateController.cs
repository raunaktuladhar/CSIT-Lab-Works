using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;

namespace Qno4.Controllers
{
    public class StateController : Controller
    {
        [HttpGet]
        public IActionResult Index()
        {
            // Retrieve previously set state values
            ViewBag.SessionValue = HttpContext.Session.GetString("SessionKey");
            ViewBag.TempDataValue = TempData["TempDataKey"];
            HttpContext.Request.Cookies.TryGetValue("CookieKey", out string cookieValue);
            ViewBag.CookieValue = cookieValue;

            return View();
        }

        [HttpPost]
        public IActionResult Index(string sessionValue, string tempDataValue, string cookieValue)
        {
            // Set values entered by the user into Session, TempData, and Cookies

            // Session Example
            HttpContext.Session.SetString("SessionKey", sessionValue);

            // TempData Example
            TempData["TempDataKey"] = tempDataValue;

            // Cookie Example
            HttpContext.Response.Cookies.Append("CookieKey", cookieValue);

            // Redirect to ensure the state values are displayed after posting
            return RedirectToAction("Index");
        }
    }
}