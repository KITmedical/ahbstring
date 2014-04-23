#include "ahbstring.h"
#include <fstream>
#include <cerrno>
#include <algorithm> 
#include <functional> 

namespace ahb {
namespace string {

bool
startswith(const std::string& s, const std::string& prefix)
{
  if (prefix.empty()) {
    return true;
  }
  if (s.size() < prefix.size()) {
    return false;
  }
  return s.substr(0, prefix.size()) == prefix;
}

bool
endswith(const std::string& s, const std::string& suffix)
{
  if (suffix.empty()) {
    return true;
  }
  if (s.size() < suffix.size()) {
    return false;
  }
  return s.substr(s.size() - suffix.size()) == suffix;
}

std::string&
lstrip(std::string& s) {
  s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
  return s;
}

std::string&
rstrip(std::string& s) {
 s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
 return s;
}

std::string&
strip(std::string& s) {
  return lstrip(rstrip(s));
}

bool
parseKeyValue(const std::string& inputString, const std::string& delimiterString, std::string& key, std::string& value, bool ignoreWhitespace)
{
  std::string::size_type delimiterIdx = inputString.find(delimiterString);
  if (delimiterIdx == std::string::npos) {
    return false;
  }

  key = inputString.substr(0, delimiterIdx);
  value = inputString.substr(delimiterIdx + delimiterString.size());
  if (ignoreWhitespace) {
    strip(key);
    strip(value);
  }

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

std::string
toHexString(const char* p_data, size_t p_len)
{
  std::stringstream ss;
  ss << "0x";
  for (size_t i = 0; i < p_len; i++) {
    ss << std::setw(2) << std::setfill('0') << std::hex << (unsigned int)p_data[i] << " ";
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
