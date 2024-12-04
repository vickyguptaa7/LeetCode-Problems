class Solution {
    public boolean canMakeSubsequence(String str1, String str2) {
        int count=0;
        for(int i=0;i<str1.length();i++)
        {
            int s1=str1.charAt(i)-'a';
            int s2=str2.charAt(count)-'a';
            if((s1+1)%26==s2)
            {
                count++;
            }
            else if(count<str2.length()&&str1.charAt(i)==str2.charAt(count))
            {
                count++;
            }
            if(count==str2.length())
                    return true;
        }
        return false;
    }
}