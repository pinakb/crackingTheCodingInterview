//Problem Statement: Check if the input is a palindrome permutation
// Input: Tact Coa
// Output:  True (permutations: "taco cat", "atco cta", etc.)
// Complexity: O(3n)

#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
#include<set>
#include<unordered_map>
using namespace std;

int main()
{
    string input;
    cout<<"Enter the input string: ";
    getline(cin, input);
    unordered_map<char,int> order;
    stringstream str(input);
    string word;
    string sequence="";

    while(str>>word)
    {
        sequence+=word;
    }

    transform(sequence.begin(), sequence.end(), sequence.begin(),::tolower);
    set<char> stringSet(sequence.begin(),sequence.end());
    set<char>::iterator itr;

    for(itr= stringSet.begin(); itr!= stringSet.end();++itr)
    {
        order[*itr]=0;
    }
    sort(sequence.begin(), sequence.end());

    unordered_map<char,int>::iterator locator;

    for(int i =0; i<sequence.length(); i++)
    {
        locator= order.find(sequence[i]);
        if(locator== order.end())
        {
            cout<<"not found: "<<sequence[i]<<endl;
        }
        else
        {
            int value= locator->second;
            locator->second = value+1;
        }
    }

    bool foundOne = false;
    bool pp = false;
    for(auto i = order.begin(); i!= order.end(); i++)
    {
        int value = i->second;
        if(value == 1 && foundOne == false)
        {
            foundOne= true;
        }
        else if( value == 1 && foundOne == true)
        {
            pp=false;
            break;
        }
        else if (value!= 1)
        {
            if(value%2 ==0)
            {
                pp = true;
            }
            else
            {
                pp = false;
                break;
            }
        }
    }

    if(pp==true)
    {
        cout<<"\n True"<<endl;
    }
    else
    {
        cout<<"\n False"<<endl;
    }

}
