# Q5: Write a python Program to obtain temperature in Celsius and convert it into Fahrenheit

celsius = float(input("Enter temperature in Celsius: "))

# Formula: (C * 9/5) + 32 = F
fahrenheit = (celsius * 9/5) + 32

print(f"{celsius:.2f} Celsius is equal to {fahrenheit:.2f} Fahrenheit")

'''
Output:
Enter temperature in Celsius: Traceback (most recent call last):
  File "/Users/rohitchandra/Documents/college/Python-Programming/assignment 2/5_celsius_to_fahrenheit.py", line 3, in <module>
    celsius = float(input("Enter temperature in Celsius: "))
ValueError: could not convert string to float: ''
'''
