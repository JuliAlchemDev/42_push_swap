*This project has been created as part of the 42 curriculum by aserio and iualkhim*


## Description
The main goal of the `push_swap` project is to create a program that sorts a list of unique numbers using only a small, predefined set of operations. Beyond simply sorting, the program evaluates the disorder of the input and adapts its approach to minimize the number of moves, offering detailed benchmarking data through the `--bench` flag. 

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

#### 1. Insertion Sort (Simple strategy | desorder < 0.2)

The algorithm maintains **stack B** in circular descending order, inserting each element into its correct position using the shortest rotation path. Once all elements have been moved, **stack B** is aligned with the maximum element on top and pushed back to **stack A**, reducing unnecessary rotations.

Chosen as the **Simple** strategy because it performs well on inputs with low disorder while keeping the implementation straightforward.

- **Time Complexity:** O(n²)

#### 2. Chunk Sort (Medium strategy | 0.2 ≤ desorder < 0.5)

The Chunk Sort algorithm divides the original stack a into `ceil(√n)` sub-stacks each of length up to `floor(√n)`.
The `ceil(√n)` sub-stacks are created by pushing one-by-one the elements of the stack `a` into stack `b`, the calls to function `pb` are intervalled by the rotations `rb` and `rrb` to make each substack sorted and keep them separated.

The last four or less elements of `a` are sorted with the functions `sort_a_small` which handles the simplest cases.
The sorted sub-stacks are moved from `b` into `a` with an insertion sort algorithm until the stack `b` is empty.

- **Time Complexity:** O(n√n)

#### 3. Quick Sort (Complex strategy | disorder ≥ 0.5)

The quick sort algorithm consists in recursively dividing a list into two sub-lists with smaller and greater elements than a given value called pivot.

This implementation of quick sort takes advantage of the two stacks structure by employing two function `quick_sort_a` and `quick_sort_b`:
- The `quick_sort_a` moves larger elements than the pivot to stack `b` while leaves the smaller elements in stack `a`.
- The `quick_sort_b` moves smaller elements than the pivot to stack `a` while leaving larger elements in stack `b`.
- Each function `quick_sort_a` and `quick_sort_b` recursively call both of themselves on the corresponding half of substack created by separating the elements.
- When a substack has two or less elements they are moved two stack `a`, this guarantees that eventually all elements are moved back to stack `a` sorted.
- Choice of the pivot: the `pivot` is chosen by taking the median of the values of the current sub-stack (or stack).

- **Time Complexity:** O(n log n)

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
    ---
    ##### NOTE: All flags must be placed BEFORE the number list, otherwise the program exits with an error message.
    ---
    - Force a specific strategy with **--simple**, **--medium**, or **--complex**. Otherwise, the program will use an adaptive strategy based on the calculated disorder of the input:
    ```bash
            ./push_swap --simple 5 4 3 2 1
    ```
    - Print detailed performance metrics with the **--bench** flag, which outputs the data through stderr:
    ```bash
            ./push_swap --bench 5 4 3 2 1 2> bench.txt
    ```
## Resources

- 🇪🇸 Notación Big O | Análisis de algoritmos de forma sencilla -> [Youtube](https://www.youtube.com/watch?v=MyAiCtuhiqQ)
- 🇬🇧 Insertion Sort Algorithm -> [GeeksforGeeks](https://www.geeksforgeeks.org/dsa/insertion-sort-algorithm/)
- 🇬🇧 Quick Sort -> [GeeksforGeeks](https://www.geeksforgeeks.org/dsa/quick-sort-algorithm/)
- 🇬🇧 The Chunked Merge Sort Approach -> [Medium](https://satyadeepmaheshwari.medium.com/sorting-large-datasets-with-limited-memory-the-chunked-merge-sort-approach-318275275c81)

---
**AI Usage:** I used [Claude](https://claude.ai) (Anthropic) as an AI augmentation tool throughout my learning process — breaking the project down into smaller parts before coding, discussing architecture and organization decisions, and getting guidance on documentation writing and evaluation preparation.