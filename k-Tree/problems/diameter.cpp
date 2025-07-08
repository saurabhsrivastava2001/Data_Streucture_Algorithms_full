#include <iostream>
#include <algorithm> // Needed for std::max
using namespace std;
class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
// Corrected build_tree function
node* build_tree() {
    cout << "Enter the data: ";
    int data;
    cin >> data;
    if (data == -1) {
        return NULL;
    }
    node* root = new node(data);
    cout << "Enter the data for left of " << data << endl;
    root->left = build_tree();
    cout << "Enter the data for right of " << data << endl;
    root->right = build_tree();
    return root;
}
// Function to compute the diameter of the binary tree
int max_path(node* root, int &maxi) { 
    if (root == NULL) {
        return 0;}
    int lh = max_path(root->left, maxi);
    int rh = max_path(root->right, maxi);
    // Correct max function usage
    maxi = std::max(maxi, 1 + lh + rh);  // in the code of the height we just have to update the one line that we have to cary themaxi var as the global or an parameter , and the maxi will be 1+ max(lh and rh);
    return 1 + std::max(lh, rh);
}
int main() {
    node* root = NULL;
    root = build_tree(); // Corrected function call

    int maxi = 0;
    max_path(root, maxi);

    cout << "Diameter of the tree: " << maxi - 1 << endl; // Subtract 1 to get edge count
    return 0;
}
