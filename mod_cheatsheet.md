# ⚡ LeetCode Cheat Sheet: Modular Arithmetic

### 1. The Big Three Identities (Prevent Overflow)
Use these to keep numbers small inside loops and prevent integer overflow.
* **Addition:** `(a + b) % M = ((a % M) + (b % M)) % M`
* **Subtraction:** `(a - b) % M = ((a % M) - (b % M) + M) % M`
* **Multiplication:** `(a * b) % M = ((a % M) * (b % M)) % M`

---

### 2. The Negative Mod Fix
In **C++, Java, and JavaScript**, `-1 % 5` returns `-1` instead of `4`. Use this formula to force a safe, positive remainder:
* **Formula:** `positive_rem = ((num % M) + M) % M`

---

### 3. The Complement Formula (Pair Sums)
If you have a remainder `rem` and need to find a matching number to make the total sum divisible by `M`:
* **Formula:** `needed_rem = (M - rem) % M`
* *Note: The final `% M` ensures that if `rem` is `0`, the formula safely returns `0` instead of `M`.*

---

### 4. Prefix Sum + Mod Trick (Subarray Sums)
When tracking a running total mod `M`, if the same remainder appears twice, the subarray between those two points is perfectly divisible by `M`.
* **Rule:** If `Prefix[i] % M == Prefix[j] % M`, then `Subarray(i...j) % M == 0`
* *Common Problems:* "Subarray Sum Equals K", "Make Sum Divisible by P"

---

### 5. Fast Powering (Modular Exponentiation)
Never use `pow(base, exp) % M` for huge exponents. Use **Binary Exponentiation** to calculate it in \(O(\log \text{exp})\) time:

```cpp
int modPow(long long base, long long exp, int M) {
    long long res = 1;
    base %= M;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % M;
        base = (base * base) % M;
        exp /= 2;
    }
    return res;
}
```
