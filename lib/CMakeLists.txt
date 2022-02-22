add_library(GRAF STATIC 
./exceptio.c  
./genlib.c  
./graphics.c  
./imgui.c  
./linkedlist.c  
./random.c  
./simpio.c  
./strlib.c  
./head/boolean.h  
./head/exception.h  
./head/extgraph.h  
./head/gcalloc.h  
./head/genlib.h  
./head/global.h  
./head/graphics.h  
./head/imgui.h  
./head/linkedlist.h  
./head/random.h  
./head/simpio.h  
./head/strlib.h)
target_include_directories(GRAF PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/head)