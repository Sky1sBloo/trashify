#include <ctime>
#include <string>

#define TRASH_FOLDER "/.local/share/Trash"

class TrashFile
{
public:
	/**
	 * Default constructor for TrashFile
	 */
	TrashFile(const std::string& fileName);
	/**
	 * Constructor for TrashFile
	 *
	 * @param filePath Path to original file location
	 * @param fileName Name of file to be deleted
	 */
	TrashFile(const std::string& filePath, const std::string& fileName);

	/**
	 * Moves specified file to trash defined in TRASH_FOLDER
	 */
	void MoveToTrash();

	/**
	 * Generates trash information
	 */
	bool GenerateTrashInfo();

	/**
	 * Loads all info from file
	 */
	void LoadTrashInfo();

	/**
	 * Restores the trash to mFilePath
	 */
	void RestoreTrash();

	/**
	 * Completely removes trash
	 */
	void DeleteTrash();
private:
	std::string mFilePath;
	std::string mFileName;
	std::string mDateDeleted;
	std::time_t mTimeDeleted;
};
