// * Check if linked list is circurlar or not
// * Also check if there's a loop in linked list


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
    new_ele->next = new_ele;
  } else {
    new_ele->next = tail->next;
    tail->next = new_ele;
  }
}

void insertAtTail(Node* &tail, int val) {
  Node* new_ele = new Node(val);
  if(tail == NULL) {
    tail = new_ele;
    new_ele->next = new_ele; 
    return;
  }

  new_ele->next = tail->next;
  tail->next = new_ele;
}

void insertAtPosition() {
  
}

void insertAfterELement(Node* &tail, int ele, int val) {
  // * Assuming that the element is present in the list
  Node* new_node = new Node(val);

  // * Empty list
  if(tail == NULL) {
    tail = new_node;
    new_node->next = new_node;
  } else {
    // * Non  Empty list
    Node* cur = tail;
    while(cur->data != ele) {
      cur = cur->next;
    }
    new_node->next = cur->next;
    cur->next = new_node;
  }
}

void deleteAtELement(Node* &tail, int ele) {
  // * Assuming that the element is present in the listm 

  // * Empty list
  if(tail == NULL) {
    cout<<"List is empty please check again"<<endl;
    return;
  } else {
    // * Non Empty list
    Node* prev = tail;
    Node* cur = prev->next;
    while(cur->data != ele) {
      prev = cur;
      cur = cur->next;
    }
    prev->next = cur->next;

    if(cur == prev) {
      // * LL with single node
      tail = NULL;
      return;
    } else if(tail == cur) {
      // * LL with atleast 2 elements
      tail = prev;
    }
    cur->next = NULL;
    delete cur;
  }
}

void deleteAtIndex(Node* &tail, int index) {
  if (tail == NULL && index > 0) {
    cout<<"Linked List index out or range\n";
    return;
  }

  Node* temp = tail;
  int c = 0;
  do {
    temp = temp->next;
    c++;
  } while(c < index && temp != tail);

  // cout<<temp->data<<" "<<temp->next<<" "<<temp->next->data<<endl;

  if(temp->next == tail) {
    tail = temp;
  }

  temp->next = temp->next->next;

  // cout<<temp->data<<" "<<temp->next<<" "<<temp->next->data<<endl;
}

void print(Node* &tail) {
  Node* cur = tail;
  if(tail == NULL) {
    cout<<"Linked List is empty\n";
    return;
  }
  do {
    cout<<cur->data<<" ";
    cur = cur->next;
  } while (cur != tail);
  cout<<endl;
}

// * Detect Circular Linked List
bool isCircular(Node* &head) {
  if(head == NULL)
    return true;

  Node* temp = head->next;
  while(temp != NULL && temp != head) {
    temp = temp->next;
  }

  if(temp == head) {
    return true;
  }

  return false;
}

// * Detect Loop in Linked List
bool detectLoop(Node* &head) {
  if(head == NULL) 
    return false;

  map<Node*, bool> visited;

  Node* temp = head;
  while(temp != NULL) {  

    // * Cycle is present
    if(visited[temp]) {
      return true;
    }
    visited[temp] = true;
    temp = temp->next;
  }

  return false;
}

int main() {
  Node* tail = NULL;
  Node* head = NULL;
  insertAtHead(head, tail, 10);
  insertAfterELement(tail, 10, 1);
  // print(tail);

  // insertAfterELement(tail, 1, 2);
  // insertAtTail(tail, 3);
  print(tail);
  cout<<tail->data<<endl;


  if(isCircular(tail)) {
    cout<<"Linked List is circular in nature\n";
  } else {
    cout<<"Linked List is not circular in nature\n";
  }

  if(detectLoop(tail)) {
    cout<<"Loop detected in Linked List\n";
  } else {
    cout<<"Loop not detected in Linked List\n";
  }

  return 0;
}