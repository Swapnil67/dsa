/*
* Given a string str. The task is to find the max occurring char in the string str.
* If more than one char occurs the max number of time then print the lexicographically smaller char.
*/
// * Input : "test" | Output : 't'

#include<iostream>
#include<string>

using namespace std;

// * TIME COMPLEXITY = O(N)
// * SPACE COMPLEXITY = O(1)
char getMaximumOccurringCharacter(string str) {
  int arr[26] = {0};
  for(int i=0; i<str.length(); i++) {
    char ch = str[i];
    int number = 0;
    // * Lowercase
    if(ch >= 'a' && ch <= 'z') {
      number = ch - 'a';
    } 
    else { // * uppercase
      number = ch - 'A';
    }
    arr[number]++;
  } 

  int maxi = -1, ans = 0;
  for(int i=0;i<26;i++) {
    if(maxi < arr[i]) {
      ans = i;
      maxi = arr[i];
    }
  }
  char finalAns = 'a'+ans;
  return finalAns;
}

int main() {
  string str = "test";
  char max_char = getMaximumOccurringCharacter(str);
  cout<<"Maximum occurring character "<<max_char;
  return 0;
}