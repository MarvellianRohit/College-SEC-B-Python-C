# Tuple in Python: Easy Examples

# 1. Creating a Tuple
# A tuple is a collection which is ordered and unchangeable (immutable).
fruits = ("apple", "banana", "cherry", "apple") # Create a tuple named fruits with several items

print("--- Tuple Creation ---") # Print a header for the tuple creation section
print(f"Tuple of fruits: {fruits}") # Output the entire contents of the fruits tuple

# 2. Accessing Items
print("\n--- Accessing Elements ---") # Print a header for the tuple indexing examples
print(f"First fruit: {fruits[0]}") # Access and print the first element at index 0
print(f"Last fruit: {fruits[-1]}") # Access and print the very last element using -1 index

# 3. Immutability Explained
# Unlike lists, you cannot change a tuple after it is created.
# This line would raise an error: fruits[0] = "kiwi"
print("\nNote: Tuples are immutable, meaning you cannot change their elements.") # Explain that tuples are constant

# 4. Tuple Methods: count() and index()
print("\n--- Tuple Methods ---") # Print a header for common tuple method demonstrations
apple_count = fruits.count("apple") # Use count() to find how many times "apple" is in the tuple
banana_index = fruits.index("banana") # Use index() to find the first occurrence of "banana"

print(f"Number of 'apple' in tuple: {apple_count}") # Print the quantity of apples found
print(f"Index of 'banana': {banana_index}") # Print the location of the banana item

# 5. Iterating through a Tuple
print("\n--- Iterating through Tuple ---") # Print a header for the tuple traversal section
for fruit in fruits: # Loop over every item in the fruits tuple
    print(f"Fruit: {fruit}") # Print each individual fruit name during iteration

# 6. Length of a Tuple
print(f"\nTotal number of items in tuple: {len(fruits)}") # Print the total count of items using len()

'''

Output:

--- Tuple Creation ---
Tuple of fruits: ('apple', 'banana', 'cherry', 'apple')

--- Accessing Elements ---
First fruit: apple
Last fruit: apple

Note: Tuples are immutable, meaning you cannot change their elements.

--- Tuple Methods ---
Number of 'apple' in tuple: 2
Index of 'banana': 1

--- Iterating through Tuple ---
Fruit: apple
Fruit: banana
Fruit: cherry
Fruit: apple

Total number of items in tuple: 4

'''
