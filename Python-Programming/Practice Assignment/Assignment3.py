# Assignment 3: Secure Password Validator // Title of the assignment
# Objective: Apply logical conditions with string checking. // Description of the assignment goals

def secure_password_validator(): # Define the primary function to handle the password validation logic
    password = input("Enter a password to validate: ") # Prompt the user for a string password input and map it to the 'password' variable
    
    # Minimum length = 8 -> len() // Comment detailing the next action
    is_long_enough = len(password) >= 8 # Check if the string's length is 8 or greater, storing the boolean result in 'is_long_enough'
    
    # At least one uppercase -> upper() comparison // Comment detailing the next action
    # Logic: if password converted to upper is the same as lower, it has no casing. // Explicitly outline arbitrary edge case logic
    has_upper = any(char.isupper() for char in password) # Use generator expression to check if any individual character qualifies as an uppercase letter
    
    # At least one lowercase -> lower() comparison // Comment detailing the next action
    has_lower = any(char.islower() for char in password) # Use generator expression to evaluate if any individual character is a lowercase letter
    
    # At least one digit -> in with loop // Comment detailing the next action
    digits = "0123456789" # Define a string containing all acceptable numerical digits for cross-referencing
    has_digit = False # Initialize a flag boolean 'has_digit' setting default state to False
    for char in password: # Iterate character by character recursively across the entered password string
        if char in digits: # Check if the current iterating character is discovered somewhere within the 'digits' string
            has_digit = True # Set the flag to True because a digit was successfully identified
            break # Exit the loop early since we only needed to find at least one digit
            
    # Should NOT contain spaces -> not in // Comment detailing the next action
    has_no_spaces = " " not in password # Check if the exact space character literal is absent from the password string entirely
    
    # Validation Results & Critical Thinking Extension: Meaningful feedback // Category comment grouping output phase
    print("\n--- Password Validation Results ---") # Print a newline followed by a designated header for the validation report
    is_valid = True # Initialize a master state boolean 'is_valid' to True, which will be flipped to False if any test fails
    
    if not is_long_enough: # Evaluate if the length check failed
        print("❌ FAILED: Password must be at least 8 characters long.") # Output explicit length failure message to the user
        is_valid = False # Mark the master validation state as False
    else: # If the length check evaluates as True
        print("✅ PASSED: Minimum length requirement met.") # Output success message regarding minimum character count
        
    if not has_upper: # Evaluate if the uppercase sweep failed
        print("❌ FAILED: Password must contain at least one uppercase letter.") # Output explicit uppercase criteria failure message
        is_valid = False # Mark the master validation state as False
    else: # If the uppercase logic evaluates as True
        print("✅ PASSED: Contains uppercase letter.") # Output success message regarding uppercase integration
        
    if not has_lower: # Evaluate if the lowercase check failed
        print("❌ FAILED: Password must contain at least one lowercase letter.") # Output explicit lowercase missing message
        is_valid = False # Mark the master validation flag as False
    else: # If the lowercase logic evaluates as True
        print("✅ PASSED: Contains lowercase letter.") # Output success confirmation concerning lowercase letters
        
    if not has_digit: # Evaluate if the numeric digit scanner failed
        print("❌ FAILED: Password must contain at least one digit.") # Output explicit numeric absence message
        is_valid = False # Overwrite the master validation boolean to False
    else: # If the numeric logic test succeeds
        print("✅ PASSED: Contains digit.") # Provide affirmative response detecting numerical digit incorporation
        
    if not has_no_spaces: # Check if the "no spaces" condition specifically failed (meaning spaces exist)
        print("❌ FAILED: Password should NOT contain spaces.") # Output an explicitly rigid error regarding whitespace inclusion
        is_valid = False # Trigger the master validity boolean to resolve explicitly as False
    else: # If the space test yields True (spaces are completely absent)
        print("✅ PASSED: No spaces found.") # Relay an affirmative message confirming the lack of spacing errors
        
    if is_valid: # Check the ultimate state of the master boolean after all rigorous conditional filtering checkpoints
        print("\n🎉 Success: Your password is secure!") # Congratulate the user with an enthusiastic response given total compliance
    else: # If any singular node failed previously, causing 'is_valid' to become False
        print("\n⚠️ Warning: Your password does not meet all security criteria.") # Alert the user broadly that vulnerabilities persist within the credential string
        
    # Critical Thinking Extension: Mask password using slicing (e.g., ab****yz) // Identify the masking sector block
    if len(password) >= 4: # Assess whether the length is sufficient enough to effectively mask while retaining edge character viability
        # Show first 2 and last 2 characters, mask the rest // Note explaining the specific architectural slicing matrix pattern logic
        masked_password = password[:2] + ("*" * (len(password) - 4)) + password[-2:] # Extract head/tail segments and dynamically multiply an asterisk based off total character deficit quantity
    else: # If the password literally lacks the threshold volume required to construct an unmasked wrapper ring
        masked_password = "*" * len(password) # Blanket mask the entire raw password utilizing absolute brute substitution length scaling parameter multiplication
        
    print(f"\nMasked Password: {masked_password}") # Print out the final sanitized censored string variant back out to the direct output console framework

if __name__ == "__main__": # Root core script initiation conditional to suppress unintended module auto-execution routines during standard imports
    secure_password_validator() # Engage main system operational behavior triggering full runtime deployment matrix
