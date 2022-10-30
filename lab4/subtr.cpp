#include<iostream>
using namespace std;
struct Node{
    int val;
    Node * left, * right;
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
struct bst{
    private:
        Node * root;
        int size=1;

        Node * add(Node * current, int val){
            if(current==NULL) return new Node(val);

            if(current->val<val){
                current->right=add(current->right,val);
            }

            if(current->val>val){
                current->left=add(current->left,val);
            }
            return current;
        }
        void countsize(Node* cur) {
            if(cur != 0) {
                if(cur->left != 0) {
                    size++;
                    countsize(cur->left);
                }
                if(cur->right != 0) {
                    size++;
                    countsize(cur->right);
                }
            }
        }
        void findSize(Node * current,int m){
            if(current->val==m){
                countsize(current);
                cout<<size;
            }
            else if(current->val>m){
                return findSize(current->left,m);
            }
            else return findSize(current->right,m);
        }
    public:
        bst(){
            this->root = NULL;
        }

        void add(int x){
            Node * res = add(this->root, x);
            if(this->root == NULL) this->root = res;
        }
        void findSize(int m){
            findSize(this->root,m);
        }
};

int main(){
    int n,m;
    bst * tree = new bst();
    cin>>n;
    int num;
    for(int i=0;i<n;i++){
        cin>>num;
        tree->add(num);
    }
    cin>>m;
    tree->findSize(m);


}
/*
7
4 2 6 1 3 5 7
4
*/