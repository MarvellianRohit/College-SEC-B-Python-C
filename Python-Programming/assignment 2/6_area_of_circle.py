# Q6: Write a python program to print the area of circle when radius of the circle is given by user

import math

radius = float(input("Enter the radius of the circle: "))

area = math.pi * (radius ** 2)

print(f"Area of the circle with radius {radius} is: {area:.2f}")

'''
Output:
Enter the radius of the circle: Traceback (most recent call last):
  File "/Users/rohitchandra/Documents/college/Python-Programming/assignment 2/6_area_of_circle.py", line 5, in <module>
    radius = float(input("Enter the radius of the circle: "))
ValueError: could not convert string to float: ''
'''
