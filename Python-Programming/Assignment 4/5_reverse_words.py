# Program 5: Accept a sentence and display it in reverse order of its words

sentence = input("Enter a sentence: ")

words = sentence.split()             # Split sentence into a list of words
words.reverse()                      # Reverse the list of words
reversed_sentence = " ".join(words)  # Join words back into a sentence

print("Reversed sentence:", reversed_sentence)

# -----------------------------------------------
# Sample Output:
# Enter a sentence: WE ARE LEARNING PYTHON
# Reversed sentence: PYTHON LEARNING ARE WE
# -----------------------------------------------
