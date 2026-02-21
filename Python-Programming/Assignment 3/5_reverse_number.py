# 5. Write a program to take a 3-digit number and then print the reversed number. That is, if you input 123, the program should print 321.

# Prompt the user to enter a 3-digit number and store it as a string in the 'num' variable
num = input("Enter a 3-digit number: ")

# Check two conditions: 1) The length of the string 'num' is exactly 3 characters, AND 2) all characters are digits
if len(num) == 3 and num.isdigit():
    # Use string slicing '::-1' to reverse the string and store the result in 'reversed_num'
    reversed_num = num[::-1]
    # Print the reversed number to the console using an f-string
    print(f"The reversed number is: {reversed_num}")
else:
    # If either of the conditions fails (not 3 digits or contains letters/symbols), print an error message
    print("Invalid input. Please enter a valid 3-digit number.")
