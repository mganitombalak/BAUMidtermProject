cmake_minimum_required(VERSION 3.8)

project(CSVParser)

set(CMAKE_CXX_STANDARD 11)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.65.1 COMPONENTS system program_options thread filesystem
        date_time chrono timer regex serialization)

set(SOURCE_FILES
        ApplicationManager.cpp
        Headers/ApplicationManager.h
        BaseDataModel.cpp
        Headers/BaseDataModel.h
        DataCollector.cpp
        Headers/DataCollector.h
        Date.cpp
        Headers/Date.h
        entryPoint.cpp
        FileDataAdapter.cpp
        Headers/FileDataAdapter.h
        FileManager.cpp
        Headers/FileManager.h
        Headers/FourDigitDatePart.h
        Headers/Global.h
        MenuItem.cpp
        Headers/MenuItem.h
        Movie.cpp
        Headers/Movie.h
        Headers/MovieStatus.h
        Headers/resource.h
        Headers/TwoDigitDatePart.h
        Utility.cpp
        Headers/Utility.h)

add_executable(CSVParser ${SOURCE_FILES})

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(CSVParser ${Boost_LIBRARIES})
endif()
