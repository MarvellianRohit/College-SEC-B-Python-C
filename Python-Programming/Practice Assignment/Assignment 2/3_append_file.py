# Program to append data to an existing file

def append_to_file(filename, lines):
    try:
        with open(filename, 'a') as file:
            for line in lines:
                file.write(line + "\n")
        print(f"Successfully appended {len(lines)} lines to '{filename}'.")
    except Exception as e:
        print(f"Error occurred: {e}")

def display_file_content(filename):
    print("\nUpdated content of the file:")
    print("-----------------------")
    with open(filename, 'r') as file:
        print(file.read())
    print("-----------------------")

if __name__ == "__main__":
    target_file = "practice_data.txt"
    lines_to_append = [
        "Appending a new line to the file.",
        "File handling is an essential skill."
    ]
    
    append_to_file(target_file, lines_to_append)
    display_file_content(target_file)

"""
EXPECTED OUTPUT:
Successfully appended 2 lines to 'practice_data.txt'.

Updated content of the file:
-----------------------
Python Programming Assignment.
This file is used for practice tasks.
Task 2 involves reading this content.
Appending a new line to the file.
File handling is an essential skill.

-----------------------
"""
