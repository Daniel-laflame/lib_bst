#include <iostream>
using namespace std;

class Node {
private:
    int data;
    int weight;
    Node* lc;
    Node* rc;

public:

    Node(int x) {
        this->data = x;
        this->weight = 1;
        this->lc = nullptr;
        this->rc = nullptr;
    }

    Node* insertI(int k) {
        if (this == nullptr) {
            return new Node(k);
        }

        Node* current = this;
        Node* parent = nullptr;

         while (current != nullptr) {
            parent = current;
            if (current->data == k) {
                current->weight++;
                return this;
            } else if (current->data > k) {
                current = current->lc;
            } else {
                current = current->rc;
            }
        }

        Node* newNode = new Node(k);
        if (parent->data > k) {
            parent->lc = newNode;
        } else {
            parent->rc = newNode;
        }
        return this;
    }

    Node* insertR(int k) {
        if (this == NULL) {
            return new Node(k);
        }
        if (this->data == k) {
            this->weight++;
            return this;
        }
        if (this->data < k) {
            this->rc = this->rc->insertR(k);
        } else {
            this->lc = this->lc->insertR(k);
        }
        return this;
    }

    void preOrder() {
        if (this == NULL) {
            return;
        }
        cout << this->data << " ";
        this->lc->preOrder();
        this->rc->preOrder();
    }

    void postOrder() {
        if (this == NULL) {
            return;
        }
        this->lc->postOrder();
        this->rc->postOrder();
        cout << this->data << " ";
    }

    void inOrder() {
        if (this == NULL) {
            return;
        }
        this->lc->inOrder();
        cout << this->data << " ";
        this->rc->inOrder();
    }

    bool searchI(int k) {
        Node* current = this;
        while (current != nullptr) {
            if (current->data == k) {
                return true;
            }
            if (k < current->data) {
                current = current->lc;
            } else {
                current = current->rc;
            }
        }
        return false;
    }

    bool searchR(int k) {
        if (this == nullptr) {
            return false;
        }
        if (this->data == k) {
            return true;
        }
        if (this->data < k) {
            return this->rc->searchR(k);
        } else {
            return this->lc->searchR(k);
        }
    }

    int height(Node* root) {
        if (root == NULL) {
            return 0;
        }
        int l = height(root->lc);
        int r = height(root->rc);
        return max(l, r) + 1;
    }

    Node* remove_node(Node* root, int v) {
        if (root == NULL) {
            cout << "Non e' stato trovato nessun nodo che coincida col nodo da eliminare" << endl;
            return root;
        }
        if (root->data == v) {
            if (root->lc == NULL && root->rc == NULL) {
                delete root;
                root->data = 0;
                root->lc = nullptr;
                root->rc = nullptr;
                return root;
            }
            if (root->lc == NULL) {
                Node* temp = root->rc;
                delete root;
                root->data = 0;
                root->lc = nullptr;
                root->rc = nullptr;
                return temp;
            }
            if (root->rc == NULL) {
                Node* temp = root->lc;
                delete root;
                root->data = 0;
                root->lc = nullptr;
                root->rc = nullptr;
                return temp;
            }
        }
        if (v < root->data) {
            root->lc = remove_node(root->lc, v);
        } else {
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
};
