#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <string>

// 1. Brute-Force Implementation using nested iteration
std::pair<int,int> twoSumBruteForce(const std::vector<int>& nums, int target) {
    for (size_t i = 0; i < nums.size(); ++i) {
        for (size_t j = i + 1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] == target) {
                return {static_cast<int>(i), static_cast<int>(j)};
            }
        }
    }
    return {-1, -1}; // Return sentinel if not found
}

// 2. Hash-Based Implementation for linear execution time
std::pair<int,int> twoSumHash(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> index_map;
    for (size_t i = 0; i < nums.size(); ++i) {
        int needed = target - nums[i];
        if (index_map.count(needed)) {
            return {index_map[needed], static_cast<int>(i)};
        }
        index_map[nums[i]] = static_cast<int>(i);
    }
    return {-1, -1};
}

// Helper function to fulfill all printing requirements
void verifyAndPrint(const std::string& label, const std::vector<int>& nums, int target, std::pair<int,int> result) {
    int idx1 = result.first;
    int idx2 = result.second;
    
    // Validate indices are within bounds and add up to the correct target
    bool valid = (idx1 != -1 && idx2 != -1 && (nums[idx1] + nums[idx2] == target) && idx1 != idx2);
    
    std::cout << "[" << label << "] Target: " << target << "\n"
              << "  Indices: [" << idx1 << ", " << idx2 << "]\n"
              << "  Values:  [" << nums[idx1] << ", " << nums[idx2] << "]\n"
              << "  Valid:   " << (valid ? "TRUE" : "FALSE") << "\n\n";
}

int main() {
    // Required Core Test Case
    std::vector<int> core_nums = {15, 4, 18, 8, 19, 22, 24, 59, 59, 20, 18, 12, 36, 42, 9};
    int core_target = 24;
    
    verifyAndPrint("Required Case (Brute Force)", core_nums, core_target, twoSumBruteForce(core_nums, core_target));
    verifyAndPrint("Required Case (Hash Table)", core_nums, core_target, twoSumHash(core_nums, core_target));

    // Additional Test Case 1: Elements are adjacent
    std::vector<int> test2 = {5, 12, 7, 3};
    verifyAndPrint("Add. Test 1 (Hash)", test2, 19, twoSumHash(test2, 19));

    // Additional Test Case 2: Identical elements forming the sum (e.g. 3 + 3 = 6)
    std::vector<int> test3 = {10, 3, 4, 3, 8};
    verifyAndPrint("Add. Test 2 (Hash)", test3, 6, twoSumHash(test3, 6));

    // Additional Test Case 3: Negative numbers involved
    std::vector<int> test4 = {-5, 1, 4, -2, 8};
    verifyAndPrint("Add. Test 3 (Hash)", test4, 2, twoSumHash(test4, 2));

    // Additional Test Case 4: Target contains large values
    std::vector<int> test5 = {100, 200, 500, 300};
    verifyAndPrint("Add. Test 4 (Hash)", test5, 800, twoSumHash(test5, 800));

    return 0;
}
