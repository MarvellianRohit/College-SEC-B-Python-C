# Data Visualization with Matplotlib: Bar Chart
# Demonstrating how to create a simple bar chart to represent categorical data

import matplotlib.pyplot as plt

# 1. Sample Dataset: Fruits and their sales quantities
fruits = ['Apples', 'Bananas', 'Cherries', 'Dates', 'Elderberries']
quantities = [25, 40, 15, 30, 10]

print("--- Preparing Bar Chart Data ---")
for f, q in zip(fruits, quantities):
    print(f"  {f}: {q}")

# 2. Create the Bar Chart
# figsize=(width, height) in inches
plt.figure(figsize=(8, 6)) 

# plt.bar(x_axis, y_axis, color, edgecolor)
plt.bar(fruits, quantities, color='skyblue', edgecolor='navy') 

# 3. Customizing the labels and titles
plt.xlabel('Fruit Variety', fontsize=12, fontweight='bold')
plt.ylabel('Quantity Sold (kg)', fontsize=12, fontweight='bold')
plt.title('Daily Fruit Sales Comparison', fontsize=14, color='darkred')

# 4. Grid lines (Optional, for better readability)
plt.grid(axis='y', linestyle='--', alpha=0.7)

# 5. Save the plot as an image file
# This is useful for including charts in reports
plt.savefig('fruit_sales_chart.png')
print("\n[SUCCESS] Plot has been saved as 'fruit_sales_chart.png'")

# 6. Display the Chart
print("Displaying chart window...")
plt.show()

'''
Technical Notes:
- plt.bar(): Creates the bar graph.
- plt.xlabel() / plt.ylabel(): Sets the labels for axes.
- plt.title(): Sets the main title.
- plt.show(): Renders the visualization on your screen.

Output:
--- Preparing Bar Chart Data ---
  Apples: 25
  Bananas: 40
  Cherries: 15
  Dates: 30
  Elderberries: 10

[SUCCESS] Plot has been saved as 'fruit_sales_chart.png'
Displaying chart window...
'''
