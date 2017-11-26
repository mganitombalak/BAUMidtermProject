cmake_minimum_required(VERSION 3.8)

project(DVDEngine)

set(CMAKE_CXX_STANDARD 11)

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

add_executable(DVDEngine ${SOURCE_FILES})