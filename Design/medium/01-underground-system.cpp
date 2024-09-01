// * https://leetcode.com/problems/design-underground-system/submissions/1374158774/

#include<unordered_map>
#include<iostream>

class UndergroundSystem {
  public:

    std::unordered_map<int, std::pair<std::string, int>> checkInMap;
    // * Think of it like nested json object
    std::unordered_map<std::string, std::unordered_map<std::string, std::pair<int, int>>> trainDistanceSumMap;

    UndergroundSystem() {
      this->checkInMap = {};
      this->trainDistanceSumMap = {};
    }
    
    void checkIn(int id, std::string stationName, int t) {
      checkInMap[id] = { stationName, t };
    }
    
    void checkOut(int id, std::string endStation, int t) {
      std::string startStation = checkInMap[id].first;
      int time = checkInMap[id].second;
      int diff = t - time;
      trainDistanceSumMap[startStation][endStation].first += diff;
      trainDistanceSumMap[startStation][endStation].second += 1;
    }
    
    double getAverageTime(std::string startStation, std::string endStation) {
      return (double)trainDistanceSumMap[startStation][endStation].first / (double)trainDistanceSumMap[startStation][endStation].second;
    }
};

int main() {
  UndergroundSystem *obj = new UndergroundSystem();

  // * testcase 1
  obj->checkIn(10, "churchgate", 3);
  obj->checkOut(10, "dadar", 8);
  double avg1 = obj->getAverageTime("churchgate", "dadar");
  std::cout << avg1 << std::endl;

  obj->checkIn(5, "churchgate", 10);
  obj->checkOut(5, "dadar", 16);
  double avg2 = obj->getAverageTime("churchgate", "dadar");
  std::cout << avg2 << std::endl;

  obj->checkIn(2, "churchgate", 21);
  obj->checkOut(2, "dadar", 30);
  double avg3 = obj->getAverageTime("churchgate", "dadar");
  std::cout << avg3 << std::endl;

  // * testcase 2

  // obj->checkIn(45, "a", 3);
  // obj->checkIn(32, "aa", 8);
  // obj->checkIn(27, "a", 10);

  // obj->checkOut(45, "ab", 15);
  // obj->checkOut(27, "ab", 20);
  // obj->checkOut(32, "b", 22);

  // double avg1 = obj->getAverageTime("aa", "b");
  // std::cout << avg1 << std::endl;

  // double avg0 = obj->getAverageTime("a", "ab");
  // std::cout << avg0 << std::endl;

  // obj->checkIn(10, "a", 24); 

  // double avg2 = obj->getAverageTime("a", "ab");
  // std::cout << avg2 << std::endl;

  // obj->checkOut(10, "ab", 38); 
  // double avg3 = obj->getAverageTime("a", "ab");
  // std::cout << avg3 << std::endl;


  return 0;
}

// * run the code
// * g++ --std=c++17 01-underground-system.cpp -o output && ./output