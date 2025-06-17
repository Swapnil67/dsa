/*
 * Leetcode - 901
 * Online Stock Span
 * * Example 1
 * * Input  : ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
 * [[], [100], [80], [60], [70], [60], [75], [85]]
 * * Output : [null, 1, 1, 1, 2, 1, 4, 6]
 * 
 * https://leetcode.com/problems/online-stock-span/description/
*/

// ! Monotonic Stack

#include <iostream>
#include <stack>

class StockSpanner {
  public: 
    // * pair of price & stock_span
    std::stack<std::pair<int, int>> st;
    StockSpanner() {
    }

    int nextBrute(int price) {
      int stock_span = 1;
      if (this->st.empty()) {
        this->st.push({price, stock_span});
        return stock_span;
      }

      std::stack<std::pair<int, int>> temp = this->st;
      // std::cout << temp.size() << " " << temp.top() << std::endl;

      while (!temp.empty()) {
        if (temp.top().first > price) {
          break;
        }
        stock_span++;
        temp.pop();
      }

      this->st.push({price, stock_span});
      return stock_span;
    }

    int next(int price) {
      int stock_span = 1;

      // * Stack is empty
      if(this->st.empty()) {
        this->st.push({price, stock_span});
        return stock_span;
      }

      // * Check the previous day stock price
      // * If <= to today price pop the previous day stock span
      // * This keeps the st in decreasing order
      while (!this->st.empty() && this->st.top().first <= price) {
        stock_span += this->st.top().second;
        this->st.pop();
      }
      this->st.push({price, stock_span});

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