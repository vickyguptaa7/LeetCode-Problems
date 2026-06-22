class Solution {
    public int maxNumberOfBalloons(String text) {
        ArrayList<Integer> arr = new ArrayList<>(Collections.nCopies(26, 0));
        for(int i=0;i<text.length();i++)
        {
            int indx = text.charAt(i)-'a';
            arr.set(indx, arr.get(indx)+1);
        }
        return Math.min(arr.get(0),Math.min(arr.get(1),Math.min(arr.get(13),Math.min(arr.get(11)/2,arr.get(14)/2))));
    }
}