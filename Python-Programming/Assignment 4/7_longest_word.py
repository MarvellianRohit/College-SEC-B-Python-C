# Program 7: Find and display the longest word in a sentence along with its length

sentence = input("Enter a sentence: ")

words = sentence.split()           # Split the sentence into words
longest = max(words, key=len)      # Find the word with maximum length

print("The longest word:", longest)
print("The length of the word:", len(longest))

# -----------------------------------------------
# Sample Output:
# Enter a sentence: WE ARE LEARNING PYTHON
# The longest word: LEARNING
# The length of the word: 8
# -----------------------------------------------
