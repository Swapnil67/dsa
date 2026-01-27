/*
 * Leetcode - 1472
 * Design Browser History
 * 
 * Given the head of a singly linked list and two integers left and right where left <= right, 
 * reverse the nodes of the list from position left to position right, and return the reversed list.

 * * Example 1
 * Input :  
 *   ["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
 *   [["leetcode.com"],["tsoding.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]

 * Output :
 * [null,null,null,null,"facebook.com","tsoding.com","facebook.com",null,"linkedin.com","tsoding.com","leetcode.com"]

 * https://leetcode.com/problems/design-browser-history/description/
*/

#include <vector>
#include <iostream>

// ! Can also be solved using two stack method

struct DLListNode {
  public:
    std::string data;
    DLListNode* next;
    DLListNode* prev;

    DLListNode(std::string val) {
      data = val;
      next = nullptr;
      prev = nullptr;
    }

    DLListNode(std::string val, DLListNode* back) {
      data = val;
      next = nullptr;
      prev = back;
    }
};

template <typename T>
void printArr(std::vector<T> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  printf("\n");
}

void printLL(DLListNode* head) {
  DLListNode* temp = head;
  while (temp) {
    std::cout << temp->data << " -> ";
    temp = temp->next;
  }
  std::cout << "NULL" << std::endl;
}

class BrowserHistory {
public:
  DLListNode* cur; 
  BrowserHistory(std::string homepage) {
    cur = new DLListNode(homepage);
  }

  void visit(std::string url) {
    DLListNode *page = new DLListNode(url, cur);
    cur->next = page;
    cur = page;
  }

  std::string back(int steps) {
    if (!cur)
      return "";

    while (steps && cur->prev) {
      cur = cur->prev;
      steps--;
    }
    return cur->data;
  }

  std::string forward(int steps) {
    if (!cur)
      return "";

    while (steps && cur->next) {
      cur = cur->next;
      steps--;
    }
    return cur->data;
  }

};

int main(void) {
  BrowserHistory* browser = new BrowserHistory("xbox.com");
  browser->visit("test.com");
  browser->visit("tsoding.com");
  std::cout << browser->cur->data << std::endl;
  browser->back(2);
  std::cout << browser->cur->data << std::endl;
  browser->back(1);
  std::cout << browser->cur->data << std::endl;
  browser->forward(1);
  std::cout << browser->cur->data << std::endl;
  browser->visit("tiktok.com");
  std::cout << browser->cur->data << std::endl;
  browser->back(1);
  std::cout << browser->cur->data << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 18-design-browser-history.cpp -o output && ./output


