# Install script for directory: /Users/zt/Documents/EP-491/libs/libspatialaudio

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/zt/Documents/EP-491/libs/libspatialaudio/cmake/libspatialaudio.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libspatialaudio.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libspatialaudio.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libspatialaudio.a")
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/Users/zt/Documents/EP-491/libs/libspatialaudio/cmake/libspatialaudio.0.3.0.dylib"
    "/Users/zt/Documents/EP-491/libs/libspatialaudio/cmake/libspatialaudio.0.dylib"
    "/Users/zt/Documents/EP-491/libs/libspatialaudio/cmake/libspatialaudio.dylib"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libspatialaudio.0.3.0.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libspatialaudio.0.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libspatialaudio.dylib"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/spatialaudio" TYPE FILE FILES
    "/Users/zt/Documents/EP-491/libs/libspatialaudio/include/AmbisonicBase.h"
    "/Users/zt/Documents/EP-491/libs/libspatialaudio/include/AmbisonicDecoderPresets.h"
    "/Users/zt/Documents/EP-491/libs/libspatialaudio/include/AmbisonicProcessor.h"
    "/Users/zt/Documents/EP-491/libs/libspatialaudio/include/AmbisonicSpeaker.h"
    "/Users/zt/Documents/EP-491/libs/libspatialaudio/include/AmbisonicBinauralizer.h"
    "/Users/zt/Documents/EP-491/libs/libspatialaudio/include/AmbisonicEncoderDist.h"
    "/Users/zt/Documents/EP-491/libs/libspatialaudio/include/AmbisonicPsychoacousticFilters.h"
    "/Users/zt/Documents/EP-491/libs/libspatialaudio/include/AmbisonicTypesDefinesCommons.h"
    "/Users/zt/Documents/EP-491/libs/libspatialaudio/include/SpeakersBinauralizer.h"
    "/Users/zt/Documents/EP-491/libs/libspatialaudio/include/AmbisonicCommons.h"
    "/Users/zt/Documents/EP-491/libs/libspatialaudio/include/AmbisonicEncoder.h"
    "/Users/zt/Documents/EP-491/libs/libspatialaudio/include/Ambisonics.h"
    "/Users/zt/Documents/EP-491/libs/libspatialaudio/include/AmbisonicZoomer.h"
    "/Users/zt/Documents/EP-491/libs/libspatialaudio/include/mit_hrtf_filter.h"
    "/Users/zt/Documents/EP-491/libs/libspatialaudio/include/AmbisonicDecoder.h"
    "/Users/zt/Documents/EP-491/libs/libspatialaudio/include/AmbisonicMicrophone.h"
    "/Users/zt/Documents/EP-491/libs/libspatialaudio/include/AmbisonicSource.h"
    "/Users/zt/Documents/EP-491/libs/libspatialaudio/include/BFormat.h"
    "/Users/zt/Documents/EP-491/libs/libspatialaudio/include/mit_hrtf_lib.h"
    "/Users/zt/Documents/EP-491/libs/libspatialaudio/include/hrtf/hrtf.h"
    "/Users/zt/Documents/EP-491/libs/libspatialaudio/include/hrtf/mit_hrtf.h"
    "/Users/zt/Documents/EP-491/libs/libspatialaudio/include/hrtf/sofa_hrtf.h"
    "/Users/zt/Documents/EP-491/libs/libspatialaudio/include/normal/mit_hrtf_normal_44100.h"
    "/Users/zt/Documents/EP-491/libs/libspatialaudio/include/normal/mit_hrtf_normal_48000.h"
    "/Users/zt/Documents/EP-491/libs/libspatialaudio/include/normal/mit_hrtf_normal_88200.h"
    "/Users/zt/Documents/EP-491/libs/libspatialaudio/include/normal/mit_hrtf_normal_96000.h"
    "/Users/zt/Documents/EP-491/libs/libspatialaudio/source/kiss_fft/kiss_fftr.h"
    "/Users/zt/Documents/EP-491/libs/libspatialaudio/source/kiss_fft/kiss_fft.h"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/Users/zt/Documents/EP-491/libs/libspatialaudio/cmake/spatialaudio.pc")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/spatialaudio" TYPE FILE FILES "/Users/zt/Documents/EP-491/libs/libspatialaudio/cmake/config.h")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/Users/zt/Documents/EP-491/libs/libspatialaudio/cmake/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
