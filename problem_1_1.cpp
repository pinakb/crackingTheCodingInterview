//Problem Statement: if input string has unique characters.
//Solution below is for case insensitive input strings

#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    cout<<"Enter the input string: ";
    cin>>str;
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    set<char> seqChecker(str.begin(), str.end());
    set<char>::iterator itr;
    int counter=0;
    for(itr= seqChecker.begin(); itr!= seqChecker.end(); ++itr)
    {
        counter++;
    }
    if(counter==str.length())
    {
        cout<<"input has unique characters."<<endl;
    }
    else
        cout<<"input doesn't have unique characters."<<endl;
}
