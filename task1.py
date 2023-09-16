#A patient needs rehabilitation within the next N days (numbered from 0 to N-1).
#The rehabilitation consists of X sessions. For every rehabilitation session, other than the last one, the next session is exactly Y days later.
#You are given an array A of N integers listing the costs of the individual rehabilitation sessions on the N days: that is rehabilitation on the K-th day costs
#AlKI.
#Write a function:
#int solution (int A[l, int N, int X, int Y);
#that, given the array A and the two integers X and Y, returns the minimum cost of rehabilitation.
#It is guaranteed that it is always possible toh&omplete all X rehabilitation
#sessions.
#Examples 1. Given A - [4, 2, 3, 71, X = 2 and Y = 2, your function should return 7, which is the sum of the costs on days 0 and 2 (7 = 4 + 3).
#2. Given A = [10, 3, 4, 71, X = 2 and Y = 3, your function should return 17 since rehabilitation is possible only on days 0 and 3 (17 = 10 + 7).
#3. Given A = (4, 2, 5, 4, 3, 5, 1, 4, 2, 71, X - 3 and Y = 2, your function should return 6,which is the sum of the costs on days 4, 6 and 8 (6 = 3 + 1 + 2).
#Write an efficient algorithm for the following assumptions:
#• N and X are integers within the range [2..200,000);
#• each element of array A is an integer within the range  [1..1,000];
#• Y is an integer within the range [1..199,999);
#• N is higher than (X - 1) * Y.

#you can write to stdout for debugging purposes, e.g.
#print("this is a debug message")

def solution(A, N, X, Y):
    #calculating the number of sessions required 
    num_sessions=X

    #intializing a list to store the minimum cost ypto each day 
    dp = [float('inf')]*N

#initailizing the first session cost 
dp[num_sessions-1]=sum(A[:num_sessions])

#iterating through the days starting from day X-1
for day in range(X,N):
    #calculating the cost of the current session 
    current_session_cost=sum(A[day-X+1:day+1])
    
    #updating the minimum cost for the current day 
    dp[day]=min(dp[day],dp[day-Y]+current_session_cost)

#the minimum cost will be on the last day
return dp[-1]

    #test cases 
    print("this is a debug message")
