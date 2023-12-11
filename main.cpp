#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory>
#include <vector>

#include "TrashFile.hpp"
#include "LinuxFileHandler.hpp"

#define PATH_LENGTH 100

const std::string helpMessage = "Type --help to list commands";

/**
 * Generates a TrashFile class with its own file path
 * Generally used when you want to trash a new item where its .trashinfo doesn't exist
 *
 * @param file Filename of the file to be trashed
 * @param fileVar Reference where the trashfile will be stored
 */
bool generateTrashFile(const char* file, std::unique_ptr<TrashFile>& fileVar)
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

/**
 * Compares the const char string to a lists of strings
 *
 * @param str String to be compared
 * @param vec Lists of string to be compared
 *
 * @return One of the lists matches the string
 */
bool stringMatchesVector(const char* str, const std::vector<const char*> vec)
{
	for (const char* content : vec)
	{
		if (strcmp(str, content) == 0)
			return true;
	}
	return false;
}

int main(int argc, char* argv[])
{
	switch (argc)
	{
	case 1:
		std::cout << helpMessage << std::endl;
		break;
	case 2:
		if (stringMatchesVector(argv[1], {"--help", "-h"}))
		{
			std::cout << "Trashify Commands\n" <<
				"-h   --help                         | Lists of commands\n" <<
				"-t   --trash [file]                 | Trash a file or directory\n" <<
				"-l   --list                         | Lists all trashed files and directories\n" <<
				"-r   --restore [file]               | Restores a file or directory\n" <<
				"-d   --delete [file]                | Permanently removes file or directory\n" <<
				"-e   --empty                        | Empties the trash bin" <<
				std::endl;
		}
		else if (stringMatchesVector(argv[1], {"--list", "-l"}))
		{
			std::string trashPath = getUserHome() + TRASH_FOLDER + "/files";
			std::vector<std::string> contents = listDirectoryContents(trashPath);

			for (auto fileName : contents)
			{
				std::cout << fileName << std::endl;
			}
		}
		else if (stringMatchesVector(argv[1], {"--empty", "-e"}))
		{
			std::string trashPath = getUserHome() + TRASH_FOLDER + "/files";
			std::vector<std::string> contents = listDirectoryContents(trashPath);	

			for (auto fileName : contents)
			{
				TrashFile file(fileName);
				file.LoadTrashInfo();
				file.DeleteTrash();
			}
		}
		else
		{
			std::cout << helpMessage << std::endl;
		}
		break;
	}

	if (argc >= 3)
	{
		if (stringMatchesVector(argv[1], {"--trash", "-t"}))
		{
			// Allows for multiple deletions
			for (int i = 2; i < argc; i++)
			{
				std::unique_ptr<TrashFile> file;
				if (generateTrashFile(argv[i], file))
				{
					file->MoveToTrash();
				}
				else
				{
					std::cout << "Failed to remove file: " << argv[i] << std::endl;
				}
			}
			
		}
		else if (stringMatchesVector(argv[1], {"--restore", "-r"}))
		{
			// Allos for multiple restorations
			for (int i = 2; i < argc; i++)
			{
				TrashFile file(argv[i]);
			
				file.LoadTrashInfo();
				file.RestoreTrash();
			}
		}
		else if (stringMatchesVector(argv[1], {"--delete", "-d"}))
		{
			for (int i = 2; i < argc; i++)
			{
				TrashFile file(argv[i]);

				file.LoadTrashInfo();
				file.DeleteTrash();
			}
		}
		else
		{
			std::cout << helpMessage << std::endl;
		}
	}
}
