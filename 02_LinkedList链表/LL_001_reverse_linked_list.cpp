//
// Created by LiuXing on 2019/10/23.
// LeetCode #206
#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){};
};

class solution{
public:
    ListNode* reverseList(ListNode* head){
        ListNode* pre = NULL;
        ListNode* cur = head;
        while(cur){
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};