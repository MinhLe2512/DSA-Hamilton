
# CHALLENGE 3: HAMILTONIAN GRAPH AND THE TRAVELING SALESMAN PROBLEM

# 1 Research
In this Challenge, let’s do some research about 2 of the most famous problems in graph theory: The Hamiltonian Cycle problem and The Traveling Salesman problem. See chapter 34.2 and 34.5, Introduction to Algorithms (3<sup>rd</sup> edition) and answer the following questions:
1. Define the following terms: Hamiltonian Cycle, Hamiltonian Path and
    Hamiltonian Graph. Give example for each of your definitions.
2. Given a graph of size `n`. State the maximum and minimum number of Hamiltonian Cycle(s) it can have. Explain your answer.
3. Form a simple algorithm to verify if a graph is Hamiltonian. What is the complexity of your algorithm?
4. State the Traveling Salesman Problem (TSP). Stated the relationship between a Traveling Salesman Tour and a Hamiltonian Cycle.
5. Form an algorithm to find the Traveling Salesman Tour from a connected undirected graph. What is the complexity of your algorithm?
6. The following [link](https://www.geeksforgeeks.org/travelling-salesman-problem-set-2-approximate-using-mst/) demonstrate a solution of the TSP problem. Is this solution applicable for all connected undirected graph? Explain your answer.
# 2 Programming
- You are requested to build a program verify if a Graph is Hamiltonian.
- Your program must be built into an execution ".exe" file that runs within the
    following command line arguments:
```
A.exe Action InputPath
```

∗ `A.exe`: Your executional ".exe" file.
∗ `Action`:
- `-HPath`: verify if the given graph exists a Hamiltonian Path.
→ Output: "Yes" or "No" to the Console.
- `-HCycle`: verify if the given graph exists a Hamiltonian Cycle.
→ Output: "Yes" or "No" to the Console.

∗ `InputPath`: Path to the input file, structure of the "input.txt" is given as
follow:
- 1<sup>st</sup> line: positive integer `n` represents n cities. Cities are numbered from 1 → `n`.
- Following lines: `City A` `City B` `Distance`.

Example:  
Input
```
4
1 2 3
1 3 4
1 4 5
```
Output
- -HPath: No
- -HCycle: No    

Input
```
5
1 2 4
1 4 8
3 4 2
2 5 1
3 5 1
```
Output
- -HPath: Yes
- -HCycle: Yes
