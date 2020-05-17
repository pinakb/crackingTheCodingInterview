//if an element in an MxN matrix is 0, its entire row and column are set to 0.
//input = a 4x5 matrix
//output= a 4x5 matrix with row and column set to 0 if matrix[i][j] =0
//space used to store matrix = MxN. No extra space used. inplace transformation performed.
//time complexity = O(MxN)

#include<iostream>

using namespace std;

void printMatrix(int **matrix, int M, int N)
{
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout<<matrix[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

void  convertRowColumn(int **matrix, int M, int N, int x, int y)
{
    for(int j=0; j<N; j++)
    {
        matrix[x][j]=-1;
    }
    for(int i=0; i<M; i++)
    {
        matrix[i][y]=-1;
    }
}

void convertMatrix(int **matrix, int M, int N)
{
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(matrix[i][j]==0)
            {
                convertRowColumn(matrix, M, N, i,j);
            }
        }
    }

    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(matrix[i][j]== -1)
            {
                matrix[i][j]=0;
            }
        }
    }
}


int main()
{
    int **matrix;
    int M =5;
    int N= 4;

    matrix = new int*[M];

    for(int i=0; i<M; i++)
    {
        matrix[i]= new int[N];
    }

    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            if( (i+j)>=5  && (i+j) % 4 ==2)
            {
                matrix[i][j]=0;
            }
            else
            {
                matrix[i][j]= i+j;
            }
        }
    }

    cout<<"Input Matrix: "<<endl;
    printMatrix(matrix, M, N);
    convertMatrix(matrix, M, N);
    cout<<"\n converted Matrix: "<<endl;
    printMatrix(matrix, M, N);

}
