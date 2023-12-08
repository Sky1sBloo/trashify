#include <iostream>

/**
 * Checks if path exists in user (check user privilages)
 * 
 * @param path Path to be checked
 *
 * @return If directory exists
 */
bool directoryExists(const std::string& path);

/**
 * Generates directory (check user privilages)
 *
 * @param path New directory path
 * 
 * @return If path creation is successfull
 */
bool createDirectory(const std::string& path);

/**
 * Returns path to current user's home
 */
const std::string getUserHome();

/**
 * Returns the current time with format
 *
 * @return YY-mm-ddTHr:Mm:Ss
 */
std::string getCurrentTimeFormatted();
