include("${CONAN_BUILD_DIRECTORY}/conan_paths.cmake")
include("${CONAN_BUILD_DIRECTORY}/FindBZip2.cmake")
include("${CONAN_BUILD_DIRECTORY}/FindZLIB.cmake")
include("${CONAN_BUILD_DIRECTORY}/FindIconv.cmake")
include("${CONAN_BUILD_DIRECTORY}/FindOpenSSL.cmake")
include("${CONAN_BUILD_DIRECTORY}/FindBoost.cmake")

set(BOOST_LIBRARY_DIRS "${Boost_INCLUDE_DIR}/../lib")

find_package(OpenSSL REQUIRED)
find_package(Boost 1.75.0 COMPONENTS system filesystem headers thread REQUIRED)

include_directories("${OPENSSL_INCLUDE_DIR}")
include_directories("${Boost_INCLUDE_DIR}")

