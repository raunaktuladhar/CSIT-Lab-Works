def toh(disks, source, auxiliary, target):
    if disks == 1:
        print("Move disk 1 from rod {} to rod {}." .format(source, target))
        return
    
    toh(disks - 1, source, target, auxiliary)
    print("Move disk {} from rod {} to rod {}." .format(disks, source, target))
    toh(disks - 1, auxiliary, source, target)

disks = int(input("Enter the number of disks: "))
toh(disks, 'A', 'B', 'C')