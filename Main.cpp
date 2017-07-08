#include<fstream>
#include<sstream>
#include"BinarySearchTree.h"

int main(int argc, char* argv[])
{
    std::cout<<"Welcome to the ranked binary search AVL tree (recursive) manipulator.\n"<<std::endl;
    std::cout<<"Now an empty ranked binary search AVL tree will be created for you to manipulate.\n"<<std::endl;
    BinarySearchTree* BST=new BinarySearchTree();

    std::cout<<"Now a menu will be created showing the possible operations that can be done on the ranked binary search AVL tree.\n"<<std::endl;
    std::cout<<"1. Insert a ranked element into the ranked binary search AVL tree."<<std::endl;
    std::cout<<"2. Search for a ranked element in the ranked binary search AVL tree by its rank."<<std::endl;
    std::cout<<"3. Replace a ranked element in the ranked binary search AVL tree by another element."<<std::endl;
    std::cout<<"4. Display all the ranked elements in the ranked binary search AVL tree in order by rank."<<std::endl;
    std::cout<<"5. Remove a ranked element from the ranked binary search AVL tree."<<std::endl;
    std::cout<<"6. Clear the ranked binary search AVL tree for the insertion of a new set of elements."<<std::endl;
    std::cout<<"7. Display all the ranked elements in the ranked binary search AVL tree by level order."<<std::endl;
    std::cout<<"8. Display the current number of nodes in the ranked binary search AVL tree."<<std::endl;
    std::cout<<"9. If running the program on command line and the program has any arguments, use the arguments to perform a set of operations on the ranked binary search AVL tree program."<<std::endl;
    std::cout<<"10. Quit the ranked binary search AVL tree manipulator.\n"<<std::endl;

    std::cout<<"Now you will choose which operation you want to do on the ranked binary search AVL tree by entering the number associated with its description.\n"<<std::endl;
    std::string menuChoice=std::string();
    std::getline(std::cin, menuChoice);
    std::cout<<std::endl;
    std::stringstream menuChoiceSS(menuChoice);
    int menuChoice2=0;
    menuChoiceSS>>menuChoice2;
    while(menuChoice2!=10)
    {
        switch(menuChoice2)
        {
            case 1:
            {
                std::cout<<"You will now enter the rank followed by a space the element that you want to insert at the entered rank into the ranked binary search AVL tree.\n"<<std::endl;
                std::string insertRankChoice=std::string();
                std::getline(std::cin, insertRankChoice);
                std::cout<<std::endl;
                std::stringstream insertRankSS(insertRankChoice);
                int rank=0;
                int element=0;
                insertRankSS>>rank>>element;
                BST->insertAtRank(rank, element, BST->getRoot());
                BST->updateHeights(BST->getRoot());
                BST->AVL(BST->getRoot());
                BST->updateNumberOfNodesLSTs(BST->getRoot());
                BST->setCounter(0);
                break;
            }

            case 2:
            {
                std::cout<<"You will now enter the rank of the element you want to search for in the ranked binary search AVL tree.\n"<<std::endl;
                std::string elementRankChoice=std::string();
                std::getline(std::cin, elementRankChoice);
                std::cout<<std::endl;
                std::stringstream elementRankSS(elementRankChoice);
                int rank=0;
                elementRankSS>>rank;
                BST->elementAtRank(rank, BST->getRoot());
                BST->setCounter(0);
                break;
            }

            case 3:
            {
                std::cout<<"You will now enter the rank followed by a space the element that you want to replace the current element with at the entered rank in the ranked binary search AVL tree.\n"<<std::endl;
                std::string replaceRankChoice=std::string();
                std::getline(std::cin, replaceRankChoice);
                std::cout<<std::endl;
                std::stringstream replaceRankSS(replaceRankChoice);
                int rank=0;
                int element=0;
                replaceRankSS>>rank>>element;
                BST->replaceAtRank(rank, element, BST->getRoot());
                BST->setCounter(0);
                break;
            }

            case 4:
            {
                if(BST->getRoot()!=NULL)
                {
                    std::cout<<"Now all the elements in the ranked binary search AVL tree will be printed in rank order.\n"<<std::endl;
                }

                BST->printByRank(BST->getRoot());
                BST->setRankCounter(0);
                std::cout<<std::endl;
                break;
            }

            case 5:
            {
                std::cout<<"You will now enter the rank of the element that you want to remove from the ranked binary search AVL tree.\n"<<std::endl;
                std::string removeRankChoice=std::string();
                std::getline(std::cin, removeRankChoice);
                std::cout<<std::endl;
                std::stringstream removeRankSS(removeRankChoice);
                int rank=0;
                removeRankSS>>rank;
                BST->removeAtRank(rank, BST->getRoot());
                BST->updateHeights(BST->getRoot());
                BST->AVL(BST->getRoot());
                BST->updateNumberOfNodesLSTs(BST->getRoot());
                BST->setCounter(0);
                break;
            }

            case 6:
            {
                std::cout<<"Now the ranked binary search AVL tree will be cleared for the insertion of a new set of elements.\n"<<std::endl;
                delete BST;
                BST=NULL;
                BST=new BinarySearchTree();
                break;
            }

            case 7:
            {
                if(BST->getRoot()!=NULL)
                {
                    std::cout<<"Now all the elements in the ranked binary search AVL tree will be printed in level order.\n"<<std::endl;
                }

                BST->printByLevel();
                break;
            }

            case 8:
            {
                std::cout<<"There is/are "<<BST->getNumberOfNodes()<<" node(s) currently in the ranked binary search AVL tree.\n"<<std::endl;
                break;
            }

            case 9:
            {
                if(argc>=2)
                {
                   std::cout<<"Now all the arguments to the program shall be processed so their specified set(s) of operations can be performed on the ranked binary search AVL tree.\n"<<std::endl;

                    for(int argCount=1; argCount<argc; argCount++)
                    {
                        std::fstream BSTfileStream(argv[argCount]);

                        if(BSTfileStream.is_open())
                        {
                            std::string BSTfileStreamInfo=std::string();

                            while(std::getline(BSTfileStream, BSTfileStreamInfo))
                            {
                                std::string BSTfileOperation=std::string();
                                std::stringstream BSTfileStreamInfoSS(BSTfileStreamInfo);
                                BSTfileStreamInfoSS>>BSTfileOperation;

                                if(BSTfileOperation=="insert:")
                                {
                                    int rank=0;
                                    int element=0;
                                    while(BSTfileStreamInfoSS>>rank>>element)
                                    {
                                        BST->insertAtRank(rank, element, BST->getRoot());
                                        BST->updateHeights(BST->getRoot());
                                        BST->AVL(BST->getRoot());
                                        BST->updateNumberOfNodesLSTs(BST->getRoot());
                                        BST->setCounter(0);
                                    }
                                }

                                else if(BSTfileOperation=="search:")
                                {
                                    int rank=0;
                                    while(BSTfileStreamInfoSS>>rank)
                                    {
                                        BST->elementAtRank(rank, BST->getRoot());
                                        BST->setCounter(0);
                                    }
                                }

                                else if(BSTfileOperation=="replace:")
                                {
                                    int rank=0;
                                    int element=0;
                                    while(BSTfileStreamInfoSS>>rank>>element)
                                    {
                                        BST->replaceAtRank(rank, element, BST->getRoot());
                                        BST->setCounter(0);
                                    }
                                }

                                else if(BSTfileOperation=="remove:")
                                {
                                    int rank=0;
                                    while(BSTfileStreamInfoSS>>rank)
                                    {
                                        BST->removeAtRank(rank, BST->getRoot());
                                        BST->updateHeights(BST->getRoot());
                                        BST->AVL(BST->getRoot());
                                        BST->updateNumberOfNodesLSTs(BST->getRoot());
                                        BST->setCounter(0);
                                    }
                                }

                                else if(BSTfileOperation=="clear:")
                                {
                                    std::cout<<"Now the ranked binary search AVL tree will be cleared for the insertion of a new set of elements.\n"<<std::endl;
                                    delete BST;
                                    BST=NULL;
                                    BST=new BinarySearchTree();
                                }

                                else if(BSTfileOperation=="print-rank:")
                                {
                                    if(BST->getRoot()!=NULL)
                                    {
                                        std::cout<<"Now all the elements in the ranked binary search AVL tree will be printed in rank order.\n"<<std::endl;
                                    }

                                    BST->printByRank(BST->getRoot());
                                    BST->setRankCounter(0);
                                    std::cout<<std::endl;
                                }

                                else if(BSTfileOperation=="print-level:")
                                {
                                    if(BST->getRoot()!=NULL)
                                    {
                                        std::cout<<"Now all the elements in the ranked binary search AVL tree will be printed in level order.\n"<<std::endl;
                                    }

                                    BST->printByLevel();
                                }

                                else if(BSTfileOperation=="tree-size:")
                                {
                                    std::cout<<"There is/are "<<BST->getNumberOfNodes()<<" node(s) currently in the ranked binary search AVL tree.\n"<<std::endl;
                                }

                                else
                                {
                                    std::cout<<"The operation "<<BSTfileOperation<<" is not a recognizable operation that can be done on the ranked binary search AVL tree.\n"<<std::endl;
                                }
                            }
                        }

                        else
                        {
                            std::cout<<"There was an error opening the file "<<argv[argCount]<<". Please try to re-format or re-pass the file as an argument to the program to see if it can open then.\n"<<std::endl;
                        }
                    }
                }

                else
                {
                    std::cout<<"You have not provided any arguments to the program to perform a set/sets of operations on it. Please run the program via command line in order to pass arguments to the program that can specify which set(s) of operations to be done on the ranked binary search AVL tree.\n"<<std::endl;
                }

                break;
            }

            default:
            {
               break;
            }
        }

        std::cout<<"Now a menu will be re-created showing the possible operations that can be done on the ranked binary search AVL tree for reminding purposes.\n"<<std::endl;
        std::cout<<"1. Insert a ranked element into the ranked binary search AVL tree."<<std::endl;
        std::cout<<"2. Search for a ranked element in the ranked binary search AVL tree by its rank."<<std::endl;
        std::cout<<"3. Replace a ranked element in the ranked binary search AVL tree by another element."<<std::endl;
        std::cout<<"4. Display all the ranked elements in the ranked binary search AVL tree in order by rank."<<std::endl;
        std::cout<<"5. Remove a ranked element from the ranked binary search AVL tree."<<std::endl;
        std::cout<<"6. Clear the ranked binary search AVL tree for the insertion of a new set of elements."<<std::endl;
        std::cout<<"7. Display all the ranked elements in the ranked binary search AVL tree by level order."<<std::endl;
        std::cout<<"8. Display the current number of nodes in the ranked binary search AVL tree."<<std::endl;
        std::cout<<"9. If running the program on command line and the program has an arguments, use the arguments to perform a set of operations on the ranked binary search AVL tree program."<<std::endl;
        std::cout<<"10. Quit the ranked binary search AVL tree manipulator.\n"<<std::endl;

        std::cout<<"Please enter your next choice of operation on the ranked binary search AVL tree by entering the number associated with its description.\n"<<std::endl;
        std::getline(std::cin, menuChoice);
        std::cout<<std::endl;
        menuChoiceSS.str(std::string());
        menuChoiceSS.clear();
        menuChoiceSS<<menuChoice;
        menuChoiceSS>>menuChoice2;
    }

    delete BST;
    BST=NULL;

    return 0;
}

//**COMPLETED**//
