class FoodRatings {
    map<string,string>foodcus;
    map<string,map<int,set<string>>>cusrat;
    map<string,int>foorat;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++)
        {
            foodcus[foods[i]]=cuisines[i];
            cusrat[cuisines[i]][ratings[i]].insert(foods[i]);
            foorat[foods[i]]=ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        int prev=foorat[food];
        foorat[food]=newRating;
        string cus=foodcus[food];
        cusrat[cus][prev].erase(food);
        if(cusrat[cus][prev].size()==0)
            cusrat[cus].erase(prev);
        cusrat[cus][newRating].insert(food);
    }
    
    string highestRated(string cuisine) {
        return *cusrat[cuisine].rbegin()->second.begin();
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */