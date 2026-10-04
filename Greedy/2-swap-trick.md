# Exchange Argument Lemma | Proof by contradiction

Minimize summation of a[i] * b[i] overall i
you are allowed to re-arrange a and b in any order  
let a = [1,2,3]
let b = [3,2,1]

## ASSUMPTION 1

Both arrays are sorted in different sorting order

```
a = a1 <= a2 <= a3
b = b1 >= b2 >= b3

sum1 = a1b1 + a2b2 + a3b3
```

## ASSUMPTION 2
Now let's make a assumption that swapping a1 and a2 i.e. swap(a1, a2) our sum will be even less

So with our new assumption

```
a = a3 <= a2 <= a1
b = b1 >= b2 >= b3

sum2 = a3b1 + a2b2 + a1b3
```

Now we need to prove that sum2 < sum1 for that we need to check the difference b/w them

let d = sum2 - sum1

so our d should be negative to prove `ASSUMPTION 2`.

```
d = sum2 - sum1
d = (a3b1 + a2b2 + a1b3) - (a1b1 + a2b2 + a3b3)
d = (a3b1 - a3b3) + (a1b3 - a1b1)
d = (a3b1 - a3b3) - (a1b1 - a1b3)
d = a3(b1 - b3) - a1(b1 - b3)
d = (a3 - a1) * (b1 - b3)

since (a3 - a1) => positive
since (b1 - b3) => positive

d = positive * positive => positive
```

So this proves that our `ASSUMPTION 2` is not correct our `ASSUMPTION 1` is correct.

 