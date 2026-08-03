*This project has been created as part of the 42 curriculum by aserio and iualkhim*


## Description
The main goal of the `push_swap` project is to create a program that sorts a randomly generated list of unique numbers using only a small, predefined set of operations. Beyond simply sorting, the program evaluates the disorder of the input and adapts its approach to minimize the number of moves, offering detailed benchmarking data through the `--bench` flag. 

This project is an exercise in **algorithmic thinking**, understanding **Big O notation**, comparing **sorting strategies**, and **optimizing solutions** when your tools are limited.

### Authors and Contributions

This project was developed in pairs as required by the 42 curriculum:

- **Andrea Serio (aserio)**: 
    - Input parser architecture
    - Context management (`t_context`) and project architecture
    - Memory management improvements and project infrastructure
    - `Quick sort` implementation and optimization
    - `Chunk sort` implementation and optimization
    
- **Julia Alkhimova (iualkhim)**: 
    - Stack operations (`swap`, `push`, `rotate`, `reverse rotate`)
    - Benchmark system (`--bench`, operation counting and reporting)
    - Strategy selection and adaptive strategy rules
    - Input parser (mixed arguments support)
    - `Insertion sort` implementation and optimization

### Implemented Algorithms & Complexity Justification

#### 1. Insertion Sort (Simple strategy)

The algorithm maintains **stack B** in circular descending order, inserting each element into its correct position using the shortest rotation path. Once all elements have been moved, **stack B** is aligned with the maximum element on top and pushed back to **stack A**, reducing unnecessary rotations.

Chosen as the **Simple** strategy because it performs well on inputs with low disorder while keeping the implementation straightforward.

- **Time Complexity:** O(n²)

#### 2. Quick Sort (Medium strategy)
...

#### 3. Chunk Sort (Complex strategy)
...

## Instructions

1. Clone the project and enter the folder:
```bash
   git clone git@github.com:JuliAlchemDev/42_push_swap.git push_swap
   cd push_swap
```

2. Build the main `push_swap` binary:
```bash
   make
```

3. Run the program using a set of unique numbers:

    - The program accepts numbers either as separate arguments or as a single quoted string, e.g. `5 4 3 2 1`, `"5 4 3 2 1"` or mix of both formats:
    ```bash
            ./push_swap 5 "4 3" 2 1
    ```
    - Force a specific strategy with **--simple**, **--medium**, or **--complex**. Otherwise, the program will use an adaptive strategy based on the calculated disorder of the input:
    ```bash
            ./push_swap --simple 5 4 3 2 1
    ```
    - Print detailed performance metrics with the **--bench** flag, which outputs the data through stderr:
    ```bash
            ./push_swap --bench 5 4 3 2 1 2> bench.txt
    ```
## Resources