# 2. Write a program to take the temperatures of all 7 days of the week and displays the average temperature of that week.

# Initialize a variable 'total_temp' to 0 to store the sum of all temperatures
total_temp = 0

# Start a for loop that will iterate 7 times, with 'i' taking values from 1 to 7
for i in range(1, 8):
    # Prompt the user to enter the temperature for day 'i', convert the input string to a float, and store it in 'temp'
    temp = float(input(f"Enter temperature for day {i}: "))
    # Add the entered temperature 'temp' to the running sum 'total_temp'
    total_temp += temp

# Calculate the average temperature by dividing the total sum by 7 (the number of days)
average = total_temp / 7

# Print the calculated average temperature, formatted to display 2 decimal places
print(f"The average temperature of the week is: {average:.2f}")
