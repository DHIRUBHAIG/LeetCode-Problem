/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head == NULL)
            return NULL;

        // Step 1: Create copied nodes
        // A -> B -> C
        // becomes
        // A -> A' -> B -> B' -> C -> C'
        
        Node* curr = head;

        while(curr != NULL) {

            Node* copy = new Node(curr->val);

            copy->next = curr->next;
            curr->next = copy;

            curr = copy->next;
        }


        // Step 2: Set random pointers

        curr = head;

        while(curr != NULL) {

            if(curr->random != NULL)
                curr->next->random = curr->random->next;

            curr = curr->next->next;
        }


        // Step 3: Separate original and copied lists

        curr = head;
        Node* copyHead = head->next;

        while(curr != NULL) {

            Node* copy = curr->next;

            // Restore original list
            curr->next = copy->next;

            // Connect copied list
            if(copy->next != NULL)
                copy->next = copy->next->next;

            curr = curr->next;
        }

        return copyHead;
    }
};