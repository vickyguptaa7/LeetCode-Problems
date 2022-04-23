class Solution {
public:

    // Encodes a URL to a shortened URL.
    map<string,string>longToShort,shortToLong;
    string base="http://tinyurl.com/",
alphanumeric="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    
    string encode(string longUrl) {
        if(longToShort.find(longUrl)!=longToShort.end())
            return base+longToShort[longUrl];
        string shortUrl="";
        
        while(true)
        {
            for(int i=0;i<8;i++)
            {
                shortUrl=alphanumeric[rand()%62];
            }
            if(shortToLong.find(shortUrl)==shortToLong.end())break;
            shortUrl="";
        }
        shortToLong[shortUrl]=longUrl;
        longToShort[longUrl]=shortUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return shortToLong[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));