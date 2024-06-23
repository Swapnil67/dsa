/*
 * K Inverse Pair Array
 * Inverse in an array can be defined as the number of pairs of 'i', 'j' 
 * such that 'i' < 'j' and A[i] > A[j]
 * 
 * Given two integers n and k, return the number of different arrays consisting of numbers from 1 to n such that 
 * there are exactly k inverse pairs
 * 
 * Example 1:
 * Input: n = 3, k = 0
 * Output: 1
 * Explanation: Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse pairs.
 * 
 * Example 2:
 * Input: n = 3, k = 1
 * Output: 2
 * Explanation: The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.
 * 
 * https://leetcode.com/problems/k-inverse-pairs-array/description/
*/
