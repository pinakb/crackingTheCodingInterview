//Rotate matrix by 90 degrees.
//Solution is for Anti-clockwise rotation.
//Input: Dimension N of matrix. (Matrix will be auto populated)
//Output: Rotated matrix
//Complexity = O(n square)

#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the Dimension n: ";
    cin>>n;

    int mat[n][n];

    for(int i=0; i<n;i++)
    {
        for(int j=0; j<n; j++)
        {
            mat[i][j]=i+j;
        }
    }
    cout<<"Input Matrix: "<<endl;
    for(int i=0; i<n;i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<mat[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"\n Output Matrix:\n";
    for(int i=0; i<n/2; i++)
    {
        for(int j=i; j< n-i-1; j++)
        {
            int temp = mat[i][j];
            mat[i][j]= mat[j][n-i-1];
            mat[j][n-i-1] = mat[n-i-1][n-j-1];
            mat[n-i-1][n-j-1]= mat[n-j-1][i];
            mat[n-j-1][i]=temp;
        }
    }
    for(int i=0; i<n;i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<mat[i][j]<<"\t";
        }
        cout<<"\n";
    }
}
