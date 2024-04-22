// Including necessary standard C libraries
#include <stdio.h>    // Standard Input/Output functions
#include <stdbool.h>  // Standard boolean type and values
#include <stdlib.h>   // Standard General Utilities Library

//1. Define a structure for a binary tree node
typedef struct tree_node                                                                            
{
    int value;                 // Value stored in the node
    struct tree_node *right;   // Pointer to the right child node
    struct tree_node *left;    // Pointer to the left child node
} tree_node;

// All the function's pre-definitions

//2. Insertions
tree_node *create_node(int value);//Creates new node
bool insert_value(tree_node **rootptr, int value); //Insert value into binary search tree

//3. Searching
bool find_number(tree_node *root , int value);
int find_minimum(tree_node *root);
int find_maximum(tree_node *root);

//4. Deletion
tree_node *deleteNode_succesor(tree_node *root, int value);
tree_node *deleteNode_predecessor(tree_node *root,int value);

//5. Traversal
void preorder(tree_node *root, int level);
void inorder(tree_node *root,int level);
void postorder(tree_node *root,int level);
void print_preorder(tree_node *root);
void print_inorder(tree_node *root);
void print_postorder(tree_node *root);

//6. Function to free memory allocated for the binary search tree
void freeTree(tree_node *root);

//7. Functions for structured outputs like tab space and etc
void print_space(int num_of_tabs);


//2. Function to create a new tree node
tree_node *create_node(int value) {
    // Allocate memory for a new tree node
    tree_node *result = malloc(sizeof(tree_node));

    // Check if memory allocation was successful
    if (result != NULL) {
        result->left = NULL;
        result->right = NULL;
        result->value = value;
    } else {
        // Print an error message if memory allocation fails
        fprintf(stderr, "Memory allocation failed.\n");
    }

    return result;
}

//2. Function to insert a value into the binary tree
bool insert_value(tree_node **rootptr, int value) //It's a double pointer because the function needs to modify the root pointer if the tree is empty.
{
    // Get the root of the tree
    tree_node *root = *rootptr;  
    
    // If the root is NULL, create a new node and assign it as the root
    if (root == NULL) {
        *rootptr = create_node(value);
        return true;
    }

    // If the value already exists, return false
    if (value == root->value) {
        return false; //indicating that the value is already present in the tree and thus won't be inserted again.
    }

    // If the value is greater, insert into the right subtree
    if (value > root->value) {
        return insert_value(&(root->right), value); //This continues the process of insertion into the right subtree
    }

    // If the value is smaller, insert into the left subtree
    if (value < root->value) {
        return insert_value(&(root->left), value); //This continues the process of insertion into the left subtree
    }
}


//3. Function to find a number in the Binary Search tree
bool find_number(tree_node *root, int value) {
    // If the root is NULL, the value is not found
    if (root == NULL) {
        return false;
    }
    // If the value is equal to the root's value, it's found
    else if (value == root->value) {
        return true;
    }
    // If the value is smaller, search in the left subtree
    else if (value < root->value) {
        return find_number(root->left, value);
    } 
    else if (value > root ->value) {
        // If the value is greater, search in the right subtree
        return find_number(root->right, value);
    }
}  

//3. Funtion to find the minimum value in a Binary Search Tree
int find_minimum(tree_node *root)
{
    // CHECKS RECURSIVELYIN LEFT SUBTREEE UNTIL THERE IS NO MORE SUBTREE
    if (root == NULL)
    {
        printf("<----EMPTY--->");
        return -1;
    }
    else if (root->left ==NULL)
    {
        return root->value;
    }
    return find_minimum(root->left);    
}
//3. Funtion to find the maximum element in the binary search tree
int find_maximum(tree_node *root)
{
    // CHECKS RECURSIVELYIN RIGHT SUBTREEE UNTIL THERE IS NO MORE SUBTREE
    if (root == NULL)
    {
        printf("<----EMPTY--->");
        return -1;
    }
    else if (root->right ==NULL)
    {
        return root->value;
    }
    return find_maximum(root->right);    
}

//4. Function to delete a node with the given key from the BST (IN-ORDER SUCCESOR)
tree_node *deleteNode_succesor(tree_node *root, int value)
{
    // Base case
    if (root == NULL)
        return root;

    // Recursive calls for ancestors of node to be deleted
    if (value< root->value) {
        root->left = deleteNode_succesor(root->left, value);
        return root;
    } else if (value> root->value) {
        root->right = deleteNode_succesor(root->right, value);
        return root;
    }

    // We reach here when root is the node to be deleted.

    // If both children exist
    if (root->left != NULL && root->right != NULL) {
        tree_node *succParent = root;

        // Find the in-order successor
        tree_node *succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }

        // Delete the in-order successor
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;

        // Copy the value of the in-order successor to root
        root->value = succ->value;

        // Delete the in-order successor and return root
        return root;
    }

    // If one of the children is empty
    if (root->left == NULL) {
        tree_node *temp = root->right;
        free(root);
        return temp;
    } else if (root->right == NULL) {
        tree_node *temp = root->left;
        free(root);
        return temp;
    }
}

