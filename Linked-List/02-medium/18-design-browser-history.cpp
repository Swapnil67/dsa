/*
 * Leetcode - 1472
 * Design Browser History
 * 
 * Given the head of a singly linked list and two integers left and right where left <= right, 
 * reverse the nodes of the list from position left to position right, and return the reversed list.

 * * Example 1
 * Input :  
 *   ["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
 *   [["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]

 * Output :
 * [null,null,null,null,"facebook.com","google.com","facebook.com",null,"linkedin.com","google.com","leetcode.com"]

 * https://leetcode.com/problems/design-browser-history/description/
*/

#include <vector>
#include <iostream>

// ! Can also be solved using two stack method

// struct ListNode ListNode;

struct ListNode {
  public:
    std::string data;
    ListNode* next;
    ListNode* prev;

    ListNode(std::string val) {
      data = val;
      next = nullptr;
      prev = nullptr;
    }

    ListNode(std::string val, ListNode* back) {
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

void printLL(ListNode* head) {
  ListNode* temp = head;
  while (temp) {
    std::cout << temp->data << " -> ";
    temp = temp->next;
  }
  std::cout << "NULL" << std::endl;
}

class BrowserHistory {
public:
  ListNode* history; 
  ListNode* cur; 
  BrowserHistory(std::string homepage) {
    history = new ListNode(homepage);
    cur = history;
  }

  void visit(std::string url) {
    ListNode *page = new ListNode(url, cur);
    cur->next = page;
    cur = page;
  }

  std::string back(int steps) {
    std::string page = "";
    if (!cur)
      return page;

    while (steps) {
      if (cur->prev)
        cur = cur->prev;
      else
        break;
      steps--;
    }
    return cur->data;
  }

  std::string forward(int steps) {
    while (steps) {
      if (cur->next)
        cur = cur->next;
      else 
        break;
      steps--;
    }
    return cur->data;
  }

};

int main(void) {
  BrowserHistory* browser = new BrowserHistory("google.com");
  browser->visit("facebook.com");
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


