APP = Common

SRC = src
BLD = _bld
BIN = _bin

VCPKG_PATH = ./vcpkg_installed/x64-linux
EXTERN = ./_external
INC = include
LIB = lib

CPP = $(wildcard src/*.cpp src/*/*.cpp src/*/*/*.cpp src/*/*/*/*.cpp src/*/*/*/*/*.cpp src/*/*/*/*/*/*.cpp)
OBJ = $(patsubst src/%.cpp,$(BLD)/%.o,$(CPP))
DEP = $(OBJ:.o=.d)

MAKEFLAGS += -j$(shell nproc)

COMPILER = g++
FLAGS = -std=c++23 -Wall -Wextra -Wfatal-errors -Wno-misleading-indentation -fmodules-ts -MMD -MP -O2
INCLUDE = -I./src -I$(EXTERN)/$(INC)
LINKER = -L$(EXTERN)/$(LIB) -lfmt -lspdlog -lreflectcpp -ltomlplusplus -lglm

ifeq ($(OS), Windows_NT)
	CLEAN = del /Q
	EXT = .exe
else
	CLEAN = rm -rf
	EXT = 
endif

.PHONY: build run install clean clean-deep

build: $(APP)

$(APP): $(OBJ)
	@mkdir -p $(BIN)
	@$(COMPILER) $(FLAGS) $(OBJ) $(LINKER) -o $(BIN)/$(APP)
	@echo "Build complete: $(BIN)/$(APP)"

$(BLD)/%.o: $(SRC)/%.cpp
	@echo "Building $<"
	@mkdir -p $(dir $@)
	@$(COMPILER) $(FLAGS) $(INCLUDE) -c $< -o $@

-include $(DEP)

install:
	@echo "Installing, first time might take a while"
	@vcpkg install > /dev/null 2>&1
	@mkdir -p $(EXTERN)/$(INC)/ $(EXTERN)/$(LIB)/
	@mv -f $(VCPKG_PATH)/include/* $(EXTERN)/$(INC)/ || true
	@mv -f $(VCPKG_PATH)/lib/* $(EXTERN)/$(LIB)/ || true
	@rm -rf vcpkg_installed
	@echo "Install Complete"

run:
	@./$(BIN)/$(APP)$(EXT)

clean:
	@$(CLEAN) $(BIN)
	@echo "Cleaned"

deep-clean:
	@$(CLEAN) $(BIN) $(EXTERN) $(BLD)
	@echo "Cleaned"