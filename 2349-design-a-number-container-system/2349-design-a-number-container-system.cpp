class NumberContainers {
public:
    NumberContainers() {}
    
    void change(int index, int number) {
        if(iN.find(index) != iN.end()){
            int prev = iN[index]; // the number associated with it
            nI[prev].erase(index); //simply erase it
            if(nI[prev].empty()){ // if the set is empty, then remove it
                nI.erase(prev);
            }
        }
        iN[index] = number;
        nI[number].insert(index);
        
    }
    
    int find(int number) {
        if(nI.find(number) != nI.end()){
            return *nI[number].begin();
        }
        return -1;
        
    }
private:
    unordered_map<int, set<int>> nI;
    unordered_map<int, int> iN;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */