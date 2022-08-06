Given two strings ‘X’ and ‘Y’, find the length of the longest common substring. 

Examples : 

Input : X = “GeeksforGeeks”, y = “GeeksQuiz” 
Output : 5 
Explanation:
The longest common substring is “Geeks” and is of length 5.

Input : X = “abcdxyz”, y = “xyzabcd” 
Output : 4 
Explanation:
The longest common substring is “abcd” and is of length 4.

Input : X = “zxabcdezy”, y = “yzabcdezx” 
Output : 6 
Explanation:
The longest common substring is “abcdez” and is of length 6.

Approach:
Let m and n be the lengths of the first and second strings respectively.

A simple solution is to one by one consider all substrings of the first string and for every substring check if it is a substring in the second string. Keep track of the maximum length substring. There will be O(m^2) substrings and we can find whether a string is substring on another string in O(n) time. So overall time complexity of this method would be O(n * m2)

Dynamic Programming can be used to find the longest common substring in O(m*n) time. The idea is to find the length of the longest common suffix for all substrings of both strings and store these lengths in a table. 

😀😁😂🤣😃😄😅😆😉😊😋😎😍😘🥰😗🙂☺🤔🤨😐😑😶🙄😏😜

Solution :- 
Brute force way -> For each and every character find the subsequence between both of the strings, this will give O(N^4) time complexity. 😫

The best way to solve this problem is through Dynamic Programming - O(n^2). See below for further explanation,

Construct a 2D array Arr[][]. While using 2 for loops and passing through each and every postion of the array, check if the string1[i]==string2[j], if yes, then increment the value of the present position by 1 comparing from the diagonal value of the previous index. For ex, when a match has been found Arr[i][j]=Arr[i-1][j-1]+1;

Find the max value from the array.

For detailed explanation, please watch the below videos

1)https://www.youtube.com/watch?v=Ua0GhsJSlWM&t=932s
2)https://www.youtube.com/watch?v=UZRkpGk943Q&t=955s