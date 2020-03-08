# read: http://www.cmake.org/Wiki/CMake/Tutorials/How_to_create_a_ProjectConfig.cmake_file
cmake_minimum_required(VERSION 2.8.4)
project(dcop_generator_pdcdcop C CXX)
set(dcop_generator_pdcdcop_MAJOR_VERSION 0)
set(dcop_generator_pdcdcop_MINOR_VERSION 1)
set(dcop_generator_pdcdcop_PATCH_VERSION 0)
set(VERSION  ${dcop_generator_pdcdcop_MAJOR_VERSION}.${dcop_generator_pdcdcop_MINOR_VERSION}.${dcop_generator_pdcdcop_PATCH_VERSION})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "/Users/khoihd/Dropbox/dcop_generator_pdcdcop/build")

set(SOURCE_DIR src/)
set(LIB_DIR lib/)
set(INCLUDE_DIR include/)

include_directories(
  "${SOURCE_DIR}"
  "${INCLUDE_DIR}"
  "${LIB_DIR}/rapidxml-1.13" # rapid-xml library
  "${LIB_DIR}/misc_utils"
)

set(SOURCE_FILES src/main.cpp
	include/Kernel/agent.hpp
	include/Kernel/constraint.hpp
	include/Kernel/relation.hpp
	include/Kernel/domain.hpp
	include/Kernel/variable.hpp
	include/Kernel/constants.hpp
	include/Kernel/types.hpp

	include/Graph/graph-utils.hpp
	include/Graph/graph.hpp
	include/Graph/planar-graph.hpp
	include/Graph/random-graph.hpp
	include/Graph/scale-free-graph.hpp

	include/IO/input.hpp
	include/IO/output.hpp
	include/IO/output-topology.hpp
	include/IO/output-xml.hpp
	include/IO/output-dalo.hpp
	include/IO/output-max_sum.hpp
	include/IO/output-wcsp.hpp

	include/Instance/instance.hpp
	include/Instance/instance-factory.hpp
	include/Instance/random-instance.hpp
	include/Instance/scale-free-instance.hpp
	include/Instance/grid-instance.hpp
	include/Instance/meeting_scheduling_instance.hpp
	include/Instance/acgdr_instance.hpp

	src/Graph/graph.cpp
        src/Graph/planar-graph.cpp
	src/Graph/random-graph.cpp
	src/Graph/scale-free-graph.cpp
	src/Graph/graph-utils.cpp

	src/IO/output.cpp
	src/IO/input.cpp
	src/IO/output-topology.cpp
	src/IO/output-xml.cpp
	src/IO/output-dalo.cpp
	src/IO/output-max_sum.cpp
	src/IO/output_wcsp.cpp

	src/Instance/instance.cpp
	src/Instance/instance-factory.cpp
	src/Instance/random-instance.cpp
	src/Instance/scale-free-instance.cpp
	src/Instance/grid-instance.cpp
	src/Instance/meeting_scheduling_instance.cpp
	src/Instance/acgdr_instance.cpp
)

add_executable(dcop_generator_pdcdcop ${SOURCE_FILES})
