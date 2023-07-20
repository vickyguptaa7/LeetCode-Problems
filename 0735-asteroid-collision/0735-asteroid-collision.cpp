class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>result;
        for(auto as:asteroids)
        {
            bool isAdd=true;
            while(!result.empty()&&result.back()>0&&as<0)
            {
                if(result.back()==abs(as))
                {
                    isAdd=false;
                    result.pop_back();   
                    break;
                }
                else if(result.back()<abs(as))
                {
                    result.pop_back();
                }
                else
                {
                    isAdd=false;
                    break;
                }
            }
            if(isAdd)
                result.push_back(as);
        }
        return result;
    }
};