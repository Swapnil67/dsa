/**
 * * Time Needed to Buy Tickets

 * * Example 1
 * * Input  : students = [1,1,0,0], sandwiches = [0,1,0,1]
 * * Output : 0
 * 
 * * Example 2
 * * Input  : students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1]
 * * Output : 3
 * * Explanation: [4,9] is also accepted.

 * * https://leetcode.com/problems/time-needed-to-buy-tickets/description/
*/

#include<map>
#include<iostream>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int timeRequiredToBuy(std::vector<int>& tickets, int k) {
  int n = tickets.size();
  std::map<int, int> ticketCnt;
  for (int i = 0; i < n; ++i) {
    ticketCnt[i] = tickets[i];
  }

  int c = 0;
  while (ticketCnt[k] != 0) {
    for (auto it : ticketCnt) {
      if(it.second > 0) {
        c++;
        ticketCnt[it.first]--;
      }
      else {
        break;
      }
    }
  }

  return c;
}

int main() {
  // std::vector<int> tickets = {2, 3, 2};
  // int k = 2;

  std::vector<int> tickets = {5, 1, 1, 1};
  int k = 0;

  std::cout<<"Tickets: ";
  printArr(tickets);

  int time = timeRequiredToBuy(tickets, k);
  std::cout << "Time required to buy tickets " << time << std::endl;

  return 0;
}

// * run the code 
// * g++ --std=c++17 27-time-needed-to-buy-tickets.cpp -o output && ./output