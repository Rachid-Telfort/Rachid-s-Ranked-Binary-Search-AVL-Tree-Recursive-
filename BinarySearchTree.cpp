#include"BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
    this->setCounter(0);
    this->setNumberOfNodes(0);
    this->setNumberOfNodesST(0);
    this->setRankCounter(0);
    this->setRoot(NULL);
}

BinarySearchTree::~BinarySearchTree()
{
    this->setCounter(0);
    this->setNumberOfNodes(0);
    this->setNumberOfNodesST(0);
    this->setRankCounter(0);
    this->clear(this->getRoot());
    this->setRoot(NULL);
}

void BinarySearchTree::setCounter(int counter)
{
    this->counter=counter;
}

int BinarySearchTree::getCounter()
{
    return this->counter;
}

void BinarySearchTree::setNumberOfNodes(int numberOfNodes)
{
    this->numberOfNodes=numberOfNodes;
}

int BinarySearchTree::getNumberOfNodes()
{
    return this->numberOfNodes;
}

void BinarySearchTree::setNumberOfNodesST(int numberOfNodesST)
{
    this->numberOfNodesST=numberOfNodesST;
}

int BinarySearchTree::getNumberOfNodesST()
{
    return this->numberOfNodesST;
}

void BinarySearchTree::setRankCounter(int rankCounter)
{
    this->rankCounter=rankCounter;
}

int BinarySearchTree::getRankCounter()
{
    return this->rankCounter;
}

void BinarySearchTree::setRoot(Node* root)
{
    this->root=root;
}

Node* BinarySearchTree::getRoot()
{
    return this->root;
}

void BinarySearchTree::insertAtRank(int rank, int element, Node* insertNode)
{
    if(rank<=0)
    {
        std::cout<<"You must insert an element at a positive rank. Please re-insert an element at an appropriate rank.\n"<<std::endl;
    }

    else if(rank>this->getNumberOfNodes()+1)
    {
        std::cout<<"You cannot insert an element at the specified rank as no element exists in the previous rank yet. Please re-insert an element at an appropriate rank.\n"<<std::endl;
    }

    else
    {
        if(this->getRoot()==NULL)
        {
            this->setRoot(new Node(element, 0, 0, 0, NULL, NULL, NULL));
            this->setNumberOfNodes(this->getNumberOfNodes()+1);
            std::cout<<"The element "<<element<<" has successfully been inserted at rank "<<rank<<" into the ranked binary search AVL tree.\n"<<std::endl;
        }

        else
        {
            if(rank<=this->getCounter()+insertNode->getNumberOfNodesLST()+1)
            {
                if(insertNode->getLeftChild()!=NULL)
                {
                    this->insertAtRank(rank, element, insertNode->getLeftChild());
                }

                else
                {
                    insertNode->setLeftChild(new Node(element, 0, 0, 0, NULL, NULL, insertNode));
                    this->setNumberOfNodes(this->getNumberOfNodes()+1);
                    std::cout<<"The element "<<element<<" has successfully been inserted at rank "<<rank<<" into the ranked binary search AVL tree.\n"<<std::endl;
                }
            }

            else
            {
                if(insertNode->getRightChild()!=NULL)
                {
                    this->setCounter(this->getCounter()+insertNode->getNumberOfNodesLST()+1);
                    this->insertAtRank(rank, element, insertNode->getRightChild());
                }

                else
                {
                    insertNode->setRightChild(new Node(element, 0, 0, 0, NULL, NULL, insertNode));
                    this->setNumberOfNodes(this->getNumberOfNodes()+1);
                    std::cout<<"The element "<<element<<" has successfully been inserted at rank "<<rank<<" into the ranked binary search AVL tree.\n"<<std::endl;
                }
            }
        }
    }
}

