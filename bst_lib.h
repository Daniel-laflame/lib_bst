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

    Node* Remove_node(int k) {
        if (this == nullptr) {
            return this;
        }

        if (this->data == k) {
            if (this->lc == nullptr && this->rc == nullptr) {
                delete this;
                return nullptr;
            }

            if (this->lc == nullptr) {
                Node* temp = this->rc;
                delete this;
                return temp;
            }
            if (this->rc == nullptr) {
                Node* temp = this->lc;
                delete this;
                return temp;
            }

            Node* temp = this->rc;
            while (temp->lc != nullptr) {
                temp = temp->lc;
            }
            this->data = temp->data;
            this->rc = this->rc->remove_node(temp->data);
            return this;
        }

        if (k < this->data) {
            this->lc = this->lc->remove_node(k);
        } else {
            this->rc = this->rc->remove_node(k);
        }
        return this;
    }

    bool isBst() {
        if (this == nullptr) {
            return true;
        }
        if (this->data <= -1 || this->data >= 100) {
            return false;
        }
        return this->lc->isBst && this->rc->isBst
    }
};
