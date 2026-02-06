# Q3: Write a python program to find the ASCII Value of entered character.

ch = input("Enter a character: ")

# Check if the user entered exactly one character
if len(ch) == 1:
    print(f"The ASCII value of '{ch}' is {ord(ch)}")
else:
    print("Please enter exactly one character.")
