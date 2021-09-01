/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
     int findPlatform(int a[], int d[], int n)
{
	// Your code here
	sort(a,a+n);
	sort(d,d+n);
	int i=0,j=0,maxp=0,p=0;
	while(i<n && j<n)
	{
	    if(a[i]<=d[j])
	    {
	        p++;
	        i++;
	    }
	    else //if(a[i]>d[j])
	    {
	        p--;
	        j++;
	    }
	    
	    if(p>maxp)
	        maxp=p;
	}
	return maxp;
}
    int minMeetingRooms(vector<Interval> &intervals) {
        // Write your code here

        int n=intervals.size();
        int arr[n],dep[n];
        for(int i=0;i<n;i++)
        {
            arr[i]=intervals[i].start;
            dep[i]=intervals[i].end;
        }

        return findPlatform(arr, dep, n)
    }
};
