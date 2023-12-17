#include<iostream>
#include<stack>
using namespace std;

int main() {
  stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);

  cout<<"Top element: "<<s.top()<<endl;

  cout<<"Size of Stack: "<<s.size()<<endl;

  s.pop();

  cout<<"Top element: "<<s.top()<<endl;

  cout<<"Size of Stack: "<<s.size()<<endl;

  cout<<"Empty of not: "<<s.empty()<<endl;


  return 0;
}