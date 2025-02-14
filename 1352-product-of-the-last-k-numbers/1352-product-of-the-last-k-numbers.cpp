class ProductOfNumbers {
public:
    vector<int> pp;
    int size = 0;
    ProductOfNumbers() {
        pp.push_back(1);
        size = 0;

    }
    
    void add(int num) {
        if(num==0){
            pp = {1};
            size = 0;
        }
        else{
            pp.push_back(pp[size] * num);
            size++;
        }
        
    }
    
    int getProduct(int k) {
        if(k>size) return 0;

        return pp[size]/pp[size-k];

        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */