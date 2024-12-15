# [135. Candy](https://leetcode.com/problems/candy?envType=study-plan-v2&envId=top-interview-150)

**Type:** Hard <br>
**Topics:** Array, Greedy <br>
**Companies:** Amazon, Microsoft, Google, Meta, TikTok, PhonePe, Bloomberg, Flipkart, Yandex, Adobe, Goldman Sachs, Uber, ConsultAdd, Accenture
<hr>

There are `n` children standing in a line. Each child is assigned a rating value given in the integer array `ratings`.

You are giving candies to these children subjected to the following requirements:
- Each child must have at least one candy.
- Children with a higher rating get more candies than their neighbors.

Return _the minimum number of candies you need to have to distribute the candies to the children_.
<hr>

### Examples:

- **Example 1:** <br>
**Input:** ratings = [1,0,2] <br>
**Output:** 5 <br>
**Explanation:** You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

- **Example 2:** <br>
**Input:** ratings = [1,2,2] <br>
**Output:** 4 <br>
**Explanation:** You can allocate to the first, second and third child with 1, 2, 1 candies respectively. <br>
The third child gets 1 candy because it satisfies the above two conditions.
<hr>

### Constraints:
- `n == ratings.length`
- <code>1 <= n <= 2 * 10<sup>4</sup></code>
- <code>0 <= ratings[i] <= 2 * 10<sup>4</sup></code>