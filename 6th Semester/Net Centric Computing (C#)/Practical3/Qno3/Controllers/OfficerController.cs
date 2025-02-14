using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using Qno3.Models;

namespace Qno3.Controllers
{
    public class OfficerController : Controller
    {
        private readonly AppDbContext _context;

        public OfficerController(AppDbContext context)
        {
            _context = context;
        }

        public async Task<IActionResult> Index()
        {
            var officers = await _context.Officers.ToListAsync();
            return View(officers);
        }

        [HttpPost]
        public async Task<IActionResult> Create(Officer officer)
        {
            if (ModelState.IsValid)
            {
                _context.Officers.Add(officer);
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Index));
            }
            return View("Index", await _context.Officers.ToListAsync());
        }

        [HttpPost]
        public async Task<IActionResult> Update(Officer officer)
        {
            if (ModelState.IsValid)
            {
                var existingOfficer = await _context.Officers.FindAsync(officer.Id);
                if (existingOfficer == null)
                {
                    return NotFound();
                }

                // Update the properties
                existingOfficer.Name = officer.Name;
                existingOfficer.Gender = officer.Gender;
                existingOfficer.Phone = officer.Phone;
                existingOfficer.Department = officer.Department;
                existingOfficer.Position = officer.Position;

                // Save changes to the database
                await _context.SaveChangesAsync();

                return RedirectToAction(nameof(Index));
            }

            // Return the view with validation errors
            return View("Index", await _context.Officers.ToListAsync());
        }


        [HttpPost]
        public async Task<IActionResult> Delete(int id)
        {
            var officer = await _context.Officers.FindAsync(id);
            if (officer != null)
            {
                _context.Officers.Remove(officer);
                await _context.SaveChangesAsync();
            }
            return RedirectToAction(nameof(Index));
        }

        // GET: Officer/Edit/{id}
        public async Task<IActionResult> Edit(int id)
        {
            var officer = await _context.Officers.FindAsync(id);
            if (officer == null)
            {
                return NotFound();
            }
            return View(officer);
        }

        // POST: Officer/Edit
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Edit(Officer officer)
        {
            if (ModelState.IsValid)
            {
                var existingOfficer = await _context.Officers.FindAsync(officer.Id);
                if (existingOfficer == null)
                {
                    return NotFound();
                }

                // Update properties
                existingOfficer.Name = officer.Name;
                existingOfficer.Gender = officer.Gender;
                existingOfficer.Phone = officer.Phone;
                existingOfficer.Department = officer.Department;
                existingOfficer.Position = officer.Position;

                // Save changes
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Index));
            }

            return View(officer); // Return view with validation errors
        }

    }
}