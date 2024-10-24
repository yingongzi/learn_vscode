#include <iostream>
#include <vector>
#include <string>
#include "calc.h"
#include "gtest/gtest.h"
#include <iostream>
#include <chrono>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

TEST(testcase, test_add)
{
    EXPECT_EQ(add(1,2), 3);
    EXPECT_EQ(factorial(5), 120);
}

// int main(int argc, char **argv)
// {
//     std::cout << "run google test --> " << std::endl << std::endl;
//     testing::InitGoogleTest(&argc, argv);  
//     return RUN_ALL_TESTS();
// } 

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);  
    RUN_ALL_TESTS();
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    msg.push_back("hello");
    // 1. 基本格式化输出
    fmt::print("Hello, {}!\n", "World");
    for (const string& word : msg)
    {
        cout << word << " " << endl;
    }

    cout << add(5, 13) << endl;
    // cout << factorial(10) << endl;
    // 1. 基本格式化输出
    // fmt::print("Hello, {}!\n", "World");
    // 1. 控制台日志
    spdlog::info("Hello, {}!", "World");           // 基本控制台输出
    spdlog::warn("This is a warning message.");    // 警告级别日志
    spdlog::set_level(spdlog::level::debug);       // 设置日志级别为debug
    spdlog::debug("This is a debug message.");     // 调试级别日志

    // 4. 自定义日志格式
    spdlog::set_pattern("[%Y-%m-%d %H:%M:%S] [%l] %v");
    spdlog::info("Custom format log message.");
    // create an empty structure (null)
    json j;

    // add a number that is stored as double (note the implicit conversion of j to an object)
    j["pi"] = 3.141;

    // add a Boolean that is stored as bool
    j["happy"] = true;

    // add a string that is stored as std::string
    j["name"] = "Niels";

    // add another null object by passing nullptr
    j["nothing"] = nullptr;

    // add an object inside the object
    j["answer"]["everything"] = 42;

    // add an array that is stored as std::vector (using an initializer list)
    j["list"] = { 1, 0, 2 };

    // add another object (using an initializer list of pairs)
    j["object"] = { {"currency", "USD"}, {"value", 42.99} };

    // instead, you could also write (which looks very similar to the JSON above)
    json j2 = {
    {"pi", 3.141},
    {"happy", true},
    {"name", "Niels"},
    {"nothing", nullptr},
    {"answer", {
        {"everything", 42}
    }},
    {"list", {1, 0, 2}},
    {"object", {
        {"currency", "USD"},
        {"value", 42.99}
    }}
    };
    std::string s1 = j.dump();
    std::string s2 = j2.dump();
    std::string s3 = sprintf("%s, %f, %d", j["name"], j["pi"], j["happy"]);
    spdlog::info(s3);
    spdlog::info(s1);
    spdlog::info(s2);
}