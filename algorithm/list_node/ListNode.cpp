struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class ListNode
{
public:
    ListNode();
    ~ListNode();
    ListNode* reverseList(ListNode* head) {
        ListNode* res = NULL;
        ListNode* tmp = head;
        while(head != NULL) {
            head = head->next;
            tmp->next = res;
            res = tmp;
            tmp = head;
        }
    }
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
