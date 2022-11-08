#define _CRT_SECURE_NO_WARNINGS 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* findMeet(struct ListNode* head) {
    struct ListNode* slow;
    struct ListNode* fast;
    slow = fast = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return slow;
        }
    }
    return 0;
}
struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* meet = findMeet(head);
    struct ListNode* cur = head;
    if (meet)
    {
        while (meet != cur)
        {
            meet = meet->next;
            cur = cur->next;
        }
        return meet;
    }
    return 0;
}