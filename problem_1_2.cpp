//Problem Statement: to check if two strings are permutations of each other or not.
//Solution is case insensitive.

#include<iostream>
#include<algorithm>
#include <string>

using namespace std;

int main()
{
    string str1, str2;
    cout<<"Enter string 1: ";
    cin>>str1;
    cout<<"Enter string 2: ";
    cin>>str2;

    if(str1.length() != str2.length())
    {
        cout<<"Not a permutation."<<endl;
    }
    else
    {
        //converting string to lower case to handle case sensitivity
        transform(str1.begin(), str1.end(), str1.begin(),::tolower);
        transform(str2.begin(), str1.end(), str2.begin(),::tolower);

        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());

        if(str1==str2)
        {
            cout<<"it is a permutation"<<endl;
        }
        else
        {
            cout<<"not a permutation"<<endl;
        }
    }
}
