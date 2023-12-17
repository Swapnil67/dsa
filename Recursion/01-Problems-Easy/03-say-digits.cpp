/*
* Print the digits of number
* i/p = 10
* o/p = "one" "zero"

* i/p = 67
* o/p = "six" "seven"
*/

#include<string>
#include<iostream>
using namespace std;


void sayDigits(long long n) {
  vector<string> arr_ans[10] = {};
  string arr_s[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
  int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };

  if(n == 0) return;

  int dig = n%10;
  // cout<<"dig: "<<dig<<" - "<<arr_s[dig]<<endl;

  n = n/10;
  // cout<<"n: "<<n<<endl;

  sayDigits(n);
  cout<<arr_s[dig]<<" ";
}

int main() { 
  long long n;
  cout<<"Enter a number: ";
  cin>>n;
  sayDigits(n);
  cout<<endl;
  return 0;
}