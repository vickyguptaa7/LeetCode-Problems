class Solution {
    public boolean checkIfExist(int[] arr) {
        Set<Integer>sset= new HashSet<>();
        int zeroCount=0;
        for(int i=0;i<arr.length;i++)
        {
            sset.add(arr[i]);
            if(arr[i]==0)
                zeroCount+=1;
        }
        if(zeroCount>1)
            return true;
        for(int i=0;i<arr.length;i++)
        {
            if(arr[i]!=0&&sset.contains(arr[i]*2))
            {
                return true;
            }
        }
        
        return false;
    }
}