# Program 9: Display two patterns for an input word (e.g., PYTHON)

word = input("Enter a word: ").upper()
n = len(word)

print("\n--- Left Pattern ---")
for i in range(n):
    print(" ".join([word[i]] * (i + 1)))

print("\n--- Right Pattern ---")
for i in range(n, 0, -1):
    print(" ".join(word[:i]))

# -----------------------------------------------
# Sample Output:
# Enter a word: PYTHON
#
# --- Left Pattern ---
# P
# Y Y
# T T T
# H H H H
# O O O O O
# N N N N N N
#
# --- Right Pattern ---
# P Y T H O N
# P Y T H O
# P Y T H
# P Y T
# P Y
# P
# -----------------------------------------------
