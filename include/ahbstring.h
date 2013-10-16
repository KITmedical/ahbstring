#ifndef _AHB_STRING_H_
#define _AHB_STRING_H_

#include <string>

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
  }
}

#endif // _AHB_STRING_H_
