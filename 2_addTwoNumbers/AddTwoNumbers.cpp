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
        ListNode* answer;
        int product;
        int carry = 0;

        while (l1->next != nullptr && l2->next != nullptr) {
            product = l1->val + l2->val + carry;
            if (product > 9) {
                carry = (product % 10) + 1; //Calculate the carry in the event there is one 
                product = product - 10; //calculate the next digit in the list
            }
        }

    }
private:
    //fucntion to calculate the length of a linked list
    int listLength(ListNode* lst) {
        int length = 0;
        while (lst->next != nullptr) {
            lst = lst->next; //itterate through 
            length++;
        }
        length++; //to account for the very last node

        return length;
    }
    
    //function to get the value of the last element of the linked list 
    int getLastValue(ListNode* lst) {
        int lastValue;
        //Cases
        if (lst->next == nullptr) return lst->val;
        if (lst->next->next != nullptr) getLastValue(lst->next); //use recusion to go through the list

        lastValue = lst->next->val; //get the value of the last node 
        lst->next = nullptr; //set the new end node of the linked list 
        return lastValue;
    }

    //function to get the full number for the linked list
    int compileNumber(ListNode* lst) {
        int fullNumber;
        int length = listLength(lst);
        int decimalPlace = 0;

        for (int i = 0; i < length; i++) {
            fullNumber += getLastValue(lst) + decimalPlace;
            
            //increment the decimal place
            if (decimalPlace == 0) decimalPlace = 10;
            else {
                decimalPlace *= 10;
            }
        }

        return fullNumber;
    }
};