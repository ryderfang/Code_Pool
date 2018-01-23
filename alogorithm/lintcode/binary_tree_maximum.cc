#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

typedef long long LL;

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
private:
    int ans;
public:
    /*
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxPathSum(TreeNode *root) {
        if (!root) {
            return 0;
        }
        ans = INT_MIN;
        dpSolve(root);
        return ans;
    }

    int dpSolve(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int sum = root->val;
        int lf = 0, rt = 0;
        if (root->left) {
            lf = dpSolve(root->left);
        }
        if (root->right) {
            rt = dpSolve(root->right);
        }

        if (lf > 0) {
            sum += lf;
        }
        if (rt > 0) {
            sum += rt;
        }

        ans = max(ans, sum);
        return max(0, max(lf, rt)) + root->val;
    }
};

