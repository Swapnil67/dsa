# 📌 Essential Array, Pointer, and Indexing Math Patterns

## 1. Subarray Count & Window Length (Inclusive)
Use this when you want to count all elements or subarrays between two pointers, including both ends.

### Formula
```text
Length = Right - Left + 1
```

### Visual Anchor
```text
Indices:  0   1   2   3   4   5   6
Array:   [_,  A,  B,  C,  D,  E,  _]
              ^               ^
             Left            Right
            (idx 1)         (idx 5)

Math: 5 - 1 + 1 = 5 elements inside the window: [A, B, C, D, E]
Note: We add 1 because single elements (like [E]) count as valid subarrays.
```

---

## 2. Window Length (Exclusive)
Use this when you want to count the elements *between* two boundaries, excluding the boundary pointers themselves.

### Formula
```text
Length = Right - Left - 1
```

### Visual Anchor
```text
Indices:  0   1   2   3   4   5   6
Array:   [_,  A,  B,  C,  D,  E,  _]
              ^               ^
             Left            Right
            (idx 1)         (idx 5)

Math: 5 - 1 - 1 = 3 elements strictly between them: [B, C, D]
```

---

## 3. Subarray Tracking & Counting Patterns
These two formulas are absolute lifesavers for **Sliding Window** and **Prefix Sum / Hash Map** problems (like finding subarrays that equal a target value or meet a condition).

### Pattern A: Number of valid subarrays ending exactly at 'j' (with start >= i)
* **When to use:** Used heavily in **Sliding Window** loops. Every time you expand your window by moving the right pointer `j`, this tells you how many *new* valid subarrays are created ending at `j`.

#### Formula
```text
Count = j - i + 1
```

#### Visual Anchor
```text
Indices:  0   1   2   3   4   5   6
Array:   [_,  A,  B,  C,  D,  E,  _]
              ^               ^
              i               j

All subarrays ending at E (idx 5) whose starting point doesn't cross left of i (idx 1):
1. [E]          -> Single element (starts at idx 5)
2. [D, E]       -> Starts at idx 4
3. [C, D, E]    -> Starts at idx 3
4. [B, C, D, E] -> Starts at idx 2
5. [A, B, C, D, E] -> Starts at idx 1

Math: 5 - 1 + 1 = 5 valid subarrays.
```

### Pattern B: Number of subarrays starting at 'j' extending to the end of the array
* **When to use:** Used heavily in **Prefix Sum + Hash Map** problems. If you find a valid match at index `j`, and you want to know how many total subarrays can be built using this valid starting point all the way to the end of the array (size `n`).

#### Formula
```text
Count = n - j
```

#### Visual Anchor
```text
Indices:  0   1   2   3   4   5   6   (Total elements n = 7)
Array:   [_,  _,  _,  _,  _,  E,  F]
                              ^
                              j (idx 5)

All subarrays starting at E (idx 5) stretching towards the end of the array:
1. [E]       -> Ends at idx 5
2. [E, F]    -> Ends at idx 6 (The last element)

Math: 7 - 5 = 2 valid subarrays.
```

---

## 4. Counting Pairs between Two Pointers
Use these patterns when you need to count pairs during **Two-Pointer** or **Sliding Window** problems. 
*(Note: A pair requires 2 different items, so you cannot pair an item with itself. Thus, we do NOT add 1).*

### Case A: Number of pairs ending exactly at 'j' (with start >= i)
* **Perspective:** You stand at `j` (the end) and look **backward** to pair up with every person up to the boundary line `i`.

#### Formula
```text
Pairs = j - i
```

#### Visual Anchor
```text
Indices:  0   1   2   3   4   5   6
Array:   [_,  A,  B,  C,  D,  E,  _]
              ^               ^
              i               j

Pairs ending at E (idx 5) that start at or after A (idx 1):
1. (D, E),  2. (C, E),  3. (B, E),  4. (A, E)

Math: 5 - 1 = 4 valid pairs.
```

