# The sample text provided
from loop1 import list1 # Import list1 from the loop1 module (requires loop1.py to exist)

# Assigning a multi-line string containing sample geopolitical data to the variable 'data'
data = """*Sample Data:*
The current global security situation is marked by several
 ongoing conflicts #WarUpdate,
 especially the Russia–Ukraine War, which 
continues with heavy fighting in eastern 
and southern Ukraine #GlobalConflict. Ukrainian forces are attempting to
 regain territory while Russia continues missile 
and drone strikes on military and infrastructure targets #WarUpdate. 
At the same time, tensions in the Middle East have increased with hostilities
 involving Israel and Iran, where missile exchanges and airstrikes have raised 
 fears  #GlobalConflict of a wider regional war. Armed groups such as Hezbollah 
 in Lebanon have also launched rockets toward northern Israel, increasing 
 instability along the border areas #WarUpdate. Meanwhile, the Israel–Hamas 
 War #WarUpdate continues in the Gaza region, leading to humanitarian 
 challenges and displacement of civilians.
These conflicts #InternationalRelations are affecting global stability
and economic conditions, especially energy markets, because strategic routes
such as the Strait of Hormuz are under security concern #InternationalRelations. 
International organizations including the United Nations are urging diplomatic
 dialogue and ceasefire agreements to prevent escalation. Overall, the world 
 @InternationalRelations remains in a tense geopolitical phase with ongoing 
 # military actions and negotiations. @GlobalConflict #InternationalRelations 
 #Geopolitics #WorldNews"""

print(data) # Print the entire raw string stored in 'data'
print("----------------------------") # Print a separator line for better readability
print("Number of Sentences: ") # Print a header for the sentence count
print("Number of Words: ") # Print a header for the word count
print("Number of Topic: ") # Print a header for the topic count
print("Number of Annotations: ") # Print a header for the annotation count

# This is the normal way to do it (using list comprehensions and standard string methods)

# 1. Number of Sentences: splitting by '.' and filtering out empty strings using a list comprehension
sentences = [s for s in data.split('.') if s.strip()] 
print("Number of Sentences: ", len(sentences)) # Print the result count of sentences

# 2. Number of Words: split() without arguments automatically splits by any whitespace (spaces, tabs, newlines)
words = data.split() 
print("Number of Words: ", len(words)) # Print the total count of words

# 3. Number of Topics: Filter the 'words' list to find elements starting with '#'
# (Includes topics even if they have punctuation at the end like #WarUpdate,)
topics = [w for w in words if w.startswith('#')] 
print("Number of Topic: ", len(topics)) # Print the count of hashtags/topics found

# 4. Number of Annotations: Filter the 'words' list to find elements starting with '@'
annotations = [w for w in words if w.startswith('@')] 
print("Number of Annotations: ", len(annotations)) # Print the count of handle/annotation mentions found


# Mam's way to do it (Simpler logic, often taught in introductory classes)

list1 = data.split('.') # Split the raw text at every '.' character into a list
len1 = len(list1) # Get the total number of elements in that list (includes the empty segment after the last period)
print("Number of Sentences: "+str(len1)) # Convert the number to a string and print it with a label

list2 = data.split() # Split the raw text at every whitespace character into a list of words
len2 = len(list2) # Get the total number of words in the list
print("Number of Words: "+str(len2)) # Convert the count to a string and print it with a label

# This is the mam's way to do it (using a for loop and an if condition)
cnt = 0 # Initialize a counter variable to 0
for i in list2: # Iterate through every word in list2
    if i[0]=='#': # Check if the first character of the word is '#'
        cnt = cnt + 1 # If yes, increment the counter by 1
print("Number of Topic: "+str(cnt)) # Print the final count of topics found via loop

# If you follow the alternative way (using split on the delimiter itself)
list3 = data.split('#') # Split the entire text into sections using '#' as the separator
len3 = len(list3) # Get the count of these sections (Total tags = sections - 1)
print("Number of Topic: "+str(len3)) # Print the section count (which is typically tag_count + 1)

# If you follow the same alternative way for annotations
list4 = data.split('@') # Split the entire text into sections using '@' as the separator
len4 = len(list4) # Get the count of these sections
print("Number of Annotations: "+str(len4)) # Print the section count

