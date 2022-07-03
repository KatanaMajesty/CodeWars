cmake_minimum_required(VERSION 3.2.0)
project(codewars-katas VERSION 0.0.1 LANGUAGES C CXX)

include_directories(igloo/igloo)

set(CODEWARS_KATAS 
    int32_to_ipv4:kyu5
)

enable_testing()
foreach (pair IN LISTS CODEWARS_KATAS)
    string(FIND "${pair}" ":" pos)
    if (pos LESS 1)
        message(WARNING "Skipping malformed pair (no var name): ${pair}")
    else ()
        string(SUBSTRING "${pair}" 0 "${pos}" var) # kata's name
        math(EXPR pos "${pos} + 1") # Skip the separator
        string(SUBSTRING "${pair}" "${pos}" -1 val) # kata's kyu
        set("${var}" "${val}")
        add_executable(${var} ${val}/${var}.cpp)
        add_test(${var}-test ${var})
        message(STATUS "Setting a test ${var}-test at ${val}/${var}.cpp")
    endif ()
endforeach ()

