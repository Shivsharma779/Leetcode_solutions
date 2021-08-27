
//https://leetcode.com/problems/gas-station/discuss/42568/Share-some-of-my-ideas.
//see first comment also
//https://www.youtube.com/watch?v=wDgKaNrSOEI
int Solution::canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {
    int n=gas.size(),tot=0;
    for(int i=0;i<n;i++)
        tot += gas[i]-cost[i];
    
    //no solution possible
    if(tot<0)   return -1;
    
    int st=0,tank=0;
    for(int i=0;i<n;i++)
    {
        tank += gas[i]-cost[i];     
        //ran out of gas, so start  candidate will be next index after running out
        if(tank<0)      
        {
            tank=0;
            st=i+1;
        }
    }
    return st%n;
}
