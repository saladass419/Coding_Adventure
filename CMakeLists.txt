cmake_minimum_required(VERSION 3.22.1)
project(Coding_Adventure)

set(CMAKE_CXX_STANDARD 11)

add_executable(Coding_Adventure Game.cpp Board.cpp DerivedSymbols.cpp Item.cpp ItemShop.cpp ItemUser.cpp List.cpp Player.cpp RemovedSymbolUser.cpp Symbol.cpp SymbolShop.cpp SymbolUser.cpp Neutral.cpp gtest_lite.h memtrace.cpp)
