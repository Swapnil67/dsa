#include<iostream>
#include<queue>
using namespace std;

void print(queue<int> q) {
  cout<<"\nPrint Queue\n";
  for(int i=0; i<q.size(); i++) {
    cout<<i<<" ";
  }
  cout<<endl;
}

int main() {
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  cout<<"Size before pop: "<<q.size()<<endl;
  q.pop();
  cout<<"Size after pop: "<<q.size()<<endl;
  return 0;
}