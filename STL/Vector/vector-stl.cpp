#include<iostream>
#include<vector>
using namespace std;

int main() {

  // * Static Array
  int arr[4] = { 1,2,3,4 };

  // * Dynamic Array
  vector<int> v;

  // * Size = Total number of element currently has
  // * Capacity = Total number of memory allocated

  cout<<"Size "<<v.size()<<" Capacity "<<v.capacity()<<endl;
  v.push_back(1);
  cout<<"Size "<<v.size()<<" Capacity "<<v.capacity()<<endl;
  v.push_back(2);
  cout<<"Size "<<v.size()<<" Capacity "<<v.capacity()<<endl;
  v.push_back(3);
  cout<<"Size "<<v.size()<<" Capacity "<<v.capacity()<<endl;

  cout<<"Element at index 2: "<<v.at(2)<<endl;
  cout<<"Empty of not: "<<v.empty()<<endl;

  cout<<"First element: "<<v.front()<<endl;
  cout<<"Last element: "<<v.back()<<endl;

  // * Copy a vector into another
  vector<int> last(v);
  for(int i:last) {
    cout<<i<<" ";
  } cout<<endl;

  return 0;
}