/*
 * Encode and Decode TinyURL
 * Given an integer array nums, return an array answer such that answer[i] is equal to the product of all 
 * * the elements of nums except nums[i].
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 * 
 * You must write an algorithm that runs in O(n) time and without using the division operation.
 * 
 * Example 1:
 * Input:  url = "https://leetcode.com/problems/design-tinyurl"
 * Output: encode = "http://tinyurl.com/4e9iAk" and decode = "https://leetcode.com/problems/design-tinyurl" 

 * https://www.naukri.com/code360/problems/encode-and-decode_1467061
 * https://leetcode.com/problems/encode-and-decode-tinyurl/description/
*/

#include<map>
#include<iostream>

class TinyURL {
  public: 
    std::string baseURL;
    std::map<std::string, std::string> encodeMap;
    std::map<std::string, std::string> decodeMap;

    TinyURL() {
      this->baseURL = "http://tinyurl.com/";
      this->encodeMap = {};
      this->decodeMap = {};
    }

    // * Encodes a URL to a shortened URL.
    std::string encode(std::string long_url) {
      // * If exists then return
      if(this->encodeMap.find(long_url) != this->encodeMap.end()) {
        return encodeMap[long_url];
      }

      // * Encode the URL
      int new_len = encodeMap.size();
      std::string short_url = this->baseURL + std::to_string(new_len);
      this->encodeMap[long_url] = short_url;
      this->decodeMap[short_url] = long_url;
      return short_url;
    }

    // * Decodes a shortened URL to its original URL.
    std::string decode(std::string short_url) {
      if(decodeMap.find(short_url) != decodeMap.end()) {
        return decodeMap[short_url];
      }
      return "";
    }
};




int main() {
  std::string long_url1 = "https://leetcode.com/problems/design-tinyurl";
  std::string long_url2 = "https://leetcode.com/problems/design-tinyurl2";

  // std::cout << url << std::endl;
  TinyURL *url1 = new TinyURL();
  std::string encoded_url1 = url1->encode(long_url1);
  std::cout << "Encoded URL 1 " << encoded_url1 << std::endl;
  std::string decoded_url1 = url1->decode(encoded_url1);
  std::cout << "Decoded URL 1 " << decoded_url1 << std::endl;
  
  std::string encoded_url2 = url1->encode(long_url2);
  std::cout << "Encoded URL 2 " << encoded_url2 << std::endl;
  std::string decoded_url2 = url1->decode(encoded_url2);
  std::cout << "Decoded URL 2 " << decoded_url2 << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 02-encode-and-decode-tinyURL.cpp -o output && ./output