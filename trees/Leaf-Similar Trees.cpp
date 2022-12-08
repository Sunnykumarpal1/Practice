void Traverasal(TreeNode* root,vector<int>&ans){
      if(root==NULL){
          return ;
      }
     if(root->left==NULL&&root->right==NULL){
          ans.push_back(root->val);
     }
   Traverasal(root->left,ans);
   Traverasal(root->right,ans);
  }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>ans;
        Traverasal(root1,ans);
        vector<int>temp;
        Traverasal(root2,temp);
        if(ans.size()!=temp.size()){
            return 0;
        }else{
            int n=ans.size();
            for(auto i=0;i<n;i++){
               if( temp[i]!=ans[i]){
                   return 0;
               }
            }
        }
        return 1;
    }
