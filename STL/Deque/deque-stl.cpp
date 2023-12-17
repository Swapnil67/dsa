#include<iostream>
#include<deque>
using namespace std;

void print(deque<int> d) {
  cout<<"\nPrint Deque\n";
  for(int i:d) {
    cout<<i<<" ";
  }
  cout<<endl;
}

int main() {
  deque<int> d;
  d.push_back(1);
  d.push_front(2);
  d.push_back(3);

  print(d);
  d.pop_front();
  print(d);


  cout<<"Element at index 2: "<<d.at(1)<<endl;
  cout<<"Empty of not: "<<d.empty()<<endl;

  cout<<"First element: "<<d.front()<<endl;
  cout<<"Last element: "<<d.back()<<endl;

  print(d);
  d.erase(d.begin(), d.begin()+1);
  print(d);

  return 0;
}