# This is the mam's way to do it for annotations (using a for loop and an if condition)
cnt = 0 # Reset the counter variable to 0
for i in list2: # Iterate through every word in the word list (list2)
    if i[0]=='@': # Check if the first character of the word is '@'
        cnt = cnt + 1 # If yes, increment the counter by 1
print("Number of Topic: "+str(cnt)) # Print the final count of annotations found via loop

# --------------------------------------------------------------------------------
# NEW SECTION: Finding Distinct (Unique) Elements 
# This part is kept separate to analyze unique occurrences specifically.
# --------------------------------------------------------------------------------

print("\n--- Distinct Elements Analysis ---") # Print a header for the distinct elements section

# Using a set to find unique words (case-insensitive and punctuation-stripped)
unique_words = set() # Initialize an empty set to store unique (distinct) words
for word in words: # Loop through each word in the 'words' list created earlier
    # Clean the word: remove common punctuation and symbols, and convert to lowercase
    # strip() removes the specified characters from both the beginning and end of the string
    clean = word.strip('.,!?:;()#@*').lower() 
    if clean: # If the cleaned word is not an empty string
        unique_words.add(clean) # Add the cleaned word to the set (sets only store unique values)

print("Number of Distinct Words:", len(unique_words)) # Print the count of unique words found
# print("List of Unique Words:", sorted(list(unique_words))) # (Optional) Print the sorted list of unique words

# Finding distinct hashtags (topics) with cleaning
unique_hashtags = set() # Initialize an empty set for unique hashtags
for t in topics: # Loop through each hashtag found in the 'topics' list
    # Remove trailing punctuation from topics to ensure '#WarUpdate,' and '#WarUpdate' match
    clean_t = t.rstrip('.,!?:;()').lower() 
    if clean_t: # If the cleaned hashtag is not empty
        unique_hashtags.add(clean_t) # Add it to the set to automatically keep only distinct tags

print("Number of Distinct Topics:", len(unique_hashtags)) # Print the count of unique hashtags
print("Unique Topics Found:", unique_hashtags) # Print the actual unique hashtags found

# Finding distinct annotations (mentions) with cleaning
unique_mentions = set() # Initialize an empty set for unique handle mentions
for m in annotations: # Loop through each handle found in the 'annotations' list
    # Remove trailing punctuation from mentions similarly to topics
    clean_m = m.rstrip('.,!?:;()').lower() 
    if clean_m: # If the cleaned mention handle is not empty
        unique_mentions.add(clean_m) # Add it to the set for uniqueness

print("Number of Distinct Annotations:", len(unique_mentions)) # Print the count of unique handles
print("Unique Annotations Found:", unique_mentions) # Print the actual unique handles found


# --------------------------------------------------------------------------------
# NEW SECTION: Hashtag Frequency Analysis
# Calculating how many times each specific hashtag appears in the text.
# --------------------------------------------------------------------------------

print("\n--- Hashtag Frequency Analysis ---") # Print a header for the frequency analysis section

# Using a dictionary to store hashtag counts (Key: Hashtag Name, Value: Frequency Count)
hashtag_counts = {} 

for t in topics: # Loop through each hashtag in the 'topics' list
    # Clean the hashtag to ensure consistency (remove trailing punctuation and lowercase)
    # This prevents duplicates like '#WarUpdate,' and '#WarUpdate' from having separate counts
    clean_tag = t.rstrip('.,!?:;()').lower() 
    
    if clean_tag: # If the cleaned hashtag is valid
        # Increment the count for this hashtag in the dictionary
        if clean_tag in hashtag_counts: # If the tag already exists as a key in the dictionary
            hashtag_counts[clean_tag] += 1 # Increment its existing count by 1
        else: # If the tag is seen for the first time
            hashtag_counts[clean_tag] = 1 # Initialize its count to 1

# Displaying the final frequencies stored in the dictionary
print("Hashtag Frequencies:") # Print a label for the list
for tag, count in hashtag_counts.items(): # Loop through key-value pairs in the dictionary
    print(f"  {tag}: {count} times") # Print the hashtag and its total frequency





#Output
"""
/*--- Distinct Elements Analysis ---

Unique Words: 127
Unique Topics: 6
Unique Annotations: 2
--- Hashtag Frequency Analysis ---

#warupdate: 4 times
#internationalrelations: 3 times
#globalconflict: 2 times
(others 1 time each)

"""