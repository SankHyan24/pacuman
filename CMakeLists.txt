cmake_minimum_required(VERSION 3.9)
# 指定Cmake最低版本
project(PaKuMan)
# 指定Project名字
set(CMAKE_CXX_STANDARD 11)
# 根目录里面设置，使用CXX的C11标准
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/map/lv1.pmm DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/map/lv2.pmm DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/map/lv3.pmm DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/map/lv4.pmm DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/map/lv5.pmm DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/map/lv6.pmm DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/map/lv7.pmm DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
add_subdirectory(lib)

add_executable( PaKuMan  
./sourcecode/global.c  
./sourcecode/pmanima.c  
./sourcecode/pmdirrt.c  
./sourcecode/pmeditor.c  
./sourcecode/pmerr.c  
./sourcecode/pmgame.c  
./sourcecode/pmhelp.c  
./sourcecode/pmLaucher.c  
./sourcecode/pmminit.c  
./sourcecode/pmrank.c  
./sourcecode/pmrun.c  
./sourcecode/pmsp.c  
./sourcecode/head/mpinclude.h  
./sourcecode/head/pmanima.h  
./sourcecode/head/pmdirrt.h  
./sourcecode/head/pmeditor.h  
./sourcecode/head/pmerr.h  
./sourcecode/head/pmgame.h  
./sourcecode/head/pmhelp.h  
./sourcecode/head/pmLaucher.h  
./sourcecode/head/pmminit.h  
./sourcecode/head/pmrank.h  
./sourcecode/head/pmrun.h  
./sourcecode/head/pmsp.h
./lib/exceptio.c  
./lib/genlib.c  
./lib/graphics.c  
./lib/imgui.c  
./lib/linkedlist.c  
./lib/random.c  
./lib/simpio.c  
./lib/strlib.c  
./lib/head/boolean.h  
./lib/head/exception.h  
./lib/head/extgraph.h  
./lib/head/gcalloc.h  
./lib/head/genlib.h  
./lib/head/global.h  
./lib/head/graphics.h  
./lib/head/imgui.h  
./lib/head/linkedlist.h  
./lib/head/random.h  
./lib/head/simpio.h  
./lib/head/strlib.h
)
target_link_libraries(PaKuMan GRAF)
target_include_directories(GRAF PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/sourcecode/head)
# add_custom_command(TARGET copy_map POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_file ${CMAKE_CURRENT_SOURCE_DIR}/map/lv1.pmm ${CMAKE_CURRENT_BINARY_DIR}/map.txt)

