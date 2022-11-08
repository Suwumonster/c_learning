#define _CRT_SECURE_NO_WARNINGS 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
size_t nodeNum(struct ListNode* head)
{
    int num = 0;
    struct ListNode* cur = head;
    while (cur)
    {
        num++;
        cur = cur->next;
    }
    return num;
}
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    int len1 = nodeNum(headA);
    int len2 = nodeNum(headB);
    int gap = abs(len1 - len2);
    struct ListNode* longlist;
    struct ListNode* shortlit;
    longlist = headA;
    shortlit = headB;
    if (len2 > len1)
    {
        longlist = headB;
        shortlit = headA;
    }
    struct ListNode* cur1;
    struct ListNode* cur2;
    cur1 = longlist;
    cur2 = shortlit;
    while (gap--)
    {
        cur1 = cur1->next;
    }
    while (cur1)
    {
        if (cur1 == cur2)
        {
            return cur1;
        }
        cur1 = cur1->next;
        cur2 = cur2->next;

    }
    return 0;
}