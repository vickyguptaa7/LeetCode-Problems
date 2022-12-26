typedef pair<int,int> ppi;

struct Comp {
    bool operator()(ppi &p1, ppi &p2)
    {
        if(p1.second!=p2.second)
        {
            return p1.second<p2.second;
        }
        return p1.first > p2.first;
    }
};

class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        
        int n=report.size();
        vector<vector<string>>reportArray(n);
        set<string>negFdbck(negative_feedback.begin(),negative_feedback.end()),
        posFdbck(positive_feedback.begin(),positive_feedback.end());
        
        for(int i=0;i<n;i++)
        {
            string word="";
            for(int j=0;j<report[i].size();j++)
            {
                if(report[i][j]==' ')
                {
                    reportArray[i].push_back(word);
                    word="";
                }
                else
                {
                    word+=report[i][j];
                }
            }
            if(word!="")
                reportArray[i].push_back(word);
        }
        map<int,int>smarks;
        for(int i=0;i<n;i++)
        {
            int isPos=0;
            for(auto &word:reportArray[i])
            {
                    if(posFdbck.count(word))
                    {
                        isPos++;
                    }
            }
            int isNeg=0;
            for(auto &word:reportArray[i])
            {
                    if(negFdbck.count(word))
                    {
                        isNeg++;
                    }
            }
            smarks[student_id[i]]+=3*isPos-isNeg;
        }
        priority_queue<ppi,vector<ppi>,Comp>pque;
        for(auto &x:smarks)
        {
            pque.push({x.first,x.second});
        }
        vector<int>res;
        while(k--)
        {
            res.push_back(pque.top().first);
            pque.pop();
        }
        return res;
    }
};