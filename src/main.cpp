#include "blockchain/chain.h"
#include <iostream>

using namespace std;
using namespace blockchain;

int main(int argc, char **argv) 
{
    cout << "Start\n";

    cout << "Initializing blockchain\n";
    Chain Chain(1);
    cout << "Blockchain initialized!\n";
    Block* genesis = Chain.GetLastBlock();
    cout << "Genesis Hash: " << genesis->GetHashString();
    return 0;
}