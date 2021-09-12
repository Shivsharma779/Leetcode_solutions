#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007
#define fr(i,n) for(int i=0;i<n;i++)
#define ppi pair<int,int>

/*
cout<<"\ndebugging\n";
*/
/*
static auto speedup = []() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    return NULL;
}();
*/


int main()
{
	ios_base::sync_with_stdio(false); 	//Fast I/O
    cin.tie(NULL);
    
	ll t,n,i,j=0,m,x,k,res=0;
	string s;
	cin>>s>>k;
	
	unordered_map<char,int> mp;
	ll uniq=0;
	
	for(i=0;i<s.size();i++)
	{
	    mp[s[i]]++;
	    
	    while(mp.size()>k)
	    {
	        mp[s[j]]--;
	        if(mp[s[j]]==0)
	            mp.erase(s[j]);
	        j++;
	    }
	    
	    res = max(res, i-j+1);
	}
	cout<<res<<endl;
	
	return 0;
}
