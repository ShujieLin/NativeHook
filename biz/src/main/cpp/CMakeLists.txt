# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html.
# For more examples on how to use CMake, see https://github.com/android/ndk-samples.

# Sets the minimum CMake version required for this project.
cmake_minimum_required(VERSION 3.22.1)

# get the xhookorigin dir trough  ${CMAKE_SOURCE_DIR}

#set(XHOOK_DIR  ${CMAKE_SOURCE_DIR}/../../../../xhookorigin)
set(XHOOK_DIR  ${CMAKE_SOURCE_DIR}/xhookorigin)
#print the XHOOK_DIR
#D:\Codes\Android\Hook\NativeHook\xhookorigin\src\main\cpp\src
#result:
#C/C++: XHOOK_DIR:D:/Codes/Android/Hook/NativeHook/biz/src/main/cpp/../xhookorgin/src
message("XHOOK_DIR:${XHOOK_DIR}")
message("CMAKE_SOURCE_DIR:${CMAKE_SOURCE_DIR}")
message("CMAKE_CURRENT_SOURCE_DIR:${CMAKE_CURRENT_SOURCE_DIR}")

# Declares the project name. The project name can be accessed via ${ PROJECT_NAME},
# Since this is the top level CMakeLists.txt, the project name is also accessible
# with ${CMAKE_PROJECT_NAME} (both CMake variables are in-sync within the top level
# build script scope).
project("biz")


# get the location of xhookorgin  xhookorigin/src/main/cpp/src
include_directories(
        # get the location of
    ${XHOOK_DIR}/src/main/cpp/src/
)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.
#
# In this top level CMakeLists.txt, ${CMAKE_PROJECT_NAME} is used to define
# the target library name; in the sub-module's CMakeLists.txt, ${PROJECT_NAME}
# is preferred for the same purpose.
#
# In order to load a library into your app from Java/Kotlin, you must call
# System.loadLibrary() and pass the name of the library defined here;
# for GameActivity/NativeActivity derived applications, the same library name must be
# used in the AndroidManifest.xml file.
add_library(${CMAKE_PROJECT_NAME} SHARED
        # List C/C++ source files with relative paths to this CMakeLists.txt.
        biz.cpp)

# Specifies libraries CMake should link to your target library. You
# can link libraries from various origins, such as libraries defined in this
# build script, prebuilt third-party libraries, or Android system libraries.
target_link_libraries(${CMAKE_PROJECT_NAME}
        # List libraries link to the target library
        android
        xhookorigin
        log)