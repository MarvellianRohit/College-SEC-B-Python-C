# Q6: Write a python program to print the area of circle when radius of the circle is given by user

import math

radius = float(input("Enter the radius of the circle: "))

area = math.pi * (radius ** 2)

print(f"Area of the circle with radius {radius} is: {area:.2f}")

'''

Output:

Enter the radius of the circle: 7
Area of the circle with radius 7.0 is: 153.94

'''
