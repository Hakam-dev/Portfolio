import math

# Function for factorial
def factorial(n):
    if n < 0:
        return "Not defined for negative numbers"
    return math.factorial(n)

# Function for fibonacci
def fibonacci(n):
    sequence = []
    a, b = 0, 1

    for i in range(n):
        sequence.append(a)
        a, b = b, a + b

    return sequence


while True:
    print("\n===== SIMPLE CALCULATOR =====")
    print("1. Addition")
    print("2. Subtraction")
    print("3. Multiplication")
    print("4. Division")
    print("5. Factorial")
    print("6. Fibonacci")
    print("7. Exit")

    choice = int(input("Enter your choice: "))

    if choice == 1:
        a = float(input("Enter first number: "))
        b = float(input("Enter second number: "))
        print("Result =", a + b)

    elif choice == 2:
        a = float(input("Enter first number: "))
        b = float(input("Enter second number: "))
        print("Result =", a - b)

    elif choice == 3:
        a = float(input("Enter first number: "))
        b = float(input("Enter second number: "))
        print("Result =", a * b)

    elif choice == 4:
        a = float(input("Enter first number: "))
        b = float(input("Enter second number: "))

        if b == 0:
            print("Error: Division by zero")
        else:
            print("Result =", a / b)

    elif choice == 5:
        n = int(input("Enter a number: "))
        print("Factorial =", factorial(n))

    elif choice == 6:
        n = int(input("Enter how many Fibonacci terms: "))
        print("Fibonacci sequence =", fibonacci(n))

    elif choice == 7:
        print("Exiting calculator...")
        break

    else:
        print("Invalid choice, try again.")