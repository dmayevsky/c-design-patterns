#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
struct Node
{
    T value;
    Node *left{nullptr}, *right{nullptr}, *parent{nullptr};

    Node(T value) : value(value) {}

    Node(T value, Node<T> *left, Node<T> *right) : value(value), left(left), right(right) {
      left->parent = right->parent = this;
    }

//    preorder(node)
//    if (node == null)
//        return
//    visit(node)
//    preorder(node.left)
//    preorder(node.right)
      
    
    void preorder_traversal(vector<Node<T>*>& result)
    {
      std::cout << this->value << ", ";
      if (left != NULL) {
        left->preorder_traversal(result);
        };
      if (right != NULL) {
        right->preorder_traversal(result);
        };
    };
};

int main() {
  Node<string> a{"a"};
  Node<string> b{"b"};
  Node<string> c{"c"};
  Node<string> d{"d", &a, &b};
  Node<string> e{"e", &d, &c};
  
  vector<Node<string>*> result;
  
  std::cout << "[ ";
  
  e.preorder_traversal(result);  
  std::cout << " ]";
  return 0;
}