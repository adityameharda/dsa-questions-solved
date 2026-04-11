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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int>v1;
        vector<int>v2;
        vector<int>v;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        while(temp1 != NULL)
        {
            v1.push_back(temp1->val);
            temp1 = temp1 -> next;
        }
        while(temp2 != NULL)
        {
            v2.push_back(temp2->val);
            temp2 = temp2 -> next;
        }
        int i = 0 , carry = 0;
        while(i<v1.size() || i < v2.size() || carry)
        {
            int sum = carry ;
            if(i<v1.size()) sum += v1[i];
            if(i<v2.size()) sum += v2[i];
            v.push_back(sum%10);
            carry = sum/10;
            i++;
        }
        ListNode* currhead = new ListNode(v[0]);
        ListNode* curr = currhead;
        for(int i = 1; i < v.size() ; i++)
        {
            curr -> next = new ListNode(v[i]);
            curr = curr -> next;
        }
        return currhead ;
    }
};