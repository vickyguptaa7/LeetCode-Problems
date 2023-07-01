class Solution {
public:
    
    bool isValid(int indx,int costLeft,int childLeft,int taken,vector<int>&cookies,int cost)
    {
        if(indx==cookies.size())
        {
            if(childLeft==1)
                return (taken==((1<<(cookies.size()))-1));
            return isValid(0,cost,childLeft-1,taken,cookies,cost);
        }
        
        if(isValid(indx+1,costLeft,childLeft,taken,cookies,cost))
            return true;
        if(costLeft>=cookies[indx]&&!(taken&(1<<indx))&&isValid(indx+1,costLeft-cookies[indx],childLeft,taken|(1<<indx),cookies,cost))
            return true;
        
        return false;
             
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        int high=accumulate(cookies.begin(),cookies.end(),0);
        int low=*max_element(cookies.begin(),cookies.end());
        int result=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(isValid(0,mid,k,0,cookies,mid))
            {
                result=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return result;
    }
};