void BinarySearchTree::elementAtRank(int rank, Node* elementNode)
{
    if(rank<=0)
    {
        std::cout<<"You can only search for an element at a positive rank. Please re-search for an element at an appropriate rank.\n"<<std::endl;
    }

    else if(rank>this->getNumberOfNodes()+1)
    {
        std::cout<<"You cannot search for an element at the specified rank as no element exists in the specified rank yet. Please re-search for an element at an appropriate rank.\n"<<std::endl;
    }

    else if(this->getRoot()==NULL)
    {
        std::cout<<"You cannot search for an element at the specified rank because the ranked binary search AVL tree is currently empty. Please re-search for an element at the specified rank when more nodes are added to the ranked binary search AVL tree.\n"<<std::endl;
    }

    else
    {
        if(rank==this->getCounter()+elementNode->getNumberOfNodesLST()+1)
        {
            std::cout<<"The element at rank "<<rank<<" is "<<elementNode->getElement()<<".\n"<<std::endl;
        }

        else if(rank<this->getCounter()+elementNode->getNumberOfNodesLST()+1)
        {
            if(elementNode->getLeftChild()!=NULL)
            {
                this->elementAtRank(rank, elementNode->getLeftChild());
            }

            else
            {
                std::cout<<"There is no element at the specified rank. Please re-search for an element at the specified rank when a node is added at the specified rank.\n"<<std::endl;
            }
        }

        else
        {
            if(elementNode->getRightChild()!=NULL)
            {
                this->setCounter(this->getCounter()+elementNode->getNumberOfNodesLST()+1);
                this->elementAtRank(rank, elementNode->getRightChild());
            }

            else
            {
                std::cout<<"There is no element at the specified rank. Please re-search for an element at the specified rank when a node is added at the specified rank.\n"<<std::endl;
            }
        }
    }
}

void BinarySearchTree::replaceAtRank(int rank, int element, Node* replaceNode)
{
    if(rank<=0)
    {
        std::cout<<"You can only search for an element at a positive rank to replace. Please re-search for an element at an appropriate rank to replace.\n"<<std::endl;
    }

    else if(rank>this->getNumberOfNodes()+1)
    {
        std::cout<<"You cannot search for an element at the specified rank as no element exists at the specified rank yet to replace. Please re-search for an element at an appropriate rank to replace.\n"<<std::endl;
    }

    else if(this->getRoot()==NULL)
    {
        std::cout<<"You cannot search for an element to replace at the specified rank because the ranked binary search AVL tree is currently empty. Please re-search for an element to replace at the specified rank when more nodes are added to the ranked binary search AVL tree.\n"<<std::endl;
    }

    else
    {
        if(rank==this->getCounter()+replaceNode->getNumberOfNodesLST()+1)
        {
            int previousElement=replaceNode->getElement();
            replaceNode->setElement(element);
            std::cout<<"The element "<<previousElement<<" at rank "<<rank<<" was successfully replaced with the element "<<replaceNode->getElement()<<" in the ranked binary search AVL tree.\n"<<std::endl;
        }

        else if(rank<this->getCounter()+replaceNode->getNumberOfNodesLST()+1)
        {
            if(replaceNode->getLeftChild()!=NULL)
            {
                this->replaceAtRank(rank, element, replaceNode->getLeftChild());
            }

            else
            {
                std::cout<<"There is no element at the specified rank to replace. Please re-search for an element to replace at the specified rank when a node is added at the specified rank.\n"<<std::endl;
            }
        }

        else
        {
            if(replaceNode->getRightChild()!=NULL)
            {
                this->setCounter(this->getCounter()+replaceNode->getNumberOfNodesLST()+1);
                this->replaceAtRank(rank, element, replaceNode->getRightChild());
            }

            else
            {
                std::cout<<"There is no element at the specified rank to replace. Please re-search for an element to replace at the specified rank when a node is added at the specified rank.\n"<<std::endl;
            }
        }
    }
}

