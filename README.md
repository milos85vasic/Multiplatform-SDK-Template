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
- Cmake
- [Boost](https://www.boost.org/)

### Android dependencies

Tbd.

### iOS dependencies

Tbd.

## How to build

Tbd.

## How to try it out

Tbd.
