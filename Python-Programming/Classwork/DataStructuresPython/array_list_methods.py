# Array (List) Methods in Python

# In Python, lists are commonly used as arrays for storing multiple items.
my_list = [10, 20, 30, 40, 50, 20] # Create a list (array) of integers with a duplicate value
print("Original List:", my_list) # Print the initial state of the list

# 1. append() - Adds an element to the end of the list
my_list.append(60) # Add the number 60 to the very end of the list
print("After append(60):", my_list) # Print the list after appending 60

# 2. insert() - Adds an element at a specific position
my_list.insert(2, 25) # Insert the number 25 at index position 2
print("After insert(2, 25):", my_list) # Print the list after the insertion

# 3. extend() - Adds all elements from another list to the current list
my_list.extend([70, 80]) # Connect another list of [70, 80] to the end of the current list
print("After extend([70, 80]):", my_list) # Print the list after extension

# 4. remove() - Removes the first occurrence of a specific value
my_list.remove(20) # Find and remove the first instance of number 20 from the list
print("After remove(20):", my_list) # Print the list after removing the first 20

# 5. pop() - Removes and returns an item at a given index (default is last)
removed_item = my_list.pop() # Remove the very last item from the list and store it in a variable
print(f"Popped item (last): {removed_item}") # Print the item that was just removed
print("After pop():", my_list) # Print the list after popping the last element

# 6. pop(index) - You can also pop from a specific index
middle_item = my_list.pop(1) # Remove the item at index 1 (the second element)
print(f"Popped item at index 1: {middle_item}") # Print the removed middle element
print("After pop(1):", my_list) # Print the current list state

# 7. index() - Returns the first index of a value
pos_of_50 = my_list.index(50) # Locate the position of number 50 and save its index
print("Index of 50:", pos_of_50) # Print the index where 50 is located

# 8. count() - Returns the number of times a value appears
count_of_20 = my_list.count(20) # Count how many times 20 still remains in the list
print("Count of 20:", count_of_20) # Print the resulting frequency count

# 9. sort() - Sorts the list in ascending order
my_list.sort() # Rearrange all elements in the list from smallest to largest
print("After sort():", my_list) # Print the sorted list

# 10. reverse() - Reverses the order of the list
my_list.reverse() # Flip the entire list so that it points from end to beginning
print("After reverse():", my_list) # Print the reversed list

# 11. copy() - Returns a shallow copy of the list
new_list = my_list.copy() # Create an independent copy of the list for safe modifications
print("Copied List:", new_list) # Print the new copied list to verify

# 12. clear() - Removes all elements from the list
my_list.clear() # Delete every single element currently inside my_list
print("After clear():", my_list) # Print the empty list to show it's cleared

'''

Output:

Original List: [10, 20, 30, 40, 50, 20]
After append(60): [10, 20, 30, 40, 50, 20, 60]
After insert(2, 25): [10, 20, 25, 30, 40, 50, 20, 60]
After extend([70, 80]): [10, 20, 25, 30, 40, 50, 20, 60, 70, 80]
After remove(20): [10, 25, 30, 40, 50, 20, 60, 70, 80]
Popped item (last): 80
After pop(): [10, 25, 30, 40, 50, 20, 60, 70]
Popped item at index 1: 25
After pop(1): [10, 30, 40, 50, 20, 60, 70]
Index of 50: 3
Count of 20: 1
After sort(): [10, 20, 30, 40, 50, 60, 70]
After reverse(): [70, 60, 50, 40, 30, 20, 10]
Copied List: [70, 60, 50, 40, 30, 20, 10]
After clear(): []

'''
