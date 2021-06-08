class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0, value = 0;
        ListNode *head = new ListNode;
        ListNode *index=head;
        while( l1 || l2 ){
            if( l1 && l2 ){
                value = (l1->val + l2->val + carry);
                l1 = l1->next;
                l2 = l2->next;
            }
            else if( l1 ){
                value = (l1->val + carry);
                l1 = l1->next;
            }
            else{
                value = ( l2->val + carry );
                l2 = l2->next;
            }
            carry = value/10;
            index->next = new ListNode( value%10 );
            index = index->next;
        }
        if( carry !=0 ){
            index->next = new ListNode(carry);
        }
        return head->next;
    }
};
/*
Mind the carry in the end

Time Complexity : O( n1 + n2 )

Space Complexity : O( n1 | n2 )

*/