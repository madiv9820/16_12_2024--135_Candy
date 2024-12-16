from typing import List

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