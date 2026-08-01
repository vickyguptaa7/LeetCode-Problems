class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String,List<String>> mp = new HashMap<>();
        for(int i=0;i<strs.length;i++)
        {
            char[] chr = strs[i].toCharArray();
            Arrays.sort(chr);
            String nstr = new String(chr);
            if(!mp.containsKey(nstr))
            {
                mp.put(nstr,new ArrayList<String>());
            }
            mp.get(nstr).add(strs[i]);
        }
        List<List<String>>result = new ArrayList<>();
        for(List<String> group : mp.values())
        {
            result.add(group);
        }
        return result;
    }
}