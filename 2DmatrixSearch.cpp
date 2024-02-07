/* Problem =>
            Given a nxm matrix.
            Write an algorithm to find that the given value exists in the matrix or not.
            Integers in each row are sorted in ascending from left to right.
            Integers in each column are sorted in ascending from top to bottom.
*/

/*          Sample Test Case:
            Consider the following matrix:
            [
            [1, 4, 7, 11, 15],
            [2, 5, 8, 12, 19],
            [3, 6, 9, 16, 22],
            [10, 13, 14, 17, 24],
            [18, 21, 23, 26, 30]
            ]
            Given target = 5, return true.
            Given target = 20, return false. 
*/

/*  Brute Force Approach
    Linear search in a 2D Array.
*/

// #include "bits/stdc++.h"
// using namespace std;
// int32_t main() {
//     int n, m; cin >> n >> m;
//     int target; cin >> target;
//     int mat[n][m];
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             cin >> mat[i][j];
//         }
//     }
//     bool found = false;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (mat[i][j] == target)
//                 found = true;
//         }
//     }
//     if (found)
//         cout << "Found";
//     else
//         cout << "Not Found";
// }

/* CAN WE DO BETTER !! */

/* Optimised Approach [IMP]
            1. Start from the top right element.
            2. You are at (r,c)
            if(matrix[r][c] == target)
            return true
            If (matrix[r][c] > target)
            c--
            else
            r++;
    
            At (r,c), you can go to (r-1,c) or (r,c-1), depending on the value of matrix[i][j]
            and target.
*/

#include "bits/stdc++.h"
using namespace std;
int main() {
    int n, m; 
    cout << "Enter the number of rows and columns: ";
    cin >> n >> m;
    int mat[n][m];
    cout << "Enter the elements of the matrix: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    cout << "Enter the elements of the matrix: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    int target; 
    cout << "Enter the KEY to be searched: ";
    cin >> target;
    bool found = false;
    int r = 0, c = n - 1;
    while (r < m && c >= 0) {
        if (mat[r][c] == target) {
            found = true;
        }
        mat[r][c] > target ? c-- : r++;
    }
    cout << "After Searching : ";
    if (found)
        cout << "Element Found";
    else
        cout << "Element does Not Exist";
        return 0;
}
