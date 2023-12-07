#include "TrashFile.hpp"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sys/stat.h>

bool directoryExists(const std::string& path)
{
	struct stat info;
	return stat(path.c_str(), &info) == 0 && S_ISDIR(info.st_mode);
}

bool createDirectory(const std::string& path)
{
	if (mkdir(path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == 0)
	{
		return true;
	}
	else
	{
		std::cout << "Error creating directory" << std::endl;
		return false;
	}
}

TrashFile::TrashFile(const std::string& filePath, const std::string& fileName) :
	mFilePath(filePath), mFileName(fileName)
{
	if (directoryExists(TRASH_FOLDER))
	{
		std::string moveCmd = "mv " + filePath + " " + TRASH_FOLDER + "/files";
		system(moveCmd.c_str());
	}
	else
	{
		createDirectory(std::string(TRASH_FOLDER) + "/files");	
		createDirectory(std::string(TRASH_FOLDER) + "/info");	
	}
}

bool TrashFile::GenerateTrashInfo()
{
	const std::string fileInfoName = mFileName + ".trashinfo";	

	std::ofstream fileInfo(fileInfoName);

	if (!fileInfo.is_open())
	{
		std::cerr << "Error creating file info: " << fileInfoName << std::endl;
		return false;
	}

	fileInfo << "[Trash Info]\n";
	fileInfo << "Path=" << mFilePath << "\n";
}
