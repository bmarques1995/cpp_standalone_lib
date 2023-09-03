#include "model_shared/log.hpp"

#include <iostream>

using std::cout;
using std::endl;

void ModelShared::Log::InfoLog()
{
	cout << "This is a DLL access" << endl;
}
