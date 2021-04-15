# Multiplatform SDK Template

Template / Example project for multiplatform SDKs.

## Basic architecture

Code is divided into three parts:

- Native, the core that contains native C++ implementation shared between platforms
- Android, Android SDK version
- iOS, iOS SDK version

Both Android and iOS use C++ core (native library). On top of this, they are adding OS-specific features.

## Dependencies

To be able to build SDK some dependencies must be fulfilled:

- Native code (C++) dependencies
- OS-specific dependencies (Android and iOS)

### Native dependencies

Native C++ core depends on the following libraries:

- C++ >= 17
- Cmake >= 3.19.8
- [Boost](https://www.boost.org/) (used as a part of this example SDK) >= 1.71.1
- [Boost ASIO](https://www.boost.org/doc/libs/1_75_0/doc/html/boost_asio.html) (used as a part of this example SDK) >= 1.71.1

### Android dependencies

Tbd.

### iOS dependencies

iOS dependencies are the following:

- XCode >= 12.4

## How to build

Tbd.

## How to try it out

Example SDK is demonstrated through use in the following platforms:

- Android
- iOS
- Qt
- Java application


