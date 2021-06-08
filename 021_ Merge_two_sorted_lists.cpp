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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head, *index;
        head = new ListNode(0);
        index = head;
        while( l1 != nullptr && l2 != nullptr ){
            if( l1->val > l2->val ){
                index->next = l2;
                index=index->next;
                l2 = l2->next;
            }
            else{
                index->next = l1;
                index=index->next;
                l1= l1->next;
            }
        }
        while( l1 != nullptr ){
            index->next = l1;
            index=index->next;
            l1= l1->next;
        }
        while( l2 != nullptr ){
            index->next = l2;
            index=index->next;
            l2 = l2->next;
        }
        return head->next;
    }
};

/*

check whether value of head1 or head2 is smaller
add the smaller one

if one head is null, then only add another one, check corner case of two null list

Time Complexity
O( l1 + l2 )

Space Complexity
O(1)

*/