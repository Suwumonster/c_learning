#define _CRT_SECURE_NO_WARNINGS 1
//*********************************
// 作者：suwu
// 环境: vs2019 win10
// 最后修改时间：2023/7/29 11：03
//*********************************

struct ListNode {
    int val;
    struct ListNode* next;
};

// 函数名称：reverseList
// 函数功能：头插逆置链表
// 函数参数：链表头指针
// 返回类型及内容：逆置后的头指针
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* cur = head;
    struct ListNode* rhead = NULL;
    while (cur)
    {
        struct ListNode* next = cur->next;
        cur->next = rhead;
        rhead = cur;
        cur = next;
    }
    return rhead;
}