/*
 * Leetcode - ?
 * Remove Duplicates From an Unsorted Linked List
 * 
 * Given the head of a linked list, find all the values that appear more than once in the list and delete the 
 * nodes that have any of those values.
 * 
 * Return the linked list after the deletions.
 *  
 * Example 1
 * Input  : head = [1,2,3,2]
 * Output : [1,3]
 * 
 * Example 2
 * Input  : head = [2,1,1,2]
 * Output : []
 * 
 * Example 3
 * Input  : head = [3,2,2,1,3,2,4]
 * Output : [1,4]

 * https://neetcode.io/problems/remove-duplicates-from-an-unsorted-linked-list/question
*/

#include <vector>
#include <iostream>
#include "../common.hpp"


// * ------------------ Optimal Approach ---------------------
// * Dummy Pointer Approach + Unordered Map
// * TIME COMPLEXITY  O(N)
// * SPACE COMPLEXITY O(N)
ListNode* deleteDuplicatesUnsorted(ListNode* head) {
	unordered_map<int, int> freq;
	ListNode* temp = head;
	while (temp) {
		freq[temp->data]++;
		temp = temp->next;
	}

	ListNode* dummy = new ListNode(-1, head);
	ListNode* prev = dummy;
	ListNode* cur = dummy->next;

	while (cur) {
		if (freq[cur->data] > 1) {
			prev->next = cur->next;
		} else {
			prev = cur;
		}
		cur = cur->next;
	}

	return dummy->next;
}

int main()
{
	// * testcase 1
	// std::vector<int> arr = {1, 2, 3, 2};

	// * testcase 2
	// std::vector<int> arr = {2, 1, 1, 2};

	// * testcase 3
	std::vector<int> arr = {3, 2, 2, 1, 3, 2, 4};

	ListNode *head = arrayToLL(arr);
	printLL(head);

	head = deleteDuplicatesUnsorted(head);
	printLL(head);
}

// * Run the code
// * g++ --std=c++20 33-remove-duplicates-from-an-unsorted-linked-list.cpp -o output && ./output