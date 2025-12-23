/*
 * Leetcode - 901
 * Online Stock Span
 * 
 * Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.
 * The span of the stock's price in one day is the maximum number of consecutive days (starting from that day 
 * and going backward) for which the stock price was less than or equal to the price of that day.
 * 
 * * Example 1
 * * Input  : ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
 * [[], [100], [80], [60], [70], [60], [75], [85]]
 * * Output : [null, 1, 1, 1, 2, 1, 4, 6]
 * 
 * https://leetcode.com/problems/online-stock-span/description/
*/

// ! Monotonic Stack
// ! Microsoft, Google, Amazon, Meta, Adobe, Apple

#include <stack>
#include <iostream>

class StockSpanner {
  public: 
    // * pair of price & stock_span
    std::stack<std::pair<int, int>> st;
    StockSpanner() {
    }

    // * Brute Force
    int nextBrute(int price) {
      int stock_span = 1;
      if (st.empty()) {
        st.push({price, stock_span});
        return stock_span;
      }

      std::stack<std::pair<int, int>> temp = st;
      // std::cout << temp.size() << " " << temp.top() << std::endl;

      while (!temp.empty()) {
        if (temp.top().first > price) {
          break;
        }
        stock_span++;
        temp.pop();
      }

      st.push({price, stock_span});
      return stock_span;
    }

    // * Optimal Approach
    int next(int price) {
      int stock_span = 1;

      // * Stack is empty
      if(st.empty()) {
        st.push({price, stock_span});
        return stock_span;
      }

      // * Check the previous day stock price
      // * If <= to today price pop the previous day stock span
      // * This keeps the st in decreasing order
      while (!st.empty() && st.top().first <= price) {
        stock_span += st.top().second;
        st.pop();
      }
      st.push({price, stock_span});

      return stock_span;
    }
};

int main() {
  StockSpanner *obj = new StockSpanner();
  std::cout << obj->next(100) << std::endl;
  std::cout << obj->next(80) << std::endl;
  std::cout << obj->next(60) << std::endl;
  std::cout << obj->next(70) << std::endl;
  std::cout << obj->next(60) << std::endl;
  std::cout << obj->next(75) << std::endl;
  std::cout << obj->next(85) << std::endl;
}

// * Run the code
// * g++ --std=c++20 06-online-stock-span.cpp -o output && ./output