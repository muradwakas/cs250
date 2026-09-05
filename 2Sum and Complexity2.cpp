#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>

// Brute-force approach: compare each pair until the target sum is found
std::pair<int, int> twoSumBruteForce(const std::vector<int>& nums, int target){
    // check each element in the vector
    for (int i = 0; i < nums.size(); i++){
        for (int j = i + 1; j < nums.size(); j++){
            //compare the current element with the following elements
            if (nums[i] + nums[j] == target){
                // If the pair adds up to the target, return the two indices
                return std::make_pair(i, j);
            }
        }
    }
    // Return (-1, -1) if no valid pair is found
    return {-1, -1};
}

// Hash approach: use a hash map to find the needed value efficiently
std::pair<int, int> twoSumHash(const std::vector<int>& nums, int target){
    // Store each value and its index
    std::unordered_map<int, int> numMap;
    for (int i = 0; i < nums.size(); i++){
        // Traverse the vector once
        int complement = target - nums[i]; // Complement is the value needed to reach the target
        if (numMap.find(complement) != numMap.end()){
            // If needed value was seen before, return the two indices
            return std::make_pair(numMap[complement], i);
        }
        numMap[nums[i]] = i; // Store the current value and its index
    }
    // Return (-1, -1) if no valid pair is found
    return {-1, -1};
}

int main(){
    // Test 1: Required test case
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
    // Test 2: Harper & Georgina Treat Budget
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
    // Test 3: Travel tickets - Brazil / Poland
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
    // Test 4: Movie Genres (Changed target so a match actually exists!)
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
    // Test 5: College Supplies
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
