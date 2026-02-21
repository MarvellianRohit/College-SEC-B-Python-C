# 4. Write a program to input a single digit(n) and print a 3 digit number created as <n(n+1)(n+2)> e.g., if you input 7, then it should print 789. Assume that the input digit is in range 1-7.

# Start a try block to handle potential errors if the user enters non-numeric input
try:
    # Prompt the user to enter a single digit, convert it to an integer, and store it in 'n'
    n = int(input("Enter a single digit (1-7): "))

    # Check if the entered integer 'n' is within the valid range of 1 to 7 inclusive
    if 1 <= n <= 7:
        # Assign the value of 'n' to 'n1'
        n1 = n
        # Calculate the next number by adding 1 to 'n' and store it in 'n2'
        n2 = n + 1
        # Calculate the number after that by adding 2 to 'n' and store it in 'n3'
        n3 = n + 2
        # Use an f-string to concatenate n1, n2, and n3 and print them side-by-side as a 3-digit number
        print(f"{n1}{n2}{n3}")
    else:
        # If the number is outside the 1-7 range, print an error message
        print("Invalid input. Please enter a digit between 1 and 7.")
# Catch a ValueError exception, which occurs if int() fails (e.g., user enters text instead of a number)
except ValueError:
    # Print a user-friendly error message indicating that a valid number should be entered
    print("Invalid input. Please enter a valid number.")
