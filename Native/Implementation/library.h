#ifndef NATIVE_LIBRARY_H
#define NATIVE_LIBRARY_H

#include <string>
#include <functional>
#include "BoostInfo.h"

void hello();

std::string getBoostVersion();

BoostInfo getBoostInfo();

void tryHttpGet(const std::function<void(bool)> &callback);

void tryCallback(const std::function<void(bool)> &callback);

#endif //NATIVE_LIBRARY_H