### Case B: Number of pairs starting exactly at 'i' (with end <= j)
* **Perspective:** You stand at `i` (the start) and look **forward** to pair up with every person up to the boundary line `j`.

#### Formula
```text
Pairs = j - i
```

#### Visual Anchor
```text
Indices:  0   1   2   3   4   5   6
Array:   [_,  A,  B,  C,  D,  E,  _]
              ^               ^
              i               j

Pairs starting at A (idx 1) that end at or before E (idx 5):
1. (A, B),  2. (A, C),  3. (A, D),  4. (A, E)

Math: 5 - 1 = 4 valid pairs.
```

### Case C: Handshake Lemma & Unique Pairings (Unordered Pairs)
Use this when you want to count the number of unique, unordered pairs that can be formed from a group of elements, such as finding matching pairs in an array or counting unique connections.

### Formula
```text
Pairs = (Count * (Count - 1)) / 2
```

### Visual Anchor
```text
Elements:   A, B, C, D  (Count = 4)

Connections:
  A ─── B     A ─── C     A ─── D
  B ─── C     B ─── D     C ─── D

Math: (4 * 3) / 2 = 6 unique pairs.
Note: Order does not matter. The pair (A, B) is identical to (B, A), which is why we divide by 2 to prevent double counting.
```


## 5. Mathematical & Algorithmic Ways to Count Subsets

Use these core formulas and structural rules whenever a problem asks you to calculate, filter, or evaluate combinations of elements within an array or set of size \(N\).

---

### Pattern A: Total Power Set Count (No Restrictions)
* **Definition:** The total number of all possible unique combinations you can pull from a set, including the empty set and the set itself. Elements do not need to be consecutive, and order does not matter.
* **Core Rule:** For each of the \(N\) items, you make a binary choice: either **Include** (\(1\)) or **Exclude** (\(0\)).

#### Formula
```text
Total Subsets = 2^N
```

#### Visual Execution
```text
Array: [A, B, C] (N = 3)

Decisions:   A      B      C
           / \    / \    / \
          0   1  0   1  0   1

Math: 2 * 2 * 2 = 2^3 = 8 total subsets.
```

---

### Pattern B: Size-Bounded Subsets (Exactly 'K' Elements)
* **Definition:** You want to count only the subsets that contain exactly \(K\) elements out of a pool of \(N\) items. This uses the combinatoric "Choose" function (Binomial Coefficient).

#### Formula
```text
Subsets of size K = N! / (K! * (N - K)!)  -->  written as C(N, K) or nCr
```

#### Visual Execution
```text
Array: [A, B, C, D] (N = 4), looking for subsets of size K = 2.

Combinations: (A,B), (A,C), (A,D), (B,C), (B,D), (C,D)

Math: C(4, 2) = 4! / (2! * 2!) = 24 / 4 = 6 valid subsets.
```

---

### Pattern C: Consecutive Subsets (Subarrays / Contiguous Blocks)
* **Definition:** Subsets where the chosen elements must be strictly adjacent/consecutive in the original array. Elements cannot be skipped.
* **Core Rule:** Every non-empty consecutive subset is uniquely defined by choosing 1 starting boundary and 1 ending boundary. 

#### Formula
```text
Non-Empty Consecutive Subsets = (N * (N + 1)) / 2
Total (Including Empty Set)    = ((N * (N + 1)) / 2) + 1
```

#### Visual Execution
```text
Array: [A, B, C] (N = 3)

Subarrays: [A], [B], [C], [A,B], [B,C], [A,B,C]

Math: (3 * 4) / 2 = 6 non-empty subsets.
```

---

### Pattern D: Non-Consecutive Subsets (No Two Adjacent Elements)
* **Definition:** You want to find subsets where you are **forbidden** from picking any two elements that sit right next to each other in the original array. 
* **Core Rule:** This structural restriction natively generates the sequence of **Fibonacci numbers**.

#### Formula
```text
Valid Subsets = Fib(N + 2) 
(where Fib(1)=1, Fib(2)=1, Fib(3)=2, Fib(4)=3, Fib(5)=5, etc.)
```

