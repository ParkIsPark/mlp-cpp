cmake_minimum_required(VERSION 3.24)
project(mlp_cpp VERSION 0.1.0 LANGUAGES CXX)

include(FetchContent)

# Eigen is header-only. Fetch its release into the ignored build directory.
set(EIGEN_BUILD_DOC OFF CACHE BOOL "" FORCE)
set(EIGEN_BUILD_TESTING OFF CACHE BOOL "" FORCE)
set(EIGEN_BUILD_PKGCONFIG OFF CACHE BOOL "" FORCE)
FetchContent_Declare(
    Eigen3
    GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
    GIT_TAG 5.0.1
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(Eigen3)

add_executable(eigen_smoke src/main.cpp)
target_compile_features(eigen_smoke PRIVATE cxx_std_20)
set_target_properties(eigen_smoke PROPERTIES CXX_EXTENSIONS OFF)
target_link_libraries(eigen_smoke PRIVATE Eigen3::Eigen)

if(MSVC)
    target_compile_options(eigen_smoke PRIVATE /W4 /permissive- /utf-8)
else()
    target_compile_options(eigen_smoke PRIVATE -Wall -Wextra -Wpedantic)
endif()

enable_testing()
add_test(NAME eigen_matrix_multiply COMMAND eigen_smoke)
