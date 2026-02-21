# Import the math module to get access to mathematical constants, specifically pi (3.14159...)
import math

# Prompt the user to enter a value for 'x', convert it to a float, and store it
x = float(input("Enter x: "))
# Prompt the user to enter a value for 'y', convert it to a float, and store it
y = float(input("Enter y: "))
# Prompt the user to enter a value for 'z', convert it to a float, and store it
z = float(input("Enter z: "))

# Calculate the mathematical expression expression evaluated as follows:
# 1. 4 * (x raised to the power of 4)
# 2. 3 * (y raised to the power of 3)
# 3. 9 * (z raised to the power of 2)
# 4. 6 multiplied by the mathematical constant pi (approx 3.14159)
# Add all four terms together and store the final sum in 'result'
result = (4 * x**4) + (3 * y**3) + (9 * z**2) + (6 * math.pi)

# Print the final calculated result to the console
print(f"The result is: {result}")