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

    void print(Node<T>* tmp, int l) {
        while (tmp != NULL) {
            print(tmp->left, l + 2);
            for (int i = 1; i < l; i++) {
                std::cout << " ";
            }
            std::cout << tmp->value << "\n";
            tmp = tmp->right;
            l += 2;
        }
    }

    void insert(Node<T>** tmp,T val) {
        if (*tmp == NULL) {
           *tmp = new Node<T>(val);
        }
        else {
            if ((*tmp)->value > val) {
                insert((&(*tmp)->left), val);
            }
            if((*tmp)->value < val) {
                insert((&(*tmp)->right), val);
            }
        }
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
    void printTree() {
        print(this->first, 5);
    }
   
};

int main()
{
    BinTree<int> num;
    num.add(0);
    num.add(1);
    num.add(15);
    num.add(18);
    num.add(2);
    num.add(-5);
    num.printTree();
}
