#include "TrashFile.hpp"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <pwd.h>
#include <sys/stat.h>
#include <unistd.h>

#include "LinuxFileHandler.hpp"


TrashFile::TrashFile(const std::string& filePath, const std::string& fileName) :
	mFilePath(filePath), mFileName(fileName) 
{
	if (!directoryExists(getUserHome() + TRASH_FOLDER))
	{
		createDirectory(getUserHome() + "/" + std::string(TRASH_FOLDER));
		createDirectory(getUserHome() + "/" + std::string(TRASH_FOLDER) + "/files");	
		createDirectory(getUserHome() + "/" + std::string(TRASH_FOLDER) + "/info");	
	}
}

void TrashFile::MoveToTrash()
{
	GenerateTrashInfo();
	std::string moveCmd;
	moveCmd = "mv " + mFilePath + "/" + mFileName + " " + getUserHome() + TRASH_FOLDER + "/files";	
	system(moveCmd.c_str());
}

bool TrashFile::GenerateTrashInfo()
{
	const std::string fileInfoName = mFileName + ".trashinfo";	

	std::ofstream fileInfo(getUserHome() + TRASH_FOLDER + "/info/" + fileInfoName);

	if (!fileInfo.is_open())
	{
		std::cerr << "Error creating file info: " << fileInfoName << std::endl;
		return false;
	}

	fileInfo << "[Trash Info]\n";
	fileInfo << "Path=" << mFilePath << "\n";
	fileInfo << "DeletionDate=" << getCurrentTimeFormatted();

	fileInfo.close();
	return true;
}
