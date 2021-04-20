set(OPENSSL_ROOT_DIR "${PROJECT_SOURCE_DIR}/../../OpenSSL")
set(OPENSSL_INCLUDE_DIR "${OPENSSL_ROOT_DIR}/include")

set(OPENSSL_LIBRARIES "${OPENSSL_ROOT_DIR}")
set(OPENSSL_CRYPTO_LIBRARIES "${OPENSSL_ROOT_DIR}")

if (CMAKE_HOST_SYSTEM_NAME MATCHES "Darwin")

    set(OPENSSL_LIBRARY "${OPENSSL_ROOT_DIR}/libssl.3.dylib")
    set(OPENSSL_CRYPTO_LIBRARY "${OPENSSL_ROOT_DIR}/libcrypto.dylib")
elseif (CMAKE_HOST_SYSTEM_NAME MATCHES "Linux")

    # TODO: Test and verify on Linux and Windows

    set(OPENSSL_LIBRARY "${OPENSSL_ROOT_DIR}/libssl.3.so")
    set(OPENSSL_CRYPTO_LIBRARY "${OPENSSL_ROOT_DIR}/libcrypto.so")
elseif (CMAKE_HOST_SYSTEM_NAME MATCHES "Windows")

    set(OPENSSL_LIBRARY "${OPENSSL_ROOT_DIR}/libssl.3.dll")
    set(OPENSSL_CRYPTO_LIBRARY "${OPENSSL_ROOT_DIR}/libcrypto.dll")
endif ()

find_package(OpenSSL REQUIRED)

if (OPENSSL_FOUND)

    message("Found OpenSSL ${OPENSSL_VERSION}")
else ()

    message("OpenSSL Not Found")
endif ()

include_directories(${OPENSSL_INCLUDE_DIR})