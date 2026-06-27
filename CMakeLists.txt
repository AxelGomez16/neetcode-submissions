cmake_minimum_required(VERSION 3.10)
project(NeetcodeProblems)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Enable debug symbols
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")

# Find all cpp files recursively
file(GLOB_RECURSE CPP_FILES "*.cpp")

# Create executable for each cpp file
foreach(CPP_FILE ${CPP_FILES})
    # Get the folder name (problem name)
    get_filename_component(PROBLEM_FOLDER ${CPP_FILE} DIRECTORY)
    get_filename_component(FOLDER_NAME ${PROBLEM_FOLDER} NAME)
    
    # Get the file name without extension
    get_filename_component(EXE_NAME ${CPP_FILE} NAME_WE)
    
    # Use folder + file name as executable name to avoid duplicate target names
    set(TARGET_NAME "${FOLDER_NAME}_${EXE_NAME}")
    string(REPLACE " " "_" TARGET_NAME "${TARGET_NAME}")
    string(REPLACE "-" "_" TARGET_NAME "${TARGET_NAME}")
    
    # Create executable
    add_executable(${TARGET_NAME} ${CPP_FILE})
    
    # Set properties for better organization
    set_target_properties(${TARGET_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${TARGET_NAME}"
        DEBUG_POSTFIX "_debug"
    )
    
    # If the problem has multiple cpp files in the same folder
    # you can link them together (uncomment if needed)
    # target_include_directories(${TARGET_NAME} PRIVATE ${PROBLEM_FOLDER})
    
    # Print progress
    message(STATUS "Added target: ${TARGET_NAME} from ${CPP_FILE}")
endforeach()

# Optional: Group targets by folder in IDE
foreach(TARGET ${CPP_FILES})
    get_filename_component(PARENT_DIR ${TARGET} DIRECTORY)
    get_filename_component(GROUP_NAME ${PARENT_DIR} NAME)
    source_group("${GROUP_NAME}" FILES ${TARGET})
endforeach()