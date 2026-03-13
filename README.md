# Push_swap

**This project has been created as part of the 42 curriculum by dtaylor and gefada.**

---

# Overview

**Push_swap** is an algorithmic challenge that consists of sorting a list of integers using only two stacks (`a` and `b`) and a restricted set of operations.

The objective is to produce the shortest possible sequence of operations that leaves stack `a` sorted in ascending order.

The difficulty lies not only in sorting the numbers but in doing so efficiently within the constraints of the available operations.

To address this, the program implements four different sorting strategies and automatically selects the most suitable one based on the disorder index of the input data.

---

# Available Operations

| Operation | Description |
|-----------|-------------|
| `sa` / `sb` | Swap the first two elements of stack `a` / `b` |
| `ss` | Perform `sa` and `sb` simultaneously |
| `pa` / `pb` | Push the top element from `b` to `a` / from `a` to `b` |
| `ra` / `rb` | Rotate stack `a` / `b` upward (first element becomes last) |
| `rr` | Perform `ra` and `rb` simultaneously |
| `rra` / `rrb` | Reverse rotate stack `a` / `b` (last element becomes first) |
| `rrr` | Perform `rra` and `rrb` simultaneously |

---

# Installation

Compile the project using:

```bash
make
```
# Usage

```bash
./push_swap [--bench] [--simple | --medium | --complex | --adaptive] <list of integers>
```
## Strategy Selection (Optional)

| Flag | Description |
|-----|-------------|
| `--simple` | Force the **O(n²)** algorithm |
| `--medium` | Force the **O(n√n)** algorithm |
| `--complex` | Force the **O(n log n)** algorithm |
| `--adaptive` | Automatically select the best algorithm (**default behavior**) |

---

# Benchmark Mode (Optional)

```bash
./push_swap --bench --adaptive 4 67 3 87 23 2> bench.txt | ./checker_linux 4 67 3 87 23
```

When `--bench` is enabled, the program outputs the following information to **stderr**:

- Disorder index  
- Selected algorithm  
- Total number of operations  
- Operation breakdown by type  

This makes it easier to evaluate and compare algorithm performance.
**Note:** `--bench` must be the first flag if used.

---

# Examples

```bash
# Sort 5 numbers using the adaptive strategy
./push_swap 3 1 4 1 5

# Force the simple algorithm and verify the result
./push_swap --simple 5 4 3 2 1 | ./checker_linux 5 4 3 2 1

# Count operations for 100 random numbers
shuf -i 0-999 -n 100 | tr '\n' ' ' | xargs ./push_swap | wc -l
```

# Error Handling

The program prints **`Error`** to `stderr` in the following cases:

- Non-integer arguments  
- Integers outside the `int` range  
- Duplicate values  

---

# Implemented Algorithms

## Disorder Index

Before choosing a sorting strategy, the program computes a disorder index, a value between:

- **0 → perfectly sorted**
- **1 → completely disordered**

It is calculated using the proportion of **inverted pairs** in the input:

```
disorder = number of pairs (i, j) where i < j and a[i] > a[j]
           ---------------------------------------------------
                     total number of pairs
```

This metric provides a quick estimate of how far the input is from being sorted.

---

# Sorting Strategies

## 1. Simple Algorithm — O(n²)

### Minimum / Maximum Extraction

This strategy repeatedly extracts the **minimum (or maximum)** value from stack `a` and pushes it into stack `b`.

### Process

1. Find the position of the smallest element in `a`.
2. Rotate `a` (`ra` or `rra`) to bring it to the top with the fewest moves.
3. Push it to `b` using `pb`.
4. Repeat until only one element remains in `a`.
5. Push all elements back from `b` to `a`.

### Complexity

**O(n²)** operations in the Push_swap model, since each extraction may require up to **O(n)** rotations.

### When it is used

- When the disorder index is very low (< 0.2)
- When the `--simple` flag is used

This method works well for small or nearly sorted inputs.

---

## 2. Medium Algorithm — O(n√n)

### Chunk-based Sorting

This strategy divides the value range into chunks of size √n and moves them from stack `a` to stack `b` in groups.

### Process

1. Normalize values to indices `[0, n-1]`.
2. Divide them into **√n chunks**.
3. Scan stack `a` and push elements belonging to the current chunk to `b`.
4. Once all elements are in `b`, retrieve them by repeatedly selecting the largest element.

### Complexity

**O(n√n)** operations.

Each chunk requires scanning stack `a`, and the retrieval phase also requires rotations.

### When it is used

- **Moderate disorder (0.2 ≤ disorder < 0.5)**
- When the `--medium` flag is used

This approach offers a good balance between simplicity and performance.

---

## 3. Complex Algorithm — O(n log n)

### Radix Sort (LSD)

This is an adaptation of **Radix Sort (Least Significant Digit)** to the Push_swap constraints.

Sorting is performed bit by bit, starting from the least significant bit.

### Process

1. Normalize values to `[0, n-1]`.
2. For each bit position:
   - If the current bit is **0**, push the element to `b`.
   - If the bit is **1**, rotate `a`.
3. Move everything back from `b` to `a`.
4. Repeat for all bits.

### Complexity

**O(n log n)** operations.

Each bit requires a full pass over the stack.

### When it is used

- **High disorder (≥ 0.5)**
- When the `--complex` flag is used

This is the most reliable algorithm for large random inputs.

---

# Adaptive Strategy

The adaptive mode selects the algorithm based on the disorder index:

| Disorder Index | Selected Algorithm | Complexity |
|----------------|-------------------|------------|
| `< 0.2` | Minimum extraction | ~O(n) |
| `0.2 – 0.5` | Chunk sorting | O(n√n) |
| `≥ 0.5` | Radix sort | O(n log n) |

### Why these thresholds?

- **0.2:** If the list is nearly sorted, only a few corrections are needed.  
- **0.5:** Above this level the permutation behaves almost randomly, making Radix sort consistently more efficient.

---

# Team Contributions

Although both team members collaborated across the project, the main responsibilities were:

## Dylan (`dtaylor-`)

- Implementation of all stack operations  
- Development of the adaptive strategy  
- Implementation of the **chunk-based algorithm (O(n√n))**

## George (`gefada`)

- Argument validation and error handling  
- Implementation of the **simple algorithm (O(n²))**  
- Implementation of **Radix Sort (O(n log n))**

Both contributors participated in **code reviews, debugging, and performance testing**.

---

# Expected Performance

| Input Size | Minimum (pass) | Good | Excellent |
|------------|---------------|------|-----------|
| 100 numbers | < 2000 ops | < 1500 ops | < 700 ops |
| 500 numbers | < 12000 ops | < 8000 ops | < 5500 ops |

---

# Resources

## References

- *The Art of Computer Programming, Vol. 3: Sorting and Searching* — Donald Knuth  
- Radix Sort — https://en.wikipedia.org/wiki/Radix_sort  
- Push_swap Visualizer — https://github.com/o-reo/push_swap_visualizer  
- Sorting visualizations — https://visualgo.net/en/sorting  

---

# Use of AI

During development, AI (**Claude**) was used for:

- Clarifying **Big-O complexity** in the context of Push_swap operations  
- Generating **test cases** for algorithm validation  
- Reviewing the **index normalization logic** for Radix Sort  
- Assisting with the **writing and structure of this README**

All implemented code was **written, reviewed, and fully understood by the contributors before submission**.
