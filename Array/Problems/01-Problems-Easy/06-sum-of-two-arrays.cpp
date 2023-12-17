// * A = [1 8 3]
// * B = [4 6 6]
// * A+B = [6 4 9]

#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> arr) {
  for(int i=0;i<arr.size();i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

vector<int> reverse(vector<int> nums) {
  int s=0, e=nums.size()-1;
  while(s<e) {
    swap(nums[s++], nums[e--]);
  }
  return nums;
}

vector<int> sumOfArrays(vector<int> &a, vector<int> &b) {
  int i=a.size()-1;
  int j=b.size()-1;
  int carry = 0;
  vector<int> ans;
  while(i>=0 && j>=0) {
    int sum = a[i]+b[j]+carry;
    carry = sum/10;
    sum = sum%10;
    ans.push_back(sum);
    i--;
    j--;
  }

  while(i>=0) {
    int sum = a[i]+carry;
    carry = sum/10;
    sum = sum%10;
    ans.push_back(sum);
    i--;
  }

  while(j>=0) {
    int sum = b[j]+carry;
    carry = sum/10;
    sum = sum%10;
    ans.push_back(sum);
    j--;
  }

  if(carry != 0) {
    int sum = carry;
    carry = sum/10;
    sum = sum%10;
    ans.push_back(sum);
  }

  return ans;
}

int main() {
  vector<int> ans;
  vector<int> a;
  a.push_back(1);
  a.push_back(8);
  a.push_back(3);

  vector<int> b;
  b.push_back(4);
  b.push_back(6);
  b.push_back(6);

  cout<<"a: ";
  print(a);
  cout<<"b: ";
  print(b);

  ans = sumOfArrays(a, b);
  ans = reverse(ans);
  cout<<"---------------"<<endl;
  cout<<"a + b: ";
  print(ans);
  return 0;
}

