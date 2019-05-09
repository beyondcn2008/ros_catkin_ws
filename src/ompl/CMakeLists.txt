#############################################
# Construct configuration file              #
#############################################

cmake_minimum_required(VERSION 3.10)

file(TO_NATIVE_PATH "${CMAKE_CURRENT_SOURCE_DIR}" VERSION_DIR)
configure_file("${VERSION_DIR}/config.h.in" "${VERSION_DIR}/config.h")


#############################################
# recursively find all *.cpp files that     #
# correspond to the basic ompl library      #
#############################################
file(GLOB_RECURSE OMPL_SOURCE_CODE datastructures/*.cpp util/*.cpp base/*.cpp geometric/*.cpp control/*.cpp tools/*.cpp)

if(NOT OMPL_HAVE_EIGEN3)
    list(REMOVE_ITEM OMPL_SOURCE_CODE
        "${CMAKE_CURRENT_SOURCE_DIR}/util/src/ProlateHyperspheroid.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/base/samplers/informed/src/PathLengthDirectInfSampler.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/geometric/planners/rrt/src/VFRRT.cpp"
    )
endif()

#############################################
# Add enabled extensions to the source code #
#############################################

## replace XXX by the extension
#if (OMPL_EXTENSION_XXX)
#    file(GLOB_RECURSE OMPL_XXX_EXTENSION_SOURCE_CODE extensions/XXX/*.cpp)
#    set(OMPL_SOURCE_CODE ${OMPL_SOURCE_CODE} ${OMPL_XXX_EXTENSION_SOURCE_CODE})
#
##    if additional libraries need to be linked, they are added to manifest.xml for ROS
##    or they are added to the list of OMPL_LINK_LIBRARIES
#
#endif()

if (OMPL_EXTENSION_MORSE)
    file(GLOB_RECURSE OMPL_MORSE_EXTENSION_SOURCE_CODE extensions/morse/*.cpp)
    set(OMPL_SOURCE_CODE ${OMPL_SOURCE_CODE} ${OMPL_MORSE_EXTENSION_SOURCE_CODE})
endif()

if (OMPL_EXTENSION_OPENDE)
    file(GLOB_RECURSE OMPL_OPENDE_EXTENSION_SOURCE_CODE extensions/opende/*.cpp)
    set(OMPL_SOURCE_CODE ${OMPL_SOURCE_CODE} ${OMPL_OPENDE_EXTENSION_SOURCE_CODE})
    list(APPEND OMPL_LINK_LIBRARIES "${OPENDE_LIBRARY}")
endif()

if (OMPL_EXTENSION_TRIANGLE)
  file(GLOB_RECURSE OMPL_TRIANGLE_EXTENSION_SOURCE_CODE extensions/triangle/*.cpp)
  set(OMPL_SOURCE_CODE ${OMPL_SOURCE_CODE} ${OMPL_TRIANGLE_EXTENSION_SOURCE_CODE})
  list(APPEND OMPL_LINK_LIBRARIES ${TRIANGLE_LIBRARY})
endif()

#############################################
# Build and install the library             #
#############################################
if(MSVC OR IS_ICPC)
  add_library(ompl STATIC ${OMPL_SOURCE_CODE})
else(MSVC OR IS_ICPC)
  add_library(ompl SHARED ${OMPL_SOURCE_CODE})
endif(MSVC OR IS_ICPC)
target_link_libraries(ompl
  ${OMPL_LINK_LIBRARIES}
  ${Boost_DATE_TIME_LIBRARY}
  ${Boost_THREAD_LIBRARY}
  ${Boost_SERIALIZATION_LIBRARY}
  ${Boost_FILESYSTEM_LIBRARY}
  ${Boost_SYSTEM_LIBRARY}
  ${Boost_CHRONO_LIBRARY}
  ${CMAKE_THREAD_LIBS_INIT})

set(OMPL_VERSION "1.2.1")

if(MSVC)
  set_target_properties(ompl PROPERTIES VERSION "${OMPL_VERSION}" STATIC_LIBRARY_FLAGS "psapi.lib ws2_32.lib")
else(MSVC)
  if (MINGW)
    target_link_libraries(ompl psapi ws2_32)
    set_target_properties(ompl PROPERTIES LINK_FLAGS "-Wl,--export-all-symbols")
  endif(MINGW)
  set_target_properties(ompl PROPERTIES VERSION "${OMPL_VERSION}" SOVERSION "${OMPL_ABI_VERSION}")
endif(MSVC)


# install the library
include(GNUInstallDirs)
install(TARGETS ompl DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT ompl)
