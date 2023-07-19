

class NestedIterator
{
    public:
        stack<NestedInteger> st;
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        pushedList(nestedList);
    }

    int next()
    {
        hasNext();
        int res = st.top().getInteger();
        st.pop();
        return res;
    }

    bool hasNext()
    {
        while (!st.empty())
        {
            if (st.top().isInteger())
            {
                return true;
            }
            auto temp=st.top();
            st.pop();
            pushedList(temp.getList());
        }
        return false;
    }
    void pushedList(vector<NestedInteger> &nestedList)
    {
        for (int i = nestedList.size() - 1; i >= 0; i--)
        {
            st.push(nestedList[i]);
        }
    }
};

/**
 *Your NestedIterator object will be instantiated and called as such:
 *NestedIterator i(nestedList);
 *while (i.hasNext()) cout << i.next();
 */