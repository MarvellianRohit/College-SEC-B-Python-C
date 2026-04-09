# File Append Operations in Python
# Demonstrating how to use 'a' mode (Append)

# Step 1: Create an initial file with some data
filename = "append_demo.txt"
with open(filename, "w") as f:
    f.write("Initial Data: Line 1\n")
    f.write("Initial Data: Line 2\n")

print("--- Initial state of file ---")
# Read the file to see existing content
with open(filename, "r") as f:
    print(f.read())

# Step 2: Append data using 'a' mode
# In 'a' (append) mode, new data is added to the end of the file.
# The existing content is NOT deleted (unlike 'w' mode).
print("--- Appending new data ---")
with open(filename, "a") as f:
    f.write("Appended Data: Line 3\n")
    f.write("Appended Data: Line 4\n")

# Step 3: Verify the result by reading again
print("--- Final contents after appending ---")
with open(filename, "r") as f:
    print(f.read())

'''
Output:

--- Initial state of file ---
Initial Data: Line 1
Initial Data: Line 2

--- Appending new data ---
--- Final contents after appending ---
Initial Data: Line 1
Initial Data: Line 2
Appended Data: Line 3
Appended Data: Line 4
'''
