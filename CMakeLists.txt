cmake_minimum_required(VERSION 3.10)
project(Omnirend)

file(
    GLOB src_files
    "${CMAKE_CURRENT_SOURCE_DIR}/src/**.cpp"
)

set(BASE_INC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
file(
    GLOB inc_files
    "${BASE_INC_DIR}/**.h"
)

set(inc_dirs "${BASE_INC_DIR}")

set(BIN_NAME ezn_omnirend)
set(OMNIREND_LIB_TYPE SHARED CACHE STRING "Type of library omnirend should compile to (e.g. Shared, Static, etc.")
add_library(${BIN_NAME} ${OMNIREND_LIB_TYPE} ${src_files} ${inc_files})

###
# EXTERNAL LIBS
###
set(EXTERNAL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external")

# imgui
set(IMGUI_PATH "${EXTERNAL_DIR}/imgui")
file(GLOB imgui_src "${IMGUI_PATH}/*.cpp" "${IMGUI_PATH}/*.h")
set(IMGUI_BACKENDS_DIR "${IMGUI_PATH}/backends")
set(imgui_src "${imgui_src}" "${IMGUI_BACKENDS_DIR}/imgui_impl_glfw.h" "${IMGUI_BACKENDS_DIR}/imgui_impl_glfw.cpp")
set(imgui_src "${imgui_src}" "${IMGUI_BACKENDS_DIR}/imgui_impl_opengl3.h" "${IMGUI_BACKENDS_DIR}/imgui_impl_opengl3.cpp")
set(EZN_OMNIREND_IMGUI_LIB_TYPE SHARED CACHE STRING "Type of lib ImGui should compile to, e.g. SHARED, STATIC, etc.")
add_library(imgui ${EZN_OMNIREND_IMGUI_LIB_TYPE} ${imgui_src})
target_include_directories(imgui PUBLIC "${IMGUI_PATH}" "${IMGUI_BACKENDS_DIR}")
target_link_libraries(imgui glfw)

set(linked_libs "${linked_libs}" imgui)

target_include_directories(${BIN_NAME} PUBLIC ${inc_dirs})
target_link_libraries(${BIN_NAME} PUBLIC ${linked_libs})
set(EZN_OMNIREND_INCLUDE_DIRECTORIES "${inc_dirs}" PARENT_SCOPE)