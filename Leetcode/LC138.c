#define _CRT_SECURE_NO_WARNINGS 1
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

//一旧一新节点相链接
//设置新链表的random指针
//将新旧链表解开
struct Node* copyRandomList(struct Node* head) {
    struct Node* cur = head;
    while (cur)
    {
        struct Node* next = cur->next;
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = cur->val;
        copy->next = next;
        cur->next = copy;
        cur = next;
    }
    cur = head;
    while (cur)
    {
        struct Node* copy = cur->next;
        if (cur->random == NULL)
        {
            copy->random = NULL;
        }
        else
        {
            copy->random = cur->random->next;
        }
        cur = copy->next;
    }
    cur = head;
    struct Node* copyhead = NULL;
    if (cur)
    {
        copyhead = cur->next;
    }
    while (cur)
    {
        struct Node* copy = cur->next;
        struct Node* next = copy->next;
        if (next)
        {
            copy->next = next->next;
        }
        cur->next = next;
        cur = next;
    }
    return copyhead;
}