#include<iostream>
#include<string>
using namespace std;

void swap(char &a, char &b) {
  char temp = a;
  a = b;
  b = temp;
}

void reverse(string &word) {
  int s = 0;
  int e = word.length() - 1;
  while(s<=e) {
    swap(word[s++], word[e--]);
  }
}

void reverseWords(char str[]) {
  string word;
  for(int i=0; str[i] != '\0'; i++) {
    cout<<str[i]<<" ";
    if(str[i] == ' ') {
      cout<<word<<endl;
      reverse(word);
      cout<<word<<endl;
      word = "";
    }
    word.push_back(str[i]);
  }
}

int main() {
  char myword[] = { 'H', 'e', 'l', 'l', 'o', ' ', 't', 'h', 'e', 'r', 'e'};
  reverseWords(myword);
  return 0;
}