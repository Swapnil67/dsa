#include<iostream>

class Node {
  public:
  int data;
  Node* next;

  Node(int d) {
    this->data = d;
    this->next = NULL;
  }

  Node(int d, Node* n) {
    this->data = d;
    this->next = n;
  }
};

// * ------------------- Utility Functions ---------------------

Node* arrayToLL(std::vector<int> arr) {
  if(arr.size() == 0) {
    return NULL;
  }

  Node* head = new Node(arr[0]);
  Node* temp = head;
  for(int i=1; i<arr.size(); i++) {
    Node* newNode = new Node(arr[i]);
    temp->next = newNode;
    temp = newNode;
  }
  return head;
}

void printLL(Node* head) {
  Node* temp = head;
  while(temp != NULL) {
    std::cout<<temp->data<<" ";
    temp = temp->next;
  }
  std::cout<<"\n";
}

// * ------------------ Optimal FORCE ---------------------

// * TIME COMPLEXITY O(max(h1, h1))
// * SPACE COMPLEXITY O(max(h1, h1))
Node* addTwoLL(Node* h1, Node* h2) {
  Node* sumHead = new Node(0);
  Node* temp = sumHead;
  int carry = 0;

  while(h1 != NULL || h2 != NULL) {
    int sum = carry;
    if(h1) sum = sum + h1->data;
    if(h2) sum = sum + h2->data;

    Node* curSum = new Node(sum%10);
    carry = sum / 10;
    temp->next = curSum;
    temp = curSum;
    if(h1) h1 = h1->next;
    if(h2) h2 = h2->next;
  }
  if(carry > 0) {
    Node* carryNode = new Node(carry);
    temp->next = carryNode;
  }

  return sumHead->next;
}

int main() {
  // * testcase 1
  // std::vector<int> num1 = { 1, 2, 3 };
  // std::vector<int> num2 = { 4, 5, 9 };

  // * testcase 2
  std::vector<int> num1 = { 0, 1 };
  std::vector<int> num2 = { 0 };

  Node* n1_head = arrayToLL(num1);
  Node* n2_head = arrayToLL(num2);

  std::cout<<"First Linked List"<<std::endl;
  printLL(n1_head);
  std::cout<<"Second Linked List"<<std::endl;
  printLL(n2_head);

  Node* addHead = addTwoLL(n1_head, n2_head);
  std::cout<<"-----------------------------------------"<<std::endl;
  // std::cout<<"Sum of two Linked List"<<std::endl;
  printLL(addHead);
}

// * Note whenever there is a need for new LL, always create a dummyNode node and return dummyNode->next