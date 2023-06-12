class SnapshotArray {
public:
    map<int,int>*arr;
    int snap_id;
    SnapshotArray(int length) {
        arr=new map<int,int>[length];
        // initially all zero;
        for(int i=0;i<length;i++)
            arr[i][0]=0;
        snap_id=0;
    }
    
    void set(int index, int val) {
        arr[index][snap_id]=val;
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        if(!arr[index].count(snap_id))
        {
           return (--arr[index].lower_bound(snap_id))->second;
        }
        return arr[index].lower_bound(snap_id)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */