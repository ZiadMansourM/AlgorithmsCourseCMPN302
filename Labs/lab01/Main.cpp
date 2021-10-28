#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define LOG(x) cout << x << endl

void BoosLair(const vector<vector<vector<int>>>& grid, int& min_sum, int sum, int i, int j, int k)
{
    // valid point
    if (i<0 || i>=grid.size())
        return;
    if (j<0 || j>=grid.size())
        return;
    if (k<0 || k>=grid.size())
        return;
    // sum 
    sum += grid[i][j][k];
    // check reached target 
    int target = grid.size()-1;
    if (i==target && j==target && k==target)
    {
        if (sum < min_sum)
            min_sum = sum;
        return;
    }
    // move above
    BoosLair(grid, min_sum, sum, i+1, j, k);
    // move bottom
    BoosLair(grid, min_sum, sum, i, j+1, k);
    // move right
    BoosLair(grid, min_sum, sum, i, j, k+1);
}

int main()
{
    int N;
    cin >> N;
    vector<vector<vector<int>>> grid(N, vector<vector<int>>(N, vector<int>(N, 0)));
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            for(int k=0; k<N; k++){
                int x;
                cin >> x;
                grid[i][j][k] = x;  
            }
        }
    }
    // LOG(grid.size());
    int sum=0;
    int max_sum = INT_MAX;
    int i=0, j=0, k=0;
    BoosLair(grid, max_sum, sum,i, j, k);
    cout << "max sum: " << max_sum << endl;
    // print grid
    // for(int i=0; i<N; i++)
    // {
    //     for(int j=0; j<N; j++)
    //     {
    //         for(int k=0; k<N; k++){
    //             cout << grid[i][j][k] << " ";  
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    return 0;
}