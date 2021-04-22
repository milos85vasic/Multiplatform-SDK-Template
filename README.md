# Multiplatform SDK Template

Template / Example project for multiplatform SDKs.

## Basic architecture

Project is divided into the several parts:

- Native, the core that contains native C++ implementations shared between platforms:
  - Native, main SDK C++ implementation
  - Test, test for main SDK C++ implementation
  - JNI, JVM bindings with SDK C++ implementation
  - CMake, CMake includes used by all C++ targets
- Android, Android SDK version
  - Android SDK
  - Example application that uses Android SDK
- iOS, iOS SDK version
  - iOS SDK
  - Example application that uses iOS SDK

Both Android and iOS SDKs use C++ core (native library). On the top of this, OS-specific features are added.

## Operating systems

This project has been tested on the following operating systems:

- macOS Big Sur >= 11.2.3
- Majnaro Linux >= 21.0.2

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
- [Boost](https://www.boost.org/) (provided by [Conan](https://conan.io/center/openssl)) >= 1.75.0
- [OpenSSL](https://www.openssl.org/) (provided by [Conan](https://conan.io/center/openssl)) >= 1.1.1k
- [Google Test library](https://github.com/google/googletest) for the testing (obtained by Cmake script) >= 1.10.0

### Android dependencies

Android dependencies are the following:

- [Gradle](https://gradle.org/) build tool >= 6.7
- Android Studio >= 4.1.3
- Android NDK >= 22.1.7171670
- Kotlin >= 1.4.32

### iOS dependencies

iOS dependencies are the following:

- XCode >= 12.4

## Configurations

Here is the list of important configurations required in order to successfully build, test and run this project.

### Gradle wrapper properties

gradle-wrapper.properties:

```
distributionBase=GRADLE_USER_HOME
distributionPath=wrapper/dists
zipStoreBase=GRADLE_USER_HOME
zipStorePath=wrapper/dists
distributionUrl=https\://services.gradle.org/distributions/gradle-6.7-all.zip
```

### Conan profiles

The following conan profiles (located at: `~/.conan/profiles`) have been used for building:

default (macOS host):

```
Tbd.
```

android_armeabi-v7a:

```
Tbd.
```

android_arm64-v8a:

```
Tbd.
```

android_x86:

```
Tbd.
```

android_x86_64:

```
Tbd.
```

## How to build and test

To be able to access project source code or build it is required to clone the Git repository. The following command clones the project and initializes all Git submodules:

```
mkdir Multiplatform-SDK-Template && cd Multiplatform-SDK-Template && \
git clone --recurse-submodules git@github.com:milos85vasic/Multiplatform-SDK-Template.git .
```

*Note:* All commands in upcoming sections are realtive to `Multiplatform-SDK-Template` directory where the project is cloned.

### How to build and test native code

To build and test native code perform the following commands:

```
cd Native/Implementation && ./buildAndInstall.sh
```

Which will build and install main shared library. In order to test the library execute the following:

```
cd ../Test && ./buildAndTest.sh
```

And finally, to build and install JNI library execute:

```
cd ../JNI && ./buildAndInstall.sh
```

### How to build and test Android code

Steps from the previous section are not required in order to build, run or test Android version of the SDK.

To build Android SDK perform the following steps:

```
cd Android && gradle wrapper && ./gradlew clean && ./gradlew build
```

*Note:* Befor you trigger build command make sure thet your Android `local.properties` is defined. It should look like in the following example:

```
sdk.dir=/Users/milosvasic/Library/Android/sdk
```

To execute Android tests perform the following steps from the `Android` directory:

```
./gradlew connectedAndroidTest
```

### How to build and test iOS code

Tbd.

## How to try it out

Example SDK is demonstrated through use in the following platforms:

- [Android](Android/Application)
- iOS

