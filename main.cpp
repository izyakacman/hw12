#include <iostream>

#include "check_tensor.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Usage: fashio_mnist <test> <model>";
		return -1;
	}

	std::cout << "Calculations in progress, please wait...\n";

	std::cout << GetTensorAccuracy(argv[2], argv[1]) << endl;

	return 0;
}