//5.Traversal method in Binary Search Tree PRE-ORDERING (root - left - right)
void preorder(tree_node *root, int level) 
{
    // Print the value of the current node, then traverse left and right subtrees
    if (root == NULL) {
        print_space(level);
        printf("---<EMPTY>---\n");
        return;
    }
    print_space(level);
    printf("Value: %d \n", root->value);

    print_space(level);
    printf("Left subtree:\n");
    preorder(root->left, level + 1);

    print_space(level);
    printf("Right subtree:\n");
    preorder(root->right, level + 1);
}
//5. Actual function which calls the pre-ordering into main interface
void print_preorder(tree_node *root)
{   preorder(root,0);    }

//5. Traversal method in Binary Search Tree In - Ordering(left - root - right)
void inorder(tree_node *root,int level)
{
// Print the value of the left subtree, then traverse root and right subtree
    if (root == NULL)
    {
        print_space(level);
        printf("---<EMPTY>---\n");
        return;
    }
    print_space(level);
    printf("Left Subtree :\n");
    inorder(root->left,level+1);

    print_space(level);
    printf("Value: %d\n",root->value);

    print_space(level);
    printf("Right Subtree :\n");
    inorder(root->right,level+1);
}
//5. Actual function which calls the in-ordering into main interface
void print_inorder(tree_node *root)
{   inorder(root,0);    }

//5. Traversal method in Binary Search Tree Post-ordering(left - right - root)
void postorder(tree_node *root, int level)
{
// Print the value of the left subtree, then traverse right subtree and root
    if (root == NULL)
    {
        print_space(level);
        printf("---<EMPTY>---\n");
        return;
    }
    print_space(level);
    printf("Left Subtree :\n");
    postorder(root->left,level+1);

    print_space(level);
    printf("Right Subtree :\n");
    postorder(root->right,level+1);

    print_space(level);
    printf("Value: %d\n",root->value);
}
//5. Actual function which calls the post-ordering into main interface
void print_postorder(tree_node *root)
{   postorder(root,0);    }


//6. Function to free memory allocated for the binary search tree.
void freeTree(tree_node *root)
{ 
    if (root != NULL) {
        freeTree(root->left);  // Recursively free memory for the left subtree.
        freeTree(root->right); // Recursively free memory for the right subtree.
        free(root);            // Free memory for the current node.
    }
}

//7. Function to print a specified number of tabs
void print_space(int num_of_tabs) {
    // Print tabs based on the specified number
    for (int i = 0; i < num_of_tabs; i++) {
        printf("\t");
    }
}

//The Interface between BST and user
int main() {

    int choice = 1, value;
    tree_node *root = NULL;  // Initialize the root of the binary tree as NULL.

    while (choice != 0) {
        // Display menu options
        printf("\nBinary Tree Menu:\n");
        printf("1. Insert a value into the binary search tree\n");
        printf("2. Find the number in binary search tree\n");
        printf("3. Find the minimum number in binary search tree\n");
        printf("4. Find the maximum number in binary search tree\n");
        printf("5. Delete the number from binary search tree(successor)\n");
        printf("6. Traverse the binary search tree using pre-order method\n");
        printf("7. Traverse the binary search tree using in-order method\n");
        printf("8. Traverse the binary search tree using post-order method\n");
        printf("0. Exit.\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);  // Get the user's choice for the menu.
        int val;
        switch (choice) {
            case 0:
                // Exit the program
                printf("Exiting the program.\n");
                break;

            case 1:
                // Insert a value into the tree
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                if (insert_value(&root, value)) {
                    printf("Value %d inserted into the tree.\n", value);
                } else {
                    printf("Value %d already exists in the tree.\n", value);
                }
                break;
            
            case 2:
                // Check if the number exists in the tree. 
                printf("Enter the value you want to find: \n");
                scanf("%d", &value);
                if (find_number(root,value))
                {
                    printf("The given number %d exists in the tree",value);
                }
                else
                {
                    printf("The given number %d does not exist in the tree",value);
                }
                break;

            case 3:
                val = find_minimum(root);
                printf("The minimum number in a tree is %d\n",val);
                break;
            
            case 4:
                val = find_maximum(root);
                printf("The maximum number in a tree is %d\n",val);
                break;
            
            case 5:
                // to delete if the number exists in the tree 
                printf("\nEnter the value to be deleted :");
                scanf("%d", &value);
                if (deleteNode_succesor(root,value))
                {
                    printf("The given number %d is deleted from the tree",value);
                }
                else
                {
                    printf("The given number %d does not exist in the tree",value);
                }
                break;           
            
            case 6:
                // Print Preorder traversal
                printf("Preorder traversal:\n");
                print_preorder(root);  // Print the tree in preorder (root->left->right).
                break;
            
            case 7:
                // Print Inorder traversal
                printf("Inorder traversal:\n");
                print_inorder(root);  // Print the tree in inorder (left->root->right).
                break;
            
            case 8:
                // Print Postorder traversal (left->right->root)
                printf("Postorder traversal :\n");
                print_postorder(root);  // Print the tree in postorder (left->right->root).
                break;
            default:
                // Invalid choice
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    }

    // Free memory
    freeTree(root);  // Free the memory allocated for the entire tree.

    return 0;
}