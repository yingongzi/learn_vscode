#include <iostream>
#include <vector>
#include <string>
#include "calc.h"

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    msg.push_back("hello");
    
    for (const string& word : msg)
    {
        cout << word << " " << endl;
    }

    cout << add(5, 13) << endl;
    cout << factorial(10) << endl;
}