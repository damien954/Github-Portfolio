#include<iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include <cstdlib>
using namespace std;

class BinarySearchTree
{
    private:
        struct tree_node
        {
           tree_node* left;
           tree_node* right;
           int data;
char description[20];
string descrip;
int onHand;
int capacity;
float price;
unsigned month;
unsigned day;
unsigned year;
unsigned monthM;
unsigned dayM;
unsigned yearM;
int stock;

        };
        tree_node* root;
    
    public:
        BinarySearchTree()
        {
           root = NULL;
        }
       
        bool isEmpty() const { return root==NULL; }
        void print_inorder();
        void inorder(tree_node*);
        void print_preorder();
        void preorder(tree_node*);
        void print_postorder();
        void postorder(tree_node*);
        void insert();
        void remove(int);
};

// Smaller elements go left
// larger elements go right
void BinarySearchTree::insert()
{
ifstream inF;
inF.open ("emp.dat");

int d;

while(inF >> d)
{
    tree_node* t = new tree_node;
    tree_node* parent;

int Item;
int OnHand;
int Capacity;
char Description[20];
string descr;
unsigned Month;
unsigned Day;
unsigned Year;
unsigned MonthM;
unsigned DayM;
unsigned YearM;
float Price;
int Stock;
    t->left = NULL;
    t->right = NULL;
    parent = NULL;
//inF >> d;
//inF >>Description; 
inF.ignore();
inF.get(Description,20);
inF>> OnHand;
inF >>Capacity;
inF >> Price;
inF >> Year;
inF >> Month;
inF >> Day;
inF >> YearM;
inF >> MonthM;
inF>> DayM;
inF >>Stock ;

descr=Description;

	t->data = d;
	t->descrip = descr;
	t->onHand= OnHand;
	t->capacity= Capacity;
	t->price= Price;
	t->year= Year;
	t->month= Month;
	t->day= Day;
	t->yearM= YearM;
	t->monthM= MonthM;
	t->dayM= DayM;
	t->stock= Stock;

    // is this a new tree?
    if(isEmpty()) root = t;
    else
    {
        //Note: ALL insertions are as leaf nodes
        tree_node* curr;
        curr = root;

        // Find the Node's parent
        while(curr)
        {
            parent = curr;
            if(t->data > curr->data) curr = curr->right;
            else curr = curr->left;
        }

        if(t->data < parent->data)
           parent->left = t;
        else
           parent->right = t;
    }
}
}

void BinarySearchTree::remove(int d)
{
    //Locate the element
    bool found = false;
    if(isEmpty())
    {
        cout<<" This Tree is empty! "<<endl;
        return;
    }
    
    tree_node* curr;
    tree_node* parent;
    curr = root;
    
    while(curr != NULL)
    {
         if(curr->data == d)
         {
            found = true;
            break;
         }
         else
         {
             parent = curr;
             if(d>curr->data) curr = curr->right;
             else curr = curr->left;
         }
    }
    if(!found)
		 {
        cout<<" Data not found! "<<endl;
        return;
    }


		 // 3 cases :
    // 1. We're removing a leaf node
    // 2. We're removing a node with a single child
    // 3. we're removing a node with 2 children

    // Node with single child
    if((curr->left == NULL && curr->right != NULL)|| (curr->left != NULL
&& curr->right == NULL))
    {
       if(curr->left == NULL && curr->right != NULL)
       {
           if(parent->left == curr)
           {
             parent->left = curr->right;
             delete curr;
           }
           else
           {
             parent->right = curr->right;
             delete curr;
           }
       }
       else // left child present, no right child
       {
          if(parent->left == curr)
           {
             parent->left = curr->left;
             delete curr;
           }
           else
           {
             parent->right = curr->left;
             delete curr;
           }
       }
     return;
    }

		 //We're looking at a leaf node
		 if( curr->left == NULL && curr->right == NULL)
    {
        if(parent->left == curr) parent->left = NULL;
        else parent->right = NULL;
		 		 delete curr;
		 		 return;
    }


    //Node with 2 children
    // replace node with smallest value in right subtree
    if (curr->left != NULL && curr->right != NULL)
    {
        tree_node* chkr;
        chkr = curr->right;
        if((chkr->left == NULL) && (chkr->right == NULL))
        {
            curr = chkr;
            delete chkr;
            curr->right = NULL;
        }
        else // right child has children
        {
            //if the node's right child has a left child
            // Move all the way down left to locate smallest element

            if((curr->right)->left != NULL)
            {
                tree_node* lcurr;
                tree_node* lcurrp;
                lcurrp = curr->right;
                lcurr = (curr->right)->left;
                while(lcurr->left != NULL)
                {
                   lcurrp = lcurr;
                   lcurr = lcurr->left;
                }
		curr->data = lcurr->data;
                delete lcurr;
                lcurrp->left = NULL;
           }
           else
           {
               tree_node* tmp;
               tmp = curr->right;
               curr->data = tmp->data;
	       curr->right = tmp->right;
               delete tmp;
           }

        }
		 return;
    }

}

