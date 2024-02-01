/*
* Aggressive Cows
* You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.
* You are also given an integer 'k' which denotes the number of aggressive cows.
* You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of 
* them is the maximum possible.
* Return the maximum possible minimum distance.


* Example 1:
* Input: 'k' = 2 and 'arr' = {1, 2, 3}
* Output: 2

* Example 2:
* Input: 'k' = 4 and 'arr' = {0,3,4,7,10.9}
* Output: 3


* https://www.codingninjas.com/studio/problems/aggressive-cows_1082559
*/

#include<iostream>
using namespace std;

bool canWePlace(vector<int> stalls, int distance, int cows) {
    int cowCount = 1, last = stalls[0];
    int n = stalls.size();

    for(int i=1; i<n; i++) {
        // cout<<"Stall "<<stalls[i]<<endl;
        if(stalls[i] - last >= distance) {
            cowCount++;
            last = stalls[i];
        }    
        if(cowCount >= cows) {
            return true;
        }
    }
    return false;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------

// * TIME COMPLEXITY O(max-mix) * O(N) = O(N^2) 
// * O(nlogn) for sorting
// * SPACE COMPLEXITY O(1)
int bruteForce(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    for(int i=0; i<=stalls[n-1]-stalls[0]; i++) {
        bool ans = canWePlace(stalls, i, k);
        // cout<<"ans "<<ans<<endl; 
        // cout<<"distance "<<i-1<<endl;

        if(ans == true) {
            continue;
        }
        else {
            return i-1;
        }
    }
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------

// * TIME COMPLEXITY log(max-mix) * O(N) 
// * O(nlogn) for sorting
// * SPACE COMPLEXITY O(1)
int optimalApproach(vector<int>&stalls, int cows) {
    sort(stalls.begin(), stalls.end());
    int n = stalls.size(), ans = 0;
    int low = 0, high = stalls[n-1]-stalls[0];
    while(low <= high) {
        int mid = low + (high - low)/2;
        bool canPlace = canWePlace(stalls, mid, cows);
        if(canPlace == false) {
            high = mid - 1;
            ans = high;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int cows = 4;
    // int distance = bruteForce(stalls, cows);
    int distance = optimalApproach(stalls, cows);
    cout<<"Distance "<<distance<<endl;
    return 0;
}