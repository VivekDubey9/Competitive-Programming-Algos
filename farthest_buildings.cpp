class Solution {
public:
    int furthestBuilding(vector<int>& heights, int br, int lad) {
        priority_queue<int,vector<int>,greater<int>> que;
        int i=0;
        int diff;
        while(que.size()<lad && i<heights.size()-1)
        {
            diff = heights[i+1]-heights[i];
            if(diff<=0)
            {
                i++;
                continue;
            }
            que.push(diff);
            i++;
            
        }
        for(;i<heights.size()-1;i++)
        {
            diff = heights[i+1]-heights[i];
            if(diff>0)
            {
                if(!que.empty() && que.top()<diff)
                {
                    br = br - que.top();
                    que.pop();
                    que.push(diff);
                }
                else
                {
                    br = br - diff;
                }
            }
            if(br<0)
            {
                return i;
            }
                
        }
        return i;
        
        
    }
};
