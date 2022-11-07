#define _CRT_SECURE_NO_WARNINGS 1
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

 /**
  *
  * @param pListHead ListNode��
  * @param k int����
  * @return ListNode��
  */
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
    // write code here
    if (pListHead == 0)
    {
        return 0;
    }
    struct ListNode* slow, * fast;
    slow = fast = pListHead;
    while (k--)
    {
        if (fast)
        {
            fast = fast->next;
        }
        else {
            return 0;
        }
    }
    while (fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}