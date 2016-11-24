cmake_minimum_required(VERSION 2.8)

# mycv
set(mycv_exe mycv)
file(GLOB_RECURSE mycv_srcs *.cpp)
message(warning ${mycv_srcs})
add_library(${mycv_exe} ${mycv_srcs})

include_directories(include)
include_directories(src)

