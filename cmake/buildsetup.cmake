option(INFLUXDBLPTOOL_ENABLE_CODE_COVERAGE "Set this to ON to build unit tests")

set(CMAKE_CXX_STANDARD 20)   

if (MSVC)
    add_compile_options("$<$<CONFIG:RELEASE>:/W4;/WX>")
    add_compile_options("$<$<CONFIG:DEBUG>:/W4;/WX>")
else()
    add_compile_options("$<$<CONFIG:RELEASE>:-W;-Wall;-Werror;-Wshadow;-Wextra;-Wpedantic;-pedantic-errors>")
    if (INFLUXDBLPTOOL_ENABLE_CODE_COVERAGE)
        add_compile_options("$<$<CONFIG:DEBUG>:-W;-Wall;-Werror;-Wshadow;-Wextra;-Wpedantic;-pedantic-errors;-fprofile-arcs;-ftest-coverage>")
        add_link_options("$<$<CONFIG:DEBUG>:-lgcov;-coverage>")
    else()
        add_compile_options("$<$<CONFIG:DEBUG>:-W;-Wall;-Werror;-Wshadow;-Wextra;-Wpedantic;-pedantic-errors;>")
    endif()
endif()
