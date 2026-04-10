# Program to read data from a file

def read_file_data(filename):
    try:
        with open(filename, 'r') as file:
            data = file.read()
            print("Content of the file:")
            print("-----------------------")
            print(data)
            print("-----------------------")
    except FileNotFoundError:
        print(f"Error: The file '{filename}' was not found.")

if __name__ == "__main__":
    read_file_data("practice_data.txt")

"""
EXPECTED OUTPUT:
Content of the file:
-----------------------
Python Programming Assignment.
This file is used for practice tasks.
Task 2 involves reading this content.

-----------------------
"""
