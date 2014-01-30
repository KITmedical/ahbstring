#include "ahbstring.h"
#include <fstream>
#include <cerrno>

namespace ahb {
namespace string {

bool
parseKeyValue(const std::string& inputString, const std::string& delimiterString, std::string& key, std::string& value)
{
  std::string::size_type delimiterIdx = inputString.find(delimiterString);
  if (delimiterIdx == std::string::npos) {
    return false;
  }

  key = inputString.substr(0, delimiterIdx);
  value = inputString.substr(delimiterIdx + delimiterString.size());

  return true;
}

std::string
toHexString(const std::string& p_str)
{
  std::stringstream ss;
  ss << "0x";
  for (size_t i = 0; i < p_str.size(); i++) {
    ss << std::setw(2) << std::setfill('0') << std::hex << (unsigned int)p_str[i] << " ";
  }
  return ss.str();
}

std::string&
replace(std::string& inputString, const std::string& oldString, const std::string& newString)
{
  if (inputString.empty()) {
    return inputString;
  }
  size_t replaceStart = 0;
  while ((replaceStart = inputString.find(oldString, replaceStart)) != std::string::npos) {
    inputString.replace(replaceStart, oldString.length(), newString);
    replaceStart += newString.length(); // avoid infinite loop if newString contains oldString
  }

  return inputString;
}

std::string
fileToString(const std::string& filename)
{
  std::string fileString;
  std::ifstream fileStream(filename.c_str(), std::ios::in | std::ios::binary);
  if (!fileStream) {
    throw(errno);
  }

  fileStream.seekg(0, std::ios::end);
  fileString.resize(fileStream.tellg());
  fileStream.seekg(0, std::ios::beg);
  fileStream.read(&fileString[0], fileString.size());
  fileStream.close();

  return fileString;
}

}} // namespaces
