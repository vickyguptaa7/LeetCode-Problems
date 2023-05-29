class ParkingSystem {
public:
    vector<int>capacity;
    ParkingSystem(int big, int medium, int small) {
        capacity.resize(3,0);
        capacity[0]=big;
        capacity[1]=medium;
        capacity[2]=small;
    }
    
    bool addCar(int carType) {
        if(capacity[carType-1])
        {
            --capacity[carType-1];
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */