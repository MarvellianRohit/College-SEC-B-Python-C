# Program to read a file line by line

def read_file_line_by_line(filename):
    try:
        print(f"Reading '{filename}' line by line:")
        print("-----------------------")
        with open(filename, 'r') as file:
            line_count = 1
            for line in file:
                # Using strip() to remove trailing newline characters
                print(f"Line {line_count}: {line.strip()}")
                line_count += 1
        print("-----------------------")
    except FileNotFoundError:
        print(f"Error: The file '{filename}' was not found.")

if __name__ == "__main__":
    read_file_line_by_line("practice_data.txt")

"""
EXPECTED OUTPUT:
Reading 'practice_data.txt' line by line:
-----------------------
Line 1: Python Programming Assignment.
Line 2: This file is used for practice tasks.
Line 3: Task 2 involves reading this content.
Line 4: Appending a new line to the file.
Line 5: File handling is an essential skill.
-----------------------
"""
