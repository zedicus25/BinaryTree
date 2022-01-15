#include <iostream>
template <typename T>
struct Node {
    T value;
    Node* left;
    Node* right;
    Node(T val) {
       right = left = NULL;
       value = val;
   }
};
template <typename T>
class BinTree {
private:
    Node<T>* first;
    unsigned long size;
    template <typename T>
    void print(Node<T>* tmp, int l) {
        while (tmp != NULL) {
            print(tmp->left, l+1);
            for (int i = 0; i < l; i++) {
                std::cout << "   ";
            }
            std::cout << tmp->value << "\n";
            tmp = tmp->right;
            l += 1;
        }
    }

    template <typename T>
    void insert(Node<T>** tmp,T val) {
        if (*tmp == NULL) {
           *tmp = new Node<T>(val);
        }
        else {
            if ((*tmp)->value >= val) {
                insert((&(*tmp)->left), val);
            }
            if((*tmp)->value < val) {
                insert((&(*tmp)->right), val);
            }
        }
    }

    template <typename T>
    Node<T>* remove(Node<T>* root, T val) {
        if (root == NULL) {
            return NULL;
        }
        if (val == root->value) {
            Node<T>* tmp;
            if (root->right == NULL)
                tmp = root->left;
            else {
                tmp = root->right;
                if (tmp->left == NULL) {
                    tmp->left = root->left;
                }
                else {

                    Node<T>* tmp2 = tmp->left;
                    while (tmp2 != NULL) {
                        tmp = tmp2;
                        tmp2 = tmp->left;
                    }
                    tmp->left = tmp2->right;
                    tmp2->left = root->left;
                    tmp2->right = root->right;
                }
            }
            delete root;
            return tmp;
        }
        else if (val < root->value)
            root->left = remove(root->left, val);
        else
            root->right = remove(root->right, val);
        return root;
    }
public:
    explicit BinTree() {
        this->first = NULL;
        this->size = 0;
    }

    template <typename T>
    void add(T val) {
        insert(&this->first, val);
    }
    template <typename T>
    void del(T val) {
        remove(first, val);
    }
   
    void printTree() {
        print(this->first,5);
    }
   
};

int main()
{
    BinTree<int> num;
    num.add(44);
    num.add(19);
    num.add(29);
    num.add(8);
    num.add(10);
    num.add(107);
    num.add(36);
    num.add(7);
    num.add(42);
    num.printTree();
    std::cout << "-----------------------------------------------\n";
    num.del(8);
    num.del(36);
    num.del(55);
    num.del(42);
    num.printTree();
    std::cout << "----------------------------------------------\n";
    num.add(8);
    num.add(36);
    num.add(42);
    num.printTree();
}
