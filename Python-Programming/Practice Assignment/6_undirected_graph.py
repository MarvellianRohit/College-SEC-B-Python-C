import networkx as nx
import matplotlib.pyplot as plt

# Program to create and display an undirected graph

def create_undirected_graph():
    # Initialize an undirected graph
    G = nx.Graph()
    
    # Add nodes: A, B, C, D, E
    nodes = ["A", "B", "C", "D", "E"]
    G.add_nodes_from(nodes)
    
    # Add edges:
    # A —> B
    # A —> C
    # B —> D
    # C —> D
    # D — > E
    edges = [
        ("A", "B"),
        ("A", "C"),
        ("B", "D"),
        ("C", "D"),
        ("D", "E")
    ]
    G.add_edges_from(edges)
    
    # Display coordinates and edges for verification
    print("Nodes:", G.nodes())
    print("Edges:", G.edges())
    
    # Visualizing the graph
    plt.figure(figsize=(8, 6))
    pos = nx.spring_layout(G)  # Position nodes using Fruchterman-Reingold force-directed algorithm
    
    # Draw nodes, edges and labels
    nx.draw(G, pos, with_labels=True, node_color='skyblue', 
            node_size=2000, edge_color='black', linewidths=2, font_size=15)
    
    plt.title("Undirected Graph Visualization")
    
    # Save the visualization
    output_image = "undirected_graph.png"
    plt.savefig(output_image)
    plt.close()
    
    print(f"\nGraph visualization saved as '{output_image}'")

if __name__ == "__main__":
    create_undirected_graph()

"""
EXPECTED OUTPUT:
Nodes: ['A', 'B', 'C', 'D', 'E']
Edges: [('A', 'B'), ('A', 'C'), ('B', 'D'), ('C', 'D'), ('D', 'E')]

Graph visualization saved as 'undirected_graph.png'
"""
