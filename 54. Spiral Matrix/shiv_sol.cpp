class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& M) {
        vector<int> ans;
        int n = M.size() , m = M[0].size();
        int lt = 0, lb = n-1;
        int ll = 0 , lr = m-1;
        int d = 0;
        int i = 0 , j = 0;
        while(lb >= lt && lr >= ll){
            if(d%4 == 0){
                while(j<=lr) ans.push_back(M[i][j++]);
                i++,j--,lt++;
            }
            else if(d%4 == 1){
                while(i<=lb) ans.push_back(M[i++][j]);
                i--,j--,lr--;
            }
            else if(d%4 == 2){
                while(j>=ll) ans.push_back(M[i][j--]);
                i--,j++,lb--;
            }
            else{
                while(i>=lt) ans.push_back(M[i--][j]);
                i++,j++,ll++;
            }
            d++;
        }
        return ans;
    }
};
