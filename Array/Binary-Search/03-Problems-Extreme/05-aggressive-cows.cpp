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


bool canWePlace(vector<int> stalls, int distance, int cows) {
    int cowCount = 1, last = stalls[0];
    int n = stalls.size();

    for(int i=1; i<n; i++) {
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

int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    for(int i=0; i<=stalls[n-1]; i++) {
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
