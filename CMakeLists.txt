cmake_minimum_required(VERSION 3.19)
project(MusicPlayer LANGUAGES CXX)

set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(MusicPlayer
    WIN32 MACOSX_BUNDLE
    main.cpp
    musicplayer.cpp
    musicplayer.h
    musicplayer.ui
    Resources.qrc
    btform.h
    btform.cpp
    btform.ui
    recbox.h recbox.cpp recbox.ui
    recboxitem.h recboxitem.cpp recboxitem.ui
)

target_link_libraries(MusicPlayer
    PRIVATE
        Qt::Core
        Qt::Widgets
)

install(TARGETS MusicPlayer
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET MusicPlayer
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