#### Visual Execution
```text
Array: [A, B, C] (N = 3)

Valid:   [] (Empty set works)
         [A], [B], [C] (Single items can't be adjacent)
         [A, C] (Valid because B is skipped!)
Invalid: [A, B], [B, C], [A, B, C]

Math: Fib(3 + 2) = Fib(5) = 5 valid subsets.
```

---

### Pattern E: Conditional Counting (Dynamic Programming Target Sum)
* **Definition:** You are given an array of integers and must count how many subsets add up to a precise `Target` value.
* **Core Rule:** Instead of a mathematical formula, you build an \(O(N \times \text{Target})\) state table mapping the choice tree: `dp[i][j] = dp[i-1][j] + dp[i-1][j - arr[i]]`.

#### Visual Execution Matrix
```text
Array: [2, 3, 5], Target = 5

      Target Sum (j) ->  0  1  2  3  4  5
Item (i) 
  [ ] (Base case)       1  0  0  0  0  0
  [2]                   1  0  1  0  0  0
  [3]                   1  0  1  1  0  1  <-- One way to get 5: [2, 3]
  [5]                   1  0  1  1  0  2  <-- Two ways to get 5: [2, 3] or [5]

Result: dp[N][Target] = 2 valid subsets.
```


## 6. Circular Array Indexing (The Clock Pattern)
Use this to seamlessly wrap back to the start or end of an array when stepping out of bounds.

### Formulas
* **Move Forward:**  `Next = (Current + 1) % Length`
* **Move Backward:** `Prev = (Current - 1 + Length) % Length`

### Visual Anchor
```text
Index:     0 -> 1 -> 2 -> 3
          ^               |  (Wraps around)
          |_______________v
          
Array:   [A,  B,  C,  D]  (Length = 4)

If Current = 3 (Element D):
Forward:  (3 + 1) % 4 = 0 -> Loops back to [A]
Backward: (3 - 1 + 4) % 4 = 2 -> Moves back to [C]
```

---

## 6. 2D Grid to 1D Array Flattening
Use this to store a 2D matrix (`Rows x COLS`) into a flat, linear array.

### Formulas
* **2D Coordinates to 1D Index:** `Linear_Index = (r * COLS) + c`
* **1D Index back to 2D Coordinates:** `r = Linear_Index / COLS` and `c = Linear_Index % COLS`

### Visual Anchor
```text
2D Grid (2 Rows, 3 Columns):          1D Flattened Array:
      c=0  c=1  c=2
r=0  [ A,   B,   C ]             [ A,  B,  C,  D,  E,  F ]
r=1  [ D,   E,   F ]               0   1   2   3   4   5

Example for element 'E' at r=1, c=1 (COLS = 3):
2D -> 1D: (1 * 3) + 1 = 4
1D -> 2D: r = 4 / 3 = 1 | c = 4 % 3 = 1
```

---

## 7. Binary Heap (Array-Based Tree)
Use this when a binary tree is packed into a flat array level by level.

### Formulas
* **Left Child:**   `Left  = (2 * Parent) + 1`
* **Right Child:**  `Right = (2 * Parent) + 2`
* **Parent:**       `Parent = (Child - 1) / 2`  (Integer division drops remainder)

### Visual Anchor
```text
Tree Structure:               Array Representation:
       A (idx 0)              Indices:  0   1   2   3   4   5
      / \                     Array:   [A,  B,  C,  D,  E,  F]
     B   C
    / \   \
   D   E   F                  Parent of E (idx 4): (4 - 1) / 2 = 1 -> [B]
```

---

## 8. Fast Round-Up Division
Use this to find how many chunks/containers of size `X` you need to fit a total size of `Y` without using floating-point math.

### Formula
```text
Total_Chunks = (Y + X - 1) / X
```

### Visual Anchor
```text
Task: Fit Y = 7 items into boxes of size X = 3.

Math: (7 + 3 - 1) / 3 
    = 9 / 3 
    = 3 boxes needed.

Visual: [ * * * ] [ * * * ] [ * ]  -> 3 boxes full/partially full.
```
