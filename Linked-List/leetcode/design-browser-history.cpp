#include<string>
#include<iostream>
using namespace std;

class BrowserHistory {
public:
    string tab_url;
    BrowserHistory* next;
    BrowserHistory* head;
    BrowserHistory* prev;
    BrowserHistory* tail;
    BrowserHistory* cur;
    
    BrowserHistory(string homepage) {
      this->tab_url = homepage;
      this->cur = NULL;
      this->next = NULL;
      this->head = NULL;
      this->tail = NULL;
      this->prev = NULL;
    }
    
    void visit(string url) {
      BrowserHistory* new_tab = new BrowserHistory(url);
      new_tab->tab_url = url;
      if(tail == NULL) {
        cout<<"First "<<new_tab<<" | url "<<new_tab->tab_url;
        cur = new_tab;
        tail = new_tab; 
        head = new_tab; 
      } else {
        new_tab->prev = tail;
        tail->next = new_tab;
        tail = new_tab;
        cur = new_tab;
      }
    }
    
    string back(int steps) {
      // cout<<"------------------- back -------------------"<<endl;
      // BrowserHistory* ptemp = head;
      // while(ptemp != NULL) {
      //   cout<<"pTemp "<<ptemp<<" | url "<<ptemp->tab_url<<endl;
      //   ptemp = ptemp->next;
      // }

      BrowserHistory* temp = cur;
      int c = 0;
      while(c<steps) {
        c++;
        if(temp->prev == NULL) {
          return head->tab_url;
        }
        temp = temp->prev;
      }
      // cout<<"Temp "<<temp<<" | url "<<temp->tab_url<<endl;
      // return "test.com";
      cur = temp;
      return temp->tab_url;
    }
    
    string forward(int steps) {
      BrowserHistory* temp = cur;

      int c = 0;
      while(c<steps) {
        c++;
        if(temp->next == NULL) {
          return tail->tab_url;
        }
        temp = temp->next;
      }
      cur = temp;
      return temp->tab_url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */