# Import the math module to get access to mathematical functions like square root
import math

# Prompt the user for coefficient 'a', convert it to a float, and store it
a = float(input("Enter a: "))
# Prompt the user for coefficient 'b', convert it to a float, and store it
b = float(input("Enter b: "))
# Prompt the user for coefficient 'c', convert it to a float, and store it
c = float(input("Enter c: "))

# Calculate the discriminant 'd' using the formula b^2 - 4ac
# This determines the nature of the roots (real or imaginary)
d = b**2 - 4*a*c

# Check if the discriminant is greater than or equal to 0 (meaning roots are real)
if d >= 0:
    # Calculate the first root using the quadratic formula: (-b + sqrt(d)) / 2a
    root1 = (-b + math.sqrt(d)) / (2 * a)
    # Calculate the second root using the quadratic formula: (-b - sqrt(d)) / 2a
    root2 = (-b - math.sqrt(d)) / (2 * a)
    # Print both calculated roots to the console
    print(f"Roots are: {root1} and {root2}")
else:
    # If the discriminant is less than 0, the roots are complex/imaginary numbers
    # We simply print "Roots are imaginary" as per basic requirements
    print("Roots are imaginary")