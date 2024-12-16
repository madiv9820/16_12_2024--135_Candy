- ## Approach 1:- Brute Force

    - ### Intuition
        The goal of this problem is to distribute candies to students based on their ratings, ensuring the following conditions:
        1. Each student must receive at least one candy.
        2. If a student has a higher rating than their neighbors, they should receive more candies than those neighbors.

        We can approach this problem by iterating over the ratings multiple times, adjusting the candy counts based on the above conditions. The process stops when no more changes need to be made.

    - ### Approach
        1. **Initialization**:
            - We initialize a `candies_For_Each_Student` array where each student initially gets 1 candy.
        
        2. **Multiple Passes (Repeated Adjustments)**:
            - We perform multiple passes over the `ratings` array. In each pass, we check each student's candy count:
                - **Left Neighbor**: If a student has a higher rating than the previous student and their candy count is not greater than the previous student's candy count, we update the current student's candy count.
                - **Right Neighbor**: Similarly, if a student has a higher rating than the next student and their candy count is not greater than the next student's candy count, we update the current student's candy count.
        
        3. **Changes Flag**:
            - A flag (`changes_Made`) is used to track whether any updates are made during a pass. If no changes are made during an entire pass, the process terminates, ensuring that the candy distribution has stabilized.

        4. **Termination**:
            - The loop continues until no changes are made in a full pass, meaning the candy counts are finalized.

        5. **Final Calculation**:
            - Once the candy distribution is stable, we return the sum of all candy counts to get the total number of candies required.

    - ### Code Implementation
        - **Python Solution**
            ```python3 []
            class Solution:
                def candy(self, ratings: List[int]) -> int:
                    n = len(ratings)  # Get the number of students (size of the ratings list)
                    
                    # Initialize a list to store the number of candies each student gets
                    # Initially, every student gets 1 candy.
                    candies_For_Each_Student = [1] * n
                    
                    # This flag will help to track if any changes were made during a pass.
                    changes_Made = False

                    # We will keep making passes over the ratings until no changes are made in a pass.
                    while not changes_Made:
                        # Traverse the ratings list to compare each student's rating with their neighbors
                        for index in range(n):
                            
                            # Check if the current student has a higher rating than the previous student
                            # and if they do not have more candies than the previous student
                            if (index - 1 >= 0 and 
                                ratings[index] > ratings[index - 1] and 
                                candies_For_Each_Student[index] <= candies_For_Each_Student[index - 1]):
                                # If the conditions are met, update the current student's candy count
                                # to be 1 more than the previous student's candy count.
                                candies_For_Each_Student[index] = max(candies_For_Each_Student[index], candies_For_Each_Student[index - 1]) + 1
                                changes_Made = True  # A change was made, so we need to continue checking in the next pass

                            # Check if the current student has a higher rating than the next student
                            # and if they do not have more candies than the next student
                            if (index + 1 < n and 
                                ratings[index] > ratings[index + 1] and 
                                candies_For_Each_Student[index] <= candies_For_Each_Student[index + 1]):
                                # If the conditions are met, update the current student's candy count
                                # to be 1 more than the next student's candy count.
                                candies_For_Each_Student[index] = max(candies_For_Each_Student[index], candies_For_Each_Student[index + 1]) + 1
                                changes_Made = True  # A change was made, so we need to continue checking in the next pass
                        
                        # If changes were made during this pass, set changes_Made to False to check again in the next pass
                        if changes_Made:
                            changes_Made = False  # Reset the flag for the next iteration
                        else:
                            break  # No changes were made, so we can break out of the loop and stop checking

                    # After all the passes, return the total number of candies distributed
                    return sum(candies_For_Each_Student)
            ```
        - **C++ Solution**
            ```cpp []
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
            ```

    - ### Time Complexity
        - **Worst Case**: In the worst case, the algorithm may need multiple passes over the ratings list. Each pass checks the entire list of students, which results in a time complexity of **$O(n^2)$**, where **$n$** is the number of students.
        - The worst case occurs when many students' candy counts are adjusted repeatedly across multiple passes.

    - ### Space Complexity
        - The space complexity is **$O(n)$**, as we use an extra array `candies_For_Each_Student` of size **$n$** to store the number of candies each student receives. This is the primary space usage in the algorithm.