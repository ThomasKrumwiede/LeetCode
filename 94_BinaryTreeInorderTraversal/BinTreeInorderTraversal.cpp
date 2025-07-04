#include <iostream>
#include <vector>

using namespace std;

//Binary Tree
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//Inorder traversal solution 
class Solution {
public: 
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inOrderList;

        traversal(root, inOrderList);

        return inOrderList;
    }

private:
    void traversal(TreeNode* root, vector<int>& inOrderList)
    {
        if (root == nullptr) return;
        traversal(root->left, inOrderList);
        inOrderList.push_back(root->val);
        traversal(root->right, inOrderList);
    }
};

//Helper funciton to print the vector 
void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

//Main function to test the solution 
int main() {
    Solution test;

    // Case 1: [1,null,2,3]
    TreeNode* case1 = new TreeNode(1);
    case1->right = new TreeNode(2);
    case1->right->left = new TreeNode(3);
    cout << "Case 1: ";
    printVector(test.inorderTraversal(case1));

    //Case 2: [1,2,3,4,5,null,8,null,null,6,7,9]
    TreeNode* case2 = new TreeNode(1,
        new TreeNode(2,
            new TreeNode(4),
            new TreeNode(5,
                new TreeNode(6),
                new TreeNode(7))),
        new TreeNode(3,
            nullptr,
            new TreeNode(8,
                new TreeNode(9),
                nullptr))
    );
    cout << "Case 2: ";
    printVector(test.inorderTraversal(case2));

    //Case 3: []
    TreeNode* case3 = nullptr;
    cout << "Case 3: ";
    printVector(test.inorderTraversal(case3));

    //Case 4: [1]
    TreeNode* case4 = new TreeNode(1);
    cout << "Case 4: ";
    printVector(test.inorderTraversal(case4));

    return 0;
}