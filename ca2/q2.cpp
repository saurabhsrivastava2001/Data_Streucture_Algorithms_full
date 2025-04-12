// "Mind Maze - BST Edition"
// Problem Statement:
// Each move in the BST costs or earns points: left = -1, right = +1. Your score depends on the search path.

// Insertion Keys:
// [45, 30, 60, 20, 35, 50, 70]
// Search Keys:
// [35, 50, 70]

// Challenge:

// Build the BST.
// For each search, calculate the score based on left/right moves.....For even roll numbers

#include <iostream>

using namespace std;

class mind_maze{
public:
    int score;
    mind_maze *left;
    mind_maze *right;

    mind_maze(int val)
    {
        score = val;
        left = right = NULL;
    }
};

mind_maze * insert(mind_maze *root, int val)
{
    if (root == NULL)
        return new mind_maze(val);

    if (val < root->score)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}
mind_maze * search(mind_maze * root, int val, int &score)
{
    if (root == NULL)
        return NULL;

    if (val < root->score)
    {
        score -= 1; // left move
        cout << "Left move: " << root->score<< endl;
        return search(root->left, val, score);
    }
    else if (val > root->score)
    {
        score += 1; // right move
        cout << "Right move: " << root->score << endl;
        return search(root->right, val, score);
    }
    else
        return root; // found
}
int main(){
    mind_maze *root = NULL;
    int warriors[] = {45, 30, 60, 20, 35, 50, 70};
    int search_keys[] = {35, 50, 70};

    for (int i = 0; i < 7; i++)
    {
        root = insert(root, warriors[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        int score = 0;
        mind_maze *result = search(root, search_keys[i], score);
        if (result != NULL)
            cout << "Found " << search_keys[i] << " with score: " << score << endl;
        else
            cout << search_keys[i] << " not found." << endl;
    }

    return 0;
}