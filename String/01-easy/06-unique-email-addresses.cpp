/*
 * Leetcode - 929
 * Unique Email Addresses
 * Every valid email consists of a local name and a domain name, separated by the '@' sign.
 * Besides lowercase letters, the email may contain one or more '.' or '+'.

 * Example 1
 * Input  : emails = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com",
 *                    "testemail+david@lee.tcode.com"]
 * Output : 2
 * Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails.

 * Example 2
 * Input  : emails = ["a@leetcode.com","b@leetcode.com","c@leetcode.com"]
 * Output : 3

 * https://leetcode.com/problems/unique-email-addresses/description/
*/

#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

void printVectorString(std::vector<std::string> strs) {
  int n = strs.size();
  std::cout << "[ "; 
  for (std::string s : strs) {
    std::cout << s << ", ";
  }
  std::cout << "]" << std::endl;
}

std::string isValidEmail(std::string email) {
  int domain_idx = email.find('@');
  std::string hostname = "";
  for (int i = 0; i < domain_idx; ++i) {
    if(email[i] == '.') 
      continue;
    else if(email[i] == '+')
      break;
    hostname += email[i];
  }

  std::string domain = email.substr(domain_idx);

  return hostname + domain;
}

// * Find Valid Email
// * TIME COMPLEXITY O(N) * O(M)    [M - Characters of each emails]
// * SPACE COMPLEXITY O(N)          [N - number of emails]
int numUniqueEmails(std::vector<std::string> emails) {
  std::unordered_set<std::string> emailSet;
  for (std::string e : emails) {
    std::string ans = isValidEmail(e);
    // std::cout << ans << std::endl;
    emailSet.insert(ans);
  }
  return emailSet.size();
}

int main() {
  // std::vector<std::string> emails = {"test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com",
  //                                    "testemail+david@lee.tcode.com"};

  std::vector<std::string> emails = {"a@leetcode.com", "b@leetcode.com", "c@leetcode.com"};
  printVectorString(emails);

  int validEmails = numUniqueEmails(emails);
  std::cout << "Valid Emails " << validEmails << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 06-unique-email-addresses.cpp -o 06-unique-email-addresses && ./06-unique-email-addresses
