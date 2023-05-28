add_test (NAME add_authors COMMAND add_authors_test)
add_executable (add_authors_test add_authors_test.cpp)
target_link_libraries (add_authors_test Sources gtest_main)
