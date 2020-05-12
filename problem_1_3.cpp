//Problem Statement: to URLify the input string
//example:
//Input= "This is pinak     "
//output= "This%20is%20pinak"

#include<iostream>
#include<algorithm>
#include <string>
#include<sstream>

using namespace std;

int main()
{
    string input;
    cout<<"Enter the input string: ";
    getline(cin, input);

    stringstream ss;
    ss.str(input);
    string word;
    string output="";

    while(ss >> word)
    {
//        cout<<word<<endl;
        output+=word;
        output+="%20";
    }
    output= output.substr(0, output.length()-3);
    cout<<"Output URL: "<<output<<endl;

}
