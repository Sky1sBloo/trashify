#include <cstdlib>
#include <iostream>

#define PATH_LENGTH 100

int main(int argc, char* argv[])
{
	char resolvedPath[PATH_LENGTH];	
	if (realpath(argv[1], resolvedPath) == NULL)
	{
		perror("File Input Error");
		return 1;
	}
	std::cout << resolvedPath << std::endl;

	return 0;
}
