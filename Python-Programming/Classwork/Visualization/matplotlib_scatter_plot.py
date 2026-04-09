# Data Visualization with Matplotlib: Scatter Plot
# Scatter plots are used to observe relationships between two numerical variables.

import matplotlib.pyplot as plt

# 1. Dataset: Number of hours studied vs. Marks obtained in an exam
study_hours = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
exam_marks = [35, 45, 50, 58, 65, 70, 82, 85, 90, 95]

print("--- Preparing Scatter Plot Data ---")
print(f"Study Hours: {study_hours}")
print(f"Exam Marks:  {exam_marks}")

# 2. Create the Scatter Plot
# figsize set to (10, 6) for a wide clear view
plt.figure(figsize=(10, 6))

# plt.scatter arguments:
# - c: color of the points
# - s: size of the points
# - marker: shape of the points ('o' for circle)
# - alpha: transparency (0 to 1) 
# - edgecolors: color of the border around each point
plt.scatter(study_hours, exam_marks, color='green', s=100, marker='o', edgecolors='black', alpha=0.8)

# 3. Adding Labels and Title
plt.xlabel('Hours Studied (per day)', fontsize=12)
plt.ylabel('Exams Score (out of 100)', fontsize=12)
plt.title('Impact of Study Duration on Academic Performance', fontsize=14, fontweight='bold', color='darkblue')

# 4. Adding a Grid for precise reading of data points
plt.grid(True, linestyle='--', alpha=0.6)

# 5. Save the plot as an image
plt.savefig('study_marks_scatter.png')
print("\n[SUCCESS] Scatter plot has been saved as 'study_marks_scatter.png'")

# 6. Display the Chart
print("Displaying chart window...")
plt.show()

'''
Key Learning Points:
- Scatter plots are great for finding CORRELATIONS.
- In this example, we see a 'Positive Correlation' (higher study time = higher score).
- alpha: Helps in seeing overlapping points if the dataset is dense.

Output:
--- Preparing Scatter Plot Data ---
Study Hours: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
Exam Marks:  [35, 45, 50, 58, 65, 70, 82, 85, 90, 95]

[SUCCESS] Scatter plot has been saved as 'study_marks_scatter.png'
Displaying chart window...
'''
