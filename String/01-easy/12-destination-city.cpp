/**
 * * Destination City
 * * You are given the array paths, where paths[i] = [cityAi, cityBi] 
 * * means there exists a direct path going from cityAi to cityBi. 
 * * Return the destination city, that is, the city without any path outgoing to another city

 * * Example 1
 * * Input  :  paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
 * * Output : "Sao Paulo" 
 * * Explanation : Starting at "London" city you will reach "Sao Paulo" city which is the destination city. 
 * *               Your trip consist of: "London" -> "New York" -> "Lima" -> "Sao Paulo".
 * 
 * * Example 2
 * * Input  :  paths = [["B","C"],["D","B"],["C","A"]]
 * * Output : "A" 
 * * Explanation : All possible trips are: 
 * *               "D" -> "B" -> "C" -> "A". 
 * *               "B" -> "C" -> "A". 
 * *               "C" -> "A". 
 * *               "A". 
 * *              Clearly the destination city is "A".
 * 
 * * https://leetcode.com/problems/destination-city/description/
*/

#include<iostream>
#include<unordered_set>

void printPaths(std::vector<std::vector<std::string>> cities) {
  for(auto vec : cities) {
    std::cout<<"[ ";
    for (int i = 0; i < vec.size(); i++) {
      if (i == vec.size() - 1) {
        std::cout << vec[i] << " ";
      }
      else {
        std::cout << vec[i] << ", ";
      }
    }
    std::cout << "]" << std::endl;
  }
}

// * Check which city does not have any linked city
std::string destCity(std::vector<std::vector<std::string>> cities) {
  int n = cities.size();
  if (n == 1)
    return cities[0][1];

  // * Push first cities to a set
  std::unordered_set<std::string> strSet;
  for (auto it : cities) {
    strSet.insert(it[0]);
  }

  // * Find Second cities in set
  for (auto it : cities) {
    if(strSet.find(it[1]) == strSet.end()) {
      return it[1];
    }
  }

  return "";
}

int main() {
  // * testcase 1
  // std::vector<std::vector<std::string>> paths = {{"London", "New York"}, {"New York", "Lima"}, {"Lima", "Sao Paulo"}};
  // * testcase 2
  // std::vector<std::vector<std::string>> paths = {{"B", "C"}, {"D", "B"}, {"C", "A"}};
  // * testcase 3
  std::vector<std::vector<std::string>> paths = {{"A", "Z"}};
  printPaths(paths);
  std::string city = destCity(paths);
  std::cout << "Destination City " << city << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 12-destination-city.cpp -o 12-destination-city && ./12-destination-city