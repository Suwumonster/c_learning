#define _CRT_SECURE_NO_WARNINGS 1
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
    ListNode* MidNode(ListNode* A)
    {
        ListNode* slow, * fast;
        slow = A;
        fast = A;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* A)
    {
        ListNode* newhead = 0;
        ListNode* cur = A;
        ListNode* next = 0;
        while (cur)
        {
            next = cur->next;
            cur->next = newhead;
            newhead = cur;
            cur = next;
        }
        return newhead;
    }
    bool chkPalindrome(ListNode* A) {
        // write code here
        ListNode* B = reverse(MidNode(A));
        ListNode* cur1, * cur2;
        cur1 = A;
        cur2 = B;
        while (cur1 && cur2)
        {
            if (cur1->val != cur2->val)
            {
                return false;
            }
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return true;
    }
};