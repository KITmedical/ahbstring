#include "ahbstring.h"

namespace ahb {
  namespace string {
    bool
    parseKeyValue(const std::string& inputString, const std::string& delimiterString, std::string& key, std::string& value)
    {
      unsigned delimiterIdx = inputString.find(delimiterString);
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

  }
}
