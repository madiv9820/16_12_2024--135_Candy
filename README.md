- ## Approach 2:- Greedy

    - ### Intuition
        The goal is to distribute candies to students based on their ratings, ensuring that:
        1. Each student receives at least one candy.
        2. A student with a higher rating than their neighbors should receive more candies than them.

        To achieve this, we use a **two-pass approach**:
        1. **First pass (left to right)**: In this pass, we ensure that if a student has a higher rating than the student before them, they receive more candies.
        2. **Second pass (right to left)**: In this pass, we ensure that if a student has a higher rating than the student after them, they receive more candies.

        By the end of these two passes, all conditions will be satisfied, and we can sum up the total number of candies.

    - ### Approach
        1. **Initialization**:
            - We begin by assigning 1 candy to each student because every student should receive at least one candy.

        2. **First Pass (left to right)**:
            - We loop through the list of ratings starting from the second student.
            - If the current student's rating is higher than the previous student's rating, we increment the current student's candy count to be one more than the previous student's candy count. This ensures that the candies distribution respects the increasing ratings condition.

        3. **Second Pass (right to left)**:
            - We then loop through the list from the second last student to the first student.
            - If the current student's rating is higher than the next student's rating, we update the current student's candy count to be the maximum of their current candy count or one more than the next student's candy count. This ensures that the candies distribution respects the decreasing ratings condition.

        4. **Final Calculation**:
            - Once both passes are completed, we sum up all the candy counts to get the total number of candies required.

    - ### Code Implementation
        - **Python Solution**
            ```python3 []
            class Solution:
                def candy(self, ratings: List[int]) -> int:
                    n = len(ratings)  # Get the number of students (or the length of the ratings list)
                    
                    # Initialize a list to track the number of candies each student gets
                    # Initially, every student gets 1 candy.
                    candies_For_Each_Student = [1] * n
                    
                    # First pass (left to right): Ensure that if a student has a higher rating than the previous one, 
                    # they receive more candies than that student.
                    for index in range(1, n):  # Start from the second student
                        if ratings[index] > ratings[index - 1]:  # If current student's rating is higher than the previous one
                            # Ensure the current student gets more candies than the previous student.
                            # If it's not already the case, update the candies for the current student.
                            if candies_For_Each_Student[index] <= candies_For_Each_Student[index - 1]:
                                candies_For_Each_Student[index] = candies_For_Each_Student[index - 1] + 1
                    
                    # Second pass (right to left): Ensure that if a student has a higher rating than the next one, 
                    # they get more candies than the next student.
                    for index in range(n - 2, -1, -1):  # Start from the second last student and move leftwards
                        if ratings[index] > ratings[index + 1]:  # If current student's rating is higher than the next one
                            # Ensure the current student gets more candies than the next student.
                            # If it's not already the case, update the candies for the current student.
                            if candies_For_Each_Student[index] <= candies_For_Each_Student[index + 1]:
                                candies_For_Each_Student[index] = candies_For_Each_Student[index + 1] + 1
                    
                    # The total number of candies is the sum of candies for each student.
                    return sum(candies_For_Each_Student)
            ```
        - **C++ Solution**
            ```cpp []
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
            ```

    - ### Time Complexity
        - The **first pass** (left to right) takes **$O(n)$** time, where $n$ is the number of students, because we iterate through the list once.
        - The **second pass** (right to left) also takes **$O(n)$** time.
        - The **final summation** of the candy counts takes **$O(n)$** time.

        Thus, the overall **time complexity** is **$O(n)$**.

    - ### Space Complexity
        - We use an array to store the candy count for each student, which requires **$O(n)$** space.

        Thus, the overall **space complexity** is **$O(n)$**.