class Solution {
public:
    vector<int> partitionLabels(string S) {
        int n = S.size();
        
        
        map<char,int> alphabets;
        for (int i =n-1 ; i > -1; i--){
            if(alphabets.find(S[i]) == alphabets.end()){
                alphabets[S[i]] = i;
            }
        }
        
        
        vector<int> answer;
        
        int start = 0, end = -1;
        for(int i =0 ; i < n ; i++){
            end = max(end,alphabets[S[i]]);
            if(end == i){
                answer.push_back(end-start+1);
                start = i+1;
                end = -1;
            }
        }
        
        return answer;
        
    }
};
