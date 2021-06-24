class MinStack {
private: 
	long long int minele=INT_MAX;
	stack<long long int> st;
public:
	/** initialize your data structure here. */    
	void push(int x) {
		if(st.empty())
		{
			minele=x;
			st.push(x);
		}
		else if(x<minele)
		{
			long long int temp=x;
			temp=2*temp-minele;
			st.push(temp);
			minele=x;
		}
		else
			st.push(x);
	}
	void pop() {
		if(st.top()<minele)
		{
			int temp=st.top();
			minele=2*minele-temp;
		}
			st.pop();
		if(st.empty())
			minele=INT_MAX;
	}

	int top() {
		if(st.top()<minele)
		{
			return minele;
		}
		else
		return st.top();
	}

	int getMin() {
		return minele;
	}
};
