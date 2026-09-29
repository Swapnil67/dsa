/*
 * NAME: 1869A - Make It Zero
 * 
 * Description:
 * Given an array of n integers, you can perform an operation at most 8 times: choose a range [l, r] 
 * and replace all elements in that range with their bitwise XOR sum (a[l] ^ a[l+1] ^ ... ^ a[r]). 
 * Your goal is to make all elements in the array equal to 0.
 * 
 * Constraints:
 * 1 <= t <= 500 (Number of test cases)
 * 4 <= n <= 100
 * 0 <= a[i] <= 100
 * 
 * Example 1    :
 * Input        : n = 4, a = [1, 2, 3, 0]
 * Output       : 2
 *                1 4
 *                1 4
 * Explanation  : Since n is even, XORing the whole array twice turns all elements to 0.
 * 
 * Example 2    :
 * Input        : n = 5, a = [1, 2, 3, 4, 5]
 * Output       : 4
 *                1 4
 *                1 4
 *                4 5
 *                4 5
 * Explanation  : For odd n, clear an even prefix [1, 4] twice, then clear the overlapping suffix [4, 5] twice.
 * 
*/


/*
* ====================================================================
*            INTUITION: MAKE IT ZERO (XOR RANGE OPERATIONS)
* ====================================================================
* 
* CORE XOR PROPERTIES:
* 1. X ^ X = 0  (Identical values cancel each other out)
* 2. 0 ^ X = X  (XOR with 0 leaves the value unchanged)
* 
* --------------------------------------------------------------------
* CASE 1: EVEN ARRAY LENGTH (n % 2 == 0) -> Requires 2 Operations
* --------------------------------------------------------------------
* * Op 1 [1 to n]: Calculates total XOR sum = X.
*   Array becomes: [X, X, X, X]
*   
* * Op 2 [1 to n]: Calculates new XOR sum of an EVEN number of X's.
*   Pairs cancel out perfectly: (X^X) ^ (X^X) = 0 ^ 0 = 0.
*   Array becomes: [0, 0, 0, 0]
* 
* --------------------------------------------------------------------
* CASE 2: ODD ARRAY LENGTH (n % 2 != 0) -> Requires 4 Operations
* --------------------------------------------------------------------
* * Why [1 to n] fails: An ODD number of X's leaves one leftover X without
*   a partner to cancel out: (X^X) ^ (X^X) ^ X = X. Array stays stuck.
* 
* * Fix: Split into overlapping EVEN-sized segments.
* 
*   Initial Array State   : [ x1, x2, x3, x4, x5 ]
*   
*   Op 1 & 2 on [1 to n-1]: Range length is even (4). Turns prefix to 0.
*                           Array: [  0,  0,  0,  0, x5 ]
*                           
*   Op 3 on [n-1 to n]    : Range length is even (2). Elements: 0 and x5.
*                           XOR sum = 0 ^ x5 = x5. Both become x5.
*                           Array: [  0,  0,  0, x5, x5 ]
*                           
*   Op 4 on [n-1 to n]    : Range length is even (2). Elements: x5 and x5.
*                           XOR sum = x5 ^ x5 = 0. Both become 0.
*                           Array: [  0,  0,  0,  0,  0 ]
* ====================================================================
*/