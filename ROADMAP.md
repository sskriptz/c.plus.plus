flowchart TD
    %% ===== Foundations =====
    A[Foundations] --> B[Variables, Loops, Functions, Recursion]
    B --> C[Arrays & Strings]
    C --> D[Basic Sorting & Searching]
    D --> E[Simple Math Algorithms]
    E --> F[Understanding Time Complexity / Big O]

    %% ===== Sorting & Searching =====
    F --> G[Sorting Algorithms]
    G --> G1[Bubble Sort]
    G --> G2[Selection Sort]
    G --> G3[Insertion Sort]
    G --> G4[Merge Sort]
    G --> G5[Quick Sort]
    G --> G6[Heap Sort]
    F --> H[Searching Algorithms]
    H --> H1[Linear Search]
    H --> H2[Binary Search]
    H --> H3[Ternary Search]

    %% ===== Recursion & Backtracking =====
    F --> I[Recursion & Backtracking]
    I --> I1[N-Queens]
    I --> I2[Sudoku Solver]
    I --> I3[Maze Solving DFS]
    I --> I4[Word Search]

    %% ===== Dynamic Programming =====
    I --> J[Dynamic Programming]
    J --> J1[Fibonacci Sequence]
    J --> J2[Knapsack Problem]
    J --> J3[Longest Common Subsequence]
    J --> J4[Matrix Chain Multiplication]
    J --> J5[Coin Change Problem]

    %% ===== Greedy Algorithms =====
    J --> K[Greedy Algorithms]
    K --> K1[Activity Selection]
    K --> K2[Huffman Coding]
    K --> K3[Fractional Knapsack]
    K --> K4[Prim's / Kruskal's MST]

    %% ===== Graph Algorithms =====
    K --> L[Graph Algorithms]
    L --> L1[Graph Representation]
    L --> L2[BFS - Shortest Path]
    L --> L3[DFS - Path / Connectivity]
    L --> L4[Topological Sort]
    L --> L5[Minimum Spanning Tree]
    L --> L6[Cycle Detection]
    L --> L7[Connected Components]
    L --> L8[A* Algorithm]

    %% ===== Randomized / Probabilistic =====
    L --> M[Randomized / Probabilistic Algorithms]
    M --> M1[Monte Carlo Simulation]
    M --> M2[Randomized QuickSort]
    M --> M3[Las Vegas Algorithms]

    %% ===== Computational Geometry =====
    M --> N[Computational Geometry]
    N --> N1[Convex Hull]
    N --> N2[Line Intersection]
    N --> N3[Polygon Area]
    N --> N4[Closest Pair of Points]

    %% ===== String Algorithms =====
    N --> O[String / Text Algorithms]
    O --> O1[KMP Pattern Search]
    O --> O2[Rabin-Karp]
    O --> O3[Trie / Prefix Trees]
    O --> O4[Suffix Arrays / Suffix Trees]
    O --> O5[Levenshtein Distance]

    %% ===== Number Theory & Math =====
    O --> P[Number Theory & Math Algorithms]
    P --> P1[GCD / LCM]
    P --> P2[Sieve of Eratosthenes]
    P --> P3[Modular Exponentiation]
    P --> P4[Fast Fourier Transform]
    P --> P5[Pollard's Rho Factorization]

    %% ===== Advanced / Miscellaneous =====
    P --> Q[Advanced / Miscellaneous]
    Q --> Q1[Union-Find / DSU]
    Q --> Q2[Network Flow (Ford-Fulkerson)]
    Q --> Q3[Graph Coloring]
    Q --> Q4[Game Theory / Minimax]
    Q --> Q5[Neural Networks From Scratch]

    %% ===== Connections =====
    style A fill:#FFD700,stroke:#333,stroke-width:2px
    style F fill:#FFB347,stroke:#333,stroke-width:2px
    style G fill:#FFA500,stroke:#333,stroke-width:2px
    style H fill:#FFA500,stroke:#333,stroke-width:2px
    style I fill:#FF8C00,stroke:#333,stroke-width:2px
    style J fill:#FF7F50,stroke:#333,stroke-width:2px
    style K fill:#FF6347,stroke:#333,stroke-width:2px
    style L fill:#FF4500,stroke:#333,stroke-width:2px
    style M fill:#FF0000,stroke:#333,stroke-width:2px
    style N fill:#FF1493,stroke:#333,stroke-width:2px
    style O fill:#C71585,stroke:#333,stroke-width:2px
    style P fill:#8A2BE2,stroke:#333,stroke-width:2px
    style Q fill:#4B0082,stroke:#333,stroke-width:2px
