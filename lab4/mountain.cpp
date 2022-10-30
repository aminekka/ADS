#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *left, *right;

    Node(int val){
        this->val = val;
        left = right = NULL;
    }
};

class BST{
    private:
        Node *root;
        Node *insert(Node *cur, int val){
            if(cur == NULL){
                return new Node(val);
            }
            if(val > cur->val){
                cur->right = insert(cur->right, val);
            } else {
                cur->left = insert(cur->left, val);
            }
            return cur;
        }

        void inorder(Node *node){
            if(node == NULL) return;
            inorder(node->left);
            cout << node->val << " ";
            inorder(node->right);
        }
        void preorder(Node *node){
            if(node == NULL) return;
            cout << node->val << " ";
            preorder(node->left);
            preorder(node->right);
        }
        void postorder(Node *node){
            if(node == NULL) return;
            postorder(node->left);
            postorder(node->right);
            cout << node->val << " ";
        }
        int rightmost(Node *node){
            if(node == NULL) return -1;
            if(node->right == NULL) return node->val;
            return rightmost(node->right);
        }
        int leftmost(Node *node){
            if(node == NULL) return -1;
            if(node->left == NULL) return node->val;
            return leftmost(node->left);
        }

        int getSize(Node *node){
            if(node == NULL) return 0;
            return getSize(node->left) + getSize(node->right) + 1;
        }


        bool search(Node *node, string target, int p){
            for(int i = 0; i < p; i++){
                if(target[i] == 'L'){
                    if(node->left == NULL) return false;
                    // else cnt++;
                    node = node->left;
                } else{
                    if(node->right == NULL) return false;
                    // else cnt++;
                    node = node->right;
                }
            }
            return true;
            // else return false;
        }

      
    public:
        BST(){
            root = NULL;
        }
        void insert(int val){
            root = insert(root, val);
        }
        void inorder(){
            inorder(root);
            cout << endl;
        }
        void preorder(){
            preorder(root);
            cout << endl;
        }
        void postorder(){
            postorder(root);
            cout << endl;
        }
        int getSize(){
            return getSize(root);
        }
        bool search(string target, int p){
            if(search(root, target, p)) return true;
            else return false;
        }
        Node *getRoot(){
            return root;
        }
};

int main(){
    BST tree;
    int n, k; cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        tree.insert(t);
    }
    for(int i = 0; i < k; i++){
        string s; cin >> s;
        int p = s.length();
        if(tree.search(s, p)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}


// #include<iostream>
// using namespace std;
// struct Node{
//     int val;
//     Node * left, * right;
//     Node(int val){
//         this->val=val;
//         this->left=NULL;
//         this->right=NULL;
//     }
// };
// struct bst{
//     private:
//         Node * root;

//         Node * add(Node * current, int val){
//             if(current==NULL) return new Node(val);

//             if(current->val<val){
//                 current->right=add(current->right,val);
//             }

//             if(current->val>val){
//                 current->left=add(current->left,val);
//             }

//             return current;
//         }
//         void findroot(Node * current, string c ){
//             bool ok = true;
//             for(int i=0;i<c.size();i++){
//                 if(c[i]=='L'){
//                     current=current->left;
//                 }
//                 if(c[i]=='R'){
//                     current=current->right;
//                 }
//                 if(current==NULL){
//                     ok=false;
//                     cout<<"NO\n";
//                     break;
//                 }
//             }
//             if(ok) cout<<"YES\n";
//         }
//     public:
//         bst(){
//             this->root = NULL;
//         }

//         void add(int x){
//             Node * res = add(this->root, x);
//             if(this->root == NULL) this->root = res;
//         }
//         void findroot(string c){
//             findroot(this->root,c);
//         }



// };

// int main(){
//     int n,m;
//     bst * tree = new bst();
//     cin>>n>>m;
//     int num;
//     for(int i=0;i<n;i++){
//         cin>>num;
//         tree->add(num);
//     }
//     string command;
//     for(int i=0;i<m;i++){
//         string c; cin>>c;
//         tree->findroot(c);
        
//     }
// }