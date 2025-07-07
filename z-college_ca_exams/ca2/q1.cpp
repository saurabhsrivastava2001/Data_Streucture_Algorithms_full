// "Kingdom of BST - Build to Rule"
// Problem Statement:
// As the royal architect, you're building a strength hierarchy using a BST. Insert warriors by strength. The stronger strength dominates if inserted first.
// Key Sequence:
// [60, 40, 70, 30, 50, 65, 80]

// Challenge:

// Build the BST.

// Output the Post-order traversal to show the chain of command....for odd roll numbers

#include <iostream>
using namespace std;

class Kingdom
{
public:
    int strength;
    Kingdom *left;
    Kingdom *right;

    Kingdom(int val)
    {
        strength = val;
        left = right = NULL;
    }
};

Kingdom *insert(Kingdom *root, int val)
{
    if (root == NULL)
        return new Kingdom(val);

    if (val < root->strength)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

void postOrder(Kingdom *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->strength << " ";
}

int main()
{
    Kingdom *root = NULL;
    int warriors[] = {60, 40, 70, 30, 50, 65, 80};

    for (int i = 0; i < 7; i++)
    {
        root = insert(root, warriors[i]);
    }

    cout << "Post-order Chain of Command: ";
    postOrder(root);
    cout << endl;

    return 0;
}
