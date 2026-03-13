# Program 6: Form a word by joining the first character of each word in a sentence

sentence = input("Enter a sentence: ")

words = sentence.split()                           # Split the sentence into words
new_word = "".join(word[0] for word in words)      # Take first character of each word

print("Formed word:", new_word)

# -----------------------------------------------
# Sample Output:
# Enter a sentence: WE ARE LEARNING PYTHON
# Formed word: WALP
# -----------------------------------------------
