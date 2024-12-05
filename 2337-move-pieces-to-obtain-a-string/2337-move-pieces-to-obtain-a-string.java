class Solution {
    public boolean canChange(String start, String target) {
        int n=start.length();
        int sid=0,tid=0;
        while(sid<n||tid<n)
        {
            while(sid<n&&start.charAt(sid)=='_')
                sid++;
            while(tid<n&&target.charAt(tid)=='_')
                tid++;
            
            if(sid==n&&tid==n)
                return true;
            if(sid==n||tid==n)
                return false;
            
            if(start.charAt(sid)!=target.charAt(tid)
               || (start.charAt(sid)=='R'&&sid>tid)
               || (start.charAt(sid)=='L'&&sid<tid))
                return false;
            sid++;
            tid++;
        }
        return sid==n&&tid==n;
    }
}