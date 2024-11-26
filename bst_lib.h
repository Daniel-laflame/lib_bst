#include <iostream>
using namespace std;

class Node {
private:
    int data;
    int weight;
    Node* lchild;
    Node* rchild;

public:

    Node(int x) {
        this->data = x;
        this->weight = 1;
        this->lchild = nullptr;
        this->rchild = nullptr;
    }


    Node *insert_it(node* root, int v){
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

Node* insertR(int k){
    if(this==NULL){
        return new Node(k);
    }
    if(this->data==k){
        this->weight++;
        return this;
    }
    if(this->data<k){
        this->rc=this->rc->insertR(k);
    } else {
        this->lc=this->lc->insertR(k);
    }
    return this;
}

void preOrder (){
    if(this==NULL){
            return;
     }
    cout << this->data << " ";
    this->lc->preOrder();
    this->rc->preOrder();
}

void postOrder (){
    if(this==NULL){
            return;
     }
    this->lc->postOrder();
    this->rc->postOrder();
    cout << this->data << " ";
}

void inOrder (){
    if(this==NULL){
            return;
     }
    this->lc->inOrder();
    cout << this->data << " ";
    this->rc->inOrder();
}

bool search_it(Node* root,int sv){
    Node* current = root;
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


bool search_ric(Node* root,int sv){
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

int height(Node* root){
    if (root==NULL){
        return 0;
    }
    int l=height(root->lc);
    int r=height(root->rc);
    return max(l,r)+1;
}

Node* remove_node(Node* root, int v){
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

bool isBST(Node* root, int mv = -100, int MV = 100) {
    if (root == nullptr) {
        return true;
    }
    if (root->data <= mv || root->data >= MV) {
        return false;
    }
    return isBST(root->lc, mv, root->data) && 
           isBST(root->rc, root->data, MV);
}