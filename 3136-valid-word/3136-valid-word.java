class Solution {

    private boolean isLengthValid(String word) {
        return word.length()>=3;
    }

    private boolean isContainValidCharacter(String word) {
        for(int i=0;i<word.length();i++)
        {
            char ch = word.charAt(i);
            if((ch>='0'&&ch<='9')||(ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
            {
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    private boolean isContainAtLeastOneVowel(String word) {
        String vowel="aeiouAEIOU";
        for(int i=0;i<word.length();i++)
        {
            if(vowel.contains(String.valueOf(word.charAt(i)))){
                return true;
            }
        }
        return false;
    }
    
    private boolean isContaintAtLeastOneVowel(String word) {
        String vowel="bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
        for(int i=0;i<word.length();i++)
        {
            if(vowel.contains(String.valueOf(word.charAt(i)))){
                return true;
            }
        }
        return false;
    }   

    public boolean isValid(String word) {
        return isLengthValid(word)&&isContainValidCharacter(word)&&isContainAtLeastOneVowel(word)&&isContaintAtLeastOneVowel(word);
    }
}