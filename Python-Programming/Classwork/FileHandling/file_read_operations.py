# File Reading Operations in Python
# Demonstrating read(), readline(), and readlines()

# Step 1: Create a sample file to work with
# We use 'w' mode to create and write to the file
with open("sample_read.txt", "w") as f:
    f.write("Line 1: Hello Students!\n")
    f.write("Line 2: Welcome to Python Programming.\n")
    f.write("Line 3: Today we are learning File Handling.\n")
    f.write("Line 4: This is the fourth line.\n")

print("--- 1. Using read() ---")
# read() - Reads the entire content of the file as a single string
# 'r' stands for read mode
with open("sample_read.txt", "r") as f:
    content = f.read()
    print("Full Content:\n", content)

print("\n--- 2. Using readline() ---")
# readline() - Reads a single line from the file. 
# Consecutive calls read subsequent lines.
with open("sample_read.txt", "r") as f:
    line1 = f.readline()
    print("First Line:", line1.strip()) # strip() removes the newline character (\n)
    line2 = f.readline()
    print("Second Line:", line2.strip())

print("\n--- 3. Using readlines() ---")
# readlines() - Reads all lines and returns them as a list of strings
with open("sample_read.txt", "r") as f:
    lines_list = f.readlines()
    print("Lines as a list:", lines_list)
    print("Last line from list:", lines_list[-1].strip())

'''
Output:

--- 1. Using read() ---
Full Content:
 Line 1: Hello Students!
Line 2: Welcome to Python Programming.
Line 3: Today we are learning File Handling.
Line 4: This is the fourth line.


--- 2. Using readline() ---
First Line: Line 1: Hello Students!
Second Line: Line 2: Welcome to Python Programming.

--- 3. Using readlines() ---
Lines as a list: ['Line 1: Hello Students!\n', 'Line 2: Welcome to Python Programming.\n', 'Line 3: Today we are learning File Handling.\n', 'Line 4: This is the fourth line.\n']
Last line from list: Line 4: This is the fourth line.
'''
