#include<iostream>
using namespace std;

class MyLinkedList {
public:
    int data;
    MyLinkedList* next;
    MyLinkedList* head;
    MyLinkedList* tail;
   
    MyLinkedList() {
      this->data = NULL;
      this->next = NULL;
      this->head = NULL;
      this->tail = NULL;
    }

    int get(int index) {
      MyLinkedList* ptemp2 = head;
      int length = 0;
      while(ptemp2 != NULL) {
        length++;
        ptemp2 = ptemp2->next;
      }

      MyLinkedList* temp = head;
      if(temp == NULL || index < 0 || index > length) {
        return -1;
      }

      int c = 0;
      while(c<index) {
        c++;
        temp = temp->next;
      }
      if(temp != NULL) {
        return temp->data;
      } else {
        return -1;
      } 
    }
    
    void addAtHead(int val) {
      MyLinkedList* new_node = new MyLinkedList;
      new_node->data = val;
      if(head == NULL) {
        head = new_node;
        tail = new_node;
      } else {
        new_node->next = head;
        head = new_node;
      }
    } 
    
    void addAtTail(int val) {
      MyLinkedList* new_node = new MyLinkedList;
      new_node->data = val;

      if(tail == NULL) {
        tail = new_node; 
        head = new_node; 
      } else {
        tail->next = new_node;
        tail = new_node;
      }
    }
    
    void addAtIndex(int index, int val) {
      int length = 0;
      MyLinkedList* ptemp2 = head;
      while(ptemp2 != NULL) {
        length++;
        ptemp2 = ptemp2->next;
      }

      if(index > length) {
        return;
      }

      MyLinkedList* temp = head;

      if(index == 0 || temp == NULL) {
        this->addAtHead(val);
        return;
      }

      int c = 1;
      while(c<index) {
        c++;
        temp = temp->next;
      }

      if(temp->next == NULL) {
        this->addAtTail(val);
        return;
      }

      MyLinkedList* new_node = new MyLinkedList;
      new_node->data = val;
      new_node->next = temp->next;
      temp->next = new_node;
    }
    
    void deleteAtIndex(int index) {
      int length = 0;
      MyLinkedList* ptemp2 = head;
      while(ptemp2 != NULL) {
        length++;
        ptemp2 = ptemp2->next;
      }

      if(index < 0 || index > length) {
        return;
      }

      if(index == 0) {
        if(head != NULL) {
          head = head->next;
        }
        return;
      } else {

        MyLinkedList* temp = head;
        MyLinkedList* prev = NULL;

        int c=0;
        while(c<index) {
          c++;
          prev = temp;
          temp = temp->next;
        }

        if(temp != NULL) {
          prev->next = temp->next;
          if(prev->next == NULL) {
            tail = prev;
          }
        } else {
          tail->next = prev;
          prev->next = NULL;
        }
      }

    }
};

int main() {
  MyLinkedList* obj = new MyLinkedList();
  int param_1 = obj->get(1);
  obj->addAtHead(10);
  obj->addAtTail(30);
  obj->addAtIndex(1,20);
  obj->deleteAtIndex(2);
}
