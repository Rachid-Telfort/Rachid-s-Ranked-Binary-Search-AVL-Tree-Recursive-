#include"Node.h"

Node::Node(int element, int leftHeight, int rightHeight, int numberOfNodesLST, Node* leftChild, Node* rightChild, Node* parent)
{
    this->setElement(element);
    this->setLeftHeight(leftHeight);
    this->setRightHeight(rightHeight);
    this->setNumberOfNodesLST(numberOfNodesLST);
    this->setLeftChild(leftChild);
    this->setRightChild(rightChild);
    this->setParent(parent);
}

Node::~Node()
{
    this->setElement(0);
    this->setLeftHeight(0);
    this->setRightHeight(0);
    this->setNumberOfNodesLST(0);
    this->setLeftChild(NULL);
    this->setRightChild(NULL);
    this->setParent(NULL);
}

void Node::setElement(int element)
{
    this->element=element;
}

int Node::getElement()
{
    return this->element;
}

void Node::setLeftHeight(int leftHeight)
{
    this->leftHeight=leftHeight;
}

int Node::getLeftHeight()
{
    return this->leftHeight;
}

void Node::setRightHeight(int rightHeight)
{
    this->rightHeight=rightHeight;
}

int Node::getRightHeight()
{
    return this->rightHeight;
}

void Node::setNumberOfNodesLST(int numberOfNodesLST)
{
    this->numberOfNodesLST=numberOfNodesLST;
}

int Node::getNumberOfNodesLST()
{
    return this->numberOfNodesLST;
}

void Node::setLeftChild(Node* leftChild)
{
    this->leftChild=leftChild;
}

Node* Node::getLeftChild()
{
    return this->leftChild;
}

void Node::setRightChild(Node* rightChild)
{
    this->rightChild=rightChild;
}

Node* Node::getRightChild()
{
    return this->rightChild;
}

void Node::setParent(Node* parent)
{
    this->parent=parent;
}

Node* Node::getParent()
{
    return this->parent;
}
