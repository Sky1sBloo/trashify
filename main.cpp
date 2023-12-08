#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory>

#include "TrashFile.hpp"

#define PATH_LENGTH 100

bool generateTrashFile(const char* file, bool isDirectory, std::unique_ptr<TrashFile>& fileVar)
{
	char resolvedPath[PATH_LENGTH];	

	if (realpath(file, resolvedPath) == NULL)
	{
		perror("File Input Error");
		return false;
	}

	// Path not including the name of file/directory
	std::string filePath = std::string(resolvedPath);
	size_t lastSlashPos = filePath.find_last_of('/');

	if (lastSlashPos != std::string::npos)
	{
		filePath.erase(lastSlashPos);
	}

	// Generate TrashFile class
	fileVar = std::make_unique<TrashFile>(filePath, std::string(file));

	return true;
}

int main(int argc, char* argv[])
{
	switch (argc)
	{
	case 1:
		std::cout << "Type -help to list commands" << std::endl;
		break;
	case 2:
		if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)
		{
			std::cout << "Trashify Commands\n" <<
				"-h   --help                         | Lists of commands\n" <<
				"-t   --trash [file]                 | Trash file\n";
		}
		break;
	case 3:
		if (strcmp(argv[1], "--trash") == 0 || strcmp(argv[1], "-t") == 0)
		{
			std::unique_ptr<TrashFile> file;
			if (generateTrashFile(argv[2], false, file))
			{
				file->MoveToTrash();
				std::cout << "Removed file: " << argv[2] << std::endl;
			}
			else
			{
				std::cout << "Failed to remove file: " << argv[2] << std::endl;
			}
		}
		break;
	}
	
}
