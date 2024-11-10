#include <iostream>
using namespace std;

struct node{
    int data;
    int weight;
    node* lc;
    node* rc;
    node(int x) {
        data = x;
        weight=1;
        lc = nullptr;
        rc = nullptr;
    }
};


node *insert_it(node* root, int v){
    if (root==NULL){
        return new node(v);
    }
    node *current=root;
    node *parent=nullptr;
    
    while(current!=NULL){
        parent = current;
        if (current->data==v){
            current->weight++;
            return root;
        } else if (current->data > v){
            current = current->lc;
        } else {
            current = current->rc;
        }
    }
        node *newNode = new node(v);
        
        if (parent->data > v){
            parent->lc = newNode;
        } else if (parent->data < v){
            parent->rc= newNode;
        }
    return root;
}

node* insert_ric(node *root,int v){
    if(root==NULL){
        return new node(v);
    }
    if(root->data==v){
        root->weight++;
        return root;
    }
    if(root->data<v){
        root->rc=insert_ric(root->rc,v);
    } else {
        root->lc=insert_ric(root->lc,v);
    }
    return root;
}

void preorder (node* root){
    if(root==NULL){
            return;
     }
    cout << root->data << " ";
    preorder(root->lc);
    preorder(root->rc);
}

void inorder (node* root){
    if(root==NULL){
            return;
     }
    inorder(root->lc);
    cout << root->data << " ";
    inorder(root->rc);
}

bool search_it(node* root,int sv){
    node* current = root;
    while(current!=NULL){
        if (current->data==sv){
            return true;
        }
        if (sv < current->data){
            current=current->lc;
        } else {
            current=current->rc;
        }
    }
    return false;
}


bool search_ric(node* root,int sv){
    if (root->data==sv){
        return true;
    }
    if (root==nullptr){
        return false;
    }
   if(root->data<sv){
        return search_ric(root->rc,sv);
    } else {
        return search_ric(root->lc,sv);
    }
    return false;
}

int height(node* root){
    if (root==NULL){
        return 0;
    }
    int l=height(root->lc);
    int r=height(root->rc);
    return max(l,r)+1;
}

node* remove_node(node* root, int v){
    if(root==NULL){
        cout<<"non e stato trovato nessun nodo che coincida col nodo da eliminare"<<endl;
        return root;
    }
    if(root->data == v){
        if(root->lc==NULL && root->rc==NULL){
            delete root;
            root->data = 0;
            root->lc = nullptr;
            root->rc = nullptr;
            return root;
        }
        if(root->lc==NULL){
            node* temp = root->rc;
            delete root;
            root->data = 0;
            root->lc = nullptr;
            root->rc = nullptr;
            return temp;
        }
        if(root->rc==NULL){
            node* temp = root->lc;
            delete root;
            root->data = 0;
            root->lc= nullptr;
            root->rc = nullptr;
            return temp;
        }
    }
    if(v<root->data){
        root->lc = remove_node(root->lc, v);
    } else{
        root->rc = remove_node(root->rc, v);
    }
    return root;
}

bool isBST(node* root, int mv = -100, int MV = 100) {
    if (root == nullptr) {
        return true;
    }
    if (root->data <= mv || root->data >= MV) {
        return false;
    }
    return isBST(root->lc, mv, root->data) && 
           isBST(root->rc, root->data, MV);
}