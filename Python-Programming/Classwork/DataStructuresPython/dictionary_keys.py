# Dictionary Keys in Python: Detailed Examples

# 1. Basic Key-Value Pair
# A dictionary uses unique keys to store and retrieve values.
user_info = { # Create a dictionary named user_info with initial profile data
    "username": "rohit_chandra", # Map the key "username" to "rohit_chandra"
    "email": "rohit@example.com", # Map the key "email" to the string email address
    "id": 101, # Map the key "id" to the integer constant 101
    "active": True # Map the key "active" to the boolean value True
} 

print("--- Accessing Values using Keys ---") # Print a header for value access examples
print(f"Username: {user_info['username']}") # Retrieve and print the value assigned to "username"
print(f"User ID: {user_info['id']}") # Retrieve and print the value assigned to "id"

# 2. Key Methods: keys(), values(), and items()
print("\n--- Dictionary Key Methods ---") # Print a header for the built-in dictionary methods
print(f"All Keys: {user_info.keys()}") # Print a view object containing all the keys in user_info
print(f"All Values: {user_info.values()}") # Print a view object containing all the values in user_info
print(f"All Items (Key-Value Pairs): {user_info.items()}") # Print a list-like view of all items (key-value tuples)

# 3. Checking for Key Existence
print("\n--- Checking for Keys ---") # Print a header for key membership demonstrations
search_key = "email" # Assign the string "email" to search_key for checking
if search_key in user_info: # Use 'in' to check if search_key exists as a key in user_info
    print(f"'{search_key}' key exists in user_info.") # Notify that the email key was found
else: # If the search_key is not found in the dictionary keys
    print(f"'{search_key}' key not found.") # Notify that the email key was missing

# Using the .get() method (safer access, returns None if key is missing)
age = user_info.get("age", "Not Available") # Safely try to get "age" or return "Not Available"
print(f"Age: {age}") # Print the result obtained through the get method

# 4. Adding and Updating Keys
print("\n--- Adding/Updating Keys ---") # Print a header for dictionary mutation examples
user_info["location"] = "Kolkata"  # Assign the value "Kolkata" to a new key "location"
user_info["active"] = False       # Update the existing key "active" to the boolean False
print(f"Updated user_info: {user_info}") # Print the dictionary after adding and updating entries

# 5. Removing Keys
print("\n--- Removing Keys ---") # Print a header for entry deletion examples
removed_value = user_info.pop("id") # Delete the "id" key and store its original value
print(f"Removed ID: {removed_value}") # Print the value that was removed using pop
del user_info["email"]             # Use the del statement to remove the "email" entry
print(f"After deletion: {user_info}") # Print the current dictionary contents after removal

# 6. Iterating through Keys
print("\n--- Iterating through Keys ---") # Print a header for dictionary iteration examples
for key in user_info: # Iterate over the keys of the dictionary by default
    print(f"Found Key: {key}") # Print each key found during the loop

# 7. Using Non-String Keys
# Keys can be any immutable type (strings, numbers, tuples)
complex_dict = { # Create a dictionary using various immutable types as keys
    10: "Integer Key", # Map an integer key 10 to a string value
    (1, 2): "Tuple Key", # Map a tuple key (1, 2) to a string value
    3.14: "Float Key" # Map a float key 3.14 to a string value
} 
print("\n--- Non-String Keys ---") # Print a header for non-string key demonstration
for k, v in complex_dict.items(): # Iterate through each key-value pair in the complex_dict
    print(f"Key: {k} ({type(k)}), Value: {v}") # Print the key, its type, and its value

'''

Output:

--- Accessing Values using Keys ---
Username: rohit_chandra
User ID: 101

--- Dictionary Key Methods ---
All Keys: dict_keys(['username', 'email', 'id', 'active'])
All Values: dict_values(['rohit_chandra', 'rohit@example.com', 101, True])
All Items (Key-Value Pairs): dict_items([('username', 'rohit_chandra'), ('email', 'rohit@example.com'), ('id', 101), ('active', True)])

--- Checking for Keys ---
'email' key exists in user_info.
Age: Not Available

--- Adding/Updating Keys ---
Updated user_info: {'username': 'rohit_chandra', 'email': 'rohit@example.com', 'id': 101, 'active': False, 'location': 'Kolkata'}

--- Removing Keys ---
Removed ID: 101
After deletion: {'username': 'rohit_chandra', 'active': False, 'location': 'Kolkata'}

--- Iterating through Keys ---
Found Key: username
Found Key: active
Found Key: location

--- Non-String Keys ---
Key: 10 (<class 'int'>), Value: Integer Key
Key: (1, 2) (<class 'tuple'>), Value: Tuple Key
Key: 3.14 (<class 'float'>), Value: Float Key

'''
