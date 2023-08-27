#include <iostream>
#include "Block.h"
using namespace std;

int main() {
	Block hello(0, "0", "1", 45, "7645hgdfs");

	hello.mineBlock("5");

	cout << hello.getNonce() << endl << hello.getHash();

	return 0;
}