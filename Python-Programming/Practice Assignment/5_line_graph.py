import matplotlib.pyplot as plt

# Program to plot a simple line graph

def plot_line_graph():
    # i. Create two lists
    # x values from 1 to 5
    x = [1, 2, 3, 4, 5]
    
    # y values as squares of x (i.e., y = x^2)
    y = [val**2 for val in x]
    
    # ii. Plot a line graph using these values
    plt.plot(x, y, marker='o', linestyle='-', color='b', label='y = x^2')
    
    # iii. Add Title and labels
    plt.title("Simple Line Graph")
    plt.xlabel("X values")
    plt.ylabel("Y values")
    
    # Adding grid for better visibility
    plt.grid(True)
    plt.legend()
    
    # Save the plot as a PNG file
    output_image = "line_graph.png"
    plt.savefig(output_image)
    print(f"Graph plotted and saved as '{output_image}'")
    
    # Display coordinates printed in console for verification
    print("\nCoordinates plotted:")
    for i in range(len(x)):
        print(f"({x[i]}, {y[i]})")

if __name__ == "__main__":
    plot_line_graph()

"""
EXPECTED OUTPUT:
Graph plotted and saved as 'line_graph.png'

Coordinates plotted:
(1, 1)
(2, 4)
(3, 9)
(4, 16)
(5, 25)
"""
