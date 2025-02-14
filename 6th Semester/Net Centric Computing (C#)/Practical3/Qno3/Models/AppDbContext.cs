using System.Collections.Generic;
using Microsoft.EntityFrameworkCore;
using Qno3.Models;

namespace Qno3.Models
{
    public class AppDbContext : DbContext
    {
        public AppDbContext(DbContextOptions<AppDbContext> options) : base(options) { }

        public DbSet<Officer> Officers { get; set; }
    }
}