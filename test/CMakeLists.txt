cmake_minimum_required(VERSION 3.22)
project(test)

#set(CMAKE_CXX_STANDARD 17)

#将当前目录的所有cpp文件存入SRC
aux_source_directory(./ SRC)

#用SRC 生成test静态库
add_library(test ${SRC})

#test链接protobuf动态库
target_link_libraries(test PUBLIC protobuf)

# 对外暴露头文件（如果 test 有头文件，方便主工程 include）
target_include_directories(test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})