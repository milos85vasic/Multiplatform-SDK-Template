# Multiplatform SDK Template

Template / Example project for multiplatform SDKs.

## Basic architecture

Code is divided into three parts:

- Boost, the [Boost](https://www.boost.org/) C++ library
- Native, the core that contains native C++ implementation shared between platforms
- Android, Android SDK version
- iOS, iOS SDK version
- Other supported platforms ([Qt](https://www.qt.io/) etc.)

Both Android and iOS use C++ core (native library). On top of this, they are adding OS-specific features.

## Dependencies

To be able to build SDK some dependencies must be fulfilled:

- Native code (C++) dependencies
- OS-specific dependencies (Android and iOS)

### Native dependencies

Native C++ core depends on the following libraries:

- [Conan](https://docs.conan.io/en/latest/installation.html) C/C++ package manager >= 1.35.2
- C++ >= 17
- A compatible C++ compiler that supports C++ >= 17
- Cmake >= 3.10
- Clang >= 12.0
- [Boost](https://www.boost.org/) (used as a part of the SDK) >= 1.76.0
- [OpenSSL](https://www.openssl.org/) (provided by [Conan](https://conan.io/center/openssl)) >= 1.1.1k
- For unit tests, [Google Test library](https://github.com/google/googletest) (provided by [Conan](https://conan.io/center/gtest)) >= 1.10.0

### Android dependencies

Android dependencies are the follwoing:

- Android Studio >= 4.1.3
- Android NDK >= 21.0.6113669
- Kotlin >= 1.4.32

### iOS dependencies

iOS dependencies are the following:

- XCode >= 12.4

## How to build and test

Tbd.

### How to build and test native code

Tbd.

### How to build and test Android code

Tbd.

### How to build and test iOS code

Tbd.

## How to try it out

Example SDK is demonstrated through use in the following platforms:

- [Android](Android/Application)
- iOS
- Qt
- Java application


