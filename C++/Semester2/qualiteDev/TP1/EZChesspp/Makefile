# Makefile pour EZChesspp
# Variables modifiables pour passer de Linux à Windows

# Compilateur
CXX = g++

# Options de compilation
CXXFLAGS = -Wall -std=c++11

# Nom de l'exécutable
EXEC = EZChess

# Options d'édition de liens (selon l'OS)
# Sous Linux :
LDFLAGS = -lXext -lX11
# Sous Windows (décommenter la ligne ci-dessous et commenter celle du dessus) :
# LDFLAGS = -lgdi32 -lmsimg32

# Liste des fichiers objets
OBJ = AbstractPiece.o AbstractZone.o Bishop.o BlackAndWhitePiece.o \
      ChessBoard.o ChessBoardWindow.o ez-draw++.o King.o Knight.o \
      main.o Pawn.o Point.o Queen.o Rook.o SquareZone.o

# Règle par défaut : édition de liens
$(EXEC): $(OBJ)
	$(CXX) -o $(EXEC) $(OBJ) $(LDFLAGS)

# Règles de compilation

AbstractPiece.o: AbstractPiece.cpp ez-draw++.hpp AbstractPiece.hpp \
  Point.hpp Chess.hpp
	$(CXX) $(CXXFLAGS) -c AbstractPiece.cpp

AbstractZone.o: AbstractZone.cpp ez-draw++.hpp AbstractZone.hpp Point.hpp \
  Chess.hpp AbstractPiece.hpp
	$(CXX) $(CXXFLAGS) -c AbstractZone.cpp

Bishop.o: Bishop.cpp ez-draw++.hpp AbstractZone.hpp Point.hpp Chess.hpp \
  Bishop.hpp BlackAndWhitePiece.hpp AbstractPiece.hpp
	$(CXX) $(CXXFLAGS) -c Bishop.cpp

BlackAndWhitePiece.o: BlackAndWhitePiece.cpp ez-draw++.hpp \
  BlackAndWhitePiece.hpp AbstractPiece.hpp Point.hpp Chess.hpp \
  AbstractZone.hpp
	$(CXX) $(CXXFLAGS) -c BlackAndWhitePiece.cpp

ChessBoard.o: ChessBoard.cpp ez-draw++.hpp ChessBoard.hpp SquareZone.hpp \
  AbstractZone.hpp Point.hpp Chess.hpp BlackAndWhitePiece.hpp \
  AbstractPiece.hpp King.hpp Queen.hpp Bishop.hpp Knight.hpp Rook.hpp \
  Pawn.hpp
	$(CXX) $(CXXFLAGS) -c ChessBoard.cpp

ChessBoardWindow.o: ChessBoardWindow.cpp ChessBoardWindow.hpp \
  ez-draw++.hpp ChessBoard.hpp SquareZone.hpp AbstractZone.hpp Point.hpp \
  Chess.hpp BlackAndWhitePiece.hpp AbstractPiece.hpp
	$(CXX) $(CXXFLAGS) -c ChessBoardWindow.cpp

ez-draw++.o: ez-draw++.cpp ez-draw++.hpp
	$(CXX) $(CXXFLAGS) -c ez-draw++.cpp

King.o: King.cpp ez-draw++.hpp AbstractZone.hpp Point.hpp Chess.hpp \
  King.hpp BlackAndWhitePiece.hpp AbstractPiece.hpp
	$(CXX) $(CXXFLAGS) -c King.cpp

Knight.o: Knight.cpp ez-draw++.hpp ChessBoard.hpp SquareZone.hpp \
  AbstractZone.hpp Point.hpp Chess.hpp BlackAndWhitePiece.hpp \
  AbstractPiece.hpp Knight.hpp
	$(CXX) $(CXXFLAGS) -c Knight.cpp

main.o: main.cpp ChessBoardWindow.hpp ez-draw++.hpp ChessBoard.hpp \
  SquareZone.hpp AbstractZone.hpp Point.hpp Chess.hpp \
  BlackAndWhitePiece.hpp AbstractPiece.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Pawn.o: Pawn.cpp ez-draw++.hpp AbstractZone.hpp Point.hpp Chess.hpp \
  Pawn.hpp BlackAndWhitePiece.hpp AbstractPiece.hpp
	$(CXX) $(CXXFLAGS) -c Pawn.cpp

Point.o: Point.cpp ez-draw++.hpp Point.hpp Chess.hpp
	$(CXX) $(CXXFLAGS) -c Point.cpp

Queen.o: Queen.cpp ez-draw++.hpp AbstractZone.hpp Point.hpp Chess.hpp \
  Queen.hpp BlackAndWhitePiece.hpp AbstractPiece.hpp
	$(CXX) $(CXXFLAGS) -c Queen.cpp

Rook.o: Rook.cpp ez-draw++.hpp AbstractZone.hpp Point.hpp Chess.hpp \
  Rook.hpp BlackAndWhitePiece.hpp AbstractPiece.hpp
	$(CXX) $(CXXFLAGS) -c Rook.cpp

SquareZone.o: SquareZone.cpp ez-draw++.hpp SquareZone.hpp \
  AbstractZone.hpp Point.hpp Chess.hpp
	$(CXX) $(CXXFLAGS) -c SquareZone.cpp

# Nettoyage
clean:
	rm -f $(OBJ) $(EXEC)
