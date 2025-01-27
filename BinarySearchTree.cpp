#include<iostream>
#define SPACE 10
using namespace std;

class TreeNode{
    public:
        int value;  //key or data
        TreeNode* left;
        TreeNode *right;

        TreeNode()
        {
            value = 0;
            left = NULL;
            right = NULL;
        }
        TreeNode(int v)
        {
            value = v;
            left = NULL;
            right = NULL;
        }

};

class BST{
    public:
        TreeNode* root;
        BST()
        {
            root = NULL;
        }

        bool isEmpty()
        {
            if(root==NULL)
                return true;
            
            else
                return false;
        }

        void insertNode(TreeNode *new_node)
        {
            if(root==NULL)
            {
                root=new_node;
                cout<<"Value Inserted as root node!"<<endl;
            }
            else
            {
                TreeNode *temp=root;
                while (temp!=NULL)
                {
                    if(new_node->value==temp->value)
                    {
                        cout<<"Value already exist, Insert another value!"<<endl;
                        return;
                    }
                    else if((new_node->value<temp->value) && (temp->left==NULL))
                    {
                        temp->left = new_node;
                        cout<<"Value Inserted to the left!"<<endl;
                        break;
                    }
                    else if(new_node->value<temp->value)
                    {
                        temp = temp->left;
                    }
                    else if((new_node->value>temp->value) && (temp->right==NULL))
                    {
                        temp->right = new_node;
                        cout<<"Value Inserted to the right!"<<endl;
                        break;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
                
            }
        }

        void print2D(TreeNode *r,int space)
        {
        if (r == NULL) // Base case
            return;
        space += SPACE; //Increase distance between Levels
        print2D(r->right, space); //Process right child first
        cout<<endl;
        for(int i=SPACE; i<space; i++) //Print current node after space count
            cout<<" ";
        cout<<r->value<<"\n";
        print2D(r->left, space); //Process Left Child
        }

        void printPreorder(TreeNode* r) //(Current Node, Left, Right)
        {
            if(r == NULL)
                return;
            // first print data of node
            cout << r->value << " ";
            // then recur on right subtree
            printPreorder(r->left);
            // now recur on right subtree
            printPreorder(r->right);
        }

        void printInorder(TreeNode* r) // (Left, Current Node, Right)
        {
            if(r == NULL)
                return;
            // first recur on left child
            printInorder(r->left);
            //then print the data of node
            cout << r->value << " ";
            //now recur on right child
            printInorder(r->right);
        }

        void printPostorder(TreeNode* r) // (Left, Right, Current Node)
        {
            if(r == NULL)
                return;
            // first recur on left subtree
            printPostorder(r->left);
            //then recur on right subtree
            printPostorder(r->right);
            //now deal with the node
            cout << r->value << " ";
        }

        TreeNode* iterativeSearch(int v)
        {
            if(root==NULL)
            {
                return root;
            }
            else
            {
                TreeNode *temp=root;
                while(temp!=NULL)
                {
                    if(v==temp->value)
                    {
                        return temp;
                    }
                    else if(v<temp->value)
                    {
                        temp = temp->left;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
                return  NULL;
            }
        }
        
        TreeNode* recursiveSearch(TreeNode* r, int val)
        {
            if(r == NULL || r->value == val)
                return r;
            
            else if (val < r->value)
                return recursiveSearch(r->left, val);

            else
                return recursiveSearch(r->right, val);
        }

        int height(TreeNode* r)
        {
            if (r==NULL)
                return -1;
            else
            {
                // Compute the height if each subtree
                int lheight = height(r->left);
                int rheight = height(r->right);

                //use the larger one
                if (lheight > rheight)
                    return(lheight + 1);
                else return(rheight + 1);
            }
        }

        // Print nodes at a given level
        void printGivenLevel(TreeNode* r, int level)
        {
            if (r == NULL)
                return;
            else if (level == 0)
                cout << r->value << " ";
            else // level > 0
            {
                printGivenLevel(r->left, level-1);
                printGivenLevel(r->right, level-1);
            }
        }
        void printLevelOrderBFS(TreeNode* r)
        {
            int h = height(r);
            for (int i=0; i<=h; i++)
                printGivenLevel(r, i);            
                    
        }

        TreeNode* minValueNode(TreeNode* node)
        {
            TreeNode* current = node;
            // Loop down to find the leftmost leaf
            while (current->left != NULL)
            {
                current = current->left;
            }
            return current;
        }

        TreeNode* deleteNode(TreeNode* r, int v)
        {
            // base case
            if(r == NULL)
            {
                return NULL;
            }
            // if the key to be deleted is smaller than the root's key,
            // then it lies in left subtree
            else if ( v < r->value)
            {
                r->left = deleteNode(r->left, v);
            }
            // if the key to be deleted is greater than the root's key,
            // then it lies in right subtree
            else if (v > r->value)
            {
                r->right = deleteNode(r->right, v);
            }
            // if key is same as root's key, the this is the node to be deleted
            else
            {
                // node with only one child or no child
                if (r->left == NULL)
                {
                    TreeNode* temp = r->right;
                    delete r;
                    return temp;
                }
                else if(r->right == NULL)
                {
                    TreeNode* temp = r->left;
                    delete r;
                    return temp;
                }
                else
                {
                    // node with two children: Get the inorder successor (smallest
                    // in the right subtree)
                    TreeNode* temp = minValueNode(r->right);
                    // copy the inorder sucessor's content to this node
                    r->value = temp->value;
                    // Delete the inorder sucessor
                    r->right = deleteNode(r->right, temp->value);
                    // deleteNode(r->right, temp->value);
                }
                }
                return r;
            }

};

int main()
{   
    BST obj;
    int option,val;
    
    do
    {
       cout << "What operation do you want to perform?" <<endl;
       cout<< "Select Option number. Enter 0 to exit." <<endl; 
       cout<<"1. Insert Node" <<endl;
       cout<<"2. Search Node" <<endl;
       cout<<"3. Delete Node" <<endl;
       cout<<"4. Print BST Values" <<endl;
       cout<<"5. Height of Tree" <<endl;
       cout<<"6. Clear Screen" <<endl;
       cout<<"0. Exit Program" <<endl;

       cin>>option;
       //Node n1 = new Node();
       TreeNode *new_node = new TreeNode();

       switch (option)
       {
       case 0:
            break;
        case 1:
            cout<<"INSERT"<<endl;
            cout<<"Enter Value of Tree Node to Insert in BST: ";
            cin >> val;
            new_node->value = val;
            obj.insertNode(new_node);
            cout<<endl;
            break;
        case 2:
            cout<<"SEARCH"<<endl;
            cout<<"ENTER VALUE OF TREE NODE TO SEARCH IN BST: ";
            cin >> val;
            // new_node = obj.iterativeSearch(val);
            new_node = obj.recursiveSearch(obj.root,val);
            if(new_node!=NULL)
            {
                cout <<"Value Found"<<endl;
            }
            else
            {
                cout <<"Value NOT Found"<<endl;
            }
            break;
        case 3:
            cout<<"DELETE"<<endl;
            cout<<"Enter VALUE OF TREE NODE TO DELETE IN BST: ";
            cin >> val;
            new_node = obj.iterativeSearch(val);
            if (new_node!=NULL)
            {
                obj.deleteNode(obj.root, val);
                cout <<"Value Deleted"<<endl;
            }
            else
            {
                cout <<"Value Deleted"<<endl;
            }
            break;
        case 4:
            cout<<"PRINT"<<endl;
            obj.print2D(obj.root,5);
            cout << endl;
            cout << "Print Level Order BFS: \n";
            obj.printLevelOrderBFS(obj.root);
            cout<<endl;
            cout<<"PREORDER :"<<endl;
            obj.printPreorder(obj.root);
            cout<<endl;
            cout<<"INORDER :"<<endl;
            obj.printInorder(obj.root);
            cout<<endl;
            cout<<"POSTORDER :"<<endl;
            obj.printPostorder(obj.root);
            cout<<endl;
            break;
        case 5:
            cout<<"TREE HEIGHT"<<endl;
            cout<<"Height : "<<obj.height(obj.root)<<endl;
            break;
        case 6:
            cout<<"CLR SCR"<<endl;
            system("cls");
            break;
       default:
            cout<<"Enter Proper Option Number" << endl;
       }

    
    } 
    while (option!=0);
    
    return 0;
}
