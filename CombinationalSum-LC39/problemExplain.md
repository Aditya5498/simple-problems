Problem :- 
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

SOLUTION :- O(2^Target)

You can understand the solution from here -> https://www.youtube.com/watch?v=GBKI9VSKdGg

General discussion on how we devlop approach-

This was a problem where we have to explore all possibility, make each combination and if sum of a combination becomes equal to target sum then we have to store that possible combination in our answer array.

One more thing we have to notice here is that, for a particular element we have unlimited choice i.e we can choose a element as many times as we want.

But their is some restiction also on choosing a number.

See for every number in making our target sum, we have two possibility i.e

Whether to include that element in making our target sum.
Whether not to include that element in making our target sum.
We will try and explore each possible combination and if at a point we got our sum as zero then we will say yeah!!, we find a possible combination and include that combination in our answer.

Suppose if at any point our target sum becomes less than zero, then we will return from that point and will not explore further possibility by saying that, ok our target sum becomes negative that means from now no any combination is possible because we have given a non - negative array.

See below tree diagram for more clarity.

How Tree diagram will work-

We will make a op array, that contains all the possible combinations sum of the array.

We will start from the index 0 and as we already discussed that for each and every element we have two possibility whether to include this element in making our answer or not, so we will explore all possibilities.

op aray represents which elements this array contains now in making combination sum.

Target represents the left combination sum that we have to make. Intially it is same as the original target that we have to make.

The red cursor below the array, points that on which index we are currently standing.

If at any point our target becomes zero, then we will include that combination in our answer array saying that yes, this is an possible combination and return from there.

If at any point our target becomes less than zero, then we return from there saying that we are never able to make our cbination sum by this combination.

If at any point we cross the size of the array then we will return from there saying that no more element is left to choose.

As we dicussed for every element we have two choices whether to include in our answer or not include in our answer.

So, if we do not a include a element in our answer then without decreasing target sum, we will move to next index. Why we do not decrese sum? because we will choose not to include in this element in our combination, hence it does not contribute in making our sum.

But, if we choose a particular element to include in our answer, then we will decrease the target sum but we will not move to next index. Why we will not move to next index? because for a specific element we have unlimited number of choice, so it may be possible that specific element again contribute in making our sum.

If Image is not cleary visible to you, then for that I have uploaded it on my drive.

You may visit this link to see Image in good quality.

General discussion on how we devlop approach-

This was a problem where we have to explore all possibility, make each combination and if sum of a combination becomes equal to target sum then we have to store that possible combination in our answer array.

One more thing we have to notice here is that, for a particular element we have unlimited choice i.e we can choose a element as many times as we want.

But their is some restiction also on choosing a number.

See for every number in making our target sum, we have two possibility i.e

Whether to include that element in making our target sum.
Whether not to include that element in making our target sum.
We will try and explore each possible combination and if at a point we got our sum as zero then we will say yeah!!, we find a possible combination and include that combination in our answer.

Suppose if at any point our target sum becomes less than zero, then we will return from that point and will not explore further possibility by saying that, ok our target sum becomes negative that means from now no any combination is possible because we have given a non - negative array.

See below tree diagram for more clarity.

How Tree diagram will work-

We will make a op array, that contains all the possible combinations sum of the array.

We will start from the index 0 and as we already discussed that for each and every element we have two possibility whether to include this element in making our answer or not, so we will explore all possibilities.

op aray represents which elements this array contains now in making combination sum.

Target represents the left combination sum that we have to make. Intially it is same as the original target that we have to make.

The red cursor below the array, points that on which index we are currently standing.

If at any point our target becomes zero, then we will include that combination in our answer array saying that yes, this is an possible combination and return from there.

If at any point our target becomes less than zero, then we return from there saying that we are never able to make our cbination sum by this combination.

If at any point we cross the size of the array then we will return from there saying that no more element is left to choose.

As we dicussed for every element we have two choices whether to include in our answer or not include in our answer.

So, if we do not a include a element in our answer then without decreasing target sum, we will move to next index. Why we do not decrese sum? because we will choose not to include in this element in our combination, hence it does not contribute in making our sum.

But, if we choose a particular element to include in our answer, then we will decrease the target sum but we will not move to next index. Why we will not move to next index? because for a specific element we have unlimited number of choice, so it may be possible that specific element again contribute in making our sum.

I've attached a tree diagram in this repo, please look at that image for further understanding