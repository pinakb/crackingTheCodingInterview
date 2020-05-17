//Problem Defn: Given two strings, s1 and s2, write code to check if s2 is a rotation of s1
//using only one call to isSubstring
//approach: find the longest common substring. remove longest common substring from s1 and s2.
// if s1 == s2 after removal of longest common substring, it is a rotation.
//isSubstring function returns the length of longest common substring

#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int isSubstring(string input, string referenceString)
{
    int len = input.length();
    int ma = 1;
    int mis= 0;
    int gap= 0;

    int dpMatrix[len+1][len+1];
    dpMatrix[0][0]=0;

    for(int i=1; i<len+1; i++)
    {
        dpMatrix[i][0]=0;
    }
    for(int j=1; j<len+1; j++)
    {
        dpMatrix[0][j]=0;
    }

    int diag, left, up;
    for(int i=1; i<len+1; i++)
    {
        for(int j=1; j<len+1; j++)
        {

            if(input[i] == referenceString[j])
            {
                diag = dpMatrix[i-1][j-1] + ma;
            }
            else
            {
                diag = dpMatrix[i-1][j-1] + mis;
            }
            left = dpMatrix[i][j-1] + gap;
            up = dpMatrix[i-1][j] + gap;

            dpMatrix[i][j] = max( max(diag, left), up );
        }
    }
    return dpMatrix[len][len];
}


int main()
{
    string referenceString, input;
    cout<<"enter referenceString: ";
    getline(cin, referenceString);
    cout<<"enter input: ";
    getline(cin, input);

    if(input.length()!= referenceString.length() || input==referenceString)
    {
        cout<<"Not a rotation."<<endl;

    }
    else
    {
        int commonLength = isSubstring(input, referenceString);
        cout<<"commonLength: "<<commonLength<<endl;
        int remainingLength = input.length()- commonLength;
        string remainingInput = input.substr(remainingLength, (input.length()-remainingLength) );
        string remainingRef = referenceString.substr(0, commonLength);

        if(remainingInput == remainingRef)
        {
            cout<<"It is a rotation."<<endl;
        }
        else
        {
            cout<<"Not a rotation."<<endl;
        }
    }
}
