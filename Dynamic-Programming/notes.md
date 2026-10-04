# Dynamic Programming

- `Forward loop:` 
    - You see your own updates as you move along. (Great if you have infinite copies of an item).
- `Backward loop:` 
    - You only see the "past" version of the array to your left. (Required when you have only one copy of each item).


- Use `dp[i - 1]` when elements cannot be reused (0/1 Knapsack / Subset Sum).
- Use `dp[i]` when elements can be reused infinitely (Unbounded Knapsack / Coin Change).