#include<iostream>

class Node {
  public: 
    int data;
    Node* next;
    Node* prev;

  Node(int d) {
    this->data = d;
    this->next = nullptr;
    this->prev = nullptr;
  }

  Node(int d, Node* n, Node* p) {
    this->data = d;
    this->next = n;
    this->prev = p;
  }

};


// * ------------------- Utility Functions ---------------------

Node* arrayToDLL(std::vector<int>arr) {
  Node* head = new Node(arr[0]);
  Node* prev = head;
  for(int i=1; i<arr.size(); i++) {
    Node* temp = new Node(arr[i], nullptr, prev);
    prev->next = temp;
    prev = temp;
  }
  return head;
}

void printDLL(Node* head) {
  Node* temp = head;
  while(temp != NULL) {
    std::cout<<temp->data<<" ";
    temp = temp->next;
  }
  std::cout<<std::endl;
}

Node* deleteHead(Node* head) {
  if(head == NULL || head->next == NULL) return NULL;

  Node* temp = head;
  head = head->next;  // * Move the head
  temp->prev = nullptr; // * head back point to nullptr

  // * free the head pointer
  temp->next = nullptr; 
  delete temp;

  return head;
}

// * Delete the Tail
void deleteTail(Node* head) {
  if(head == NULL || head->next == NULL) return;
  Node* temp = head;
  while(temp->next != NULL) {
    temp = temp->next;
  }
  Node* back = temp->prev;
  back->next = nullptr;
  delete temp;
}

Node* deleteKthNode(Node* head, int k) {
  int c = 0;
  Node* temp = head;
  while(temp != NULL) {
    c++;
    if(c == k) {
      break;
    }
    temp = temp->next;
  }
  Node* back = temp->prev;
  Node* front = temp->next;

  if(back == NULL && front == NULL) {
    return NULL;
  }
  else if(back == NULL) {
    // * Standing at head
    std::cout<<"Delete the head"<<std::endl;
    return deleteHead(head);
  }
  else if(front == NULL) {
    // * Standing at tail
    std::cout<<"Delete the tail"<<std::endl;
    deleteTail(head);
    return head;
  }
  else {
    std::cout<<"Delete the middle"<<std::endl;
    // std::cout<<back->data<<std::endl;
    // std::cout<<front->data<<std::endl;

    // * Standing in middle
    back->next = front;
    front->prev = back;

    // * Free the deleted node
    temp->next = nullptr;
    temp->prev = nullptr;
    delete temp;
  }
  return head;
}


int main() {
  std::vector<int> arr = { 1,2,3,4,5 };
  Node* head = arrayToDLL(arr);

  std::cout<<"------ Before Deleteting Node ------"<<std::endl;
  printDLL(head);

  std::cout<<"------ After Deleteting Node ------"<<std::endl;
  head = deleteKthNode(head, 2);
  printDLL(head);

  return 0;
}
