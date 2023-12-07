#include <ctime>
#include <string>

#define TRASH_FOLDER "~/.local/share/Trash"

class TrashFile
{
public:
	TrashFile(const std::string& filePath, const std::string& fileName);
	bool GenerateTrashInfo();
private:
	std::string mFilePath;
	std::string mFileName;
	std::time_t mTimeDeleted;

};
