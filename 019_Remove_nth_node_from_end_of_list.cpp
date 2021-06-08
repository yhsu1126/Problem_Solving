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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *first, *second, *beforeSecond;
        int ready=n;
        first = head;
        second = head;
        beforeSecond = new ListNode( 0,head );
        while( first->next != nullptr ){
            if( ready != 0 ){
                ready--;
            }
            if( ready==0 ){
                second = second->next;
                beforeSecond = beforeSecond->next;
            }
            first = first->next;
        }
        if( beforeSecond->next == head ){
            beforeSecond->next = second->next;
            delete(second);
            first = nullptr;
            second = nullptr;
            return (beforeSecond->next);
        }
        else{
            ListNode *result;
            beforeSecond->next = second->next;
            delete(second);
            second = nullptr;
            return head;
        }
    }
};

/*
have three pointers
if we want to remove the nth node
we forward the first pointer n times
then start forwarding second and first pointer, where the third poniter point to the node before second pointer
when first meet the end, the node second pointer point to is the node we want to remove.
##################
have two pointers
first pointer run n+1 times
second pointer start running,second pointer points to the node before the node we want to remove

Time Complexity
O(n)
Space Complexity
O(1)


*/