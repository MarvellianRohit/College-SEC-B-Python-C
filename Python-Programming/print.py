x,y = input(" Enter your age: ").split()
print(x,y)



age_input = input("Enter your age: ")
age = int(age_input)
print(age)

if age < 0:
    print("Enter a valid age: ")
elif age < 18:
    print("You are a minor.")
elif age >= 18 and age < 65:
    print("You are adult")
else:
    print("You are senior citizen")


