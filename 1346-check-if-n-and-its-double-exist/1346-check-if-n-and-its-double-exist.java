class Solution {
    public boolean checkIfExist(int[] arr) {
        Arrays.sort(arr);
        for(int i=0;i<arr.length;i++)
        {
            int indx=Arrays.binarySearch(arr,arr[i]*2);
            if(indx>=0&&indx!=i)
                return true;
        }
        return false;
    }
}