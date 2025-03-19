# CMake generated Testfile for 
# Source directory: C:/Ashish/myWork/coding/learning/projects/tataTechnolgies_project/BowlingGame
# Build directory: C:/Ashish/myWork/coding/learning/projects/tataTechnolgies_project/BowlingGame/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(BowlingGameTests "C:/Ashish/myWork/coding/learning/projects/tataTechnolgies_project/BowlingGame/build/Debug/BowlingGameTests.exe")
  set_tests_properties(BowlingGameTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Ashish/myWork/coding/learning/projects/tataTechnolgies_project/BowlingGame/CMakeLists.txt;43;add_test;C:/Ashish/myWork/coding/learning/projects/tataTechnolgies_project/BowlingGame/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(BowlingGameTests "C:/Ashish/myWork/coding/learning/projects/tataTechnolgies_project/BowlingGame/build/Release/BowlingGameTests.exe")
  set_tests_properties(BowlingGameTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Ashish/myWork/coding/learning/projects/tataTechnolgies_project/BowlingGame/CMakeLists.txt;43;add_test;C:/Ashish/myWork/coding/learning/projects/tataTechnolgies_project/BowlingGame/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(BowlingGameTests "C:/Ashish/myWork/coding/learning/projects/tataTechnolgies_project/BowlingGame/build/MinSizeRel/BowlingGameTests.exe")
  set_tests_properties(BowlingGameTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Ashish/myWork/coding/learning/projects/tataTechnolgies_project/BowlingGame/CMakeLists.txt;43;add_test;C:/Ashish/myWork/coding/learning/projects/tataTechnolgies_project/BowlingGame/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(BowlingGameTests "C:/Ashish/myWork/coding/learning/projects/tataTechnolgies_project/BowlingGame/build/RelWithDebInfo/BowlingGameTests.exe")
  set_tests_properties(BowlingGameTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Ashish/myWork/coding/learning/projects/tataTechnolgies_project/BowlingGame/CMakeLists.txt;43;add_test;C:/Ashish/myWork/coding/learning/projects/tataTechnolgies_project/BowlingGame/CMakeLists.txt;0;")
else()
  add_test(BowlingGameTests NOT_AVAILABLE)
endif()
