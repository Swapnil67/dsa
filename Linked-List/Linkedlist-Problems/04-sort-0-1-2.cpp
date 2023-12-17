// * Remove duplicates from a sorted linked list.

#include<iostream>
#include<map>
using namespace std;

class Node {
  public:
    int data;
    Node* next;
    Node* tail;


  // * Constructor
  Node(int d) {
    this->data = d;
    this->next = NULL;
  }

  // * Destructor
  ~Node() {
    int val = this->data;
    if(next != NULL) {
      delete next;
      next = NULL;
    }
    cout<<"Memory free for node with data "<<val<<endl;
  } 

};

void insertAtHead(Node* &head, Node* &tail, int val) {
  Node* new_ele = new Node(val);
  if(tail == NULL) {
    head = new_ele;
    tail = new_ele;
  } else {
    new_ele->next = tail->next;
    tail->next = new_ele;
  }
}

void insertAtTail(Node* &head, Node* &tail, int val) {
  Node* new_ele = new Node(val);
  if(head == NULL) {
    head = new_ele;
    tail = new_ele;
    return;
  }

  Node* temp = head;
  while(temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = new_ele;
  tail = new_ele;
}

void insertAfterELement(Node* &head, Node* &tail, int ele, int val) {
  // * Assuming that the element is present in the list

  // * Empty list
  if(head == NULL) {
    Node* new_node = new Node(val);
    head = new_node;
    tail = new_node;
    new_node->next = new_node;
  } else {
    // * Non Empty list
    Node* cur = head;
    while(cur->data != ele) {
      cur = cur->next;
    }
    if(cur->next == NULL) {
      insertAtTail(head, tail, val);
      return;
    }
    Node* new_node = new Node(val);
    // cout<<cur->next<<" "<<cur->data<<endl;
    new_node->next = cur->next;
    cur->next = new_node;
  }
}

void print(Node* &head) {
  Node* cur = head;
  if(head == NULL) {
    cout<<"Linked List is empty\n";
    return;
  }

  while(cur != NULL) {
    cout<<cur->data<<" ";
    cur = cur->next;
  }
  cout<<endl;
}

// * -------------------------------- Problem Solution --------------------------------

void sortDigits(Node* &head) {
  // * Count number of 0s, 1s & 2s
  int zeroCount = 0;
  int oneCount = 0;
  int twoCount = 0;

  Node* temp = head;
  while(temp != NULL) {
    if(temp->data == 0) zeroCount++;
    if(temp->data == 1) oneCount++;
    if(temp->data == 2) twoCount++;
    temp = temp->next;
  }

  Node* temp2 = head;
  while(temp2 != NULL) {
    if(zeroCount != 0) {
      temp2->data = 0;
      zeroCount--;
    } else if(oneCount != 0) {
      temp2->data = 1;
      oneCount--;
    } else if(twoCount != 0) {
      temp2->data = 2;
      twoCount--;
    }
    temp2 = temp2->next;
  }

}

void insertAtDummyTail(Node* &tail, Node* &cur) {
  tail->next = cur;
  tail = cur;
}

Node* sortDigitsV2(Node* &head) {
  // * Count number of 0s, 1s & 2s
  Node* zeroHead = new Node(-1);
  Node* zeroTail = zeroHead;
  Node* oneHead = new Node(-1);
  Node* oneTail = oneHead;
  Node* twoHead = new Node(-1);
  Node* twoTail = twoHead;

  Node* cur = head;
  // * Create 3 dummy separate linked list for 0s, 1s & 2s
  while(cur != NULL) {
    if(cur->data == 0) {
      cur->data = 0;
      insertAtDummyTail(zeroTail, cur);
    } else if(cur->data == 1) {
      cur->data = 1;
      insertAtDummyTail(oneTail, cur);
    } else if(cur->data == 2) {
      cur->data = 2;
      insertAtDummyTail(twoTail, cur);
    }
    cur = cur->next;
  }

  // * Now merge 3 linked list
  if(oneHead->next != NULL) {
    zeroTail->next = oneHead->next;
  }

  if(twoHead->next != NULL) {
    oneTail->next = twoHead->next;
  }

  head = zeroHead->next;
  return head;

}


int main() {
  Node* tail = NULL;
  Node* head = NULL;
  insertAtHead(head, tail, 0);
  insertAtTail(head, tail, 1);
  insertAfterELement(head, tail, 0, 2);
  insertAfterELement(head, tail, 2, 1);
  insertAtTail(head, tail, 0);
  insertAtTail(head, tail, 1);
  insertAtTail(head, tail, 2);
  print(head);

  // * Approach 1
  // sortDigits(head); 
  // print(head);

  // * Approach 2
  Node* newHead = sortDigitsV2(head);
  print(newHead);
  return 0;
}