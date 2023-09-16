#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int>& A, int N, int X, int Y) {
    vector<int> dp(N + 1, int INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= min(i, X); j++) {
            dp[i] = min(dp[i], dp[i - j * Y] + accumulate(A.begin() + i - j * Y, A.begin() + i, 0));
        }
    }

    return dp[N];
}

int main() {
    vector<int> A1 = {4, 2, 3, 71};
    int N1 = 4, X1 = 2, Y1 = 2;
    cout << solution(A1, N1, X1, Y1) << endl; // Output: 7

    vector<int> A2 = {10, 3, 4, 71};
    int N2 = 4, X2 = 2, Y2 = 3;
    cout << solution(A2, N2, X2, Y2) << endl; // Output: 17

    vector<int> A3 = {4, 2, 5, 4, 3, 5, 1, 4, 2, 71};
    int N3 = 10, X3 = 3, Y3 = 2;
    cout << solution(A3, N3, X3, Y3) << endl; // Output: 6

    return 0;
}
