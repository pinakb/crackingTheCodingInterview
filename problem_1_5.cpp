//Problem Statement: given two input strings, check if edit distance is less than 1
//example:
//Input= "pale", "ple"
//output= true
//Input= "pale", "bake"
//output= false

//Complexity O(n + m + m*n)

#include<iostream>
#include<string>

using namespace std;

int main()
{
    string input1, input2;
    cout<<"Enter first string: ";
    cin>>input1;
    cout<<"Enter second string: ";
    cin>>input2;

    int ma =0;
    int mis=1;
    int gap=1;
    int diag;
    int left;
    int up;

    int matrix[input1.length()+1][input2.length()+1];
    matrix[0][0]=0;

    for(int i=0; i<input1.length()+1;i++)
    {
        matrix[i][0]=i;
    }
    for(int i=0; i<input2.length()+1;i++)
    {
        matrix[0][i]=i;
    }

    for(int x=1; x< input1.length()+1;x++)
    {
        for(int y=1; y < input2.length()+1; y++)
        {
            if(input1[x-1]==input2[y-1])
            {
                diag = matrix[x-1][y-1] + ma;
            }
            else
            {
                diag = matrix[x-1][y-1] + mis;
            }
            left = matrix[x][y-1] + gap;
            up = matrix[x-1][y] + gap;
            matrix[x][y] = min( min(diag,left),up);
        }
    }
    if(matrix[input1.length()][input2.length()] <=1)
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
}
