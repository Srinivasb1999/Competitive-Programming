#include <bits/stdc++.h>
using namespace std;

struct BstNode{
    int data;
    BstNode* left;
    BstNode* right;
};

// Creates a new node
BstNode* GetNewNode(int data){
    BstNode* newNode = new BstNode();
    newNode -> data = data;
    newNode -> left = nullptr;
    newNode -> right = nullptr;
    return newNode;
}

// Inserts a node into the BST
BstNode* Insert(BstNode* root, int data){
    if(root == nullptr){
        root = GetNewNode(data);
    }
    else if(data <= root -> data){
        root -> left = Insert(root -> left, data);
    }
    else root -> right = Insert(root -> right, data);
    return root;
}

// Finds an element in the BST and returns a boolean value
bool Search(BstNode* root, int data){
    if(root == nullptr) return false;
    else if(root -> data == data) return true;
    else if(data <= root -> data) return Search(root -> left, data);
    else return Search(root -> right, data);
}

// Finds the minimum element and returns pointer to node
BstNode* FindMin(BstNode* root){
    if(root == nullptr) return root;
    while(root -> left != nullptr){
        root = root -> left;
    } return root;
}

// Finds the maximum element and returns pointer to node
BstNode* FindMax(BstNode* root){
    if(root == nullptr) return root;
    while(root -> right != nullptr){
        root = root -> right;
    } return root;
}

// Find the height of a BST
int Height(BstNode* root){
    if(root == nullptr){
        return -1;
    }
    int leftHeight = Height(root -> left);
    int rightHeight = Height(root -> right);
    return (max(leftHeight , rightHeight) + 1);
}

// Depth First Traversal of BST - Level Order using Queue
void LevelOrder(BstNode* root){
    if(root == nullptr) return;
    queue <BstNode*> Q;
    Q.push(root);
    while(!Q.empty()){
        BstNode* current = Q.front();
        Q.pop();
        cout<<current -> data<<" ";
        if(current -> left != nullptr) Q.push(current -> left);
        if(current -> right != nullptr) Q.push(current -> right);
    }
}

// Preorder Traversal using Recursion - DLR
void PreOrder(BstNode* root){
    if(root == nullptr) return;
    cout<< root -> data<<" ";
    PreOrder(root -> left);
    PreOrder(root -> right);
}

// Inorder Traversal using Recursion - LDR
void InOrder(BstNode* root){
    if(root == nullptr) return;
    InOrder(root -> left);
    cout<<root -> data <<" ";
    InOrder(root -> right);
}
 
//  Postorder Traversal using Recursion - LRD
void PostOrder(BstNode* root){
    if(root == nullptr) return;
    PostOrder(root -> left);
    PostOrder(root -> right);
    cout<<root -> data<<" ";
}

// Validate BST Helper Function
bool ValidateBstHelper(BstNode* root, int min, int max){
    if(root == nullptr) return true;
    if(root-> data < min or root -> data >= max) return false;
    bool leftIsValid = ValidateBstHelper(root->left, min, root -> data);
    bool rightIsValid = ValidateBstHelper(root -> right, root-> data, max);
    return leftIsValid and rightIsValid;
}

// Validate BST
bool ValidateBst(BstNode* root){
    return ValidateBstHelper(root, INT_MIN, INT_MAX);
}

// Delete a node
BstNode* deleteNode(BstNode* root, int data){
    if(root == nullptr) return root;
    else if(data > root -> data) root -> right = deleteNode(root->right, data);
    else if(data < root -> data) root -> left = deleteNode(root->left, data);
    else{
        // 0 children
        if(root -> left == nullptr and root -> right == nullptr){
            delete root;
            root = nullptr;
        }
        // Only Right Child
        else if(root -> left == nullptr){
            BstNode* temp = root;
            root = root -> right;
            delete temp;
        }
        // Only Left Child
        else if(root -> right == nullptr){
            BstNode* temp = root;
            root = root -> left;
            delete temp;
        }
        // Both Children
        else{
            BstNode* temp = FindMin(root-> right);
            root -> data = temp -> data;
            root -> right = deleteNode(root -> right, temp -> data);
        }
    }
    return root;
}

int main(){
    BstNode* root = nullptr;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 5);
    root = Insert(root, 17);
    root = Insert(root, 12);
    root = Insert(root, 23);

    int number;
    cout << "Enter number to be searched : ";
    cin >> number;
    if(Search(root, number)) cout << "Element Found\n";
    else cout << "Not found\n";
    cout << "Smallest Number in the Tree : " << FindMin(root) -> data;
    cout << "\nSmallest Number in the Tree : " << FindMax(root) -> data;
    cout << "\nHeight of the Tree : "<< Height(root);

    cout<<"\nLevel Order Traversal : ";
    LevelOrder(root);
    cout<<"\nPreorder Traversal : ";
    PreOrder(root);
    cout<<"\nInorder Traversal : ";
    InOrder(root);
    cout<<"\nPostorder Traversal : ";
    PostOrder(root);
    if(ValidateBst(root)) cout <<"\nThis BT is a BST";
    else cout<<"\nNot a BST";

    cout<<"\nBST before deleting 15 : ";
    LevelOrder(root);
    root = deleteNode(root, 15);
    cout<<"\nBST after deleting 15 : ";
    LevelOrder(root);
    return 0;
}