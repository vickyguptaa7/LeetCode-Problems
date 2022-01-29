class Solution {
public:
    vector<int>Next_Smallest_To_Left(vector<int>& heights)
    {
        vector<int>smallest_to_left;
        stack<int>helper;
        int n=heights.size();
        for(int i=0;i<n;i++)
        {
            while(!helper.empty()&&heights[helper.top()]>=heights[i])
            {
                helper.pop();
            }
            if(helper.empty())
                smallest_to_left.push_back(-1);
            else 
                smallest_to_left.push_back(helper.top());
            
            helper.push(i);
        }
        return smallest_to_left;
    }
    vector<int>Next_Smallest_To_Right(vector<int>& heights)
    {
        vector<int>smallest_to_right;
        stack<int>helper;
        int n=heights.size();
        for(int i=n-1;i>=0;i--)
        {
            while(!helper.empty()&&heights[helper.top()]>=heights[i])
            {
                helper.pop();
            }
            if(helper.empty())
                smallest_to_right.push_back(n);
            else 
                smallest_to_right.push_back(helper.top());
            
            helper.push(i);
        }
        reverse(smallest_to_right.begin(),smallest_to_right.end());
        return smallest_to_right;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int>smallest_to_left,smallest_to_right;
        
        smallest_to_left=Next_Smallest_To_Left(heights);
        smallest_to_right=Next_Smallest_To_Right(heights);
        
        int largest_area=0,n=heights.size();
        for(int i=0;i<n;i++)
        {
            int area=(smallest_to_right[i]-smallest_to_left[i]-1)*heights[i];
            largest_area=max(largest_area,area);
        }
        return largest_area;
    }
};