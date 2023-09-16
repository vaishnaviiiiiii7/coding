#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int N, vector<int>& A, vector<int>& B) {
    vector<vector<int>> graph(N);
    vector<int> degree(N, 0);
    
    for (int i = 0; i < A.size(); i++) {
        graph[A[i]].push_back(B[i]);
        graph[B[i]].push_back(A[i]);
        degree[A[i]]++;
        degree[B[i]]++;
    }
    
    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (degree[i] <= 1) {
            q.push(i);
        }
    }
    
    int seconds = 0;
    while (!q.empty()) {
        int numVerticesToRemove = q.size();
        while (numVerticesToRemove--) {
            int vertex = q.front();
            q.pop();
            degree[vertex] = 0; // Mark this vertex as removed
            
            for (int neighbor : graph[vertex]) {
                if (degree[neighbor] > 0) {
                    degree[neighbor]--;
                    if (degree[neighbor] <= 1) {
                        q.push(neighbor);
                    }
                }
            }
        }
        seconds++;
    }
    
    for (int i = 0; i < N; i++) {
        if (degree[i] > 0) {
            return 0; // There are remaining vertices with more than one edge, so they won't disappear.
        }
    }
    
    return seconds;
}

int main() {
    int N1 = 7;
    vector<int> A1 = {0, 1, 2, 1, 4, 4};
    vector<int> B1 = {1, 2, 0, 4, 5, 6};
    cout << solution(N1, A1, B1) << endl; // Output: 2

    int N2 = 7;
    vector<int> A2 = {0, 1, 2, 4, 5};
    vector<int> B2 = {1, 2, 3, 5, 6};
    cout << solution(N2, A2, B2) << endl; // Output: 2

    return 0;
}
