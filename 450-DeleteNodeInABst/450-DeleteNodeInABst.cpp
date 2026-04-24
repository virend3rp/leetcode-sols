// Last updated: 4/24/2026, 10:12:56 PM
class Solution {

    public :
    TreeNode* InorderSuccessors(TreeNode* root){
        while(root->left != NULL){
            root = root->left;
        }

        return root;
    }

    public:
     TreeNode* deleteNode(TreeNode* root, int key) {

        if(root == NULL){
            return NULL;
        }

        if(root->val < key){
            root->right = deleteNode(root->right, key);
        }
        else if(root->val > key){
            root->left = deleteNode(root->left, key);
        }else{

            if(root->left == NULL && root->right == NULL){
                return NULL;
            }

            if(root->left == NULL){
                return root->right;
            }else if(root->right == NULL){
                 return root->left;
            }

            TreeNode* IS = InorderSuccessors(root->right);
            root->val = IS->val;
            root->right = deleteNode(root->right, IS->val);
            
            
            }

  return root;   
}

};