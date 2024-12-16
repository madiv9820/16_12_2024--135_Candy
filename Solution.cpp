#include <vector>
#include <iostream>
#include <numeric>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();  // Get the number of students (size of ratings array)
        
        // Initialize a vector to keep track of the candies each student receives.
        // Initially, every student gets 1 candy.
        vector<int> candies_For_Each_Student(n, 1); 

        // First pass (left to right): If the current student's rating is higher than the previous one,
        // give the current student more candies than the previous one.
        for(int index = 1; index < n; ++index) {  // Loop through the ratings from the second student onwards
            if(ratings[index] > ratings[index-1]) {  // If current student's rating is greater than previous student's rating
                // Ensure the current student gets more candies than the previous one, if not already the case
                if(candies_For_Each_Student[index] <= candies_For_Each_Student[index-1]) {
                    candies_For_Each_Student[index] = candies_For_Each_Student[index-1] + 1;  // Give one more candy than the previous student
                }
            }
        }

        // Second pass (right to left): If the current student's rating is higher than the next one,
        // give the current student more candies than the next one.
        for(int index = n-2; index >= 0; --index) {  // Loop through the ratings from second last student to the first student
            if(ratings[index] > ratings[index+1]) {  // If current student's rating is greater than the next student's rating
                // Ensure the current student gets more candies than the next one, if not already the case
                if(candies_For_Each_Student[index] <= candies_For_Each_Student[index+1]) {
                    candies_For_Each_Student[index] = candies_For_Each_Student[index+1] + 1;  // Give one more candy than the next student
                }
            }
        }

        // Finally, return the total number of candies distributed to all students.
        // We sum all the values in the candies_For_Each_Student vector.
        return accumulate(candies_For_Each_Student.begin(), candies_For_Each_Student.end(), 0);
    }
};

int main() {
    vector<vector<int>> ratings = {{1,0,2},{1,2,2}};
    vector<int> output = {5,4};
    Solution sol;

    for(int index = 0; index < ratings.size(); ++index) {
        int result = sol.candy(ratings[index]);
        cout << ((result == output[index]) ? "true":"false") << endl;
    }
}