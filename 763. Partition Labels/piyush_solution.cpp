
class Solution {
public:
     
    vector<int> partitionLabels(string s) {
        
      vector<int> lastind(26),res;  
      for(int i=0;i<s.size();i++)
          lastind[s[i]-'a']=i;
        
      int i,j=0,st=0,n=s.size();
    
      for(i=0;i<n;i++)
      {
          j=max(j,lastind[s[i]-'a']);
          if(j==i)
          {
              res.push_back(j-st+1);
              st=i+1;
              j=i+1;
          }    
      }
    return res;
    }
};
