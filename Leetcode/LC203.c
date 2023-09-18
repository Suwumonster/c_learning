#define _CRT_SECURE_NO_WARNINGS 1
/*
*Definition for singly - linked list.
* struct ListNode {
    *int val;
    *struct ListNode* next;
    *
};
*/


struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* newhead = NULL, * tail = NULL;
    struct ListNode* cur = head;
    while (cur)
    {
        if (cur->val != val)
        {
            if (newhead == NULL)
            {
                newhead = tail = cur;
            }
            else
            {
                tail->next = cur;
                tail = cur;
            }
            cur = cur->next;
        }
        else
        {
            struct ListNode* tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }
    if (tail)
    {
        tail->next = NULL;
    }
    return newhead;
}