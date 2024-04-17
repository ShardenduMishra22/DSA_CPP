// #include <bits/stdc++.h>
// using namespace std;

// struct Treenode {
//     int val;
//     Treenode *left;
//     Treenode *right;
//     Treenode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

// int maxDepth(Treenode* root) {
//     if (root == nullptr) return 0;
//     return max(maxDepth(root->left), maxDepth(root->right)) + 1;
// }

// int minDepth(Treenode* root) {
//     if (root == nullptr) return 0;
//     if (root->left == nullptr) return minDepth(root->right) + 1;
//     if (root->right == nullptr) return minDepth(root->left) + 1;
//     return min(minDepth(root->left), minDepth(root->right)) + 1;
// }

// Treenode* invertTree(Treenode* root) {
//     if (root == nullptr) return nullptr;
//     Treenode* temp = root->left;
//     root->left = invertTree(root->right);
//     root->right = invertTree(temp);
//     return root;
// }

// bool isValidBST(Treenode* root, Treenode* minnode = nullptr, Treenode* maxnode = nullptr) {
//     if (root == nullptr) return true;
//     if ((minnode && root->val <= minnode->val) || (maxnode && root->val >= maxnode->val)) return false;
//     return isValidBST(root->left, minnode, root) && isValidBST(root->right, root, maxnode);
// }

// bool hasPathSum(Treenode* root, int sum) {
//     if (root == nullptr) return false;
//     if (root->left == nullptr && root->right == nullptr && sum - root->val == 0) return true;
//     return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
// }

// bool isSymmetric(Treenode* root) {
//     if (root == nullptr) return true;
//     return isSymmetricHelper(root->left, root->right);
// }

// bool isSymmetricHelper(Treenode* left, Treenode* right) {
//     if (left == nullptr && right == nullptr) return true;
//     if (left == nullptr || right == nullptr || left->val != right->val) return false;
//     return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
// }

// vector<vector<int>> levelOrder(Treenode* root) {
//     vector<vector<int>> result;
//     if (root == nullptr) return result;
//     queue<Treenode*> q;
//     q.push(root);
//     while (!q.empty()) {
//         int size = q.size();
//         vector<int> level;
//         for (int i = 0; i < size; ++i) {
//             Treenode* node = q.front();
//             q.pop();
//             level.push_back(node->val);
//             if (node->left) q.push(node->left);
//             if (node->right) q.push(node->right);
//         }
//         result.push_back(level);
//     }
//     return result;
// }

// Treenode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//     unordered_map<int, int> inMap;
//     for (int i = 0; i < inorder.size(); ++i) {
//         inMap[inorder[i]] = i;
//     }
//     return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
// }

// Treenode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inMap) {
//     if (preStart > preEnd || inStart > inEnd) return nullptr;
//     Treenode* root = new Treenode(preorder[preStart]);
//     int inRoot = inMap[root->val];
//     int numsLeft = inRoot - inStart;
//     root->left = buildTreeHelper(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
//     root->right = buildTreeHelper(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);
//     return root;
// }

// Treenode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//     unordered_map<int, int> inMap;
//     for (int i = 0; i < inorder.size(); ++i) {
//         inMap[inorder[i]] = i;
//     }
//     return buildTreeHelper(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
// }

// Treenode* buildTreeHelper(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inMap) {
//     if (postStart > postEnd || inStart > inEnd) return nullptr;
//     Treenode* root = new Treenode(postorder[postEnd]);
//     int inRoot = inMap[root->val];
//     int numsRight = inEnd - inRoot;
//     root->left = buildTreeHelper(postorder, postStart, postEnd - numsRight - 1, inorder, inStart, inRoot - 1, inMap);
//     root->right = buildTreeHelper(postorder, postEnd - numsRight, postEnd - 1, inorder, inRoot + 1, inEnd, inMap);
//     return root;
// }

