Problem :
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

Solution Explanation : O(n)

This problem can be solved by taking 2 variables, one for opening and another for closing. Condition should only be applied when we reach the "*" character. For the first variable-> decrement the count of opening varaible by 1(as wee will assume that the * is a closing parameter) and for the second variable -> increment the count of closing variable by 1 as we'll assume it as a closing variable.

In each loop, if opening variable becomes less than zero, then make it 0
and if closing variable becomes false, return false.

Video Explanation -> https://youtu.be/QhPdNS143Qg
