#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


class Solution {
public:
  TreeNode* create(int start , int end , vector<int>&nums){
    if(start> end)return NULL;
    int mid = (start+end)/2;
    TreeNode* m = new TreeNode(nums[mid]);
   
    m->left = create(start , mid-1 , nums);
    m->right = create(mid+1 , end , nums);
    return m;
  }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)return NULL;
       TreeNode* ans= create(0 , nums.size()-1 , nums);
     return ans;
    }
};