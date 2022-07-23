include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        # URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(../FakeIt/single_header/gtest)

# Now simply link against gtest or gtest_main as needed. Eg
enable_testing()

add_executable(hello_test hello_test.cpp ut_main.cpp fake_test.cpp)
add_executable(benchmark benchmark.cpp)
target_link_libraries(hello_test gtest_main gmock_main hello_lib)       # gtest_main  gmock_main 分别引入 gtest 和 gmock

include(GoogleTest)
gtest_discover_tests(hello_test)