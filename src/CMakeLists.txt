# CMakeList.txt : CMake project for quantum-portfolio-optimizer, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (quantum-portfolio-optimizer "main.cpp"  "quantum_algorithms/QAOA.cpp" "quantum_algorithms/GroverSearch.cpp" "quantum_algorithms/VQE.cpp" "quantum_algorithms/QuantumAnnealing.cpp" "quantum_algorithms/VQECostFunction.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET quantum-portfolio-optimizer PROPERTY CXX_STANDARD 20)
endif()

# Set the runtime library for debug and release builds
if(MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")
endif()

if(MSVC)
    # Set runtime library flags for Debug and Release configurations
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")  # Debug -> /MDd (multi-threaded debug DLL)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")  # Release -> /MD (multi-threaded DLL)
endif()

# Ensure consistency for all projects in the solution
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDLL" CACHE STRING "MSVC runtime library" FORCE)

# Define paths for libraries based on the platform
if(WIN32)
    # Specify the paths to the libraries and includes for Windows
    set(LIB_PATH "C:/Users/chris/vcpkg/installed/x64-windows/lib")
    set(INCLUDE_PATH "C:/Users/chris/vcpkg/installed/x64-windows/include")
    set(BIN_PATH "C:/Users/chris/vcpkg/installed/x64-windows/bin")

    # Add include directories
    include_directories(${INCLUDE_PATH})

    # Specify the paths to the libraries
    set(LIBXML2_LIB_PATH "${LIB_PATH}/libxml2.lib")
    set(LIBICONV_LIB_PATH "${LIB_PATH}/iconv.lib")
    set(GTEST_LIB_PATH "${LIB_PATH}/gtest.lib")
    set(ZLIB_LIB_PATH "${LIB_PATH}/zlib.lib")
    set(BOOST_FILESYSTEM_LIB_PATH "${LIB_PATH}/boost_filesystem-vc143-mt-x64-1_85.lib")
    set(BOOST_MOVE_LIB_PATH "${LIB_PATH}/boost_move-vc143-mt-x64-1_85.lib")
    set(QUANTLIB_PATH "${LIB_PATH}/QuantLib-x64-mt-s.lib")

    # Link against Windows libraries
    target_link_libraries( quantum-portfolio-optimizer PRIVATE 
        ${FMT_LIB_PATH} 
        ${LIBXML2_LIB_PATH} 
        ${LIBICONV_LIB_PATH} 
        ${GTEST_LIB_PATH} 
        ${ZLIB_LIB_PATH} 
        ${BOOST_FILESYSTEM_LIB_PATH}
        ${QUANTLIB_PATH}
    )

    # Copy necessary files to the output directory
    add_custom_command(TARGET quantum-portfolio-optimizer POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/quantum-portfolio-optimizer/input" 
        $<TARGET_FILE_DIR:quantum-portfolio-optimizer>/input
    )

    # Copy DLLs to the output directory
    add_custom_command(TARGET quantum-portfolio-optimizer POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${BIN_PATH}/spdlog.dll" $<TARGET_FILE_DIR:quantum-portfolio-optimizer>
    )
    add_custom_command(TARGET quantum-portfolio-optimizer POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${BIN_PATH}/libxml2.dll" $<TARGET_FILE_DIR:quantum-portfolio-optimizer>
    )
    add_custom_command(TARGET quantum-portfolio-optimizer POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${BIN_PATH}/liblzma.dll" $<TARGET_FILE_DIR:quantum-portfolio-optimizer>
    )
    add_custom_command(TARGET quantum-portfolio-optimizer POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${BIN_PATH}/iconv-2.dll" $<TARGET_FILE_DIR:quantum-portfolio-optimizer>
    )
    add_custom_command(TARGET quantum-portfolio-optimizer POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${Boost_LIBRARY_DIRS}/*.dll" $<TARGET_FILE_DIR:quantum-portfolio-optimizer>
    )

    # Enable Google Test
    enable_testing()

elseif(UNIX)  # This will match Linux/Unix systems
    # Specify the paths to the libraries and includes for UNIX
    set(LIB_PATH "${CMAKE_SOURCE_DIR}/vcpkg/installed/x64-linux/lib")
    set(INCLUDE_PATH "${CMAKE_SOURCE_DIR}/vcpkg/installed/x64-linux/include")

    # Add include directories
    include_directories(${INCLUDE_PATH})

    # Specify the paths to the libraries
    set(LIBXML2_LIB_PATH "${LIB_PATH}/libxml2.so")
    set(LIBICONV_LIB_PATH "${LIB_PATH}/libiconv.so")
    set(FMT_LIB_PATH "${LIB_PATH}/libfmt.so")
    set(BOOST_FILESYSTEM_LIB_PATH "${LIB_PATH}/libboost_filesystem.so")

    # Link against UNIX libraries
    target_link_libraries(xbrl-taxonomy-package-conformant-processor PRIVATE 
        ${FMT_LIB_PATH} 
        ${LIBXML2_LIB_PATH} 
        ${LIBICONV_LIB_PATH} 
        ${GTEST_LIB_PATH} 
        ${ZLIB_LIB_PATH} 
        ${BOOST_FILESYSTEM_LIB_PATH}
    )

    # Copy data.xml to the output directory
    add_custom_command(TARGET xbrl-taxonomy-package-conformant-processor POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/xbrl-taxonomy-package-conformant-processor/input" 
        $<TARGET_FILE_DIR:xbrl-taxonomy-package-conformant-processor>/input
    )
endif()