void BinarySearchTree::removeAtRank(int rank, Node* removeNode)
{
    if(removeNode==NULL)
    {
        std::cout<<"There are currently no elements in the ranked binary search AVL tree to remove. Please insert a couple of elements in the ranked binary search AVL tree in order to be able to remove them later.\n"<<std::endl;
    }

    else
    {
        if(rank==this->getCounter()+removeNode->getNumberOfNodesLST()+1)
        {
            int removedElement=removeNode->getElement();

            if(removeNode->getLeftChild()==NULL&&removeNode->getRightChild()==NULL)
            {
                if(removeNode==this->getRoot())
                {
                    delete removeNode;
                    removeNode=NULL;
                    this->setRoot(NULL);
                }

                else
                {
                    if(removeNode->getParent()->getLeftChild()==removeNode)
                    {
                        removeNode->getParent()->setLeftChild(NULL);
                    }

                    else
                    {
                        removeNode->getParent()->setRightChild(NULL);
                    }

                    delete removeNode;
                    removeNode=NULL;
                }
            }

            else if(removeNode->getLeftChild()!=NULL&&removeNode->getRightChild()==NULL)
            {
                if(removeNode==this->getRoot())
                {
                    this->setRoot(this->getRoot()->getLeftChild());
                    delete removeNode;
                    removeNode=NULL;
                    this->getRoot()->setParent(NULL);
                }

                else
                {
                    removeNode->getLeftChild()->setParent(removeNode->getParent());

                    if(removeNode->getParent()->getLeftChild()==removeNode)
                    {
                        removeNode->getParent()->setLeftChild(removeNode->getLeftChild());
                    }

                    else
                    {
                        removeNode->getParent()->setRightChild(removeNode->getLeftChild());
                    }

                    delete removeNode;
                    removeNode=NULL;
                }
            }

            else if(removeNode->getLeftChild()==NULL&&removeNode->getRightChild()!=NULL)
            {
                if(removeNode==this->getRoot())
                {
                    this->setRoot(this->getRoot()->getRightChild());
                    delete removeNode;
                    removeNode=NULL;
                    this->getRoot()->setParent(NULL);
                }

                else
                {
                    removeNode->getRightChild()->setParent(removeNode->getParent());

                    if(removeNode->getParent()->getLeftChild()==removeNode)
                    {
                        removeNode->getParent()->setLeftChild(removeNode->getRightChild());
                    }

                    else
                    {
                        removeNode->getParent()->setRightChild(removeNode->getRightChild());
                    }

                    delete removeNode;
                    removeNode=NULL;
                }
            }

            else
            {
                Node* removeNode2=removeNode->getRightChild();

                if(removeNode2->getLeftChild()==NULL)
                {
                    removeNode->getLeftChild()->setParent(removeNode2);
                    removeNode2->setLeftChild(removeNode->getLeftChild());

                    if(removeNode==this->getRoot())
                    {
                        this->setRoot(removeNode2);
                        this->getRoot()->setParent(NULL);
                    }

                    else
                    {
                        removeNode2->setParent(removeNode->getParent());

                        if(removeNode->getParent()->getLeftChild()==removeNode)
                        {
                            removeNode->getParent()->setLeftChild(removeNode2);
                        }

                        else
                        {
                             removeNode->getParent()->setRightChild(removeNode2);
                        }
                    }
                }

                else
                {
                    Node* removeNode3=removeNode2->getLeftChild();

                    while(removeNode3->getLeftChild()!=NULL)
                    {
                        removeNode3=removeNode3->getLeftChild();
                    }

                    if(removeNode3->getRightChild()!=NULL)
                    {
                        removeNode3->getRightChild()->setParent(removeNode3->getParent());
                    }

                    removeNode3->getParent()->setLeftChild(removeNode3->getRightChild());
                    removeNode2->setParent(removeNode3);
                    removeNode3->setRightChild(removeNode2);
                    removeNode->getLeftChild()->setParent(removeNode3);
                    removeNode3->setLeftChild(removeNode->getLeftChild());

                    if(removeNode==this->getRoot())
                    {
                        this->setRoot(removeNode3);
                        this->getRoot()->setParent(NULL);
                    }

                    else
                    {
                        removeNode3->setParent(removeNode->getParent());

                        if(removeNode->getParent()->getLeftChild()==removeNode)
                        {
                            removeNode->getParent()->setLeftChild(removeNode3);
                        }

                        else
                        {
                             removeNode->getParent()->setRightChild(removeNode3);
                        }
                    }

                    removeNode3=NULL;
                }

                delete removeNode;
                removeNode=NULL;
                removeNode2=NULL;
            }

            this->setNumberOfNodes(this->getNumberOfNodes()-1);

            std::cout<<"The element "<<removedElement<<" at rank "<<rank<<" has successfully been removed from the ranked binary search AVL tree.\n"<<std::endl;
        }

        else if(rank<this->getCounter()+removeNode->getNumberOfNodesLST()+1)
        {
            if(removeNode->getLeftChild()!=NULL)
            {
                this->removeAtRank(rank, removeNode->getLeftChild());
            }

            else
            {
                std::cout<<"No element exists at the specified rank to be removed from the ranked binary search AVL tree. Please try to insert an element at that rank in order to remove it later.\n"<<std::endl;
            }
        }

        else
        {
            if(removeNode->getRightChild()!=NULL)
            {
                this->setCounter(this->getCounter()+removeNode->getNumberOfNodesLST()+1);
                this->removeAtRank(rank, removeNode->getRightChild());
            }

            else
            {
                std::cout<<"No element exists at the specified rank to be removed from the ranked binary search AVL tree. Please try to insert an element at that rank in order to remove it later.\n"<<std::endl;
            }
        }
    }
}

