PROJECT = pathfinder

CL = clang
CLFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

INC_DIR = ./inc
SRC_DIR = ./src
OBJ_DIR = ./obj

LIBMX_DIR = ./libmx

$(PROJECT): clean
	make all -sC $(LIBMX_DIR)
	mkdir -p obj
	cp $(INC_DIR)/*.h $(SRC_DIR)/*.c ./
	$(CL) $(CLFLAGS) -c *.c -include *.h -I $(LIBMX_DIR)/inc
	rm -rf *.c *.h
	mv *.o $(OBJ_DIR)
	$(CL) $(CLFLAGS) ./$(OBJ_DIR)/*.o -L$(LIBMX_DIR) -lmx -o $(PROJECT)

all: install

install: $(PROJECT)

uninstall:
	rm -rf $(PROJECT)

reinstall: uninstall install

clean:
	make clean -sC $(LIBMX_DIR)
	rm -rf $(OBJ_DIR)
	rm -rf $(PROJECT)
	rm -rf *.o *.h *.c *.gch
