class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[](vector<int>a,vector<int>b){
           if(a[1]!=b[1])
               return a[1]<b[1];
            return a[0]<b[0];
        });
        
        priority_queue<int>pque;
        int days=0;
        for(int i=0;i<courses.size();i++)
        {
            if(days+courses[i][0]<=courses[i][1])
            {
                days+=courses[i][0];
                pque.push(courses[i][0]);
            }
            else if(!pque.empty()&&pque.top()>courses[i][0])
            {
                    days-=pque.top();
                    days+=courses[i][0];
                    pque.pop();
                    pque.push(courses[i][0]);
            }
        }
        return pque.size();
    }
};