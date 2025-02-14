using Microsoft.AspNetCore.Authentication;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using System.Security.Claims;

namespace Qno7.Controllers
{
    public class HomeController : Controller
    {
        [HttpGet]
        public IActionResult Index()
        {
            return View();
        }

        [HttpPost]
        public IActionResult Login(string username, string password)
        {
            if (username == "admin" && password == "password")
            {
                var claims = new List<Claim>
                {
                    new Claim(ClaimTypes.Name, username),
                    new Claim(ClaimTypes.Role, "Admin"),
                    new Claim("CanViewPage", "true")
                };

                var identity = new ClaimsIdentity(claims, "Login");
                var principal = new ClaimsPrincipal(identity);
                HttpContext.SignInAsync(principal);

                return RedirectToAction("Protected");
            }
            else if (username == "user" && password == "password")
            {
                var claims = new List<Claim>
                {
                    new Claim(ClaimTypes.Name, username),
                    new Claim(ClaimTypes.Role, "User"),
                    new Claim("CanViewPage", "true")
                };

                var identity = new ClaimsIdentity(claims, "Login");
                var principal = new ClaimsPrincipal(identity);
                HttpContext.SignInAsync(principal);

                return RedirectToAction("Protected");
            }

            ViewBag.Message = "Invalid username or password";
            return View("Index");
        }

        [Authorize(Policy = "AdminPolicy")]
        public IActionResult Admin()
        {
            return Content("Welcome, Admin! This page is protected.");
        }

        [Authorize(Policy = "UserPolicy")]
        public IActionResult Protected()
        {
            return Content("Welcome to the protected page!");
        }

        public IActionResult Logout()
        {
            HttpContext.SignOutAsync();
            return RedirectToAction("Index");
        }
    }
}