#include "TrashFile.hpp"
#include <iomanip>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <pwd.h>
#include <sys/stat.h>
#include <unistd.h>

#include "LinuxFileHandler.hpp"

TrashFile::TrashFile(const std::string& fileName) :
	mFileName(fileName)
{
}

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

void TrashFile::LoadTrashInfo()
{
	std::string trashInfo = getUserHome() + TRASH_FOLDER + "/info/" + mFileName + ".trashinfo";
	if ((!std::filesystem::exists(trashInfo)) && (!std::filesystem::is_regular_file(trashInfo)))
	{
		std::cerr << "Trash info corrupted or doesn't exist" << std::endl;
		return;
	}

	std::ifstream file(trashInfo);

	if (file.is_open())
	{
		std::string line;

		std::getline(file, line);
		std::getline(file, line);

		mFilePath = line.substr(line.find('=') + 1);

		std::getline(file, line);
		mDateDeleted = line.substr(line.find('=') + 1);
	}
}

void TrashFile::RestoreTrash()
{
	// Delete trashinfo
	std::string trashInfo = getUserHome() + TRASH_FOLDER + "/info/" + mFileName + ".trashinfo";
	std::string delCmd = "rm " + trashInfo;
	
	std::string moveCmd = "mv " + getUserHome() + TRASH_FOLDER + "/files/" + mFileName +
		" " + mFilePath;

	system(moveCmd.c_str());
	system(delCmd.c_str());
}
