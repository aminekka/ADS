#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *left;
    node *right;
    node(int x){
        val = x;
        left = NULL;
        right = NULL;

    }

}

struct bst{
    private:
    node * _root;
    node * add(node * cur, int x{}{
        if(cur == NULL) return new node(x);
        if(cur->val < x){
            cur->left = add(cur->left, x);
        }
        if(cur->val > x){
            cur->left = add(cur->left, x);

        }

        return cur;
    }

    bool find(node * cur, int x){
        if(cur == NULL) return false;
        if(cur->val == x) return true;
        if(cur->val > x) return find(cur->left, x);
        return find(cur->right, x);
    }

    void print(node * cur, int level){
        if(cur != NULL){
            print(cur->left, level+1);
            cout << cur->val << " " << level << endl;
            print(cur->right, level+1); 
        }
    }

    int leftmost(node * cur){
        if(cur == NULL) return -1;
        if(cur->left == NULL) return cur->val;
        return leftmost(cur->left);      
    }

    int rightmost(node * cur){
        if(cur == NULL) return -1;
        if(cur->right == NULL) return cur->val;
        return rightmost(cur->right);
    }



    node * del(node *cur, int x){
        if(cur == NULL) return NULL;
        if(cur->left == NULL and cur->right == NULL){
            delete cur;
            return NULL;

        }
        if(cur->right != NULL and cur->left == NULL){
            
        }
    }

}