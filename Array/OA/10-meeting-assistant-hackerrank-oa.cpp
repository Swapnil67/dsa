/*
 * NAME
 * 
 * There are n events from timing [start.end] ; in each even a particular person is doing some action in that 
 * time bracket ;
 * we have to find the timing when everyone mentioned is free so they can have party for k minutes non stop 
 * 
 * Constraints:
 * 
 * Example 1    :
 * Input        : nums = [-1,1,2,3,1], target = 2
 * Output       : 3
 * Explanation  : There are 3 pairs of indices that satisfy the conditions in the statement:
 * 
 * Example 2    :
 * Input        : nums = [-6,2,5,-2,-7,-1,3], target = -2
 * Output       : 10
 * Explanation  : There are 10 pairs of indices that satisfy the conditions in the statement:
 *
 * https://drive.google.com/file/d/1HCxliot1UQzyN41jnltRR82vVarrJGJV/view
 * https://docs.google.com/document/d/1RfDh3mhgJqLiWacqo-jkn1-90g99gMKiKpCIlpnuHOo/edit?tab=t.0
*/

// ! OA

// * Hackerrank

// ! Range update trick

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

#define all(v) v.begin(), v.end()

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << "\n";
}

// * this convert time string to integer
int convert(string s) {
  // * 00:12 ----> converted to ---> 12.
  // * 01:01-----> converted to ---> 61.
  // * hour
  int u1 = int(s[0]) - '0';
  int u5 = int(s[1]) - '0';

  int v = (u1 * 10 + u5) * 60;
  
  // * minutes
  u1 = int(s[3]) - '0';
  u5 = int(s[4]) - '0';
  
  v = v + (u1 * 10 + u5);

  return v;
}

string convert_integer_totimestring(int g) {
  int u = g / 60;
  int y = g % 60;

  string t = "";
  if (u <= 9) {
    t += "0" + to_string(u);
  } else {
    t += to_string(u);
  }
  t += ":";
  
  if (y <= 9) {
    t += ("0" + to_string(y));
  } else {
    t += to_string(y);
  }

  return t;
}

// * TIME COMPLEXITY O(N*1440 + 1440)
// * SPACE COMPLEXITY O(1440)
string bruteForce(int k, vector<string> &events) {
  int n = events.size();

  // * Map all the events in day in our minutes vector
  vector<int> mins(1441, 0);
  for (int i = 0; i < n; ++i) { // * O(n^2)
    string evt = events[i];
    string start = evt.substr(evt.length() - 11, 5);
    string end = evt.substr(evt.length() - 5, 5);
    cout << start << " " << end << endl;
    int time_start = convert(start);
    int time_end = convert(end);
    // cout << time_start << " " << time_end << endl;
    // * Mark these minutes as taken
    for (int i = time_start; i <= time_end; ++i) {
      mins[i] = mins[i] + 1;
    }
  }

  int c = 0, found = 0;
  for (int i = 0; i < 1440; ++i) { // * O(1440)
    if (mins[i] == 0) { // * No event at this minute
      c++;
      if (c == k) { // * If we can get continuous k mins to party break.
        // cout << c << " " << i << endl;
        return convert_integer_totimestring(i - k + 1);
      }
    } else {
      c = 0;
    }
  }
  
  return "-1";
}


// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1440)
string meetingAssistant(int k, vector<string> &events) {
  int n = events.size();

  // * Map all the events in day in our minutes vector
  vector<int> mins(1441, 0);
  for (int i = 0; i < n; ++i) { // * O(n^2)
    string evt = events[i];
    string start = evt.substr(evt.length() - 11, 5);
    string end = evt.substr(evt.length() - 5, 5);
    cout << start << " " << end << endl;
    int time_start = convert(start);
    int time_end = convert(end);
    // * Mark these minutes as taken
    mins[time_start] += 1;
    mins[time_end + 1] += -1;
  }

  // * Range update  
  for (int i = 1; i <= 1440; ++i) { // * O(1440)
    mins[i] += mins[i - 1];
  }

  int c = 0, found = 0;
  for (int i = 0; i < 1440; ++i) { // * O(1440)
    if (mins[i] == 0) { // * No event at this minute
      c++;
      if (c == k) { // * If we can get continuous k mins to party break.
        // cout << c << " " << i << endl;
        return convert_integer_totimestring(i - k + 1);
      }
    } else {
      c = 0;
    }
  }
  
  return "-1";
}

int main(void) {
  // * testcase 1
  int k = 60;
  vector<string> events = {"Alex sleeps 00:00 08:00", "Sam sleeps 07:00 13:00", "Alex lunch 12:30 13:59"};

  // * testcase 2
  // int k = 60;
  // vector<string> events = {"Alex sleeps 12:00 23:59", "Sam sleeps 00:00 08:03"};

  cout << "k: " << k << endl;
  cout << "events: ";
  printArr(events);
  
  // string ans = bruteForce(k, events);
  string ans = meetingAssistant(k, events);
  cout << "Answer: " << ans << endl; 

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 10-meeting-assistant-hackerrank-oa.cpp -o output && ./output
