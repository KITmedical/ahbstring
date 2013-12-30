#ifndef _AHB_STRING_H_
#define _AHB_STRING_H_

#include <string>
#include <sstream>
#include <iomanip>
#include <vector>


namespace ahb {
  namespace string {
    /**
     * Split inputString on delimiterString to get a key value pair
     * Python: key, value = inputString.split(delimiterString)
     * \param[in] inputString string containing key and value seperated by delimiterString
     * \param[in] delimiterString delimiter string
     * \param[out] key key string
     * \param[out] value value string
     * \return
     *  - true: inputString contained valid key value pair
     *  - false: otherwise
     */
    bool parseKeyValue(const std::string& inputString, const std::string& delimiterString, std::string& key, std::string& value);

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

    // partial specialization for std::vector, works if vector contents supports operator<<
    template<class T> std::string toString(const std::vector<T>& p_arg)
    {
      std::stringstream ss;

      for (typename std::vector<T>::const_iterator iter = p_arg.begin(); iter != p_arg.end(); ++iter) {
        ss << *iter << " ";
      }

      return ss.str();
    }

    /**
     * Convert characters in string to their hex value
     * \param[in] p_str string of characters to be converted
     * \return string of hex values (as characters) of input string
     */
    std::string toHexString(const std::string& p_str);

    /**
     * Slow (but type safe) string to integer conversion
     * \param[in] p_str string representation of integer
     * \return integer representation of correct type
     */
    template<class T> T toIntSlow(const std::string& p_str)
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
     * \param[in] inputString string in which substitution is to be performed
     * \param[in] oldString string that will be substitution
     * \param[in] newString replacement for oldString
     * \return reference to new inputString with all oldString replaced by newString
     */
    std::string& replace(std::string& inputString, const std::string& oldString, const std::string& newString);
  }
}

#endif // _AHB_STRING_H_
