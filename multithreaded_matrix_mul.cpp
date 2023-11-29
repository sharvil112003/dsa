#include <bits/stdc++.h>

using namespace std;

void Solve(const vector<vector<int>> &m1, const vector<vector<int>> &m2, vector<vector<int>> &ans, int r, int c)
{
    int res = 0;
    for (int i = 0; i < m1[r].size(); ++i)
    {
        res += m1[r][i] * m2[i][c];
    }
    ans[r][c] = res;
}

void ThreadSolve(const vector<vector<int>> &m1, const vector<vector<int>> &m2, vector<vector<int>> &ans)
{
    vector<thread> t;
    for (int i = 0; i < m1.size(); ++i)
    {
        for (int j = 0; j < m2[0].size(); ++j)
        {
            t.emplace_back(Solve, cref(m1), cref(m2), ref(ans), i, j);
        }
    }
    for (auto &k : t)
        k.join();
}

int main()
{
    vector<vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> matrix2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> result(3, vector<int>(3, 0));

    ThreadSolve(matrix1, matrix2, result);
    for (int i = 0; i < result.size(); ++i)
    {
        for (int j = 0; j < result[0].size(); ++j)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}