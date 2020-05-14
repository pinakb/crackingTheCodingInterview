//Compress string
//Input example: aaaabbbcccd
//Output: a4b3c3d1
//Complexity = O(n)

#include<iostream>
#include<set>
#include<string>
#include<sstream>
using namespace std;

int main()
{
    string input;
    cout<<"Enter the input string: ";
    getline(cin,input);

    int counter=0;
    string sequence="";

    set<char> alphabet(input.begin(), input.end());
    if(alphabet.size()*2 < input.length())
    {
        for(int i=0; i<input.length()-1;i++)
        {
            if(input[i]==input[i+1] && i!= input.length()-2)
            {
                counter++;
            }
            else if(input[i]==input[i+1] && i == input.length()-2)
            {
                counter+=2;
                sequence+=input[i];
                sequence += to_string(counter);
            }
            else if(input[i]!=input[i+1] && i == input.length()-2)
            {
                counter+=2;
                sequence+=input[i];
                sequence += to_string(counter);
                sequence+=input[i+1];
                counter=1;
                sequence += to_string(counter);
            }
            else
            {
                counter++;
                sequence+=input[i];
                sequence += to_string(counter);
                counter=0;
            }
        }
        cout<<"Sequence: "<<sequence<<endl;
    }
    else
    {
        cout<<"sequence: "<<input<<endl;
    }

}
