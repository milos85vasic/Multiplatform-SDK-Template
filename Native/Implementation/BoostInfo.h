#ifndef SDK_NATIVE_BOOSTINFO_H
#define SDK_NATIVE_BOOSTINFO_H

#include <string>

class BoostInfo {

public:

    BoostInfo();

    std::string getBoostVersion();

private:

    std::string version;
};


#endif //SDK_NATIVE_BOOSTINFO_H
