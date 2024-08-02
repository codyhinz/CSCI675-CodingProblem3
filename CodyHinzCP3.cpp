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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> values;
        ListNode* curr = head;
        
        // Store node values in a vector
        while (curr) {
            values.push_back(curr->val);
            curr = curr->next;
        }
        
        int n = values.size();
        vector<int> answer(n, 0);
        stack<int> st;
        
        // Traverse the vector from right to left
        for (int i = n - 1; i >= 0; i--) {
            // Pop elements from stack smaller than current value
            while (!st.empty() && values[i] >= values[st.top()]) {
                st.pop();
            }
            
            // Set answer[i] to the next greater value if found
            if (!st.empty()) {
                answer[i] = values[st.top()];
            }
            
            // Push current index onto the stack
            st.push(i);
        }
        
        return answer;
    }
};