APPS = ./app
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
SRC = ./src
FLAGS = -Wall -Werror  
FLAGGLUT = -lGL -lGLU -lglut -lSOIL


all: \
    libeb \
	myapps

libeb: \
    $(OBJ)/chao.o \
	$(OBJ)/torre.o \
	$(OBJ)/lua.o \
	$(OBJ)/textura.o \
	$(OBJ)/espaco.o

myapps: \
	cleanapp \
	$(BIN)/app

$(OBJ)/%.o: $(SRC)/%.cpp $(INCLUDE)/%.hpp
	g++ $(FLAGS) -c $< -I $(INCLUDE) -o $@ 

$(BIN)/%: $(APPS)/%.cpp
	g++ $(FLAGS) $< $(OBJ)/*.o -I $(INCLUDE) -o $@ $(FLAGGLUT)

run:
	$(BIN)/app

clean:
	rm -rf $(BIN)/* $(OBJ)/*

cleanapp:
	rm -rf $(BIN)/*