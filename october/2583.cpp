#include<iostream>
#include<queue>

using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* arrayToBinaryTree(int arr[], int n, int i = 0) {
    if (i >= n || arr[i] == -1) return NULL;

    TreeNode* root = new TreeNode(arr[i]);
    root->left = arrayToBinaryTree(arr, n, 2 * i + 1);
    root->right = arrayToBinaryTree(arr, n, 2 * i + 2);

    return root;
}

void printInOrder(TreeNode* root) {
    if (root == NULL) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}



long long kthLargestLevelSum(TreeNode* root, int k) {
    priority_queue<long long int> maxHeap;
    

    queue<TreeNode *> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();
        long long int sum = 0;

        for(int i = 0; i < size; ++i) {
            TreeNode* front = q.front();
            q.pop();
            sum += front->val;
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }

        maxHeap.push(sum);
    }

    for(int i = 0; i < k-1; ++i) {
        maxHeap.pop();
        if(maxHeap.empty()) return -1;
    }
    return maxHeap.top();
}


int main() {
    int arr[] = {5,8,9,2,1,3,7,4,6};
    TreeNode* root = arrayToBinaryTree(arr, 9);
    kthLargestLevelSum(root, 2);
}