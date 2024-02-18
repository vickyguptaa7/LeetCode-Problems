typedef long long ll;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        set<vector<ll>>room,mroom;
        
        // room => room_no no_of_acomodation
        // mroom => end room_no no_of_accomdation
        sort(meetings.begin(),meetings.end());
        for(int i=0;i<n;i++)room.insert({i,0,0});
        ll curr=0;
        for(int i=0;i<meetings.size();i++)
        {
            curr=max(curr,(ll)meetings[i][0]);
            while(!mroom.empty()&&(*mroom.begin())[0]<=curr)
            {
                auto it=mroom.begin();
                room.insert({(*it)[1],(*it)[2],0});
                mroom.erase(it);
            }
            if(!room.empty())
            {
                auto it=room.begin();
                mroom.insert({(meetings[i][1]-meetings[i][0])+curr,(*it)[0],(*it)[1]+1});
                room.erase(it);
            }
            else
            {
                ll end=(*mroom.begin())[0];
                while(!mroom.empty())
                {
                    auto it=mroom.begin();
                    if(end<(*it)[0])break;
                    room.insert({(*it)[1],(*it)[2],0});
                    mroom.erase(it);
                }
                curr=end;
                i--;
            }
        }
        ll room_no=1e9,count=0;
        while(!mroom.empty())
        {
            auto it=mroom.begin();
            if((*it)[2]>=count)
            {
                if(count==(*it)[2])
                room_no=min((ll)room_no,(*it)[1]);
                else
                room_no=(*it)[1];
                
                count=(*it)[2];
            }
            
            mroom.erase(it);
        }
        while(!room.empty())
        {
            auto it=room.begin();
            if((*it)[1]>=count)
            {
                if((*it)[1]==count)
                    room_no=min((ll)room_no,(*it)[0]);
                else 
                    room_no=(*it)[0];
                count=(*it)[1];
            }
            room.erase(it);
        }
        return room_no;
    }
};