/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* method_1(Node* root) {
        if (!root) {return root;}
        
        vector<Node*> vec, proc;
        vec.push_back(root);
        while (!vec.empty()) {
            for (Node* v : vec) {
                if (v->left) {proc.push_back(v->left);}
                if (v->right) {proc.push_back(v->right);}
            }
            for (int p = 1; p < proc.size(); p++){
                proc[p-1]->next = proc[p];
            }
            vec = proc;
            proc.clear();
        }
        
        return root;
    }
    
    Node* method_2(Node* root) {
        Node* prev; // the leading node on the next level
        Node* head; // head of the next level
        Node* parent = root;
        while (parent) { 
            while (parent) { // iterate on the parent level
                if (parent->left){
                    if (prev) {prev->next = parent->left;}
                    else {head = parent->left;}
                    prev = parent->left;
                    
                }
                if (parent->right){
                    if (prev) {prev->next = parent->right;}
                    else {head = parent->right;}
                    prev = parent->right;
                }
                parent = parent->next;
            }
            parent = head;
            prev = NULL;
            head = NULL;
        }
        return root;
    }
    
    Node* connect(Node* root) {
        // return method_1(root);
        return method_2(root);
    }
};