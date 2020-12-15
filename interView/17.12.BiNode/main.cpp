//#include "Solution.h"
#include "BSTree.h"
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
	char ch;
	while (ch = getchar() != ']') {
		if ()

		if (ch == '[') {

		}
		if (ch == ',') {
			continue;
		}

	}

	BSTree<int> intBST;
	buildTree(treeStr,intBST);
	intBST.inorder(cout);
    cout << endl;
    intBST.graph(cout);
	return 0;
}