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