# Math For DSA & CP

- Quick Tricks

- gcd(a, 1) = 1
- gcd(a, b) = 1  then (a, b) = co-prime numbers.

# 📚 Essential Modular Arithmetic Properties for DSA & CP

## 1. Addition Property
Formula: `(a + b) % k = ((a % k) + (b % k)) % k`

* **C++/Java Safe Code:** `long long ans = ((a % k + b % k) % k + k) % k;`
* **Example:** Let a = 14, b = 17, k = 5
  * **Direct:** (14 + 17) % 5 = 31 % 5 = 1
  * **Property:** ((14 % 5) + (17 % 5)) % 5 = (4 + 2) % 5 = 6 % 5 = 1

---

## 2. Subtraction Property
Formula: `(a - b) % k = ((a % k) - (b % k)) % k`

* **C++/Java Safe Code:** `long long ans = ((a % k - b % k) % k + k) % k;` (The +k % k prevents negative remainder bugs)

### ⚠️ The Negative Remainder Trap (Why we do `+ k) % k`)
In C++ and Java, the `%` operator preserves the sign of the numerator. If your prefix sum or calculation results in a negative number, standard modulo returns an incorrect negative remainder.

* **The Problem:** Let's say a calculation gives `-2`, and `k = 5`.
  * **Mathematical Modulo:** -2 % 5 should equal `3`.
  * **C++/Java Compiler:** `-2 % 5` returns `-2`.
* **The Fix:** Use the formula `((rem % k) + k) % k`.
  1. `-2 % 5` = `-2`
  2. `-2 + 5` = `3`  *(Shifted safely into positive territory)*
  3. `3 % 5` = `3`   *(Final safety wrapper)*
  
* **Example:** Let a = 12, b = 19, k = 7
  * **Direct:** (12 - 19) % 7 = -7 % 7 = 0
  * **Property:** ((12 % 7) - (19 % 7)) % 7 = (5 - 5) % 7 = 0

---

## 3. Multiplication Property
Formula: `(a * b) % k = ((a % k) * (b % k)) % k`

* **C++/Java Safe Code:** `long long ans = ((a % k) * (b % k)) % k;`
* **Example:** Let a = 12, b = 13, k = 10
  * **Direct:** (12 * 13) % 10 = 156 % 10 = 6
  * **Property:** ((12 % 10) * (13 % 10)) % 10 = (2 * 3) % 10 = 6

---

## 4. Division Property
Formula: `(a / b) % k = (a * b^-1) % k`

* **C++/Java Safe Code:** `long long ans = ((a % k) * modularInverse(b, k)) % k;`
* **Rule:** You cannot divide directly. Instead, you multiply by the Modular Multiplicative Inverse (b^-1). This inverse only exists if gcd(b, k) = 1.
* **Example:** Let a = 12, b = 4, k = 7 (We want to find (12 / 4) % 7, which should be 3)
  1. Find 4^-1 % 7. We need a number x such that (4 * x) % 7 = 1. Testing values, 4 * 2 = 8, and 8 % 7 = 1. So, the inverse is 2.
  2. Apply Property: (12 * 2) % 7 = 24 % 7 = 3.


## 5. Rules for LCM and GCD (When Divisible)
When two positive integers `a` and `b` divide each other perfectly (with a remainder of `0`), you do not need to calculate their LCM or GCD. You can use these shorthand rules:

* **LCM** is always the **larger** number.
* **GCD** is always the **smaller** number.

---

### 🧮 Rule Matrix

| If this condition is true... | Meaning | Least Common Multiple (LCM) | Greatest Common Divisor (GCD) | Example numbers |
| :--- | :--- | :--- | :--- | :--- |
| **`a % b == 0`** | `b` is a factor of `a` | **LCM(a, b) = a** | **GCD(a, b) = b** | LCM(20, 5) = 20<br>GCD(20, 5) = 5 |
| **`b % a == 0`** | `a` is a factor of `b` | **LCM(a, b) = b** | **GCD(a, b) = a** | LCM(5, 20) = 20<br>GCD(5, 20) = 5 |

---

### 💡 Why It Works (Mathematical Proof)
This logic relies on the fundamental theorem relating LCM and GCD:
`LCM(a, b) * GCD(a, b) = a * b`

If `b % a == 0`, we know by definition that the greatest common divisor is `a` (`GCD(a, b) = a`). Substituting `a` back into the formula gives:
`LCM(a, b) * a = a * b`

Divide both sides by `a`:
`LCM(a, b) = b`


# 📚 Essential Division Arithmetic Properties for DSA & CP

## 1. Divisor Generation Property
Formula: If $N = p_1^{a_1} \cdot p_2^{a_2} \cdots p_n^{a_n}$, then any divisor $d$ is given by $d = p_1^{b_1} \cdot p_2^{b_2} \cdots p_n^{b_n}$ where $0 \le b_i \le a_i$.

* **C++/Java Safe Code:**
```cpp
// Generates all divisors using prime factorization
void getDivisors(int idx, long long current, vector<pair<long long, int>>& factors, vector<long long>& divisors) {
    if (idx == factors.size()) {
        divisors.push_back(current);
        return;
    }
    long long factor = 1;
    for (int i = 0; i <= factors[idx].second; i++) {
        getDivisors(idx + 1, current * factor, factors, divisors);
        if (i < factors[idx].second) factor *= factors[idx].first;
    }
}
```
* **Example:** Let $N = 12$
  * **Prime Factorization:** $12 = 2^2 \cdot 3^1$ (where $p_1=2, a_1=2$ and $p_2=3, a_2=1$)
  * **Exponents Range:** $b_1 \in \{0, 1, 2\}$, $b_2 \in \{0, 1\}$
  * **Combinations:** 
    * $2^0 \cdot 3^0 = 1$
    * $2^0 \cdot 3^1 = 3$
    * $2^1 \cdot 3^0 = 2$
    * $2^1 \cdot 3^1 = 6$
    * $2^2 \cdot 3^0 = 4$
    * $2^2 \cdot 3^1 = 12$
  * **Total Divisors:** $(2 + 1) \cdot (1 + 1) = 3 \cdot 2 = 6$ divisors $
ightarrow \{1, 2, 3, 4, 6, 12\}$

# 📌 Divisor Parity Property (Odd vs. Even Count)

## 1. Core Rule
Divisors always pair up as $\left(d, \frac{N}{d}\right)$. The total count of divisors $\tau(N)$ is **always even**, unless the number is a **perfect square**, which yields an **odd** count because $\sqrt{N}$ pairs with itself.

> **💡 CP Theorem:** A number has an **odd number of divisors** if and only if it is a **perfect square**.

---

## 2. Direct Examples

* **Non-Perfect Square ($N = 12$):** Pairs are $(1, 12), (2, 6), (3, 4) \implies$ **6 divisors** (Even)
* **Perfect Square ($N = 36$):** Pairs are $(1, 36), (2, 18), (3, 12), (4, 9), \mathbf{(6, 6)} \implies$ **9 divisors** (Odd)

---

## 3. CP/OA Optimization Trick

### Problem
Count how many numbers in the range $[1, K]$ have an **odd number of divisors**.

### Efficient Approach
Instead of calculating divisors for every number, simply count the **perfect squares** up to $K$.

### C++ Code ($O(1)$ Time)
```cpp
long long countOddDivisorNumbers(long long K) {
    return (K < 0) ? 0 : std::sqrt(K);
}
```
