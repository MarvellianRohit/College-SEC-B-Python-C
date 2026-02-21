# 3. Write a program to calculate body mass index of a person. BMI=kg/m^2 where kg is a person's weight in kilogram and m^2 is the height in meter squared.

# Prompt the user to enter their weight in kg, convert it to a floating-point number, and store it in the 'weight' variable
weight = float(input("Enter weight in kilograms (kg): "))
# Prompt the user to enter their height in meters, convert it to a floating-point number, and store it in the 'height' variable
height = float(input("Enter height in meters (m): "))

# Calculate the BMI using the formula: weight / (height squared). '**' is the exponentiation operator in Python.
bmi = weight / (height ** 2)

# Print the calculated BMI to the console, formatted to display exactly 2 decimal places
print(f"The Body Mass Index (BMI) is: {bmi:.2f}")
