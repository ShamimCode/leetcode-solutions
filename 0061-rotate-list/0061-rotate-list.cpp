/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == nullptr || head->next == nullptr || k == 0) return head;

        int len = 1;
        ListNode* tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
            len += 1;
        }

        k = k % len;
        if (k == 0) return head;

        tail->next = head;
        ListNode* newLastNode = head;
        for (int i = 1; i < len - k; i++) {
            newLastNode = newLastNode->next;
        }
        head = newLastNode->next;
        newLastNode->next = nullptr;

        return head;
    }
};