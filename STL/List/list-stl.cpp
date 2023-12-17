#include<iostream>
#include<list>
using namespace std;

void print(list<int> l) {
  cout<<"\nPrint List\n";
  for(int i:l) {
    cout<<i<<" ";
  }
  cout<<endl;
}

int main() {
  list<int> l;
  
  l.push_back(1);
  l.push_front(2);

  print(l);

  cout<<"Size of list: "<<l.size();

  return 0;
}