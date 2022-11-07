#define _CRT_SECURE_NO_WARNINGS 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* cur1, * cur2, * head, * tail;
    cur1 = list1;
    cur2 = list2;
    head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
    tail->next = 0;
    while (cur1 && cur2)
    {
        if (cur1->val >= cur2->val)
        {
            tail->next = cur2;
            tail = cur2;
            cur2 = cur2->next;
        }
        else
        {
            tail->next = cur1;
            tail = cur1;
            cur1 = cur1->next;
        }
    }
    if (cur1)
    {
        tail->next = cur1;
    }
    else {
        tail->next = cur2;
    }
    tail = head->next;
    free(head);
    return tail;
}