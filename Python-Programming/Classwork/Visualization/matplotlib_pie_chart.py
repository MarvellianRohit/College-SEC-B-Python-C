# Data Visualization with Matplotlib: Pie Chart
# Demonstrating how to represent proportions or percentages using a pie graph

import matplotlib.pyplot as plt

# 1. Dataset: Monthly expenses breakdown (proportions)
categories = ['Rent', 'Food', 'Transport', 'Entertainment', 'Others']
expenses = [450, 250, 150, 100, 50]
colors = ['#ff9999','#66b3ff','#99ff99','#ffcc99', '#c2c2f0']

print("--- Preparing Pie Chart Data ---")
for c, e in zip(categories, expenses):
    print(f"  {c}: ${e}")

# 2. Create the Pie Chart
# Pie charts look best in a square figure: figsize=(8, 8)
plt.figure(figsize=(8, 8)) 

# Explode allows us to "pop out" a specific slice for emphasis
# Here, we explode the first slice (Rent)
explode = (0.1, 0, 0, 0, 0) 

# plt.pie() arguments:
# - expenses: The values for each slice
# - explode: Specifies which slices to push out
# - labels: The names for each slice
# - colors: The background color for each slice
# - autopct: A string format to display percentages inside the slices
# - shadow: Adds a subtle shadow effect for depth
# - startangle: Rotates the chart (140 is a common aesthetic choice)
plt.pie(expenses, 
        explode=explode, 
        labels=categories, 
        colors=colors, 
        autopct='%1.1f%%', 
        shadow=True, 
        startangle=140)

# 3. Equal axis ensures the pie remains a perfect circle
plt.axis('equal') 

# 4. Adding a Descriptive Title
plt.title('Distribution of Personal Monthly Expenses', fontsize=14, fontweight='bold', pad=20)

# 5. Save the generated chart as an image
plt.savefig('expense_pie_chart.png')
print("\n[SUCCESS] Pie chart has been saved as 'expense_pie_chart.png'")

# 6. Display the Visualization
print("Displaying chart window...")
plt.show()

'''
Technical Summary:
- labels: Categorizes the data slices.
- autopct='%1.1f%%': Displays percentages with 1 decimal point.
- plt.axis('equal'): Prevents the figure from distorting into an oval.

Output:
--- Preparing Pie Chart Data ---
  Rent: $450
  Food: $250
  Transport: $150
  Entertainment: $100
  Others: $50

[SUCCESS] Pie chart has been saved as 'expense_pie_chart.png'
Displaying chart window...
'''
