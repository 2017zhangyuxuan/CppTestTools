add_test( FakeitTest.test_fake_it C:/Users/Admin/CLionProjects/Test/cmake-build-debug/test/hello_test.exe [==[--gtest_filter=FakeitTest.test_fake_it]==] --gtest_also_run_disabled_tests)
set_tests_properties( FakeitTest.test_fake_it PROPERTIES WORKING_DIRECTORY C:/Users/Admin/CLionProjects/Test/cmake-build-debug/test SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( HelloTest.BasicAssertions C:/Users/Admin/CLionProjects/Test/cmake-build-debug/test/hello_test.exe [==[--gtest_filter=HelloTest.BasicAssertions]==] --gtest_also_run_disabled_tests)
set_tests_properties( HelloTest.BasicAssertions PROPERTIES WORKING_DIRECTORY C:/Users/Admin/CLionProjects/Test/cmake-build-debug/test SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( HelloTest.TestGmock C:/Users/Admin/CLionProjects/Test/cmake-build-debug/test/hello_test.exe [==[--gtest_filter=HelloTest.TestGmock]==] --gtest_also_run_disabled_tests)
set_tests_properties( HelloTest.TestGmock PROPERTIES WORKING_DIRECTORY C:/Users/Admin/CLionProjects/Test/cmake-build-debug/test SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( hello_test_TESTS FakeitTest.test_fake_it HelloTest.BasicAssertions HelloTest.TestGmock)
