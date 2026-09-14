#include <iostream>
#include <vector>
using namespace std;

int iterativeBinarySearch(const vector<int>& arr, int x, int& comparisons) {
    int low = 0;
    int high = arr.size() - 1;
    comparisons = 0;

    while(high >= low) {
        int mid = low + (high - low) / 2;

        comparisons++;
        if(arr[mid] == x) {
            return mid;
        }

        comparisons++;
        if(arr[mid] < x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

int recursiveBinarySearch(const vector<int>& arr, int low, int high, int x, int& comparisons){
    if (high >= low) {
        int mid = low + (high-low) / 2;

        comparisons++;
        if(arr[mid] == x){
            return mid;
        }

        comparisons++;
        if (arr[mid] > x){
            return recursiveBinarySearch(arr, low, mid-1, x, comparisons);
        }
        else{
            return recursiveBinarySearch(arr, mid+1, high, x, comparisons);
        }
    }
    return -1;
}

int linearSearch(const vector<int>& arr, int x, int& comparisons){
    comparisons = 0;

    for(int i = 0; i < arr.size(); i++) {

        comparisons++;
        if(arr[i] == x){
            return i;
        }
    }
    return -1;
}

int main() {

    vector<int> arr = {
        10, 20, 30, 40, 50,
        60, 70, 80, 90, 100,
        110, 120, 130, 140, 150
    };

    // Five required tests
    vector<int> tests = {10, 150, 80, 5, 85};

    for(int x : tests) {

        int iterativeComparisons = 0;
        int recursiveComparisons = 0;
        int linearComparisons = 0;

        int iterativeResult =
            iterativeBinarySearch(arr, x, iterativeComparisons);

        int recursiveResult =
            recursiveBinarySearch(arr, 0, arr.size() - 1,
                                  x, recursiveComparisons);

        int linearResult =
            linearSearch(arr, x, linearComparisons);

        cout << "Searching for: " << x << endl;

        cout << "Iterative Binary Search: index = "
             << iterativeResult
             << ", comparisons = "
             << iterativeComparisons << endl;

        cout << "Recursive Binary Search: index = "
             << recursiveResult
             << ", comparisons = "
             << recursiveComparisons << endl;

        cout << "Linear Search: index = "
             << linearResult
             << ", comparisons = "
             << linearComparisons << endl;

        cout << "----------------------------------" << endl;
    }

    return 0;
}