void BinarySearchTree::print_inorder()
{
  inorder(root);
}

void BinarySearchTree::inorder(tree_node* p)
{
    if(p != NULL)
    {

        if(p->left) inorder(p->left);
  cout<<setw(3)<<setfill('0')<<p->data<<"    ";cout<<setfill(' ');
        cout<<setw(20)<<p->descrip<<" ";cout << "      ";
    cout<<setw(3)<<setfill('0')<<p->onHand<<" ";cout << "     ";
    cout<<setw(3)<<setprecision(2)<<fixed<<p->price<<" ";cout << "   ";
    cout<<setw(4)<<p->month<<"/"<<setw(2)<<p->day<<"/"<<setw(2)<< p->year<<" ";
    cout<<setw(4)<<p->monthM<<"/"<<setw(2)<<p->dayM<<"/"<<setw(2)<< p->yearM<<"  ";
    cout << "  ";  
        cout<<setw(3)<<p->stock;
    cout<<endl;cout<<setfill(' ');
        if(p->right) inorder(p->right);
    }
    else return;
}

void BinarySearchTree::print_preorder()
{
    preorder(root);
}

void BinarySearchTree::preorder(tree_node* p)
{
    if(p != NULL)
    {
        cout<<" "<<p->data<<" ";
        cout<<" "<<p->description<<" ";

        cout<<" "<<p->onHand<<" ";
        cout<<" "<<p->price<<" ";
        cout<<" "<<p->month<<" ";
        cout<<" "<<p->day<<" ";
        cout<<" "<<p->year<<" ";
        cout<<" "<<p->monthM<<" ";
        cout<<" "<<p->dayM<<" ";
        cout<<" "<<p->yearM<<" ";
        cout<<" "<<p->stock<<" ";

        if(p->left) preorder(p->left);
        if(p->right) preorder(p->right);
    }
    else return;
}

void BinarySearchTree::print_postorder()
{
    postorder(root);
}

void BinarySearchTree::postorder(tree_node* p)
{
    if(p != NULL)
    {
        if(p->left) postorder(p->left);
        if(p->right) postorder(p->right);
        cout<<" "<<p->data<<" ";
        cout<<" "<<p->description<<" ";

        cout<<" "<<p->onHand<<" ";
        cout<<" "<<p->price<<" ";
        cout<<" "<<p->month<<" ";
        cout<<" "<<p->day<<" ";
        cout<<" "<<p->year<<" ";
        cout<<" "<<p->monthM<<" ";
        cout<<" "<<p->dayM<<" ";
        cout<<" "<<p->yearM<<" ";
        cout<<" "<<p->stock<<" ";

    }
    else return;
}

int main()
{
    BinarySearchTree b;
    int ch,tmp,tmp1;

    while(1)
    {
       cout<<endl<<endl;
       cout<<" Binary Search Tree Operations "<<endl;
       cout<<" ----------------------------- "<<endl;
       cout<<" 1. Insertion/Creation "<<endl;
       cout<<" 2. In-Order Traversal "<<endl;
       cout<<" 3. Pre-Order Traversal "<<endl;
       cout<<" 4. Post-Order Traversal "<<endl;
       cout<<" 5. Removal "<<endl;
       cout<<" 6. Exit "<<endl;
       cout<<" Enter your choice : ";
       cin>>ch;
       switch(ch)
       {
           case 1 : cout<<" Enter Number to be inserted : ";
                    b.insert();
                    break;
           case 2 : cout<<endl;
                    cout<<" In-Order Traversal "<<endl;
                    cout<<" -------------------"<<endl;
                    b.print_inorder();
                    break;
           case 3 : cout<<endl;
                    cout<<" Pre-Order Traversal "<<endl;
                    cout<<" -------------------"<<endl;
                    b.print_preorder();
                    break;
           case 4 : cout<<endl;
                    cout<<" Post-Order Traversal "<<endl;
                    cout<<" --------------------"<<endl;
                    b.print_postorder();
                    break;
           case 5 : cout<<" Enter data to be deleted : ";
                    cin>>tmp1;
                    b.remove(tmp1);
                    break;
           case 6 : 
                    return 0;
                    
       }
    }
}
