### String Generation 1
Given M strings you are required to find the count of all strings of length N that contain at least K strings from the M strings as substrings. You are required to answer the question above using brute force implemented using recursion.

Input Format

The first line will contain M, N, and K in this exact order.
The next M lines will contain a string each
Constraints

1 <= M <= 7
1 <= N <= 7
1 <= K <= M
1 <= Length of the M strings <= N
All strings will contain capital letters between A and E inclusive.
Output Format

The number of strings satisfying the condition.

Sample Input 0

2 3 1
AE
AD
Sample Output 0

20
Explanation 0

The strings satisfying the condition are: AAD, AAE, ADA, ADB, ADC, ADD, ADE, AEA, AEB, AEC, AED, AEE, BAD, BAE, CAD, CAE, DAD, DAE, EAD, EAE

Sample Input 1

2 3 2
AD
AEC
Sample Output 1

0