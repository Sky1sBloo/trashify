#include "LinuxFileHandler.hpp"
#include <iomanip>
#include <pwd.h>
#include <sys/stat.h>
#include <unistd.h>

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


const std::string getUserHome()
{
    const char* homeDir = getenv("HOME");

    if (homeDir == nullptr) {
        struct passwd* pw = getpwuid(getuid());
        if (pw != nullptr) {
            homeDir = pw->pw_dir;
        } else {
            // Fallback to /tmp if unable to retrieve home directory
            homeDir = "/tmp";
        }
    }

    return std::string(homeDir);
}

std::string getCurrentTimeFormatted()
{
	std::time_t currentTime = std::time(nullptr);
	std::tm* localTime = std::localtime(&currentTime);

	std::ostringstream oss;
	oss << std::put_time(localTime, "%Y-%m-%dT%H:%M:%S");
		
	return oss.str();
}
