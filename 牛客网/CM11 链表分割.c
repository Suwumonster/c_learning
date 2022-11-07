/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        // write code here
        ListNode* head1, * head2, * tail1, * tail2, * cur;
        head1 = tail1 = (ListNode*)malloc(sizeof(ListNode));
        head2 = tail2 = (ListNode*)malloc(sizeof(ListNode));
        tail1->next = 0;
        tail2->next = 0;
        cur = pHead;
        while (cur)
        {
            if (cur->val < x)
            {
                tail1->next = cur;
                tail1 = cur;
            }
            else
            {
                tail2->next = cur;
                tail2 = cur;
            }
            cur = cur->next;
        }
        tail2->next = 0;
        tail1->next = head2->next;
        tail1 = head1->next;
        free(head2);
        free(head1);
        return tail1;
    }
};