#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include<cstddef>

class Node
{
    private:
        int element;
        int leftHeight;
        int rightHeight;
        int numberOfNodesLST;//This is to keep track of the number of nodes in the left subtree for each node.
        Node* leftChild;
        Node* rightChild;
        Node* parent;

    public:
        Node(int, int, int, int, Node*, Node*, Node*);
        ~Node();
        void setElement(int);
        int getElement();
        void setLeftHeight(int);
        int getLeftHeight();
        void setRightHeight(int);
        int getRightHeight();
        void setNumberOfNodesLST(int);
        int getNumberOfNodesLST();
        void setLeftChild(Node*);
        Node* getLeftChild();
        void setRightChild(Node*);
        Node* getRightChild();
        void setParent(Node*);
        Node* getParent();
};

#endif//NODE_H_INCLUDED
