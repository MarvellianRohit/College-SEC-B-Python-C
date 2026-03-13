# Program 2: Count the number of occurrences of a substring in a string

string = input("Enter the main string: ")
substring = input("Enter the substring to search: ")

count = string.count(substring)

print(f"The substring '{substring}' occurs {count} time(s) in the given string.")

# -----------------------------------------------
# Sample Output:
# Enter the main string: hello world hello
# Enter the substring to search: hello
# The substring 'hello' occurs 2 time(s) in the given string.
# -----------------------------------------------
