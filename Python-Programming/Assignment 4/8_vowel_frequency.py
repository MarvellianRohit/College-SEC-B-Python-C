# Program 8: Accept a sentence in lowercase, find frequency of vowels in each word

sentence = input("Enter a sentence in lowercase: ")

vowels = "aeiou"
words = sentence.split()

print(f"\n{'Word':<20} {'No. of vowels'}")
print("-" * 35)

for word in words:
    count = sum(1 for ch in word if ch in vowels)
    print(f"{word.capitalize():<20} {count}")

# -----------------------------------------------
# Sample Output:
# Enter a sentence in lowercase: understanding computer science
#
# Word                 No. of vowels
# -----------------------------------
# Understanding        4
# Computer             3
# Science              3
# -----------------------------------------------
