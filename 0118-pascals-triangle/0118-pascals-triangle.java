class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> pascal = new ArrayList<>();
        for(int i=1;i<=numRows;i++)
        {
            List<Integer> arr = new ArrayList<> (Collections.nCopies(i, 1));
            for(int j=1;j<i-1;j++)
            {
                arr.set(j,pascal.get(i-2).get(j)+pascal.get(i-2).get(j-1));
            }
            pascal.add(arr);
        }
        return pascal;
    }
}