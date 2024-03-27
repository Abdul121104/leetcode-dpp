class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<pair<long long,int>> endtime;
        priority_queue<int> unusedroom;
        vector<int> roomfreq(n,0);

        for(int i=0;i<n; i++)   unusedroom.push(-i);

        for(auto itr:meetings) {
            int str = itr[0];
            while(endtime.size()) {
                pair<int,int> pr = endtime.top();
                if(-pr.first<= str)  {
                    endtime.pop();
                    unusedroom.push(pr.second);
                }
                else    break;
            }
            if(unusedroom.size()) {
                endtime.push({-itr[1],unusedroom.top()});
                roomfreq[-unusedroom.top()]++;
                unusedroom.pop();
            }
            else {
                pair<long long,int> pr = endtime.top();
                endtime.pop();
                endtime.push({pr.first-itr[1]+itr[0],pr.second});
                roomfreq[-pr.second]++;
            }
        } 
        
        int maxElementIndex = max_element(roomfreq.begin(),roomfreq.end()) - roomfreq.begin();
        return maxElementIndex; 
    }
};
