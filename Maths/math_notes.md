# Math For DSA & CP

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
