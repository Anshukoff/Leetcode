#include <iostream>
#include <vector>
#include <algorithm>

class Solution{
public:
    std::vector<std::vector<int>> minimumAbsDifference(std::vector<int>& arr);
};

std::vector<std::vector<int>> Solution::minimumAbsDifference(std::vector<int>& arr){
    std::sort(arr.begin(), arr.end());
    std::vector<std::vector<int>> res;
    int min = INT_MAX;
    int arrSize = arr.size();
    for(int i = 1; i < arrSize; ++i){
        int diff = arr[i] - arr[i-1];
        if(diff < min){
            min = diff;
        }
    }
    for(int i = 1; i < arrSize; ++i){
        if(arr[i] - arr[i-1] == min){
            res.push_back({arr[i-1], arr[i]});
        }
    }
    return res;
}

int main()
{
    std::vector<int> inputVec = {3,8,-10,23,19,-4,-14,27};
    Solution solution;
    std::vector<std::vector<int>> result = solution.minimumAbsDifference(inputVec);
    for (std::vector<int> a : result){
        for (int b : a){
            std::cout << b << " ";
        }
    }
    return 0;
}
