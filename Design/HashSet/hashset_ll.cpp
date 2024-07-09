#include<iostream>

class Node {
  public: 
    int data;
    Node* next;

    Node(int data) {
      this->data = data;
      this->next = nullptr;
    }
    
    Node(int data, Node* next) {
      this->data = data;
      this->next = next;
    }
};

class HashSet {
  public: 
    int n = 9999;
    int *const arr = new int[n];
    std::vector<Node*> brr(n, 0);

    HashSet() {
    }

    void add(int key) {
      arr[0] = 10;
      int idx = key % n;
      std::cout << idx << " -> " << key << " " << arr[idx] << std::endl;
      if(arr[idx] == 0) {
        // * Create a node
        Node* new_node = new Node(key);
        // arr[idx] = new_node;
        brr[idx] = new_node;

      }

      // if(!contains(key)) {
      //   hashSet.push_back(key);
      // }
    } 

    void remove(int key) {
      // auto k = std::find(hashSet.begin(), hashSet.end(), key);
      // if(k != hashSet.end()) {
      //   hashSet.erase(k);
      // }
    }

    bool contains(int key) {
      // return (std::find(hashSet.begin(), hashSet.end(), key) != hashSet.end());
    }
};

int main() {
  HashSet* HS1 = new HashSet();
  HS1->add(32);
  // HS1->add(2);
  // std::cout << "1 is in hashset: " << HS1->contains(1) << std::endl;
  // std::cout << "3 is in hashset: " << HS1->contains(3) << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 hashset_ll.cpp -o hashset_ll && ./hashset_lg++ --std=c++17 hashset_ll.cpp -o hashset_ll && ./hashset_lll