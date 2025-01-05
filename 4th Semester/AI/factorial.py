def fact(x):
    if x == 1:
        return 1
    
    elif x < 0:
        print("Invalid number!")

    else:
        return x * fact(x-1)


n = int(input("Enter a number to find its factorial: "))

result = fact(n)
print("The factorial of", n, "is", result)
