class Bank {
public:
    vector<long long> balance;
    Bank(vector<long long>& balance) {
        for (auto b : balance) {
            this->balance.push_back(b);
        }
    }

    bool transfer(int account1, int account2, long long money) {
        if(!isValidAccount(account1)||!isValidAccount(account2)){
            return false;
        }
        if (withdraw(account1, money) && deposit(account2, money)) {
            return true;
        }
        return false;
    }

    bool deposit(int account, long long money) {
        if (!isValidAccount(account))
            return false;
        balance[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (!isValidAccount(account) || !hasAtleastBalance(account,money)) {
            return false;
        }
        balance[account - 1] -= money;
        return true;
    }
    private : 
    bool isValidAccount(int account){
        return account <= balance.size();
    }
    bool hasAtleastBalance(int account,long long money){
        return isValidAccount(account)&&balance[account - 1] >= money;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */