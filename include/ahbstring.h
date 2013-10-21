#ifndef _AHB_STRING_H_
#define _AHB_STRING_H_

#include <string>
#include <sstream>
#include <iomanip>


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
  }
}

#endif // _AHB_STRING_H_
