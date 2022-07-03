#include <igloo/igloo_alt.h>

#include <sstream>

std::string uint32_to_ip(uint32_t ip)
{
    std::stringstream ss;
    ss << (ip >> 24) << '.' << (ip >> 16 & 0xFF) << '.' << (ip >> 8 & 0xFF) << '.' << (ip & 0xFF);
    return ss.str();
}

using namespace igloo;

Describe(test_cases)
{
    It(sample_tests)
    {
        Assert::That(uint32_to_ip(2154959208), Equals("128.114.17.104"));
        Assert::That(uint32_to_ip(0), Equals("0.0.0.0"));
        Assert::That(uint32_to_ip(2149583361), Equals("128.32.10.1"));
    }
};

int main()
{
  return TestRunner::RunAllTests();
}