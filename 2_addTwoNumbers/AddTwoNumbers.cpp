#include <iostream>

using namespace std;

//Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* answerLstHead = new ListNode();
        ListNode* currentNode = answerLstHead;
        int sum;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;

            //Get the value from l1 and move to the next node 
            if (l1) {
                sum += l1->val; 
                l1 = l1->next;
            }

            //Get the calue from l2 and move to the next node 
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            currentNode->next = new ListNode(sum % 10); //get the value for the next node 
            currentNode = currentNode->next;
        }
        ListNode* answer = answerLstHead->next; //skip over node used to create it 
        delete answerLstHead; //avoid memeory leak 
        return answer;
    }
};