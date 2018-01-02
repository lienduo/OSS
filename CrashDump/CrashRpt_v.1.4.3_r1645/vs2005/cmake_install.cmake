# Install script for directory: E:/Others/Sample/CrashDump/CrashRpt_v.1.4.3_r1645

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/CrashRpt")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("E:/Others/Sample/CrashDump/CrashRpt_v.1.4.3_r1645/vs2005/demos/ConsoleDemo/cmake_install.cmake")
  include("E:/Others/Sample/CrashDump/CrashRpt_v.1.4.3_r1645/vs2005/demos/WTLDemo/cmake_install.cmake")
  include("E:/Others/Sample/CrashDump/CrashRpt_v.1.4.3_r1645/vs2005/demos/MFCDemo/cmake_install.cmake")
  include("E:/Others/Sample/CrashDump/CrashRpt_v.1.4.3_r1645/vs2005/reporting/crashrpt/cmake_install.cmake")
  include("E:/Others/Sample/CrashDump/CrashRpt_v.1.4.3_r1645/vs2005/reporting/crashsender/cmake_install.cmake")
  include("E:/Others/Sample/CrashDump/CrashRpt_v.1.4.3_r1645/vs2005/processing/crashrptprobe/cmake_install.cmake")
  include("E:/Others/Sample/CrashDump/CrashRpt_v.1.4.3_r1645/vs2005/processing/crprober/cmake_install.cmake")
  include("E:/Others/Sample/CrashDump/CrashRpt_v.1.4.3_r1645/vs2005/tests/cmake_install.cmake")
  include("E:/Others/Sample/CrashDump/CrashRpt_v.1.4.3_r1645/vs2005/thirdparty/tinyxml/cmake_install.cmake")
  include("E:/Others/Sample/CrashDump/CrashRpt_v.1.4.3_r1645/vs2005/thirdparty/jpeg/cmake_install.cmake")
  include("E:/Others/Sample/CrashDump/CrashRpt_v.1.4.3_r1645/vs2005/thirdparty/libpng/cmake_install.cmake")
  include("E:/Others/Sample/CrashDump/CrashRpt_v.1.4.3_r1645/vs2005/thirdparty/minizip/cmake_install.cmake")
  include("E:/Others/Sample/CrashDump/CrashRpt_v.1.4.3_r1645/vs2005/thirdparty/zlib/cmake_install.cmake")
  include("E:/Others/Sample/CrashDump/CrashRpt_v.1.4.3_r1645/vs2005/thirdparty/libogg/cmake_install.cmake")
  include("E:/Others/Sample/CrashDump/CrashRpt_v.1.4.3_r1645/vs2005/thirdparty/libtheora/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "E:/Others/Sample/CrashDump/CrashRpt_v.1.4.3_r1645/vs2005/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
