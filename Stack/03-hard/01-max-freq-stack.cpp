/*
 * Leetcode - 895
 * Maximum Frequency Stack
 * Implement the FreqStack class:
 * - FreqStack() constructs an empty frequency stack.
 * - void push(int val) pushes an integer val onto the top of the stack.
 * - int pop() removes and returns the most frequent element in the stack.
 *  - If there is a tie for the most frequent element, the element closest to the stack's top is removed and returned.
 * 
 * Example 1
 * * Input       : ["FreqStack", "push", "push", "push", "push", "push", "push", "pop", "pop", "pop", "pop"]
 *                 [[], [5], [7], [5], [7], [4], [5], [], [], [], []]
 * * Output      : [null, null, null, null, null, null, null, 5, 7, 5, 4]
 * 
 * https://leetcode.com/problems/maximum-frequency-stack/description/
*/

#include <stack>
#include <iostream>
#include <unordered_map>

class FreqStack {
private: 
  // * Map to track frequency of each element
  std::unordered_map<int, int> freqMap;

  // * Map to store stacks of elements for each frequency level
  std::unordered_map<int, std::stack<int>> freqStack; // * Hashmap of stack

  // * Track the maximum frequency
  int maxFreq;
public:

    FreqStack() {
      maxFreq = 0;
    }
    
    void push(int val) {
      // * Increment the frequency of val
      int freq = freqMap[val]++;

      // * Add val to the stack at its frequency level
      freqStack[freq].push(val);

      // * Update maxFreq if needed
      maxFreq = std::max(maxFreq, freq);
    }
    
    int pop() {
      // * Get the top element from the stack with highest frequency
      int val = freqStack[maxFreq].top();
      freqStack[maxFreq].pop();

      // * Decrement the frequency of the popped element
      freqMap[val]--;

      // * If the stack at maxFreq is empty, decrement maxFreq
      if (freqStack[maxFreq].size() == 0) {
        maxFreq--;
      }
      return val;
    }

    // * Time complexity O(n)
    void printStack(std::stack<int> s) {
      std::stack<int> p = s;
      while (!p.empty()) {
        printf("%d ", p.top());
        p.pop();
      }
    }

    // * For debugging
    void printFreqStack() {
      for(auto it: freqMap) {
        printf("-> %d\n", it.second);
        std::stack st = freqStack[it.second];
        printStack(st);
        printf("\n");
      }
      printf("Max Freq: %d\n", maxFreq);
    }
};


int main() {
  FreqStack *fq = new FreqStack();
  fq->push(5);
  fq->push(7);
  fq->push(5);
  fq->push(7);
  fq->push(4);
  fq->push(5);

  // fq->printFreqStack()

  int ans = fq->pop();
  printf("%d\n", ans);
  ans = fq->pop();
  printf("%d\n", ans);
  ans = fq->pop();
  printf("%d\n", ans);
  ans = fq->pop();
  printf("%d\n", ans);
  ans = fq->pop();
  printf("%d\n", ans);
  ans = fq->pop();
  printf("%d\n", ans);
  
  // fq->printFreqStack();
  return 0;
}

// * run the code
// * g++ --std=c++17 01-max-freq-stack.cpp -o output && ./output
