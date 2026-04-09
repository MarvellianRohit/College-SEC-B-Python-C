# File Management Operations in Python
# Demonstrating os.remove() and how to "remove" specific content from a file

import os

# --- 1. Deleting a File (os.remove) ---
print("--- 1. File Deletion ---")
temp_file = "to_be_deleted.txt"

# Create a dummy file for the demonstration
with open(temp_file, "w") as f:
    f.write("This file will be deleted shortly.")

# Check if file exists using os.path.exists
print(f"File '{temp_file}' exists before deletion: {os.path.exists(temp_file)}")

# Now delete the file from the system
os.remove(temp_file)
print(f"File '{temp_file}' exists after deletion: {os.path.exists(temp_file)}")


# --- 2. Removing a specific line from a file ---
# Note: Python doesn't have a direct 'removeLine()' function for files.
# The standard way is to read everything, skip the unwanted line, and write back.
print("\n--- 2. Removing Content (Line Filtering) ---")

data_file = "data_cleanup.txt"
# Setting up our sample data
with open(data_file, "w") as f:
    f.write("Line A: Keep this.\n")
    f.write("Line B: REMOVE THIS.\n")
    f.write("Line C: Keep this too.\n")

print("Original Data in File:")
with open(data_file, "r") as f:
    print(f.read())

# Step A: Read all lines into a list
with open(data_file, "r") as f:
    lines = f.readlines()

# Step B: Write back everything EXCEPT the line we want to remove
with open(data_file, "w") as f:
    for line in lines:
        if "REMOVE THIS" not in line:
            f.write(line)

print("Updated Data after removal:")
with open(data_file, "r") as f:
    print(f.read())

# Clean up the data file if needed (optional)
# os.remove(data_file) 

'''
Output:

--- 1. File Deletion ---
File 'to_be_deleted.txt' exists before deletion: True
File 'to_be_deleted.txt' exists after deletion: False

--- 2. Removing Content (Line Filtering) ---
Original Data in File:
Line A: Keep this.
Line B: REMOVE THIS.
Line C: Keep this too.

Updated Data after removal:
Line A: Keep this.
Line C: Keep this too.
'''