void BinarySearchTree::clear(Node* clearNode)
{
    if(clearNode!=NULL)
    {
        if(clearNode->getLeftChild()!=NULL)
        {
            this->clear(clearNode->getLeftChild());
        }

        if(clearNode->getRightChild()!=NULL)
        {
            this->clear(clearNode->getRightChild());
        }

        delete clearNode;
        clearNode=NULL;
    }
}

void BinarySearchTree::printByRank(Node* printNode)
{
    if(printNode==NULL)
    {
        std::cout<<"There are currently no elements in the ranked binary search AVL tree to print. Please insert an element at a specified rank in order to print its contents in the ranked binary search AVL tree."<<std::endl;
    }

    else
    {
        if(printNode->getLeftChild()!=NULL)
        {
            this->printByRank(printNode->getLeftChild());
        }

        this->setRankCounter(this->getRankCounter()+1);
        std::cout<<"Element: "<<printNode->getElement()<<" "<<"leftHeight: "<<printNode->getLeftHeight()<<" "<<"rightHeight: "<<printNode->getRightHeight()<<" "<<"numberOfNodesLST: "<<printNode->getNumberOfNodesLST()<<" "<<"rank: "<<this->getRankCounter()<<std::endl;

        if(printNode->getRightChild()!=NULL)
        {
            this->printByRank(printNode->getRightChild());
        }
    }
}

void BinarySearchTree::printByLevel()
{
    if(this->getRoot()==NULL)
    {
        std::cout<<"There are currently no nodes in the ranked binary search AVL tree to print by level. Please insert a couple of elements in order to print them level by level in the ranked binary search AVL tree.\n"<<std::endl;
    }

    else
    {
        int maxTreeHeight=std::max(this->getRoot()->getLeftHeight(), this->getRoot()->getRightHeight());
        for(int treeLevel=0; treeLevel<=maxTreeHeight; treeLevel++)
        {
            std::cout<<"Tree Level: "<<treeLevel<<" Element(s): ";
            this->printLevelOrder(treeLevel, this->getRoot());
            std::cout<<std::endl;
        }

        std::cout<<std::endl;
    }
}

