#include <iostream>
#include <vector>
#include <set>

class Solution{
public:
    bool uniqueOccurrences(std::vector<int>& arr);
};

bool Solution::uniqueOccurrences(std::vector<int>& arr){
    int a[2001] = {0};
    for(auto x : arr){
        a[x+1000]++;
    }
    std::set<int> st;
    for(int i = 0; i < 2000; ++i){
        if(a[i] && st.find(a[i]) != st.end()){
            return false;
        }
        else if(a[i]){
            st.insert(a[i]);
        }
    }
    return true;
}

int main(void){
    Solution solution;
    std::vector<int> vec = {1, 2, 2, 1, 1, 3};
	//std::vector<int> vec = {1, 2, 2, 1, 1, 3, 4, 4, 7};
    std::cout << solution.uniqueOccurrences(vec) << std::endl;
    return 0;
}
