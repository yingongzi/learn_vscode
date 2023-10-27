#include <iostream>
#include <vector>
#include <string>
#include "calc.h"
#include "gtest/gtest.h"

using namespace std;

TEST(testcase, test_add)
{
    EXPECT_EQ(add(1,2), 3);
    EXPECT_EQ(factorial(5), 120);
}

int main(int argc, char **argv)
{
    std::cout << "run google test --> " << std::endl << std::endl;
    testing::InitGoogleTest(&argc, argv);  
    return RUN_ALL_TESTS();
} 

// int main()
// {
//     vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
//     msg.push_back("hello");
    
//     for (const string& word : msg)
//     {
//         cout << word << " " << endl;
//     }

//     cout << add(5, 13) << endl;
//     cout << factorial(10) << endl;
// }