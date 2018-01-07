set(TARGET_NAME uwl_show_block.elf)

project(${TARGET_NAME})
cmake_minimum_required(VERSION 2.6)
cmake_policy(SET CMP0015 NEW)
set(CMAKE_VERBOSE_MAKEFILE ON)

if (UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -D_UNICODE -DPCRE2_CODE_UNIT_WIDTH=8 -DENABLE_PCRE2 -O0 -g -fpermissive -fstack-check")
    #set(wxWidgets_CONFIG_OPTIONS --toolkit=base --prefix=/usr)
    set(CMAKE_EXE_LINKER_FLAGS "-lpthread")
endif (UNIX)

find_package(PkgConfig REQUIRED)

# can build elf file to run curl
#add_executable(${TARGET_NAME} console.cpp)
add_executable(${TARGET_NAME} call_msgbox.cpp)

# For wxWidgets
# For wxWidgets

find_package(wxWidgets COMPONENTS base REQUIRED)
    if(wxWidgets_FOUND)
        include(${wxWidgets_USE_FILE})
        # and for each of your dependent executable/library targets:
        target_link_libraries(${TARGET_NAME} ${wxWidgets_LIBRARIES})
        target_include_directories(${TARGET_NAME} PUBLIC ${wxWidgets_INCLUDE_DIRS})
        target_compile_options(${TARGET_NAME} PUBLIC ${wxWidgets_CFLAGS_OTHER})
    endif()


