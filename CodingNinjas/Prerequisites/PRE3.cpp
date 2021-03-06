// PRE3
// Send Feedback
// Given a 2-d square matrix of order ‘n’, find the sum of elements of both diagonals and all boundaries elements. Boundary elements refer to the elements present on all the four boundaries of matrix.
// Input:
// First line will have a single integer ‘n’ denoting the order of matrix.
// Next ‘n’ lines will have ‘n’ space separated integers each denoting the elements of matrix.
// Constraints:
// 1<=n<=100
// Output:
// Print a single integer denoting the sum.
// Sample input:
// 3
// 1 2 3
// 4 5 6
// 7 8 9
// Sample Output:
// 45

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, sum=0;
    cin>>n;
    int** a = new int*[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>*(*(a+i)+j);
        }   
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i+j==n-1 || i==j || i==0 || j==0 || i==n-1 || j==n-1)
                sum+=*(*(a+i)+j);
        }   
    }

    cout<<sum;
    delete[] a;
    
    return 0;
}