// void flatten(Treenode* root) {
//     if (root == nullptr) return;
//     stack<Treenode*> s;
//     s.push(root);
//     while (!s.empty()) {
//         Treenode* curr = s.top();
//         s.pop();
//         if (curr->right) s.push(curr->right);
//         if (curr->left) s.push(curr->left);
//         if (!s.empty()) curr->right = s.top();
//         curr->left = nullptr;
//     }
// }

// int countnodes(Treenode* root) {
//     if (root == nullptr) return 0;
//     int leftHeight = 0, rightHeight = 0;
//     Treenode* left = root, *right = root;
//     while (left) {
//         leftHeight++;
//         left = left->left;
//     }
//     while (right) {
//         rightHeight++;
//         right = right->right;
//     }
//     if (leftHeight == rightHeight) return (1 << leftHeight) - 1;
//     return 1 + countnodes(root->left) + countnodes(root->right);
// }

// Treenode* sortedArrayToBST(vector<int>& nums) {
//     return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
// }

// Treenode* sortedArrayToBSTHelper(vector<int>& nums, int start, int end) {
//     if (start > end) return nullptr;
//     int mid = start + (end - start) / 2;
//     Treenode* root = new Treenode(nums[mid]);
//     root->left = sortedArrayToBSTHelper(nums, start, mid - 1);
//     root->right = sortedArrayToBSTHelper(nums, mid + 1, end);
//     return root;
// }

// Treenode* lowestCommonAncestor(Treenode* root, Treenode* p, Treenode* q) {
//     if (root == nullptr || root == p || root == q) return root;
//     Treenode* left = lowestCommonAncestor(root->left, p, q);
//     Treenode* right = lowestCommonAncestor(root->right, p, q);
//     if (left && right) return root;
//     return left ? left : right;
// }

// int maxPathSum(Treenode* root) {
//     int maxSum = INT_MIN;
//     maxPathSumHelper(root, maxSum);
//     return maxSum;
// }

// int maxPathSumHelper(Treenode* root, int& maxSum) {
//     if (root == nullptr) return 0;
//     int leftSum = max(0, maxPathSumHelper(root->left, maxSum));
//     int rightSum = max(0, maxPathSumHelper(root->right, maxSum));
//     maxSum = max(maxSum, leftSum + rightSum + root->val);
//     return max(leftSum, rightSum) + root->val;
// }

// vector<vector<int>> zigzagLevelOrder(Treenode* root) {
//     vector<vector<int>> result;
//     if (root == nullptr) return result;
//     queue<Treenode*> q;
//     q.push(root);
//     bool leftToRight = true;
//     while (!q.empty()) {
//         int size = q.size();
//         vector<int> level(size);
//         for (int i = 0; i < size; ++i) {
//             Treenode* node = q.front();
//             q.pop();
//             int index = leftToRight ? i : size - 1 - i;
//             level[index] = node->val;
//             if (node->left) q.push(node->left);
//             if (node->right) q.push(node->right);
//         }
//         leftToRight = !leftToRight;
//         result.push_back(level);
//     }
//     return result;
// }

// node* connect(node* root) {
//     if (root == nullptr) return nullptr;
//     if (root->left) root->left->next = root->right;
//     if (root->right && root->next) root->right->next = root->next->left;
//     connect(root->left);
//     connect(root->right);
//     return root;
// }

// int sumOfLeftLeaves(Treenode* root) {
//     if (root == nullptr) return 0;
//     int sum = 0;
//     if (root->left && root->left->left == nullptr && root->left->right == nullptr) sum += root->left->val;
//     sum += sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
//     return sum;
// }

// int diameterOfBinaryTree(Treenode* root) {
//     int maxDiameter = 0;
//     diameterHelper(root, maxDiameter);
//     return maxDiameter;
// }

