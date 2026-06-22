class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int arr[26];
        memset(arr,0,sizeof(arr));
        for(auto x:text)
        {
            arr[x-'a']++;
        }
        return min({arr[0],arr[1],arr[13],arr[11]/2,arr[14]/2});
    }
};