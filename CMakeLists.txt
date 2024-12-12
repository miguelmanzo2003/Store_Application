cmake_minimum_required(VERSION 3.27)
project(Store_Application_Folder)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Store_Application_Folder
        Aisle.cpp
        Aisle.h
        drink.cpp
        drink.h
        food.cpp
        food.h
        guest.cpp
        guest.h
        Item.cpp
        Item.h
        main.cpp
        store.cpp
        store.h)
