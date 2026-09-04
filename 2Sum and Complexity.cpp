#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twosum(const vector<int>& nums, int target){
    unordered_map<int, int> index;
    
    for (int i = 0; i < nums.size(); i++){
        int needed = target - nums[i];
        
        if (index.count(needed)) {
            return {index[needed], i};
        }
        
        index[nums[i]] = i;
    }
    
    return{};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    vector<int> answer = twosum(nums, target);
    
    if (!answer.empty()) {
        cout << "indices: [" << answer[0];
		cout << ", " << answer[1] << "]" << endl;	
    }
}