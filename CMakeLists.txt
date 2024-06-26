cmake_minimum_required(VERSION 3.5)

project(ChessBattle VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        view.cpp
        view.h
        view.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ChessBattle
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        model.h
        controller.h
        model.cpp
        controller.cpp
        assets.qrc
        chess_piece.cpp
        chess_piece.h
        piece_color.h
        game.cpp
        game.h
        pawn.h
        pawn.cpp
        rook.h
        rook.cpp
        knight.h
        knight.cpp
        bishop.h
        bishop.cpp
        king.h
        king.cpp
        queen.h
        queen.cpp
        timer.h
        timer.cpp
        player.h
        player.cpp
        chess_board.h
        chess_board.cpp
        winner_dialog.cpp
        winner_dialog.h
        promotion_dialog.h
        promotion_dialog.cpp
        moves_history.h
        moves_history.cpp
        settings_dialog.h
        settings_dialog.cpp
        moves_history_view.h
        moves_history_view.cpp
        player_view.h
        player_view.cpp
        chessboard_view.h
        chessboard_view.cpp
        dialogs_view.h
        dialogs_view.cpp


    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET ChessBattle APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(ChessBattle SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(ChessBattle
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(ChessBattle PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.ChessBattle)
endif()
set_target_properties(ChessBattle PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS ChessBattle
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ChessBattle)
endif()
