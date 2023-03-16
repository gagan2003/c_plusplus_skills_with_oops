#include <iostream>
using namespace std;
int issafe(int **arr, int x, int y, int size)
{
    if ((x < size) && (y < size) && (arr[x][y] == 1))
    {
        return 1;
    }
    return 0;
}
int rateinmaze(int **arr, int x, int y, int size, int **solu)
{
    if ((x == size - 1) && (y == size - 1))
    {
        solu[x][y] = 1;
        return 1;
    }
    if (issafe(arr, x, y, size))
    {
        solu[x][y] = 1;
        if (rateinmaze(arr, x + 1, y, size, solu))
        {
            return 1;
        }
        if (rateinmaze(arr, x, y + 1, size, solu))
        {
            return 1;
        }
        solu[x][y] = 0;
        return 0;
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    cout << "HERE I AM FIND SOLUTION FOR A DASHBOARD IN WHICH A RAT AT INDEX (1,1) AND WANT TO AT INDEX (N*N), AS WELL AS PRINT POSSIBLE SOLUTION.\n";
    cout << "ENTER DASHBOARD SIZE: \nSIZE :- ";
    int n;
    cin >> n;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }
    int **solu = new int *[n];
    for (int i = 0; i < n; i++)
    {
        solu[i] = new int[n];
    }
    cout << "ENTER ENTERIES OF DASHBOARD.\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            solu[i][j] = 0;
        }
    }
    cout << "\nSolution: \n";
    if (rateinmaze(arr, 0, 0, n, solu))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << solu[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "sorry, for given dashboard ans is not possible.\n";
    }
    return 0;
}
/*
1 0 1 0 1
1 1 1 1 1
0 1 0 1 0
1 0 0 1 1
1 1 1 0 1
*/