/*You are given the head of a linked list.

Remove every node which has a node with a strictly greater value anywhere to the right side of it.

Return the head of the modified linked list.

 

Example 1:


Input: head = [5,2,13,3,8]
Output: [13,8]
Explanation: The nodes that should be removed are 5, 2 and 3.
- Node 13 is to the right of node 5.
- Node 13 is to the right of node 2.
- Node 8 is to the right of node 3.
Example 2:

Input: head = [1,1,1,1]
Output: [1,1,1,1]
Explanation: Every node has value 1, so no nodes are removed.
 

Constraints:The number of the nodes in the given list is in the range [1, 105].
1 <= Node.val <= 105
*/
  
  void Insert(int val,ListNode* &head,ListNode* &tail){
        ListNode* temp=new ListNode(val);
        if(head==NULL){
            head=temp;
            tail=temp;
            return;
        }
        tail->next=temp;
        tail=temp;
    }
    ListNode* removeNodes(ListNode* head) {
        vector<int>vec;
        ListNode* temp=head;
        while(temp!=NULL){
            vec.push_back(temp->val);
            temp=temp->next;
        }
        int n=vec.size();
        stack<int>st;
        for(auto i=n-1;i>=0;i--){
            if(!st.empty()&&vec[st.top()]<=vec[i])
            st.push(i);
            if(st.empty()){
                st.push(i);
            }
        }
        unordered_map<int,int>mp;
        vector<int>final;
        while(!st.empty()){
             final.push_back(vec[st.top()]);
            st.pop();
        }
        ListNode* newhead=  NULL;
        ListNode* tail=NULL;
        int newN=final.size();
        for(auto i=0;i<newN;i++){
            Insert(final[i],newhead,tail);
        }
        return newhead;
        
    }
tc->O(n)
sc->O(n)
