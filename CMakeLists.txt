# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.22)
project ("Protobuf_learn")

#set(CMAKE_CXX_STANDARD 17)

# 包含目录 test, 递归执行test下的CMakeLists.txt
add_subdirectory(test)

# 指定可执行文件输出路径 bin
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 由main.cpp生成可执行程序 test_exe
add_executable(test_exe main.cpp)

# 链接 test 静态库
target_link_libraries(test_exe PRIVATE test)