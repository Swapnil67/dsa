#include<iostream>
#include<stack>
using namespace std;

void deleteMid(stack<int> &a, int count, int size) {
  if(count == size/2) {
    int ctop = a.top();
    cout<<"Remove: "<<ctop<<endl;
    a.pop();
    return;
  }
  int num = a.top();
  a.pop();
  deleteMid(a, count+1, size);
  a.push(num);
}

int main() {
  stack<int> a;
  a.push(1);
  a.push(2);
  a.push(3);
  deleteMid(a, 0, a.size());
  return 0;
}