cmake_minimum_required (VERSION 3.8)

if(DEFINED ENV{GITHUB_RUN_NUMBER})
    project (fashio_mnist VERSION 0.0.$ENV{GITHUB_RUN_NUMBER})
else ()
    project (fashio_mnist)
endif()

if (UNIX)
    find_package (Threads)
endif()

# Добавьте источник в исполняемый файл этого проекта.
add_executable (fashio_mnist "main.cpp" "tf_classifier.cpp" "check_tensor.cpp")

target_link_libraries(fashio_mnist ${CMAKE_THREAD_LIBS_INIT} tensorflow) 

if (UNIX)
    target_link_libraries (fashio_mnist Threads::Threads)
endif()

if (MSVC)
    target_compile_options(fashio_mnist PUBLIC
        /W4
    )
else ()

    target_compile_options(fashio_mnist PUBLIC
        -Wall -Wextra -pedantic -Werror
    )
endif()

set_target_properties(fashio_mnist PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
install(TARGETS fashio_mnist RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "0")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "1")
set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)
