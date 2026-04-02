# Examples of 'key' in Python

# 1. Dictionary Keys
# A dictionary in Python consists of key-value pairs.
student = { # Initialize a dictionary named student with key-value pairs
    "name": "Rohit", # Assign string 'Rohit' to the key 'name'
    "age": 20, # Assign integer 20 to the key 'age'
    "course": "BCA", # Assign string 'BCA' to the key 'course'
    "sem": 2 # Assign integer 2 to the key 'sem'
} 

print("--- Dictionary Keys ---") # Print a descriptive header for dictionary keys
# Accessing all keys
print("Keys:", student.keys()) # Output all keys currently in the student dictionary

# Iterating through keys
print("Iterating over keys:") # Print a header for the key iteration demonstration
for key in student: # Loop through each key present in the student dictionary
    print(f"Key: {key}, Value: {student[key]}") # Print the current key and its associated value

# Checking if a key exists
if "name" in student: # Use the 'in' keyword to check if 'name' is a key in student
    print("'name' key exists in the dictionary.") # Inform the user that the key was found

# 2. 'key' parameter in sorted() function
# The 'key' parameter allows us to customize the sorting logic.
numbers = ["apple", "banana", "cherry", "kiwi"] # Create a list of string elements

print("\n--- 'key' in sorted() ---") # Print a header for sorting with the key parameter
# Sort by length of strings using len as key
sorted_by_len = sorted(numbers, key=len) # Sort the fruits list using their length as the criteria
print("Sorted by length:", sorted_by_len) # Display the resulting list sorted by character count

# Sort case-insensitively
mixed_case = ["Banana", "apple", "Cherry", "kiwi"] # Create a list with varying capitalizations
sorted_case_insensitive = sorted(mixed_case, key=str.lower) # Sort using lowercase version for comparison
print("Sorted case-insensitive:", sorted_case_insensitive) # Output the case-insensitive sorted list

# 3. 'key' parameter in min() and max()
print("\n--- 'key' in min() and max() ---") # Print a header for min/max functions using key
# Finding the longest string
longest = max(numbers, key=len) # Identify the string with the highest character count
print("Longest string:", longest) # Print the longest word found

# Finding the shortest string
shortest = min(numbers, key=len) # Identify the string with the lowest character count
print("Shortest string:", shortest) # Print the shortest word found

# 4. 'key' in list.sort() method
print("\n--- 'key' in list.sort() ---") # Print a header for the inplace sort method with key
students = [ # Create a list of dictionaries, each representing a student
    {"name": "Alice", "marks": 85}, # Student Alice with marks 85
    {"name": "Bob", "marks": 92}, # Student Bob with marks 92
    {"name": "Charlie", "marks": 78} # Student Charlie with marks 78
] 

# Sort by marks using a lambda function as key
students.sort(key=lambda x: x["marks"], reverse=True) # Sort list in descending order by marks value
print("Students sorted by marks (descending):") # Print a header for the sorted student list
for s in students: # Iterate through each student dictionary in the sorted list
    print(s) # Print the student dictionary details

# 5. Using custom function as a key
def last_char(s): # Define a function that returns the last character of a string
    return s[-1] # Return the character located at the end of string s

words = ["python", "java", "c", "ruby"] # Create a list of programming language names
# Sort based on the last character of each word
words.sort(key=last_char) # Use the custom last_char function to determine sort order
print("\nWords sorted by last character:", words) # Output the list sorted by trailing characters

'''

Output:

--- Dictionary Keys ---
Keys: dict_keys(['name', 'age', 'course', 'sem'])
Iterating over keys:
Key: name, Value: Rohit
Key: age, Value: 20
Key: course, Value: BCA
Key: sem, Value: 2
'name' key exists in the dictionary.

--- 'key' in sorted() ---
Sorted by length: ['kiwi', 'apple', 'banana', 'cherry']
Sorted case-insensitive: ['apple', 'Banana', 'Cherry', 'kiwi']

--- 'key' in min() and max() ---
Longest string: banana
Shortest string: kiwi

--- 'key' in list.sort() ---
Students sorted by marks (descending):
{'name': 'Bob', 'marks': 92}
{'name': 'Alice', 'marks': 85}
{'name': 'Charlie', 'marks': 78}

Words sorted by last character: ['java', 'c', 'python', 'ruby']

'''
