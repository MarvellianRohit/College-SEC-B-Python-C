# 6. Write a Python program to input 3 numbers and check all are same or not.

# Use a try block to handle cases where the user inputs letters or symbols instead of numbers
try:
    # Prompt user for the first number, convert to float (handles decimals), and store in 'num1'
    num1 = float(input("Enter the first number: "))
    # Prompt user for the second number, convert to float, and store in 'num2'
    num2 = float(input("Enter the second number: "))
    # Prompt user for the third number, convert to float, and store in 'num3'
    num3 = float(input("Enter the third number: "))

    # Check if 'num1' is equal to 'num2' AND 'num2' is equal to 'num3' simultaneously
    if num1 == num2 == num3:
        # If all comparisons are true, print that the numbers are the same
        print("All three numbers are the same.")
    else:
        # If any comparison is false, print that the numbers are not all the same
        print("The numbers are not all the same.")
# Catch a ValueError, which happens if a float conversion fails (like entering "abc")
except ValueError:
    # Print an error message asking the user to enter valid numeric values
    print("Invalid input. Please enter valid numbers.")
