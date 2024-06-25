#include "SmartSingle.hpp"

void test()
{
    SmartSingle sm1;
    sm1->IssueTokens(100);
    (*sm1).IssueTokens(100);
    // sm1();
    SmartSingle sm2;
    sm1->IssueTokens(200);
    (*sm2).IssueTokens(200);
}
