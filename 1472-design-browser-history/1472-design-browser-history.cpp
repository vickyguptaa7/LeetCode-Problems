class BrowserHistory {
public:
    vector<string>res;
    int curr=0,len=0;
    BrowserHistory(string homepage) {
        res.push_back(homepage);
        curr=0;
        len=1;
    }
    
    void visit(string url) {
        res.resize(curr+1);
        res.push_back(url);
        len=res.size();
        curr++;
    }
    
    string back(int steps) {
        if(curr<steps)
        {
            curr=0;
            return res[curr];
        }
        curr-=steps;
        return res[curr];
    }
    
    string forward(int steps) {
        if(curr+steps>=len)
        {
            curr=len-1;
            return res[curr];
        }
        curr+=steps;
        return res[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */