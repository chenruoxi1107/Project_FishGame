# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\FishGame_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\FishGame_autogen.dir\\ParseCache.txt"
  "FishGame_autogen"
  )
endif()
