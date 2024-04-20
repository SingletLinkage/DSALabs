# DATA STRUCTURES

Data structures are specialized formats for storing and organizing data in computer memory. They determine how efficiently data can be accessed, manipulated, and updated.

- `Arrays`: Ordered collections of elements of the same data type, accessed using a numerical index. **Efficient for random access but slower for insertions/deletions in the middle**.
- `Linked Lists`: Elements (nodes) contain data and a reference (pointer) to the next node, forming a linear chain. **Flexible for insertions/deletions but slower for random access**.
- `Stacks`: LIFO (Last-In-First-Out) principle, like a stack of plates. Used for **function calls, undo/redo operations**.
- `Queues`: FIFO (First-In-First-Out) principle, like a queue for a service. Used for **task scheduling, managing waiting processes**.
- `Trees`: Hierarchical structures with a root node, child nodes, and potentially siblings. Efficient for **searching and sorting**.
- `Graphs`: Collections of nodes (vertices) connected by edges. Used for **modeling networks, relationships between entities**.


# ALGORITHMS

An `algorithm` is a *procedure to accomplish a specific task*.

Algorithms are required to solve a computational problem. They have to solve them **correctly** and **efficiently**.

## Time Complexity

It does not denote the actual time (in seconds) taken by an algorithm to produce an output.  

By time we mean **clock cycle**. A clock cycle, or simply a ”cycle,” is a *single electronic pulse of a CPU*. During each cycle, a CPU can *perform a basic operation* such as fetching an instruction, accessing memory, or writing data.

Time complexity tells us how the time taken by an algorithm grows as the size of the input increases. It expresses the time taken as a function of input size. 

## Space Complexity

Space complexity refers to the amount of memory space the algorithm needs to run. This includes space for temporary variables and any data structures used internally.

When analyzing space complexity, we often break down the memory usage into two categories for better understanding:

- `Input space`: This refers to the **space occupied by the actual input data** itself. For instance, if you're sorting an array of numbers, the space used by the array is considered input space.

- `Auxiliary space`: This is the **extra space used by the algorithm** for temporary variables, data structures it creates internally (like temporary arrays during sorting), and any other overhead needed for computations. It's essentially the additional memory footprint the algorithm creates on top of the input.


### RAM Model:
Machine-independent algorithm design depends upon a hypothetical computer called the `Random Access Machine` or RAM. Under this model of computation, we are confronted with a computer where:
- Each simple operation (+, *, –, =, if, call) takes exactly one time step.
- Loops and subroutines are not considered simple operations. Instead, they are the composition of many single-step operations and are, hence, analyzed separately. 
- Each memory access takes exactly one time step. Further, we have as much memory as we need. The RAM model takes no notice of whether an item is in cache or on the disk.
  
Under the RAM model, we measure run time by counting up the number of steps an algorithm takes on a given problem instance.

### Master Theorem:

Consider `T(n) = a * T(n/b) + c(n)` :
- Length of recursion depth: `log_b (n)`
- Width of End Level : `a ^ (log_b (n)) = n ^ (log_b (a))`

T(n) = sum of all level times
     = a * T(n/b) + a^2 + T(n/b^2) + ... Theta (n ^ log_b (a))

- If prblm gets easier `c(n) = Omega(n^(log_b (a) + e)` -> T(n) = Theta(root node) = `Theta(c(n))`
- If prblm gets harder `c(n) = O(n^(log_b (a) - e)`-> T(n) = Theta(leaf nodes) = `Theta (n^log_b(a))`
- If prblm is evenly distributed `c(n) = Theta(n^(log_b (a)))`-> `T(n) = Theta(log_b(n) * n^log_b(a))`

For `c(n) = O(n^k)` ***Compare `k` and `log_b (a)` => `T(n) = Theta(n^max)`*** for unequal values and `T(n) = (log_b (n) * n^k)` for equal value of n and log_b (n).

### Advanced Master Theorem:

Consider `T(n) = a * T(n/b) + Theta(n^k * log^p (n))` :

- For `log_b (a) > k` : `T(n) = Theta(n^(log_b (a)))`
  
- For `log_b (a) < k` : 
  - `p >= 0` : `T(n) = Theta(c(n))` -- copy paste c(n)
  - `p < 0 ` : `T(n) = Theta(n^k)` -- abv + ignore log^(-ve)
  
- For `log_b (a) = k` :
  - `p > -1` : `T(n) = Theta(n^k * log^(p+1) n)` -- just multiply c(n) with log(n)
  - `p = -1` : `T(n) = Theta(n^k + log log n)` -- abv + replace log^0 with log(log())
  - `p < -1` : `T(n) = Theta(n^k)` -- abv + ignore log^(-ve)


## Asymptotic Analysis

- `Big O notation (O-notation):` This notation describes an asymptotically tight upper bound on the growth rate of a function. It signifies that there exist positive constants c and n0 such that `for all n > n0, f(n) <= c * g(n)`, where g(n) in another function used as the reference point. In simpler terms, O-notation tells us how fast a function grows in the worst case scenario, ignoring constant factors.

- `Big theta notation (Θ-notation):` This notation describes a tight bound on the growth rate of a function. It signifies that there exist positive constants c1, c2, and n0 such that `for all n > n0, c1 * g(n) <= f(n) <= c * g(n)`. Essentially, Θ-notation captures the exact growth rate of a function, considering both the lower and upper bounds.

- `Big omega notation (Ω-notation)`: This notation describes a tight lower bound on the growth rate of a function. It signifies that there exist positive constants c and n0 such that `for all n > n0, f(n) >= c * g(n)`, where g(n) is another function used as the reference point. In other words, Ω-notation tells us how fast a function must grow in the best case scenario, ignoring constant factors.

- `Little o notation (o-notation):` This notation describes a function that grows slower than another function as the input size (n) approaches infinity. Formally, for any positive constant c, there exists a constant n0 such that `for all n > n0, the f(n) < c * g(n)`. In simpler terms, o-notation indicates that the first function becomes insignificant compared to the second function as n grows very large.

- `Little omega notation (ω-notation)`: This notation describes a function that grows faster than another function as the input size (n) approaches infinity. Formally, for any positive constant c, there exists a constant n0 such that `for all n > n0, the f(n) > c * g(n)`. In simpler terms, ω-notation indicates that the first function grows much faster than the second function as n becomes very large.

`Note:` In the last two cases, the bounds are loose, i.e., *f(n) is strictly less/greater than g(n)* unlike for Theta/Omega of n.


## Correctness

### Loop Invariant:
Loop invariance is a property that remains true before and after each iteration of loop.  
We use loop invariants to help us understand why an algorithm is correct. We must show three things about a loop invariant:

- `Initialization`: It is true prior to the first iteration of the loop.
- `Maintenance`: If it is true before an iteration of the loop, it remains true before the next iteration.
- `Termination`: When the loop terminates, the invariant gives us a useful property that helps show that the algorithm is correct.
