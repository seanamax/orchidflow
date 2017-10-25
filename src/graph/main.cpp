//#define CATCH_CONFIG_MAIN
//#include "../../test/lib/catch.h"

#include "../../include/node.h"
#include "../../include/op.h"
#include <iostream>

using namespace std;
using namespace orchidflow;

int main(int argc, char** argv)
{
    auto node = Node::Create();
    cout << node->is_variable() << endl;

    return 0;
}