class TextEditor
{
    stack<char> left, right;
    public:
        TextEditor() {}

    void addText(string text)
    {
        for (int i = 0; i < text.size(); i++)
        {
            left.push(text[i]);
        }
        // print();
    }

    int deleteText(int k)
    {
        int tmp = k;
        while (!left.empty() && tmp)
        {
            left.pop();
            tmp--;
        }
        // print();
        return k - tmp;
    }

    string cursorLeft(int k)
    {
        string s;
        int tmp = k;
        while (!left.empty() && tmp)
        {
            right.push(left.top());
            left.pop();
            tmp--;
        }
        tmp=0;
        while(!left.empty()&&s.size()<10)
        {
            s=left.top()+s;
            right.push(left.top());
            left.pop();
            tmp++;
        }
        while(tmp>0)
        {
            left.push(right.top());
            right.pop();
            tmp--;
        }
        return s;
    }

    string cursorRight(int k)
    {
        string s;
        int tmp = k;
        while (!right.empty() && tmp)
        {
            left.push(right.top());
            right.pop();
            tmp--;
        }
        tmp=0;
        while(!left.empty()&&s.size()<10)
        {
            s=left.top()+s;
            right.push(left.top());
            left.pop();
            tmp++;
        }
        while(tmp>0)
        {
            left.push(right.top());
            right.pop();
            tmp--;
        }
        return s;
    }
    void print()
    {
        stack<char>t1=left,t2=right;
        while(!t1.empty())
        {
            t2.push(t1.top());
            t1.pop();
        }
        while(!t2.empty())
        {
            cout<<t2.top();
            t2.pop();
        }
        cout<<"\n";
    }
};

/**
 *Your TextEditor object will be instantiated and called as such:
 *TextEditor* obj = new TextEditor();
 *obj->addText(text);
 *int param_2 = obj->deleteText(k);
 *string param_3 = obj->cursorLeft(k);
 *string param_4 = obj->cursorRight(k);
 */