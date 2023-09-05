cmake_minimum_required(VERSION 3.11)

project(character CXX)

set(CMAKE_CXX_STANDARD 23)

# Специфичные настройки для компилятора Visual Studio
if(MSVC)
    # Генерируем статическую заглушку для динамических библиотек
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)

    # Включаем высокий уровень предупреждений
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()

# Объявляем библиотеку
add_library(character SHARED "include/character/character.h" "src/character.cc" "include/character/container.h" "src/container.cc")
target_include_directories(character PUBLIC "include")


# Подключаем googletest
include(FetchContent)
FetchContent_Declare(googletest URL "C:/Users/regis/oop-repository/01-project-structure/gtest.zip")
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Объявляем тесты
add_executable(Console "Console/Console.cc")
add_executable(character_tests "tests/character_tests.cc" "include/character/container.h")
target_link_libraries(Console character GTest::gtest_main)
target_link_libraries(character_tests character GTest::gtest_main)


