#ifndef SDK_NATIVE_BOOSTINFO_H
#define SDK_NATIVE_BOOSTINFO_H

#include <string>
#include <boost/version.hpp>

class BoostInfo {

public:

    BoostInfo();

    std::string getBoostInfo();

private:

    std::string version;
};


#endif //SDK_NATIVE_BOOSTINFO_H
