/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // if(head == NULL || head->next == NULL)  return head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = head;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast) {
                while(slow!=temp) {
                    slow = slow->next;
                    temp = temp->next;
                }
                return temp;
            }   
        }
        return NULL;
    }
    
    /*
    
    Solution 2:
    ListNode *detectCycle(ListNode *head) {
        // if(head == NULL || head->next == NULL)  return head;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = head;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast) {
                break;
            }   
        }
        
        if (!(fast && fast->next)) {
            return NULL;
        }
        
        while(slow!=temp) {
            slow = slow->next;
            temp = temp->next;
        }
        return temp;
    }
    */
};