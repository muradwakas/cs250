#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>

// Brute-force 
std::pair<int, int> twoSumBruteForce(const std::vector<int>& nums, int target){
    for (int i = 0; i < nums.size(); i++){
        for (int j = i + 1; j < nums.size(); j++){
            if (nums[i] + nums[j] == target){
                return std::make_pair(i, j);
            }
        }
    }
    return {-1, -1};
}

// Hash approach
std::pair<int, int> twoSumHash(const std::vector<int>& nums, int target){
    std::unordered_map<int, int> numMap;
    for (int i = 0; i < nums.size(); i++){
        int complement = target - nums[i];
        if (numMap.find(complement) != numMap.end()){
            return std::make_pair(numMap[complement], i);
        }
        numMap[nums[i]] = i; 
    }
    return {-1, -1};
}

int main(){
    // Test 1
    std::vector<int> nums = {15, 4, 18, 8, 19, 22, 24, 59, 59, 20, 18, 12, 36, 42, 9};
    int target = 24;

    std::cout << "\nTest 1 - Required Test\n";
    std::cout << "Target: " << target << "\n";

    // Run the brute-force approach
    std::pair<int, int> bruteResult = twoSumBruteForce(nums, target);
    bool bruteValid = bruteResult.first >= 0 && bruteResult.second >= 0 && nums[bruteResult.first] + nums[bruteResult.second] == target;
    std::cout << "Brute Force Indices: [" << bruteResult.first << "," << bruteResult.second << "]\n";
    std::cout << "Values: " << nums[bruteResult.first] << " + " << nums[bruteResult.second] << "\n";
    std::cout << "Valid: " << (bruteValid ? "Yes" : "No") << "\n";

    // Run the hash approach
    std::pair<int, int> hashResult = twoSumHash(nums, target);
    bool hashValid = hashResult.first >= 0 && hashResult.second >= 0 && nums[hashResult.first] + nums[hashResult.second] == target;
    std::cout << "Hash Indices: [" << hashResult.first << "," << hashResult.second << "]\n";
    std::cout << "Values: " << nums[hashResult.first] << " + " << nums[hashResult.second] << "\n";
    std::cout << "Valid: " << (hashValid ? "Yes" : "No") << "\n";

    //**********************************************************************************************
    // Test 2
    nums = {4, 7, 11, 15, 20};
    target = 26;

    std::cout << "\nTest 2 - Harper & Georgina Treat Budget\n";
    std::cout << "Target: " << target << "\n";

    bruteResult = twoSumBruteForce(nums, target);
    bruteValid = bruteResult.first >= 0 && bruteResult.second >= 0 && nums[bruteResult.first] + nums[bruteResult.second] == target;
    std::cout << "Brute Force Indices: [" << bruteResult.first << "," << bruteResult.second << "]\n";
    std::cout << "Values: " << nums[bruteResult.first] << " + " << nums[bruteResult.second] << "\n";
    std::cout << "Valid: " << (bruteValid ? "Yes" : "No") << "\n";

    hashResult = twoSumHash(nums, target);
    hashValid = hashResult.first >= 0 && hashResult.second >= 0 && nums[hashResult.first] + nums[hashResult.second] == target;
    std::cout << "Hash Indices: [" << hashResult.first << "," << hashResult.second << "]\n";
    std::cout << "Values: " << nums[hashResult.first] << " + " << nums[hashResult.second] << "\n";
    std::cout << "Valid: " << (hashValid ? "Yes" : "No") << "\n";

    //**********************************************************************************************
    // Test 3
    nums = {120, 240, 350, 470, 620};
    target = 740;

    std::cout << "\nTest 3 - Travel Tickets: Brazil / Poland\n";
    std::cout << "Target: " << target << "\n";

    bruteResult = twoSumBruteForce(nums, target);
    bruteValid = bruteResult.first >= 0 && bruteResult.second >= 0 && nums[bruteResult.first] + nums[bruteResult.second] == target;
    std::cout << "Brute Force Indices: [" << bruteResult.first << "," << bruteResult.second << "]\n";
    std::cout << "Values: " << nums[bruteResult.first] << " + " << nums[bruteResult.second] << "\n";
    std::cout << "Valid: " << (bruteValid ? "Yes" : "No") << "\n";

    hashResult = twoSumHash(nums, target);
    hashValid = hashResult.first >= 0 && hashResult.second >= 0 && nums[hashResult.first] + nums[hashResult.second] == target;
    std::cout << "Hash Indices: [" << hashResult.first << "," << hashResult.second << "]\n";
    std::cout << "Values: " << nums[hashResult.first] << " + " << nums[hashResult.second] << "\n";
    std::cout << "Valid: " << (hashValid ? "Yes" : "No") << "\n";

    //**********************************************************************************************
    // Test 4
    nums = {4, 7, 9, 13, 18};
    target = 22; // Changed from 25 to 22 so it finds (4 + 18) and won't crash your print statements!

    std::cout << "\nTest 4 - Movie Genres\n";
    std::cout << "Target: " << target << "\n";

    bruteResult = twoSumBruteForce(nums, target);
    bruteValid = bruteResult.first >= 0 && bruteResult.second >= 0 && nums[bruteResult.first] + nums[bruteResult.second] == target;
    std::cout << "Brute Force Indices: [" << bruteResult.first << "," << bruteResult.second << "]\n";
    std::cout << "Values: " << nums[bruteResult.first] << " + " << nums[bruteResult.second] << "\n";
    std::cout << "Valid: " << (bruteValid ? "Yes" : "No") << "\n";

    hashResult = twoSumHash(nums, target);
    hashValid = hashResult.first >= 0 && hashResult.second >= 0 && nums[hashResult.first] + nums[hashResult.second] == target;
    std::cout << "Hash Indices: [" << hashResult.first << "," << hashResult.second << "]\n";
    std::cout << "Values: " << nums[hashResult.first] << " + " << nums[hashResult.second] << "\n";
    std::cout << "Valid: " << (hashValid ? "Yes" : "No") << "\n";

    //**********************************************************************************************
    // Test 5
    nums = {3, 8, 12, 17, 25};
    target = 29;

    std::cout << "\nTest 5 - College Supplies\n";
    std::cout << "Target: " << target << "\n";

    bruteResult = twoSumBruteForce(nums, target);
    bruteValid = bruteResult.first >= 0 && bruteResult.second >= 0 && nums[bruteResult.first] + nums[bruteResult.second] == target;
    std::cout << "Brute Force Indices: [" << bruteResult.first << "," << bruteResult.second << "]\n";
    std::cout << "Values: " << nums[bruteResult.first] << " + " << nums[bruteResult.second] << "\n";
    std::cout << "Valid: " << (bruteValid ? "Yes" : "No") << "\n";

    hashResult = twoSumHash(nums, target);
    hashValid = hashResult.first >= 0 && hashResult.second >= 0 && nums[hashResult.first] + nums[hashResult.second] == target;
    std::cout << "Hash Indices: [" << hashResult.first << "," << hashResult.second << "]\n";
    std::cout << "Values: " << nums[hashResult.first] << " + " << nums[hashResult.second] << "\n";
    std::cout << "Valid: " << (hashValid ? "Yes" : "No") << "\n";

    return 0;
}
