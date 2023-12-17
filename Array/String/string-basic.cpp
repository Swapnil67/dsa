#include<iostream>
#include <string>
using namespace std;

int main() {
  string name ("Swapnil Adsul");
  cout<<name<<endl;

  cout<<"Length of name: "<<name.length()<<endl;

  // * Loop over string chars
  for(int i=0; i<name.length(); i++) {
    cout<<name[i]<<" ";
  }
  cout<<endl;

  // * Reverse
  cout<<"Reversing string"<<endl;
  for(string::reverse_iterator rit=name.rbegin(); rit!=name.rend(); ++rit) {
    cout<<*rit<<" ";
  }

  return 0;
}