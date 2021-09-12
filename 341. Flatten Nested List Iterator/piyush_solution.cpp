class NestedIterator {
public:
    //https://www.youtube.com/watch?v=V-gPWPOyq8I
    
    //look at below link also
    //https://leetcode.com/problems/flatten-nested-list-iterator/discuss/80234/Evolve-from-intuition-to-optimal-a-review-of-top-solutions
    
    vector<int> flatlist;
    int i=0;
    
    //faltten list in constructor itself
    void helper(vector<NestedInteger> nestedList, vector<int> &flatlist)
    {
        for(int i=0 ; i<nestedList.size() ; i++)
            if(nestedList[i].isInteger())
                flatlist.push_back(nestedList[i].getInteger());
            else
                helper(nestedList[i].getList() , flatlist);
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        helper(nestedList , flatlist);
    }
    
    int next() {
        return flatlist[i++];
    }
    
    bool hasNext() {
        return i<flatlist.size();
    }
};
