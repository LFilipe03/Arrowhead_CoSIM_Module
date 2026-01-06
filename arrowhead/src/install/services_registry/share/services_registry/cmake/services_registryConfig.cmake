# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_services_registry_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED services_registry_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(services_registry_FOUND FALSE)
  elseif(NOT services_registry_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(services_registry_FOUND FALSE)
  endif()
  return()
endif()
set(_services_registry_CONFIG_INCLUDED TRUE)

# output package information
if(NOT services_registry_FIND_QUIETLY)
  message(STATUS "Found services_registry: 0.0.0 (${services_registry_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'services_registry' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${services_registry_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(services_registry_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${services_registry_DIR}/${_extra}")
endforeach()
