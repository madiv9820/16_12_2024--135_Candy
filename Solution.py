from typing import List

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