#define _CRT_SECURE_NO_WARNINGS 1
//*********************************
// ���ߣ�suwu
// ����: vs2019 win10
// ����޸�ʱ�䣺2023/7/29 11��03
//*********************************

struct ListNode {
    int val;
    struct ListNode* next;
};

// �������ƣ�reverseList
// �������ܣ�ͷ����������
// ��������������ͷָ��
// �������ͼ����ݣ����ú��ͷָ��
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