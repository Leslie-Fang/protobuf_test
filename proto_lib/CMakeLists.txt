#https://cmake.org/cmake/help/v3.12/command/string.html
file(GLOB files *.proto)
foreach(one ${files})
	string(REGEX REPLACE "^.*/(.*.proto)$" "\\1" pb_file ${one})
	string(REGEX REPLACE "^.*/(.*).proto$" "\\1.pb.h" pbh_file ${one})
	string(REGEX REPLACE "^.*/(.*).proto$" "\\1.pb.cc" pbc_file ${one})
	set(pb_files ${pb_files} ${pb_file})
	set(pbh_files ${pbh_files} ${pbh_file})
	set(pbc_files ${pbc_files} ${pbc_file})
	add_custom_command(OUTPUT ${pbh_file} ${pbc_file}
		COMMAND protoc --cpp_out . ${CMAKE_CURRENT_SOURCE_DIR}/${pb_file} -I${CMAKE_CURRENT_SOURCE_DIR} 
		DEPENDS ${pb_file})
endforeach()
add_library(test_comm_proto ${pbc_files})
target_include_directories(test_comm_proto PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(test_comm_proto PRIVATE protobuf pthread)