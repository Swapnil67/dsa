# ⚡ Ultimate XOR Bitwise Cheat Sheet

A quick-reference guide for the properties, mathematical proofs, and common algorithmic patterns of the **Exclusive OR (XOR)** operation.

---

## 1. Core Mechanics & Truth Table
The XOR operation (`^`) outputs `1` (true) only when the two inputs are **different**.

| Input A | Input B | Output (A ^ B) |
| :---: | :---: | :---: |
| 0 | 0 | **0** |
| 0 | 1 | **1** |
| 1 | 0 | **1** |
| 1 | 1 | **0** |

* **💡 Intuition:** Think of bitwise XOR as **addition without carrying**.

---

## 2. Fundamental Properties
These algebraic properties allow you to manipulate complex bitwise equations easily.

* **Commutative Property:** The order does not matter.
  ```text
  a ^ b = b ^ a
  ```
* **Associative Property:** Grouping does not matter.
  ```text
  (a ^ b) ^ c = a ^ (b ^ c)
  ```
* **Identity Property:** XORing with zero changes nothing.
  ```text
  x ^ 0 = x
  ```
* **Self-Inverse Property (Cancellation):** XORing a number with itself cancels out.
  ```text
  x ^ x = 0
  ```

---

## 3. The Equation Reversal Proof
If you know that:
```text
a ^ b = c
```
You can isolate either variable by XORing both sides with the other. To isolate `b`, XOR both sides by `a`:
```text
a ^ (a ^ b) = a ^ c
(a ^ a) ^ b = a ^ c   [Associative Property]
0 ^ b = a ^ c         [Self-Inverse Property: a ^ a = 0]
b = a ^ c             [Identity Property: 0 ^ b = b]
```

---

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
