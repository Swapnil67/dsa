#include <vector>
#include <iostream>

using namespace std;

class ListNode {
  public:
  int data;
  ListNode* next;

  ListNode(int d) {
    this->data = d;
    this->next = NULL;
  }

  ListNode(int d, ListNode* n) {
    this->data = d;
    this->next = n;
  }
};

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

ListNode* arrayToLL(vector<int> &arr) {
  int n = arr.size();

  ListNode *head = new ListNode(arr[0]);
  ListNode* mover = head;
  for (int i = 1; i < n; ++i) {
    ListNode *newNode = new ListNode(arr[i], nullptr);
    mover->next = newNode;
    mover = newNode;
  }
  return head;
}

int lengthOfLL(ListNode *node) {
  ListNode* temp = node;
  int c = 0;
  while(temp) {
    c++;
    temp = temp->next;
  }
  return c;
}

template <typename T>
void printLL(T* head) {
  T *temp = head;
  while (temp) {
    cout << temp->data << " -> ";
    temp = temp->next;
  }
  cout << "NULL" << endl;
}

template <typename T>
class DLListNode {
public:
  T data;
  DLListNode* next;
  DLListNode* prev;

  DLListNode(T d) {
    this->data = d;
    this->next = NULL;
    this->prev = NULL;
  }

  DLListNode(T d, DLListNode *n, DLListNode *p) {
    this->data = d;
    this->next = n;
    this->prev = p;
  }
};

template <typename T>
DLListNode<T> *arrayToDLL(vector<T> &arr) {
  int n = arr.size();
  if (!n)
    return nullptr;

  DLListNode<T>* head = new DLListNode<T>(arr[0]);
  DLListNode<T>* mover = head;

  for (int i = 1; i < n; ++i) {
    DLListNode<T> *new_node = new DLListNode<T>(arr[i], nullptr, mover);
    mover->next = new_node;
    mover = new_node;
  }

  return head;
}

template <typename T>
void printDLL(DLListNode<T> *head) {
  DLListNode<T> *temp = head;
  while (temp)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

int countLL(ListNode* head) {
  if (!head)
    return 0;
    
  ListNode* temp = head;
  int c = 0;
  while (temp) {
    c++;
    temp = temp->next;
  }
  return c;
}