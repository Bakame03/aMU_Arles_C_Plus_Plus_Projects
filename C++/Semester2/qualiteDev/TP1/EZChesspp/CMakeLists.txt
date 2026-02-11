cmake_minimum_required(VERSION 3.11)

project(EZChess,CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(EZChess
  AbstractPiece.cpp
  AbstractZone.cpp
  Bishop.cpp
  BlackAndWhitePiece.cpp
  ChessBoard.cpp
  ChessBoardWindow.cpp
  ez-draw++.cpp
  King.cpp
  Knight.cpp
  main.cpp
  Pawn.cpp
  Point.cpp
  Queen.cpp
  Rook.cpp
  SquareZone.cpp
)

if (WIN32)
find_library(GDI32 gdi32)
find_library(GDI32 msimg32)
target_link_libraries(EZChess gdi32 msimg32)
endif (WIN32)

if (UNIX)
  find_package(X11 REQUIRED)
  target_link_libraries(EZChess X11 Xext)
endif (UNIX)
