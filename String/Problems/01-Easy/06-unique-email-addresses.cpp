/**
 * * Unique Email Addresses
 * * Every valid email consists of a local name and a domain name, separated by the '@' sign.
 * * Besides lowercase letters, the email may contain one or more '.' or '+'.

 * * Example 1
 * * Input  : emails = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com",
 * *                    "testemail+david@lee.tcode.com"]
 * * Output : 2
 * * Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails.

 * * Example 2
 * * Input  : emails = ["a@leetcode.com","b@leetcode.com","c@leetcode.com"]
 * * Output : 3

 * * https://leetcode.com/problems/unique-email-addresses/description/
*/

#include<unordered_set>
#include<string>
#include<iostream>

void printVectorString(std::vector<std::string> arr) {
  std::cout<<"[ ";
  for(std::string s: arr) {
    std::cout<<s;
    std::cout<<", ";
  }
  std::cout<<"]\n";
}

std::string isValidEmail(std::string email) {
  std::string localName = "";
  int i = 0;
  int p = email.find('@');
  std::string dname = email.substr(p);

  while(email[i] != '@') {
    if(email[i] == '.') {
      i++;
      continue;
    }
    else if(email[i] == '+') {
      break;
    }
    localName += email[i];
    i++;
  }

  std::string newEmail = localName + dname;
  return newEmail;
}

int bruteForce(std::vector<std::string> emails) {
  int n = emails.size();
  int validMails = 0;
  std::unordered_set<std::string> emailSet;
  for(std::string e : emails) {
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
  int validEmails = bruteForce(emails);
  std::cout << "Valid Emails " << validEmails << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 06-unique-email-addresses.cpp -o 06-unique-email-addresses && ./06-unique-email-addresses
