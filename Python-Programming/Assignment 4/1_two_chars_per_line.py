# Program 1: Traverse a string and print two characters per line

string = input("Enter a string: ")

for i in range(0, len(string), 2):
    print(string[i : i + 2])

# -----------------------------------------------
# Sample Output:
# Enter a string: PYTHON
# PY
# TH
# ON
# -----------------------------------------------