void BinarySearchTree::printLevelOrder(int treeLevel, Node* levelOrderNode)
{
    if(levelOrderNode!=NULL)
    {
        if(treeLevel==0)
        {
            std::cout<<levelOrderNode->getElement()<<" ";
        }

        else
        {
            this->printLevelOrder(treeLevel-1, levelOrderNode->getLeftChild());
            this->printLevelOrder(treeLevel-1, levelOrderNode->getRightChild());
        }
    }
}

int BinarySearchTree::getSubTreeSize(Node* subTreeNode)
{
    if(subTreeNode!=NULL)
    {
        this->setNumberOfNodesST(this->getNumberOfNodesST()+1);

        if(subTreeNode->getLeftChild()!=NULL)
        {
            this->getSubTreeSize(subTreeNode->getLeftChild());
        }

        if(subTreeNode->getRightChild()!=NULL)
        {
            this->getSubTreeSize(subTreeNode->getRightChild());
        }
    }

    return this->getNumberOfNodesST();
}

void BinarySearchTree::updateNumberOfNodesLSTs(Node* LSTNode)
{
    if(LSTNode!=NULL)
    {
        if(LSTNode->getLeftChild()!=NULL)
        {
            this->updateNumberOfNodesLSTs(LSTNode->getLeftChild());
        }

        if(LSTNode->getRightChild()!=NULL)
        {
            this->updateNumberOfNodesLSTs(LSTNode->getRightChild());
        }

        if(LSTNode->getLeftChild()==NULL)
        {
            LSTNode->setNumberOfNodesLST(0);
        }

        else
        {
            this->setNumberOfNodesST(0);
            LSTNode->setNumberOfNodesLST(this->getSubTreeSize(LSTNode->getLeftChild()));
        }
    }
}

void BinarySearchTree::updateHeights(Node* heightNode)
{
    if(heightNode!=NULL)
    {
        if(heightNode->getLeftChild()!=NULL)
        {
            this->updateHeights(heightNode->getLeftChild());
        }

        if(heightNode->getRightChild()!=NULL)
        {
            this->updateHeights(heightNode->getRightChild());
        }

        if(heightNode->getLeftChild()==NULL&&heightNode->getRightChild()==NULL)
        {
            heightNode->setLeftHeight(0);
            heightNode->setRightHeight(0);
        }

        else if(heightNode->getLeftChild()!=NULL&&heightNode->getRightChild()==NULL)
        {
            heightNode->setLeftHeight(std::max(heightNode->getLeftChild()->getLeftHeight(), heightNode->getLeftChild()->getRightHeight())+1);
            heightNode->setRightHeight(0);
        }

        else if(heightNode->getLeftChild()==NULL&&heightNode->getRightChild()!=NULL)
        {
            heightNode->setLeftHeight(0);
            heightNode->setRightHeight(std::max(heightNode->getRightChild()->getLeftHeight(), heightNode->getRightChild()->getRightHeight())+1);
        }

        else
        {
            heightNode->setLeftHeight(std::max(heightNode->getLeftChild()->getLeftHeight(), heightNode->getLeftChild()->getRightHeight())+1);
            heightNode->setRightHeight(std::max(heightNode->getRightChild()->getLeftHeight(), heightNode->getRightChild()->getRightHeight())+1);
        }
    }
}

