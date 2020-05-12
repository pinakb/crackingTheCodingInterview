//Problem Statement: given two input strings, check if edit distance is less than 1
//example:
//Input= "pale", "ple"
//output= true
//Input= "pale", "bake"
//output= false

#include<iostream>
#include<algorithm>
#include<string>
#include<set>

using namespace std;

int main()
{
    string first, second;
    cout<<"Enter first string: ";
    cin>>first;
    cout<<"Enter second string: ";
    cin>>second;
    string great;
    set<char> s1(first.begin(), first.end());
    set<char> s2(second.begin(), second.end());
    set<char>::iterator itr;

    if(first.length()>second.length())
        great = first;
    else
        great= second;

    for(itr= s2.begin(); itr!= s2.end(); ++itr)
    {
        s1.insert(*itr);
    }
    int counter=0;
    for(itr= s1.begin(); itr!= s1.end(); ++itr)
    {
        counter++;
    }
    if( (counter-great.length()) <=1)
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;

}
