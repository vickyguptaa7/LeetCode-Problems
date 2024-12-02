class Solution {
    public int isPrefixOfWord(String sentence, String searchWord) {
        int word=1;
        for(int i=0;i<sentence.length();i++)
        {
            if(sentence.charAt(i)==' ')
            {
                word++;
            }
            else
            {
                int indx=0;
                while(i<sentence.length()&&indx<searchWord.length()
                      &&sentence.charAt(i)==searchWord.charAt(indx))
                {
                    i++;
                    indx++;
                }
                if(indx==searchWord.length())
                    return word;
                while(i<sentence.length()&&sentence.charAt(i)!=' ')
                    i++;
                i--;
            }
        }
        return -1;
    }
}