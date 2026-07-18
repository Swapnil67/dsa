/*
 * Leetcode - 82
 * Remove Duplicates from Sorted List II
 * 
 * Given the head of a sorted linked list, delete all nodes that have duplicate numbers, 
 * leaving only distinct numbers from the original list. Return the linked list sorted as well.
 * 
 * Example 1
 * Input  : head = [1,2,3,3,4,4,5]
 * Output : [1,2,5]
 * 
 * Example 2
 * Input  : head = [1,1,1,2,3]
 * Output : [2,3]

 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
*/

#include <vector>
#include <iostream>
#include "../common.hpp"


// * ------------------ Optimal Approach ---------------------
// * Dummy Pointer Approach
// * TIME COMPLEXITY  O(N)
// * SPACE COMPLEXITY O(1)
ListNode *deleteDuplicates(ListNode *head) {
	if (!head || !head->next)
		return head;

	ListNode *dummy = new ListNode(-1);
	dummy->next = head;

	ListNode *prev = dummy;
	ListNode *cur = head;

	while (cur) {
		if (cur->next && cur->data == cur->next->data) {
			int duplicate = cur->data; 
			while (cur && cur->data == duplicate) { // * Find the next val
				cur = cur->next;
			}
			prev->next = cur;
		}
		else {
			prev = cur;
			cur = cur->next;
		}
	}

	return dummy->next;
}

int main()
{
	// * testcase 1
	// std::vector<int> arr = {1, 2, 3, 3, 4, 4, 5};

	// * testcase 2
	std::vector<int> arr = {1, 1, 1, 2, 3};

	// * testcase 3
	// std::vector<int> arr = {1, 1, 2, 3, 3};

	ListNode *head = arrayToLL(arr);
	printLL(head);

	head = deleteDuplicates(head);
	printLL(head);
}

// * Run the code
// * g++ --std=c++20 32-remove-duplicates-from-sorted-list-ii.cpp -o output && ./output