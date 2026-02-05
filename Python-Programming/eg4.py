# Formatting Output
amount = 1000
print("The amount is", str(amount))

#Format
amount = 150.75
print("The amount is: ${:.2f}".format(amount))

#Using Seperators
print("apple" + "-" "orange" + "-" + "cherry")
print("apple", "banana", "cherry", sep="-")  #Using Seperators as "-"
#One more example
a = 'S'
b = 'N'
c = 'U'
print(a, b, c, sep=" ")

#Using End()
a = 'S'
b = 'N'
c = 'U'
print(a, end="-")
print(b)
print(c)

#Formatting with Placeholders, {0} replaced by Geeks
print("potrtal and {0}".format("Geeks"))

a = 'Soumik'
b = 'Tanushree'
print("{0}He asked me, \"How are you?\" and {1} replied, \"I am fine.\"".format(a, b))
print("{a}He asked me, \"How are you?\" and {b} replied, \"I am fine.\"".format(a=a, b=b))

#Python program introducing f-string
val = "Geeks"
print(f"{val} for {val} is a portal for {val}")
name = "OM"
age = 21
print(f"{name} is {age} years old.")