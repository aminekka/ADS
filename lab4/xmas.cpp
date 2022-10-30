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
        void print(Node * current){
            if(current != NULL){
                cout << current->val << " ";
                print(current->left);
                print(current->right);
            }
        }
        void findSize(Node * current,int m){
            if(current->val==m){
                print(current);
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