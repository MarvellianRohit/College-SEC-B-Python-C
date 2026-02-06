# Q7: Write a python program that asks your height in centimeters and converts it into foot and inches

height_cm = float(input("Enter your height in centimeters: "))

# 1 inch = 2.54 cm
total_inches = height_cm / 2.54

# 1 foot = 12 inches
feet = int(total_inches // 12)
remaining_inches = total_inches % 12

print(f"Your height is {feet} feet and {remaining_inches:.2f} inches")
