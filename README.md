# Multiplatform SDK Template

Template / Example project for multiplatform SDKs.

## Basic architecture

Code is divided into several parts:

- [Boost](https://www.boost.org/) C++ library provided as Git submodule
- Native, the core that contains native C++ implementations shared between platforms
- Android, Android SDK version
- iOS, iOS SDK version

Both Android and iOS use C++ core (native library). On top of this, OS-specific features are added.

## Dependencies

To be able to build SDK some dependencies must be fulfilled:

- Dependencies for the native code
- OS-specific dependencies (Android and iOS)

### Native dependencies

Native C++ code depends on several libraries and technologies:

- [Conan](https://docs.conan.io/en/latest/installation.html) C/C++ package manager >= 1.35.2
- C++ >= 17
- Clang >= 12.0
- Cmake >= 3.10
- [Boost](https://www.boost.org/) (used as a part of the SDK) >= 1.76.0
- [OpenSSL](https://www.openssl.org/) (provided by [Conan](https://conan.io/center/openssl)) >= 1.1.1k
- [Google Test library](https://github.com/google/googletest) for the testing (obtained by Cmake script) >= 1.10.0

### Android dependencies

Android dependencies are the following:

- Android Studio >= 4.1.3
- Android NDK >= 22.1.7171670
- Kotlin >= 1.4.32

### iOS dependencies

iOS dependencies are the following:

- XCode >= 12.4

## Configurations

### Conan profiles

The following conan profiles (located at: `~/.conan/profiles`) have been used for building:

default:
```
[settings]
os=Macos
os_build=Macos
arch=x86_64
arch_build=x86_64
compiler=clang
compiler.version=12
compiler.libcxx=libstdc++11
build_type=RelWithDebInfo
[options]
[build_requires]
[env]
```

android_armeabi-v7a:
```
include(default)
[settings]
arch=armv7
build_type=Release
compiler=clang
compiler.libcxx=libc++
compiler.version=8
os=Android
os.api_level=21
[build_requires]
android_ndk_installer/r20@bincrafters/stable
[options]
[env]
```

android_arm64-v8a:
```
include(default)
[settings]
arch=armv8
build_type=Release
compiler=clang
compiler.libcxx=libc++
compiler.version=8
os=Android
os.api_level=21
[build_requires]
android_ndk_installer/r20@bincrafters/stable
[options]
[env]
```

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

