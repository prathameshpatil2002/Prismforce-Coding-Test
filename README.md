# Prismforce Coding Test 

## Problem statement 

Imagine Abhimanyu in Chakravyuha. There are 11 circles in the Chakravyuha surrounded by
different enemies. Abhimanyu is located in the innermost circle and has to cross all the 11
circles to reach Pandavas army back.
Given:
Each circle is guarded by different enemy where enemy is equipped with k1, k2……k11
powers
Abhmanyu start from the innermost circle with p power
Abhimanyu has a boon to skip fighting enemy a times
Abhmanyu can recharge himself with power b times
Battling in each circle will result in loss of the same power from Abhimanyu as the enemy. If
Abhmanyu enter the circle with energy less than the respective enemy, he will lose the battle
k3 and k7 enemies are endured with power to regenerate themselves once with half of their
initial power and can attack Abhimanyu from behind if he is battling in iteratively next circle
Write an algorithm to find if Abhimanyu can cross the Chakravyuh and test it with two sets of
test cases.

## Solution 

```sh
Inputs: 
- AbhimanyuPowerGlobal = initial power of abhimanyu
- a = Allowed Number of Skips
- b = Allowed Number of Recharges
- enemies = A vector containing power of the enemy inside chakravyuh
```
### Dynamic Programming Approach
- This approach is used because we have multiple options for skip and rechagres combination and can lead to overlapping subproblems with state management.
- To manage Abhimanyu's battles using a dynamic programming approach, defined a 3D DP vector to represent his state. The states are defined by:
1. The current circle he is fighting in.
2. The number of skips left denoted by a.
3. The number of recharges left denoted by b.
- The state of dp vector will store the maximum power Abhimanyu has left after battling in current circle, given the number of skips and recharges available.
- Base Case: If Abhimanyu crosses the last circle, return true.
- Logic:
  - If the current enemy's power is strictly greater than Abhimanyu's current power:
    - Abhimanyu can skip the enemy, adjusting for the cases with remaining skips and recharges.
    - Abhimanyu can recharges himself to his initial power.
  - Otherwise, Abhimanyu will fight the enemy, and we update the dp vector states accordingly.
  - The aim of function `canAbhimanyuCrossChakravyuh` is to return the power Abhimanyu has left after fighting the last enemy.

## Output
If power left for any combination of skips and recharges is positive then we will output `YES` else output `NO`.

## Testcases
I have Added test cases as in txt file with corresponding output.