void BinarySearchTree::AVL(Node* AVLNode)
{
    if(AVLNode!=NULL)
    {
        if(AVLNode->getLeftChild()!=NULL)
        {
            this->AVL(AVLNode->getLeftChild());
        }

        if(AVLNode->getRightChild()!=NULL)
        {
            this->AVL(AVLNode->getRightChild());
        }

        if(AVLNode->getLeftHeight()-AVLNode->getRightHeight()>1)
        {
            if(AVLNode->getLeftChild()->getLeftHeight()>=AVLNode->getLeftChild()->getRightHeight())
            {
                if(AVLNode==this->getRoot())
                {
                    Node* AVLNode2=AVLNode->getLeftChild();
                    AVLNode->setLeftChild(AVLNode2->getRightChild());
                    AVLNode2->setRightChild(AVLNode);
                    AVLNode->setParent(AVLNode2);

                    if(AVLNode->getLeftChild()!=NULL)
                    {
                        AVLNode->getLeftChild()->setParent(AVLNode);
                    }

                    AVLNode2->setParent(NULL);
                    this->setRoot(AVLNode2);

                    AVLNode2=NULL;
                }

                else
                {
                    Node* AVLNode2=AVLNode->getParent();
                    Node* AVLNode3=AVLNode->getLeftChild();
                    AVLNode->setLeftChild(AVLNode3->getRightChild());
                    AVLNode3->setRightChild(AVLNode);
                    AVLNode->setParent(AVLNode3);

                    if(AVLNode->getLeftChild()!=NULL)
                    {
                        AVLNode->getLeftChild()->setParent(AVLNode);
                    }

                    AVLNode3->setParent(AVLNode2);

                    if(AVLNode2->getLeftChild()==AVLNode)
                    {
                        AVLNode2->setLeftChild(AVLNode3);
                    }

                    else
                    {
                        AVLNode2->setRightChild(AVLNode3);
                    }

                    AVLNode2=NULL;
                    AVLNode3=NULL;
                }
            }

            else
            {
                if(AVLNode==this->getRoot())
                {
                    Node* AVLNode2=AVLNode->getLeftChild();
                    Node* AVLNode3=AVLNode2->getRightChild();
                    AVLNode->setLeftChild(AVLNode3->getRightChild());
                    AVLNode3->setRightChild(AVLNode);
                    AVLNode2->setRightChild(AVLNode3->getLeftChild());
                    AVLNode3->setLeftChild(AVLNode2);
                    AVLNode->setParent(AVLNode3);
                    AVLNode2->setParent(AVLNode3);

                    if(AVLNode->getLeftChild()!=NULL)
                    {
                        AVLNode->getLeftChild()->setParent(AVLNode);
                    }

                    if(AVLNode2->getRightChild()!=NULL)
                    {
                        AVLNode2->getRightChild()->setParent(AVLNode2);
                    }

                    AVLNode3->setParent(NULL);
                    this->setRoot(AVLNode3);

                    AVLNode2=NULL;
                    AVLNode3=NULL;
                }

                else
                {
                    Node* AVLNode2=AVLNode->getParent();
                    Node* AVLNode3=AVLNode->getLeftChild();
                    Node* AVLNode4=AVLNode3->getRightChild();
                    AVLNode->setLeftChild(AVLNode4->getRightChild());
                    AVLNode4->setRightChild(AVLNode);
                    AVLNode3->setRightChild(AVLNode4->getLeftChild());
                    AVLNode4->setLeftChild(AVLNode3);
                    AVLNode->setParent(AVLNode4);
                    AVLNode3->setParent(AVLNode4);

                    if(AVLNode->getLeftChild()!=NULL)
                    {
                        AVLNode->getLeftChild()->setParent(AVLNode);
                    }

                    if(AVLNode3->getRightChild()!=NULL)
                    {
                        AVLNode3->getRightChild()->setParent(AVLNode3);
                    }

                    AVLNode4->setParent(AVLNode2);

                    if(AVLNode2->getLeftChild()==AVLNode)
                    {
                        AVLNode2->setLeftChild(AVLNode4);
                    }

                    else
                    {
                        AVLNode2->setRightChild(AVLNode4);
                    }

                    AVLNode2=NULL;
                    AVLNode3=NULL;
                    AVLNode4=NULL;
                }
            }
        }

        else if(AVLNode->getLeftHeight()-AVLNode->getRightHeight()<-1)
        {
            if(AVLNode->getRightChild()->getLeftHeight()<=AVLNode->getRightChild()->getRightHeight())
            {
                if(AVLNode==this->getRoot())
                {
                    Node* AVLNode2=AVLNode->getRightChild();
                    AVLNode->setRightChild(AVLNode2->getLeftChild());
                    AVLNode2->setLeftChild(AVLNode);
                    AVLNode->setParent(AVLNode2);

                    if(AVLNode->getRightChild()!=NULL)
                    {
                        AVLNode->getRightChild()->setParent(AVLNode);
                    }

                    AVLNode2->setParent(NULL);
                    this->setRoot(AVLNode2);

                    AVLNode2=NULL;
                }

                else
                {
                    Node* AVLNode2=AVLNode->getParent();
                    Node* AVLNode3=AVLNode->getRightChild();
                    AVLNode->setRightChild(AVLNode3->getLeftChild());
                    AVLNode3->setLeftChild(AVLNode);
                    AVLNode->setParent(AVLNode3);

                    if(AVLNode->getRightChild()!=NULL)
                    {
                        AVLNode->getRightChild()->setParent(AVLNode);
                    }

                    AVLNode3->setParent(AVLNode2);

                    if(AVLNode2->getLeftChild()==AVLNode)
                    {
                        AVLNode2->setLeftChild(AVLNode3);
                    }

                    else
                    {
                        AVLNode2->setRightChild(AVLNode3);
                    }

                    AVLNode2=NULL;
                    AVLNode3=NULL;
                }
            }

            else
            {
                if(AVLNode==this->getRoot())
                {
                    Node* AVLNode2=AVLNode->getRightChild();
                    Node* AVLNode3=AVLNode2->getLeftChild();
                    AVLNode->setRightChild(AVLNode3->getLeftChild());
                    AVLNode3->setLeftChild(AVLNode);
                    AVLNode2->setLeftChild(AVLNode3->getRightChild());
                    AVLNode3->setRightChild(AVLNode2);
                    AVLNode->setParent(AVLNode3);
                    AVLNode2->setParent(AVLNode3);

                    if(AVLNode->getRightChild()!=NULL)
                    {
                        AVLNode->getRightChild()->setParent(AVLNode);
                    }

                    if(AVLNode2->getLeftChild()!=NULL)
                    {
                        AVLNode2->getLeftChild()->setParent(AVLNode2);
                    }

                    AVLNode3->setParent(NULL);
                    this->setRoot(AVLNode3);

                    AVLNode2=NULL;
                    AVLNode3=NULL;
                }

                else
                {
                    Node* AVLNode2=AVLNode->getParent();
                    Node* AVLNode3=AVLNode->getRightChild();
                    Node* AVLNode4=AVLNode3->getLeftChild();
                    AVLNode->setRightChild(AVLNode4->getLeftChild());
                    AVLNode4->setLeftChild(AVLNode);
                    AVLNode3->setLeftChild(AVLNode4->getRightChild());
                    AVLNode4->setRightChild(AVLNode3);
                    AVLNode->setParent(AVLNode4);
                    AVLNode3->setParent(AVLNode4);

                    if(AVLNode->getRightChild()!=NULL)
                    {
                        AVLNode->getRightChild()->setParent(AVLNode);
                    }

                    if(AVLNode3->getLeftChild()!=NULL)
                    {
                        AVLNode3->getLeftChild()->setParent(AVLNode3);
                    }

                    AVLNode4->setParent(AVLNode2);

                    if(AVLNode2->getLeftChild()==AVLNode)
                    {
                        AVLNode2->setLeftChild(AVLNode4);
                    }

                    else
                    {
                        AVLNode2->setRightChild(AVLNode4);
                    }

                    AVLNode2=NULL;
                    AVLNode3=NULL;
                    AVLNode4=NULL;
                }
            }
        }

        this->updateHeights(this->getRoot());
    }
}
