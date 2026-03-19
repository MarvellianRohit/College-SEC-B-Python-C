# Assignment 1: Smart Text Analyzer // Title of the assignment
# Objective: Apply multiple string operations to analyze text. // Description of the assignment goals

def smart_text_analyzer(): # Define the main function named 'smart_text_analyzer'
    sentence = input("Enter a sentence: ") # Prompt the user to input a string and store it in 'sentence'
    
    # Remove extra spaces using strip() // Comment detailing the next action
    sentence = sentence.strip() # Remove any leading and trailing whitespace from the inputted sentence
    
    # Count total characters using len() // Comment detailing the next action
    total_chars = len(sentence) # Calculate the total number of characters in the string using len()
    
    # Count number of words using split() // Comment detailing the next action
    words = sentence.split() # Break the string into a list of words, separating by whitespace
    total_words = len(words) # Calculate the total number of words by finding the length of the 'words' list
    
    # Check if the word "Python" exists using in // Comment detailing the next action
    has_python = "Python" in sentence # Evaluate if the exact substring "Python" exists within the string, returning True or False
    
    # Convert entire string to Uppercase and Lowercase // Comment detailing the next action
    upper_case = sentence.upper() # Create a copy of the sentence with all characters converted to uppercase
    lower_case = sentence.lower() # Create a copy of the sentence with all characters converted to lowercase
    
    print("\n--- Analysis Results ---") # Print a newline followed by a header for the results section
    print(f"Total characters: {total_chars}") # Print the total character count using an f-string for formatting
    print(f"Number of words: {total_words}") # Print the total word count using an f-string for formatting
    print(f"Contains 'Python': {has_python}") # Print whether "Python" was found (True/False) using an f-string
    print(f"Uppercase: {upper_case}") # Print the fully uppercase version of the sentence using an f-string
    print(f"Lowercase: {lower_case}") # Print the fully lowercase version of the sentence using an f-string
    
    # Critical Thinking Extension: // Comment header for the extension portion
    if words: # Check if the 'words' list is not empty to avoid errors
        # Identify the longest word in the sentence // Comment detailing the next action
        longest_word = max(words, key=len) # Use the built-in max function to find the longest string in 'words' based on its length
        print(f"Longest word: {longest_word} (length: {len(longest_word)})") # Print the longest word and its respective length
        
        # Count how many times a specific word appears // Comment detailing the next action
        search_word = input("\nEnter a word to count its occurrences: ").strip() # Prompt the user for a word to search for, and strip any surrounding spaces
        # Case-insensitive count // Comment detailing the next action
        word_count = lower_case.split().count(search_word.lower()) # Count how many times the lowercased target word appears in the list of lowercased words from the sentence
        print(f"The word '{search_word}' appears {word_count} times.") # Print the final integer count of the searched word

if __name__ == "__main__": # Check if this script is being executed directly by the Python interpreter
    smart_text_analyzer() # Call the 'smart_text_analyzer' function to start the standard execution flow
