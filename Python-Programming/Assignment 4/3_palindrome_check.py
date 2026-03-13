# Program 3: Check if a given string is a palindrome

string = input("Enter a string: ")

# Reverse the string and compare (ignore case)
if string.lower() == string[::-1].lower():
    print(f'"{string}" is a Palindrome.')
else:
    print(f'"{string}" is NOT a Palindrome.')

# -----------------------------------------------
# Sample Output 1:
# Enter a string: madam
# "madam" is a Palindrome.
#
# Sample Output 2:
# Enter a string: python
# "python" is NOT a Palindrome.
# -----------------------------------------------
