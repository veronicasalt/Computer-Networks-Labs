# Link State Routing Protocol Implementation

This repository contains an implementation of the Link State (LS) routing algorithm in C. The project uses Dijkstra's algorithm to compute the shortest path tree from a source node to all other nodes in a network. It simulates the behavior of a router running the Link State routing protocol with iterative updates based on cost changes.

---

## Objective

The primary objective of this lab is to develop and test a Link State routing protocol, enabling each node (router) in a network to compute its forwarding table based on the least-cost paths to other nodes. The project also demonstrates how routers communicate with one another using UDP and manage dynamic network changes.

---

## Features

- **Dijkstra's Algorithm:** Computes the shortest path tree iteratively for the source node.
- **Threaded Architecture:**
  - **Thread 1:** Listens for incoming updates from other nodes and modifies the cost table.
  - **Thread 2:** Handles user input for cost updates and sends these updates to other nodes.
  - **Thread 3:** Periodically runs the LS algorithm to update the least-cost paths and outputs the results.
- **UDP Communication:** Simulates message exchanges between routers to reflect real-world routing behavior.
- **Dynamic Network Updates:** Incorporates cost changes in real-time and recalculates the shortest paths accordingly.
- **Synchronization:** Uses mutex locks to ensure safe access to shared data structures like the neighbor cost table.

---

## Program Details

### Input Data

1. **Cost Table:**  
   A matrix representing the cost of links between nodes. If the cost is `1000` (infinity), the nodes are not directly connected.
2. **Machine Table:**  
   Contains machine names, IP addresses, and port numbers for each node.

### Output
- Updated least-cost paths from the source node to every other node.
- Logs of received messages, updated costs, and shortest path calculations.

### Communication
Messages exchanged between routers contain three integers:

## How to Run Program

### Prerequisites
1. A C compiler (e.g., `gcc`) installed on your system.
2. Input files for:
   - The cost table (e.g., `costs.txt`).
   - Machine information (e.g., `machines.txt`).
  
gcc -pthread -o ls ls.c
./ls <Router ID> <Number of Nodes> <Cost File> <Machine File>
