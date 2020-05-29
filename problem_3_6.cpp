//Sort the stacks in ascending order.
//complexity O(n)

#include<iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;

class dataBase{

public:
    queue<string>cat;
    queue<string>dog;
    vector<queue<string>> db;
    //Constructor
    dataBase()
    {
        db.push_back(cat);
        db.push_back(dog);
    }

    //prototypes
    void addCat(string name);
    void addDog(string name);
    string giveAnimal(string choice);

};

void dataBase::addCat(string name)
{
    db[0].push(name);
    cout<<"cat added."<<endl;
}

void dataBase::addDog(string name)
{
    db[1].push(name);
    cout<<"dog added."<<endl;
}

string dataBase::giveAnimal(string choice)
{
    int c;
    if(choice == "cat")
    {
        c=0;
    }
    else if(choice == "dog")
    {
        c=1;
    }
    else if(choice == "any")
    {
        c=2;
    }
    switch(c)
    {
        case 0:
            if(db[0].empty()!=true)
            {
                string returnAnimal= db[0].front();
                db[0].pop();
                return returnAnimal;

            }
            else
            {
                cout<<"no cats available"<<endl;
                return NULL;
            }
            break;

        case 1:
            if(db[1].empty()!= true)
            {
                string returnAnimal = db[1].front();
                db[1].pop();
                return returnAnimal;

            }
            else
            {
                cout<<"no dogs available"<<endl;
                return NULL;
            }
            break;

        case 2:
            if(db[0].empty()==true && db[1].empty()==true)
            {
                cout<<"No animals available."<<endl;
                return NULL;
            }
            else if(db[0].size() >= db[1].size())
            {
                string returnAnimal= db[0].front();
                db[0].pop();
                return returnAnimal;

            }
            else
            {
                string returnAnimal = db[1].front();
                db[1].pop();
                return returnAnimal;

            }
            break;

        default:
            cout<<"Invalid choice."<<endl;
            return NULL;
            break;
    }
}

int main()
{
    dataBase d;
    d.addCat("c1");
    d.addCat("c2");
    d.addCat("c3");
    d.addCat("c4");
    d.addCat("c5");
    d.addCat("c6");

    d.addDog("d1");
    d.addDog("d2");
    d.addDog("d3");
    d.addDog("d4");
    d.addDog("d5");
    d.addDog("d6");

    string myCat= d.giveAnimal("cat");
    cout<<"myCat: "<<myCat<<endl;
    myCat= d.giveAnimal("cat");
    cout<<"myCat: "<<myCat<<endl;
    string myDog= d.giveAnimal("dog");
    cout<<"myDog: "<<myDog<<endl;

    string myAny = d.giveAnimal("any");
    cout<<"myAny: "<<myAny<<endl;

}



