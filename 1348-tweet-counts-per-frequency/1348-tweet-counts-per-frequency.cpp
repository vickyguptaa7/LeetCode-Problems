class TweetCounts {
    unordered_map<string,map<int,int>>tweets;
public:
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        tweets[tweetName][time]++;
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int duration=(freq=="minute")?60:(freq=="hour")?3600:86400;
        vector<int>tweetsFreq((endTime-startTime)/duration+1,0);
        auto begin=tweets[tweetName].lower_bound(startTime);
        auto end=tweets[tweetName].upper_bound(endTime);
        for(auto iter=begin;iter!=end;iter++)
        {
            tweetsFreq[(iter->first-startTime)/duration]+=iter->second;
        }
        return tweetsFreq;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */