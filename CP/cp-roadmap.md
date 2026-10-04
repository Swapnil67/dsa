# 3-Month MAANG OA Preparation Plan (CP Transition)

This plan is optimized for candidates who already have a strong foundation (**700+ LeetCode problems solved**) and are pivoting to Competitive Programming (CP) to crack modern, plagiarism-resistant Online Assessments (OAs).

| Rating Sheet | Suggested Pace | Days to Complete | Execution Strategy for OA Prep |
| :--- | :--- | :--- | :--- |
| **800 – 1000**<br>*(3 Sheets)* | 8–10 problems / day | **1 day** per sheet | **Speed Run:** Use these strictly to adjust to Codeforces' input/output syntax, tricky corner cases, and basic math/ad-hoc reasoning. |
| **1100 – 1200**<br>*(2 Sheets)* | 4–5 problems / day | **6 to 8 days** total | **Transition:** Focus on greedy logic and array manipulation. Code them quickly to build fluid implementation speed. |
| **1300 – 1500**<br>*(3 Sheets)* | 2–3 problems / day | **10 to 14 days** per sheet | **The OA Sweet Spot:** This is the most crucial bracket for placements. Master the constructive algorithms, prefix sums, binary search variations, and bit manipulation concepts here. |
| **1600 – 1700**<br>*(2 Sheets)* | 1–2 problems / day | **15 to 20 days** per sheet | **Hard OA Tier:** Focus deeply on optimized dynamic programming (DP), graph traversals, and combinatorics. |
| **1800 – 1900**<br>*(2 Sheets)* | 1 problem / day | **31 days** per sheet | **Advanced / Optional:** Tackle these only if you have remaining time before your placements. They match LeetCode Hard / advanced standard interview questions. |

---

## 📅 Phase 1: The Transition & Speed Building (Weeks 1 – 4)
**Goal:** Master Codeforces input/output conventions, adapt to dense mathematical problem descriptions, and eliminate execution speed bottlenecks.

* **Daily Target:** 2 to 3 problems per day.
* **Codeforces Focus:** Skip 800–1000 entirely. Complete the **1100 and 1200 rating** brackets of the CP-31 sheet.
* **Core Logic & Patterns:**
  * **Constructive Algorithms:** Building arrays/strings that satisfy highly specific boundary conditions.
  * **Invariants:** Recognizing properties (like sum parity, remainders, or differences) that remain constant during array transformations.
  * **Advanced Greedy/Sorting:** Customizing sorting criteria based on mathematical relations rather than simple element comparisons.
* **Practice Rules:** Set a strict **25-minute timer** per problem. If your logic fails hidden test cases or you get stuck, read the editorial immediately. Understand the mathematical "trick" you missed, then code the solution completely from scratch.

---

## 📅 Phase 2: The Core OA Bracket (Weeks 5 – 8)
**Goal:** Master the absolute sweet spot of modern corporate OAs. Reaching comfort in this zone guarantees clearing assessments for companies like Amazon, Microsoft, Meta, and Uber.

* **Daily Target:** 2 problems per day.
* **Codeforces Focus:** Complete the **1300, 1400, and 1500 rating** sections of the CP-31 sheet.
* **Core Logic & Patterns:**
  * **Bit Manipulation & Bitmasks:** Highly favored by Google for tracking combinations and state transitions.
  * **Number Theory:** Prime factorization, GCD/LCM properties, Sieve of Eratosthenes, and modular arithmetic to avoid overflow.
  * **Advanced Prefix Sums:** Multi-dimensional prefix grids and frequency tracking arrays.
  * **Binary Search on Answer:** Optimization problems disguised as searching tasks (finding min/max valid bounds).
* **Practice Rules:** Increase your problem timer to **40 minutes**. Pay immense attention to constraints (e.g., catching if N ≤ 10⁵ requires an \(O(N \log N)\) or O(N) approach instead of O(N²)). Proactively check for **integer overflows** (`long long` in C++) before clicking submit.

---

## 📅 Phase 3: The Google Level & Simulation (Weeks 9 – 12)
**Goal:** Push your boundaries into the 1600–1800 range (Google OA tier) while refining your coding style back to interview-ready clean formatting.

* **Weekly Target:** 6 to 8 hard problems + 2 Virtual Contests.
* **Codeforces Focus:** The **1600, 1700, and 1800 brackets** of the CP-31 sheet.
* **Weekly Schedule Matrix:**
  * **Days 1 to 4 (Advanced Grind):** Work through 1600–1800 problems. Focus heavily on **Advanced Graph Theory** (Dijkstra/BFS variations on complex grid matrices) and **Non-trivial Dynamic Programming** (DP with bitmasks or heavy space optimization).
  * **Days 5 & 6 (Virtual Contests):** Find a past **Codeforces Division 2 or Division 3 contest** and run it as a "Virtual Contest" under a live 2-hour timer. This perfectly simulates the high-stress, real-time environment of a corporate OA.
  * **Day 7 (Clean Code Reset):** Pick 2 problems you solved during the week. Rewrite them completely. Eliminate all single-letter variables (`a`, `b`, `v`, `sz`) and write clean, modular code with functional comments. This prevents messy CP habits from ruining your performance during technical interview rounds.

---

## 🔄 The Revision Strategy (Crucial for Long-Term Retention)

Unlike LeetCode, where you memorize standard algorithms, **CP requires revising patterns of mathematical logic**. Use this workflow to ensure you don't forget the "tricks":

### 1. The Dynamic Error Log (Every Time You Read an Editorial)
Do not just copy-paste the editorial solution. Maintain an active document tracking:
* **The Problem Link & Rating**
* **The "Aha!" Observation:** Write down the exact mathematical observation or invariant you missed (e.g., *"If we sort by differences (A[i] - B[i]), the greedy choice becomes optimal"* or *"An array can be partitioned into equal sums only if the total sum is even"*).
* **The Code Snippet:** Paste only the core logical block or function that solved the problem, not the entire boilerplate template.

### 2. The Sunday Morning "Codeless" Revision (Weekly)
* Spend **1 hour** every Sunday opening your Error Log.
* Look *only* at the titles/links of the problems you struggled with that week.
* Spend 2 minutes mentally tracing how to solve it. **Do not write code.** 
* If you can state the core mathematical observation out loud instantly, mark it as **Green**. If you draw a blank on the "trick," mark it as **Red**.

### 3. The Bi-Weekly "Red Problem" Speedrun (Every 2 Weeks)
* Go back to all problems marked **Red** in your Error Log from the last 14 days.
* Open a blank editor on Codeforces and try to pass them under a tight **15-minute timer**.
* Because you have already read the editorial once before, your brain will build deeper neurological pathways by forcing yourself to reconstruct the exact logic under time pressure.

---

## 💡 Crucial Daily Execution Habits

* **The 45-Minute Cutoff Rule:** Never spend more than **45 minutes** actively trying to code or debug a problem before looking at the editorial. At your level, your goal is rapid exposure to new logical patterns, not stubborn grinding.
* **The Mathematical Overkill Warning:** When looking at Codeforces tags, ignore topics like *Heavy-Light Decomposition*, *Centroid Decomposition*, or *FFT*. Focus tightly on **Greedy, Math, Bitmasks, Dynamic Programming, and Graphs**—these are what corporate OAs care about.


## Important links
-- For Practice Div3 Contest
https://codeforces.com/blog/entry/87257