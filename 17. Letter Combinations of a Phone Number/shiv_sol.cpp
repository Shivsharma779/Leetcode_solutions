class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        map<string,vector<string>> ntos{
            {"2",{"a","b","c"}},
            {"3",{"d","e","f"}},
            {"4",{"g","h","i"}},
            {"5",{"j","k","l"}},
            {"6",{"m","n","o"}},
            {"7",{"p","q","r","s"}},
            {"8",{"t","u","v"}},
            {"9",{"w","x","y","z"}}
        };
        
        
        vector<string> prev_ans{""};
        
        for (auto d : digits){
            vector<string> curr_ans;
            for(auto s:  ntos[string(1,d)])
                for(auto a : prev_ans)
                    curr_ans.push_back(a+s);
            
            prev_ans = curr_ans;
        }
        return ((digits.size() > 0)?prev_ans:vector<string>{});
    }
};
