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
        return res;
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
    bool isPalindromePro(ListNode* head) {
        if (head == NULL || head->next == NULL)
        {
            return true;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = reverseList(slow->next);
        slow = slow->next;
        while(slow != NULL) {
            if (head->val != slow->val)
            {
                return false;
            }
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};
