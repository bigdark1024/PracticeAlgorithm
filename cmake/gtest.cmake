include(ExternalProject)

set(gtest_src        ${CMAKE_BINARY_DIR}/gtest/src)
set(gtest_binary     ${CMAKE_BINARY_DIR}/gtest/build)
set(gtest_download   ${CMAKE_BINARY_DIR}/gtest/download)
set(gtest_install    ${CMAKE_CURRENT_SOURCE_DIR}/output/)

ExternalProject_Add(googletest
        URL                "${TOP_SOURCE_DIR}/external/3rd/googletest-release-1.8.0.zip"
        DOWNLOAD_DIR        ${gtest_download}
        SOURCE_DIR         "${gtest_src}"
        CONFIGURE_COMMAND   ${CMAKE_COMMAND} ${gtest_src} -DCMAKE_INSTALL_PREFIX=${gtest_install}
        BINARY_DIR          ${gtest_binary}
        INSTALL_COMMAND     ${CMAKE_MAKE_PROGRAM} install
        )