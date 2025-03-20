# Dynamic Traffic Management System

## Overview
This project implements a **Dynamic Traffic Management System** using **Graph Algorithms** in C++. The system models a city as a **graph** and computes the shortest travel times between intersections using **Dijkstra's Algorithm**.

## Features
- **Graph Representation**: Uses an adjacency list to represent city roads.
- **Shortest Path Calculation**: Utilizes **Dijkstra's Algorithm** to find the quickest route between intersections.
- **Dynamic Traffic Handling**: Allows real-time updates to the road network.
- **Scalability**: Supports large city graphs with thousands of intersections.

## How to Run
1. **Compile the program**:
   ```sh
   g++ traffic_management.cpp -o traffic_management
   ```
2. **Run the program**:
   ```sh
   ./traffic_management
   ```
3. **Input Format**:
   - Enter the number of intersections (nodes) and roads (edges).
   - Input road data in the format:
     ```
     source destination travel_time
     ```
   - Specify the starting intersection.

## Sample Input/Output
### **Input**:
```
6 8
0 1 4
0 2 2
1 2 5
1 3 10
2 4 3
4 3 4
3 5 11
4 5 6
Enter starting intersection: 0
```
### **Output**:
```
Shortest travel time from intersection 0 to other intersections:
To intersection 0 : 0 minutes
To intersection 1 : 4 minutes
To intersection 2 : 2 minutes
To intersection 3 : 9 minutes
To intersection 4 : 5 minutes
To intersection 5 : 11 minutes
```

## Dependencies
- C++ Compiler (GCC, Clang, MSVC)

## Future Enhancements
- Add **real-time traffic congestion updates**.
- Implement **A* Search Algorithm** for improved efficiency.
- Support **Graphical Visualization** of the traffic network.

## Author
- Developed by: **[Your Name]**

