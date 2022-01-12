//2022-01-11
class Solution {
public:
    bool is_prime(int n){
        if (n == 2) return true; 
        for (int i = 2; i < n; ++i){
            if (n%i == 0) return false;
        }
        return true; 
    }
    // // k!
    // long int perm(int k){
    //     long int product = 1;
    //     for (int i = k; i > 1; i--){
    //         product = (product * i)%num;
    //     }
    //     return product; 
    // }
    
    int numPrimeArrangements(int n) {
        int num = std::pow(10, 9) + 7; 
        int prime_count = 0; 
        for (int i = 2; i <= n; ++i){
            if (is_prime(i))
                ++prime_count;
        }
        long prod = 1; 
        for (int i = 1; i <= prime_count; ++i)
            prod = (prod*i)%num; 
        for (int i = 1; i <= (n-prime_count); ++i)
            prod = (prod*i)%num; 
        
        return prod;
    }
};
