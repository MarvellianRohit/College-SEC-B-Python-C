# Tuple Built-in Methods and Operations

my_tuple = (1, 2, 3, 2, 4, 5, 2) # Create a tuple with some duplicate elements
print("Original Tuple:", my_tuple) # Print the initial tuple to the console

# 1. count() - Returns the number of times a value appears
count_of_twos = my_tuple.count(2) # Count how many times the number 2 appears in the tuple
print("Count of 2s:", count_of_twos) # Print the count of number 2

# 2. index() - Returns the index of the first occurrence of a value
first_index_of_two = my_tuple.index(2) # Find the first position (index) where 2 occurs
print("First index of 2:", first_index_of_two) # Print the index of the first occurrence of 2

# 3. len() - Returns the total number of items
total_items = len(my_tuple) # Calculate the total number of elements in the tuple
print("Total Items:", total_items) # Print the length of the tuple

# 4. Accessing elements by index
third_element = my_tuple[2] # Access the element at index 2 (the third item)
print("Element at index 2:", third_element) # Print the accessed element

# 5. Slicing
sub_tuple = my_tuple[1:4] # Get elements from index 1 up to (but not including) index 4
print("Slice [1:4]:", sub_tuple) # Print the sliced portion of the tuple

# 6. Membership Test
is_present = 5 in my_tuple # Check if the number 5 exists within the tuple
print("Is 5 in the tuple?", is_present) # Print the result of the membership check

# 7. Concatenation
another_tuple = (10, 20) # Create another small tuple
combined_tuple = my_tuple + another_tuple # Combine the two tuples into a new one
print("Combined Tuple:", combined_tuple) # Print the result of merging the tuples

# 8. Repetition
repeated_tuple = another_tuple * 3 # Repeat the small tuple three times
print("Repeated Tuple:", repeated_tuple) # Print the tuple after repetition

'''

Output:

Original Tuple: (1, 2, 3, 2, 4, 5, 2)
Count of 2s: 3
First index of 2: 1
Total Items: 7
Element at index 2: 3
Slice [1:4]: (2, 3, 2)
Is 5 in the tuple? True
Combined Tuple: (1, 2, 3, 2, 4, 5, 2, 10, 20)
Repeated Tuple: (10, 20, 10, 20, 10, 20)

'''
