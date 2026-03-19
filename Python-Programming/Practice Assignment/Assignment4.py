# Assignment 4: Dynamic String Formatter (Real-world Scenario) // Title of the assignment
# Objective: Use f-strings and formatting. // Description of the assignment goals

def dynamic_string_formatter(): # Define the primary function to handle the dynamic string generation
    print("--- User Details Input ---") # Print a distinct header section for prompting the user's initial core credentials
    name = input("Enter your name: ").strip() # Solicit the user to input a name string, immediately stripping stray spaces assigning it to variables
    
    try: # Initialize a protective testing block catching predictable input errors during numeric conversion
        age_str = input("Enter your age: ").strip() # Request the raw string age value while cleanly trimming accidental spaces
        age = int(age_str) # Attempt parsing the raw formatted age string variable down specifically into integer type form
        
        marks_str = input("Enter your marks: ").strip() # Prompt explicit query collecting the user's numeric marks value text string
        marks = float(marks_str) # Safely mutate the string-casted mark input structurally to a decimal floating point object
    except ValueError: # Actively declare error catching behavior prioritizing the explicit ValueError exception event
        print("Invalid input for age or marks. Please enter numeric values.") # Direct a clear fallback instruction towards the user notifying text input failure
        return # Terminate the executing application function layer entirely preserving application stability preventing crash behavior
        
    print("\n--- Formatted Outputs ---") # Display separated structural display header for printing explicit dynamic results
    
    # 1. Format marks to 2 decimal places -> {marks:.2f} // Comment detailing the next action
    # 2. Display name in uppercase // Comment detailing the next action
    formatted_sentence = f"My name is {name.upper()}, I am {age} years old, and I scored {marks:.2f} marks." # Build complex interpolation template dynamically coercing naming uppercase alongside strictly truncated floating constraints
    print("Standard Output:") # Deliver output label identifier explicitly naming general structural formatting type baseline
    print(formatted_sentence) # Relay generated master concatenated evaluation result straight down into standard text system output handler
    
    # Extract and display initials using slicing // Comment detailing the next action
    words = name.split() # Fragment master textual name explicitly severing space delimited chunks loading isolated strings inside a list array
    initials = "" # Instantiate a completely blank neutral zero-length textual variable dedicated to slowly appending letter fragments
    for w in words: # Engage dedicated iterator loop cyclically stepping directly across each segmented string slice present
        if w: # Establish logic gate strictly blocking isolated empty null strings ensuring iteration safely touches character arrays only
            initials += w[0].upper() # Force extract the 0th index character coordinate while explicitly casting strictly toward capitalized encoding format
            
    print(f"Initials: {initials}") # Inject successfully fully harvested acronym abbreviation variable into f-string framework output routine
    
    # Concatenate a welcome message // Comment detailing the next action
    welcome_message = "Welcome aboard, " + name + "! We are glad to have you." # Form strict absolute manual concatenation directly stitching discrete textual blocks integrating root name query string
    print(f"Welcome Message: {welcome_message}") # Announce compiled welcoming output utilizing format prefixing presentation pattern style
    
    # Critical Thinking Extension: // Priority category comment demarcating advanced logic problem subset
    print("\n--- Critical Thinking Extensions ---") # Transmit visible categorical divider header text stream output
    
    # Add calculated field (e.g., next year age) // Comment detailing the next action
    next_year_age = age + 1 # Evaluate simple algebraic addition incrementing base integer dynamically generating fresh computational numeric node
    
    # Create multiple formatted outputs (formal, informal) // Comment detailing the next action
    formal_output = f"Dear {name.title()}, this is to formally certify that you have achieved a score of {marks:.2f}. You are currently {age} years of age." # Assemble dense official documentary formatting style coercing title casing text dynamically alongside decimal rounding logic
    informal_output = f"Hey {name.split()[0] if name else 'buddy'}! Awesome job getting {marks:.2f} points! Can't believe you'll be {next_year_age} next year!" # Construct a highly casual text structure extracting the zero-index name word via split targeting alongside the incremented age variable payload
    
    print("Formal Output:") # Output secondary label grouping structural design tag
    print(f"  {formal_output}") # Deploy deeply nested string utilizing spatial whitespace text indentation padding formatting
    print("Informal Output:") # Emit casual structural text grouping design layer tag label directly 
    print(f"  {informal_output}") # Display aggressively nested string via secondary whitespace padding layout interpolation routine

if __name__ == "__main__": # Evaluate specific runtime condition directly testing if module was invoked sequentially versus implicitly called remotely
    dynamic_string_formatter() # Channel execution pipeline initiating functional payload behavior routing downwards sequentially
