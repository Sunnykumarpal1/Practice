/*Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
 */
// Tc->0(n^2)for main function & 4^mn for wordsearch
bool WordSearch(int i,int j,int m,int n,string word,vector<vector<char>>&board,vector<vector<int>>&mat,int ind){
        if(ind==word.size()){
            return 1;
        }
        
        if(i<0|| j<0||i>=m||j>=n||board[i][j]!=word[ind]||mat[i][j]==1){
            return 0;
        }
        mat[i][j]=1;
        int up=WordSearch(i-1,j,m,n,word,board,mat,ind+1);
        int down=WordSearch(i+1,j,m,n,word,board,mat,ind+1);
        int lef=WordSearch(i,j-1,m,n,word,board,mat,ind+1);
        int rig=WordSearch(i,j+1,m,n,word,board,mat,ind+1);
        mat[i][j]=0;
        return (up||down||lef||rig);
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>mat(m,vector<int>(n,0));
        for(auto i=0;i<m;i++){
            for(auto j=0;j<n;j++){
                if(WordSearch(i,j,m,n,word,board,mat,0)){
                    return 1;
                }
            }
        }
        return 0;
    }
