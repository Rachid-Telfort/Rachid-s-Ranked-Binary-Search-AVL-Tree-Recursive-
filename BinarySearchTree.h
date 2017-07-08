#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED

#include<iostream>
#include"Node.h"

class BinarySearchTree
{
    private:
        int counter;//This is to keep track of the current rank when traversing the tree.
        int numberOfNodes;//This is to keep track of the number of nodes in the entire tree.
        int numberOfNodesST;//This is to calculate how many nodes are in a particular subtree of a node.
        int rankCounter;//This is to record the current rank when printing out the various attributes of the tree.
        Node* root;

    public:
        BinarySearchTree();
        ~BinarySearchTree();
        void setCounter(int);
        int getCounter();
        void setNumberOfNodes(int);
        int getNumberOfNodes();
        void setNumberOfNodesST(int);
        int getNumberOfNodesST();
        void setRankCounter(int);
        int getRankCounter();
        void setRoot(Node*);
        Node* getRoot();
        void insertAtRank(int, int, Node*);
        void elementAtRank(int, Node*);
        void replaceAtRank(int, int, Node*);
        void removeAtRank(int, Node*);
        void clear(Node*);
        void printByRank(Node*);
        void printByLevel();
        void printLevelOrder(int, Node*);
        int getSubTreeSize(Node*);
        void updateNumberOfNodesLSTs(Node*);
        void updateHeights(Node*);
        void AVL(Node*);
};

#endif//BINARYSEARCHTREE_H_INCLUDED
