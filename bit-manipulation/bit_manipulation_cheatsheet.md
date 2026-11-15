## 1. Fundamental Properties
These algebraic properties allow you to manipulate complex bitwise equations easily.

* **Commutative Property:** The order does not matter.
  ```text
  a ^ b = b ^ a
  ```
* **Associative Property:** Grouping does not matter.
  ```text
  (a ^ b) ^ c = a ^ (b ^ c)
  ```
  You can isolate either variable by XORing both sides with the other. To isolate `b`, XOR both sides by `a`:
  ```text
  a ^ (b ^ c) = c ^ b
  (a ^ b) ^ b = a ^ c   [Associative Property]
  0 ^ b = a ^ c         [Self-Inverse Property: a ^ a = 0]
  b = a ^ c             [Identity Property: 0 ^ b = b]
  ```

* **Identity Property:** XORing with zero changes nothing.
  ```text
  x ^ 0 = x
  ```
* **Self-Inverse Property (Cancellation):** XORing a number with itself cancels out.
  ```text
  x ^ x = 0
  ```
* **Bitwise Boundedness (AND):**
  ```text
  A & B <= MIN(A, B)
  ```
* **Lower Bound Property of Bitwise OR (OR):**
  ```text
  A | B >= MAX(A, B)
  ```
* **Lower Bound Property of Bitwise OR (OR):**
  ```text
  A | B >= MAX(A, B)
  ```
* **Lower Bound Property of Bitwise OR (OR):**
  ```text
  A & (A - 1) = 0
  ```
* **Addition Identity:**
  ```text
  A + B = (A ^ B) + 2 * (A & B)
  A + B = (A | B) + (A & B)
  ```
* **geometric series and binary counting:**
$$2^n > 2^{n-1} + 2^{n-2} + 2^{n-3} + \dots + 2^0$$

$$2^n = (2^{n-1} + 2^{n-2} + 2^{n-3} + \dots + 2^0) + 1$$

---

## 4. Parity of number of set bits in A ^ B
Lets say we've two number A & B
- if set bits combined of A + B is even then parity of set bits of (A ^ B) is also even.
- if set bits combined of A + B is odd then parity of set bits of (A ^ B) is also odd.
- This is becoz XOR operations removes 2 set bits at once
```
A      = 1 0 1 0 1
B      = 0 1 0 1 1
---------------
A ^ B  = 1 1 1 1 0
```
- So the final set bits are 4 and parity of set bits is even. 

## 5. Swap two numbers without temp variable.
```
a = a ^ b
b = a ^ b
a = a ^ b
```

## 4. Subarray Queries Using Prefix XOR
To find the XOR sum of a specific subarray from index `i` to `j` in O(1) time, use a cumulative prefix array `p`.

### The Definition
* `p[j] = arr[0] ^ ... ^ arr[i-1] ^ arr[i] ^ ... ^ arr[j]`
* `p[i-1] = arr[0] ^ ... ^ arr[i-1]`

### The Mathematical Proof
By splitting the full prefix `p[j]` into its constituent components:
```text
p[j] = p[i-1] ^ XOR(i...j)
```
XOR both sides by `p[i-1]` to isolate the subarray target:
```text
p[j] ^ p[i-1] = p[i-1] ^ p[i-1] ^ XOR(i...j)
p[j] ^ p[i-1] = 0 ^ XOR(i...j)                 [Since p[i-1] ^ p[i-1] = 0]
XOR(i...j) = p[j] ^ p[i-1]                     [Since 0 ^ X = X]
```

---

## 5. The O(N) Target Subarray Map Optimization Formula
When asked to count or find subarrays where `XOR(i...j) = k`:

1. Substitute `k` into your proven formula: 
   ```text
   k = p[j] ^ p[i-1]
   ```
2. Rearrange the variables to isolate the historical prefix you need to search for by XORing both sides by `p[j]`:
   ```text
   k ^ p[j] = p[j] ^ p[i-1] ^ p[j]
   k ^ p[j] = (p[j] ^ p[j]) ^ p[i-1]
   k ^ p[j] = 0 ^ p[i-1]
   p[i-1] = k ^ p[j]
   ```

---

## 6. Famous Algorithmic XOR Patterns

### Pattern A: Find the Unique Element
* **Problem:** Every number in an array appears twice except for one. Find it.
* **Proof:** XOR all numbers together. The pairs will cancel out to `0` (`x ^ x = 0`), leaving behind the lonely unique number.

### Pattern B: Continuous Range XOR (1 to N)
The cumulative XOR sum from `1` up to `N` can be found in O(1) without a loop because the pattern repeats every 4 numbers:

| If N % 4 equals | Result is |
| :--- | :--- |
| **0** | N |
| **1** | 1 |
| **2** | N + 1 |
| **3** | 0 |

## 7. Others

### Power of Two Index Check (0-Based Indexing)
* **Problem:** Determine if a 0-based array index represents a position that is a power of 2 (e.g., indices 0, 1, 2, 4, 8...).
* **Proof:** The expression `(i & (i - 1)) == 0` clears the lowest set bit. If the result is 0, the number has exactly one bit set (a power of 2). Because index `0` represents the 1st element (2⁰ = 1), it must be safely included using 
`i == 0 || (i & (i - 1)) == 0`.

### Next Boundary Check (0-Based Range Size)
* **Problem:** Determine if the number of elements from `0` to index `i` (inclusive) forms a total size that is **NOT** a power of 2.
* **Proof:** In 0-based indexing, index `i` means we have processed `i + 1` elements. Substituting `Size = i + 1` into the standard bitwise power-of-two formula `Size & (Size - 1)` yields `(i + 1) & i`. If this evaluates to `!= 0`, the total capacity processed so far is **not** a power of 2 (useful for triggering array resizing/doubling dynamically).

### Mod property
- n % 2^i that means you get back the answer that is the decimal value of the last i bits from right of binary number.
```
mod with 2^1
n = 15 (1111) % 2 = 1
That is the last 1 bit in decimal

mod with 2^2
n = 15 (1111) % 4 = 3
That is the last [0..1] bits in decimal
```