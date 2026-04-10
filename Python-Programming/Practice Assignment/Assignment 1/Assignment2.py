# Assignment 2: String Transformation Engine // Title of the assignment
# Objective: Understand string modification and replacement. // Description of the assignment goals

def string_transformation_engine(): # Define the main function named 'string_transformation_engine'
    txt = "  Data Science is powerful and data is everywhere  " # Initialize a string variable 'txt' with leading/trailing spaces and mixed casing
    print(f"Original string: '{txt}'") # Print the original unmodified string padded with single quotes for visibility
    
    # Remove whitespace -> strip() // Comment detailing the next action
    clean_txt = txt.strip() # Remove leading and trailing whitespace characters, assigning the result to 'clean_txt'
    print(f"After strip(): '{clean_txt}'") # Print the cleaned string to show whitespace removal
    
    # Replace "data" with "information" (case insensitive) // Comment detailing the next action
    # Replaces both capitalized and lowercase variations found in the string // Explaining dual-replace strategy
    replaced_txt = clean_txt.replace("Data", "Information").replace("data", "information") # Chain replace() to swap "Data" for "Information" and "data" for "information"
    print(f"After replacement: '{replaced_txt}'") # Print the newly modified string after word replacements
    
    # Convert first half of string to uppercase and second half to lowercase (use slicing) // Comment detailing the next action
    mid_index = len(replaced_txt) // 2 # Calculate the middle integer index of the string using floor division
    first_half = replaced_txt[:mid_index].upper() # Extract characters from the start to the middle index and convert them to uppercase
    second_half = replaced_txt[mid_index:].lower() # Extract characters from the middle index to the end and convert them to lowercase
    half_cased_txt = first_half + second_half # Concatenate the uppercase first half and lowercase second half into a new string
    print(f"Half upper / Half lower: '{half_cased_txt}'") # Print the split-cased string output
    
    # Split the sentence into words and display in reverse order // Comment detailing the next action
    words = replaced_txt.split() # Split the previously replaced text into a list of isolated words
    reversed_words = words[::-1] # Reverse the internal order of the 'words' list using Python's slice step operator[::-1]
    print(f"Words in reverse order: {reversed_words}") # Print the entire reversed list structure to the console
    
    # Critical Thinking Extension: // Comment header for the extension portion
    # Reconstruct the sentence using concatenation (+) // Comment detailing the next action
    reconstructed_sentence = "" # Initialize an empty string variable named 'reconstructed_sentence' for holding the concatenated result
    for word in reversed_words: # Begin a for loop iterating over every word inside the 'reversed_words' list
        reconstructed_sentence += word + " " # Append the current word followed by a single space character to the reconstructed string
    reconstructed_sentence = reconstructed_sentence.strip() # Remove the trailing auxiliary space from the final concatenated sentence
    print(f"Reconstructed from reversed: '{reconstructed_sentence}'") # Print the fully reconstructed backward sentence
    
    # Ensure proper capitalization using logic // Comment detailing the next action
    if reconstructed_sentence: # Execute the internal block only if the string is not empty
        proper_capitalization = reconstructed_sentence[0].upper() + reconstructed_sentence[1:].lower() # Capitalize the very first letter and force the remainder of the sentence to strictly lowercase
        print(f"Properly capitalized reconstructed sentence: '{proper_capitalization}'") # Print the grammar-adjusted normalized final sentence

if __name__ == "__main__": # Detect if the file is being run directly as a primary standalone script
    string_transformation_engine() # Invoke the specific defined transformation sequence function
