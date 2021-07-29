class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        for(int i=digits.size()-1 ; i>=0;i--)
        {
            int temp = digits[i] + 1;
            digits[i] = temp%10;
            carry = temp/10;
            //cout<<carry;
            if(!carry)
                return digits;
        }
        
            
        if(carry)
        {
            reverse(digits.begin(),digits.end());
            digits.push_back(1);
            reverse(digits.begin(),digits.end());
        }
        
        return digits;
            
    }
};