// int diameterHelper(Treenode* root, int& maxDiameter) {
//     if (root == nullptr) return 0;
//     int leftHeight = diameterHelper(root->left, maxDiameter);
//     int rightHeight = diameterHelper(root->right, maxDiameter);
//     maxDiameter = max(maxDiameter, leftHeight + rightHeight);
//     return max(leftHeight, rightHeight) + 1;
// }

// Treenode* upsideDownBinaryTree(Treenode* root) {
//     if (root == nullptr || root->left == nullptr) return root;
//     Treenode* left = root->left;
//     Treenode* right = root->right;
//     Treenode* newRoot = upsideDownBinaryTree(left);
//     left->left = right;
//     left->right = root;
//     root->left = nullptr;
//     root->right = nullptr;
//     return newRoot;
// }

// Treenode* deletenode(Treenode* root, int key) {
//     if (root == nullptr) return nullptr;
//     if (root->val > key) root->left = deletenode(root->left, key);
//     else if (root->val < key) root->right = deletenode(root->right, key);
//     else {
//         if (root->left == nullptr) return root->right;
//         else if (root->right == nullptr) return root->left;
//         Treenode* minnode = findMin(root->right);
//         root->val = minnode->val;
//         root->right = deletenode(root->right, root->val);
//     }
//     return root;
// }

// Treenode* findMin(Treenode* node) {
//     while (node->left != nullptr) {
//         node = node->left;
//     }
//     return node;
// }

// int main() {
//     Treenode* root = new Treenode(1);
//     root->left = new Treenode(2);
//     root->right = new Treenode(3);
//     root->left->left = new Treenode(4);
//     root->left->right = new Treenode(5);

//     cout << "Maximum Depth of Binary Tree: " << maxDepth(root) << endl;
//     cout << "Minimum Depth of Binary Tree: " << minDepth(root) << endl;

//     Treenode* invertedRoot = invertTree(root);
//     cout << "Inverted Tree: " << endl;

//     vector<int> preorder = {1, 2, 4, 5, 3};
//     vector<int> inorder = {4, 2, 5, 1, 3};
//     Treenode* constructedRoot = buildTree(preorder, inorder);
//     cout << "Constructed Tree from Preorder and Inorder Traversal: " << endl;

//     vector<int> postorder = {4, 5, 2, 3, 1};
//     constructedRoot = buildTree(inorder, postorder);
//     cout << "Constructed Tree from Inorder and Postorder Traversal: " << endl;

//     flatten(root);
//     cout << "Flattened Binary Tree: " << endl;

//     cout << "Count Complete Tree nodes: " << countnodes(root) << endl;

//     vector<int> sortedArray = {1, 2, 3, 4, 5};
//     Treenode* bstRoot = sortedArrayToBST(sortedArray);
//     cout << "Constructed BST from Sorted Array: " << endl;

//     Treenode* lca = lowestCommonAncestor(root, root->left->left, root->left->right);
//     cout << "Lowest Common Ancestor: " << lca->val << endl;

//     cout << "Maximum Path Sum: " << maxPathSum(root) << endl;

//     vector<vector<int>> zigzagOrder = zigzagLevelOrder(root);
//     cout << "Zigzag Level Order Traversal: " << endl;

//     node* connectedRoot = connect(root);
//     cout << "Populating Next Right Pointers in Each node: " << endl;

//     cout << "Sum of Left Leaves: " << sumOfLeftLeaves(root) << endl;

//     cout << "Diameter of Binary Tree: " << diameterOfBinaryTree(root) << endl;

//     Treenode* upsideDownRoot = upsideDownBinaryTree(root);
//     cout << "Upside Down Binary Tree: " << endl;

//     Treenode* bst = new Treenode(5);
//     bst->left = new Treenode(3);
//     bst->right = new Treenode(6);
//     bst->left->left = new Treenode(2);
//     bst->left->right = new Treenode(4);
//     bst->right->right = new Treenode(7);
//     Treenode* deletedBST = deletenode(bst, 3);
//     cout << "BST after deleting node with key 3: " << endl;

//     return 0;
// }

