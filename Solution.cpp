#include <vector>
#include <iostream>
#include <numeric>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();  // Get the number of students (size of ratings list)
        
        // Initialize a vector to store the number of candies each student gets
        // Initially, every student gets 1 candy.
        vector<int> candies_For_Each_Student(n, 1);  
        
        // Flag to track if any changes were made during the current pass
        bool changes_Made = false;

        // Continue looping as long as changes are made during a pass
        while(!changes_Made) {
            // Traverse through the ratings list to check each student's candy count
            for(int index = 0; index < n; ++index) {
                
                // Check if the current student has a higher rating than the previous student
                // and if they do not have more candies than the previous student
                if(index-1 >= 0 &&  // Ensure we are not out of bounds
                    ratings[index] > ratings[index-1] &&  // If current student has a higher rating
                    candies_For_Each_Student[index] <= candies_For_Each_Student[index-1]) {  // If candies are not enough
                
                    changes_Made = true;  // Mark that a change was made
                    // Update the current student's candy count to be one more than the previous student's candy count
                    // Use the max to avoid reducing the candy count if it's already correct
                    candies_For_Each_Student[index] = max(candies_For_Each_Student[index-1], candies_For_Each_Student[index]) + 1;
                }
                
                // Check if the current student has a higher rating than the next student
                // and if they do not have more candies than the next student
                if(index+1 < n &&  // Ensure we are not out of bounds
                    ratings[index] > ratings[index+1] &&  // If current student has a higher rating
                    candies_For_Each_Student[index] <= candies_For_Each_Student[index+1]) {  // If candies are not enough
                    
                    changes_Made = true;  // Mark that a change was made
                    // Update the current student's candy count to be one more than the next student's candy count
                    // Use the max to avoid reducing the candy count if it's already correct
                    candies_For_Each_Student[index] = max(candies_For_Each_Student[index+1], candies_For_Each_Student[index]) + 1;
                }
            }

            // If any changes were made during this pass, reset the flag and continue checking
            // If no changes were made, exit the loop
            if(changes_Made) {
                changes_Made = false;  // Reset the flag for the next iteration
            } else {
                break;  // No changes were made, break out of the while loop
            }
        }

        // Return the total number of candies distributed, which is the sum of all elements in candies_For_Each_Student
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