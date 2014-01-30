#ifndef _AHB_STRING_H_
#define _AHB_STRING_H_

#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <map>


namespace ahb {
namespace string {

/**
 * Strip whitespace from left side of string
 * Python: s = s.lstrip()
 * Boost: trim_left(s)
 * \param[in] s string to be stripped
 * \return reference to stripped string s
 */
std::string& lstrip(std::string& s);

/**
 * Strip whitespace from right side of string
 * Python: s = s.rstrip()
 * Boost: trim_right(s)
 * \param[in] s string to be stripped
 * \return reference to stripped string s
 */
std::string& rstrip(std::string& s);

/**
 * Strip whitespace from both sides of string
 * Python: s = s.strip()
 * Boost: trim(s)
 * \param[in] s string to be stripped
 * \return reference to stripped string s
 */
std::string& strip(std::string& s);

/**
 * Split inputString on delimiterString to get a key value pair
 * Python: key, value = inputString.split(delimiterString)
 * \param[in] inputString string containing key and value seperated by delimiterString
 * \param[in] delimiterString delimiter string
 * \param[out] key key string
 * \param[out] value value string
 * \param[in] ignoreWhitespace remove whitespace at start and end of key, value and delimiterString
 * \return
 *  - true: inputString contained valid key value pair
 *  - false: otherwise
 */
bool parseKeyValue(const std::string& inputString, const std::string& delimiterString, std::string& key, std::string& value, bool ignoreWhitespace = false);

/**
 * Convert type with operator<< to string
 * \param[in] p_arg object to be converted
 * \return string representation of p_arg
 */
template<class T> std::string toString(const T& p_arg)
{
  std::stringstream ss;

  ss << p_arg;

  return ss.str();
}

// partial specialization for std::vector, works if type in vector supports operator<<
template<class T> std::string toString(const std::vector<T>& p_arg)
{
  std::stringstream ss;

  for (typename std::vector<T>::const_iterator iter = p_arg.begin(); iter != p_arg.end(); ++iter) {
    ss << *iter << " ";
  }

  return ss.str();
}

// partial specialization for std::map, works if both types in map support operator<<
template<class T, class U> std::string toString(const std::map<T,U>& p_arg)
{
  std::stringstream ss;

  for (typename std::map<T,U>::const_iterator iter = p_arg.begin(); iter != p_arg.end(); ++iter) {
    ss << iter->first << ": " << iter->second << ", ";
  }

  return ss.str();
}

/**
 * Return string of characters in input string to their hex value
 * \param[in] p_str string of characters to be converted
 * \return string of hex values (as characters) of input string
 */
std::string toHexString(const std::string& p_str);

/**
 * Return string of data as their hex values
 * \param[in] p_data data to be converted
 * \param[in] p_len length of data
 * \return string of hex values (as characters) of data
 */
std::string toHexString(const char* p_data, size_t p_len);


/**
 * Slow (but type safe) string to integer conversion
 * \param[in] p_str string representation of integer
 * \return integer representation of correct type
 */
template<class T> T toNumberSlow(const std::string& p_str)
{
  std::stringstream ss;
  ss << p_str;
  T res;
  ss >> res;

  return res;
}

/**
 * Replace all occurences of string oldString with string newString in string inputString
 * Qt: QString::replace
 * Python: inputString = inputString.replace(oldString, newString)
 * \param[in,out] inputString string in which substitution is to be performed
 * \param[in] oldString string that will be substitution
 * \param[in] newString replacement for oldString
 * \return reference to (modified) inputString
 */
std::string& replace(std::string& inputString, const std::string& oldString, const std::string& newString);

/**
 * Return complete file as single string.
 * \param[in] filename file to be read
 * \return string containing whole content of filename
 */
std::string fileToString(const std::string& filename);

}} // namespaces

#endif // _AHB_STRING_H_
