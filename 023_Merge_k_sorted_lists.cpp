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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int minVal, minIndex,i;
        ListNode *head,*index;
        head = new ListNode(0, nullptr );
        index=head;
        while( !lists.empty() ){
            minIndex = -1;
            for(i=0 ; i< lists.size();i++ ){
                if( lists[i] == nullptr ){
                    lists[i] = lists.back();
                    lists.pop_back();
                    i--;
                    continue;
                }
                else{
                    if( minIndex == -1 ){
                        minIndex = i;
                        minVal = lists[i]->val;
                    }
                    else{
                        if( minVal > lists[i]->val ){
                            minIndex = i;
                            minVal = lists[i]->val;
                        }
                    }
                }
            }
            if( minIndex != -1 ){
                index->next = lists[minIndex];
                index = index->next;
                lists[minIndex] = lists[minIndex]->next;
            }
        }
        return head->next;
    }
};

/*

add a min node every time
remove the one that is null

Time Complexity
O(kN)
Space Complexity
O(1)
*/

//However
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int minVal, minIndex,i;
        ListNode *head,*index;
        head = new ListNode(0, nullptr );
        vector<int> allInt;
        for( auto it = lists.begin(); it != lists.end();it++ ){
            index = *it;
            while( index != nullptr ){
                allInt.push_back( index->val );
                index = index->next;
            }
        }
        sort( allInt.begin(), allInt.end() );
        index=head;
        for( auto it= allInt.begin(); it != allInt.end();it++ ){
            index->next = new ListNode( *it );
            index = index->next;
        }
        return head->next;
    }
};

/*
this method is surprisingly faster consider it's only brute force

Time Complexity
O( NlogN )
Space Complexity
O(N)
*/
