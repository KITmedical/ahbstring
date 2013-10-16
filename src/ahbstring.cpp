#include "ahbstring.h"

namespace ahb {
  namespace string {
    bool
    parseKeyValue(const std::string& inputString, const std::string& delimiterString, std::string& key, std::string& value)
    {
      int delimiterIdx = inputString.find(delimiterString);
      if (delimiterIdx == std::string::npos) {
        return false;
      }

      key = inputString.substr(0, delimiterIdx);
      value = inputString.substr(delimiterIdx + delimiterString.size());

      return true;
    }
  }
}
