## 📊 Quick-Reference Counting Configurations

### 1. C(n, r) - "n Choose r"
*   **Plain English:** The number of ways to **select a subset** of r items from a pool of n unique items where the **order of selection does not matter**.
*   **Formula:** C(n, r) = n! / (r! * (n - r)!)
*   **CP Mental Trigger:** *"Pick a team of 3 players out of 10 candidates."* (Picking Player A then Player B is identical to picking Player B then Player A).

---

### 2. C(n, r) * r! - Permutation P(n, r)
*   **Plain English:** The number of ways to **select AND arrange** r items out of a pool of n unique items. 
*   **The Intuition:** First, you *choose* the r items (C(n, r) ways). Then, you *shuffle/arrange* those chosen r items in a specific order (r! ways).
*   **Formula:** P(n, r) = n! / (n - r)!
*   **CP Mental Trigger:** *"Assign a Gold, Silver, and Bronze medal to 3 players chosen out of 10 candidates."* (Order matters because being 1st is different than being 3rd).

---

### 3. m^n - Independent Sequences / Grid Configurations
*   **Plain English:** The number of ways to make n total choices, where **each choice has exactly m available options**, and items can be reused infinitely.
*   **The Intuition:** For the 1st slot you have m options, for the 2nd slot you have m options... all the way to the n-th slot.
    m * m * m * ... * m (n times) = m^n
*   **CP Mental Trigger:** *"Find the number of unique strings of length n you can make using only lowercase English letters (m = 26)."* 
*   **Modular Math Connection:** In CP, this is calculated efficiently in O(log n) time using **Binary Exponentiation**.

---

### 4. C(n + k - 1, k - 1) - Stars and Bars (Allowed to be Empty)
*   **Plain English:** The number of ways to distribute `n` identical items into `k` distinct groups or bins where any group can receive zero or more items.
*   **The Intuition:** Imagine `n` identical balls lined up with `k - 1` dividers (bars). Arranging these items and dividers creates unique distributions. Choosing the positions of the `k - 1` bars out of the total `n + k - 1` available slots yields the configuration.
*   **Formula:** Ways = C(n + k - 1, k - 1)
*   **CP Mental Trigger:** *"Find the number of ways to distribute 5 identical resource cards among 2 players."* (Options include one player getting all 5, or splitting them up like 4 and 1).

---

### 5. C(n - 1, k - 1) - Stars and Bars (Strictly Non-Empty Bins)
*   **Plain English:** The number of ways to distribute `n` identical items into `k` distinct groups where **every group must receive at least 1 item**.
*   **The Intuition:** Line up `n` identical balls. This creates `n - 1` spaces between them. To ensure no group is empty, you place `k - 1` dividers into these spaces.
*   **Formula:** Ways = C(n - 1, k - 1)
*   **CP Mental Trigger:** *"Find the number of positive integer solutions to the equation x1 + x2 + x3 = 10 where xi >= 1."*

---

### 6. C(n + r - 1, r) - Non-Decreasing Arrays
*   **Plain English:** The number of ways to build an array of length `r` using numbers from `1` to `n` such that the elements are sorted but **duplicates are allowed** (`arr[i] <= arr[i+1]`).
*   **The Intuition:** This maps directly back to Stars and Bars! Choosing `r` numbers with replacement from `n` possibilities is mathematically identical to distributing `r` identical elements into `n` distinct buckets.
*   **Formula:** Ways = C(n + r - 1, r)
*   **CP Mental Trigger:** *"Count the number of valid arrays of size 4 where 1 <= arr[i] <= 10 and arr[i] <= arr[i+1]."*

---

### 7. Catalan(n) - Balanced Formations & Structure Counting
*   **Plain English:** A magical sequence used to count the number of valid configurations for nested structures (like brackets or tree nodes) of size `n`.
*   **The Intuition:** Calculated cleanly using combinations: `C(2n, n) / (n + 1)`.
*   **Formula:** Catalan(n) = C(2n, n) - C(2n, n - 1)
*   **CP Mental Trigger:** Matches patterns like:
    1. Number of valid matching parenthesis expressions with `n` pairs of `(` and `)`.
    2. Number of unique Binary Search Trees (BSTs) that can be formed using `n` unique keys (LeetCode 96).
    3. Number of ways to polygonally triangulate a convex polygon with `n + 2` vertices.

---

### 8. D(n) - Derangements (Complete Disarrangement)
*   **Plain English:** The number of ways to permute `n` unique elements such that **no element appears in its original starting position**.
*   **The Intuition:** Computed using a simple subproblem relation. For an element at index `i`, you either swap it with another element (reducing the problem to `n-2`), or place it in a spot that changes the remaining problem size to `n-1`.
*   **Formula:** D(n) = (n - 1) * (D(n - 1) + D(n - 2))  *(Base cases: D(0)=1, D(1)=0)*
*   **CP Mental Trigger:** *"There are n secret santa participants. Find the number of ways to distribute gifts so that nobody receives their own gift."*

---

