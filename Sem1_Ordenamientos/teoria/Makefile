# Compilador
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic

# Detectar sistema operativo
ifeq ($(OS),Windows_NT)
    EXEEXT := .exe
else
    EXEEXT :=
endif

# Todos los archivos .cpp del directorio actual
SRCS := $(wildcard *.cpp)

# Nombres de ejecutables (mismo nombre que el .cpp, extensión según OS)
TARGETS := $(SRCS:%.cpp=%$(EXEEXT))

# Regla por defecto
all: $(TARGETS)

# Regla genérica cpp -> ejecutable
%$(EXEEXT): %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# Limpiar ejecutables
clean:
	rm -f $(TARGETS)




# # Compilador
# CXX := g++
# CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic

# # Detectar sistema operativo
# ifeq ($(OS),Windows_NT)
#     EXEEXT := .exe
# else
#     EXEEXT :=
# endif

# # Buscar todos los .cpp
# SRCS := $(wildcard *.cpp)

# # Generar los ejecutables correspondientes
# TARGETS := $(SRCS:.cpp=$(EXEEXT))

# # Regla por defecto
# all: $(TARGETS)

# # Regla genérica cpp -> ejecutable
# %$(EXEEXT): %.cpp
# 	$(CXX) $(CXXFLAGS) $< -o $@

# # Limpiar
# clean:
# 	rm -f $(TARGETS)




# Automatización real
# Cada programa es independiente
# El compilador y flags no se eligen al azar
# No compilar “a mano” con comandos distintos

# Evitamos
# Copiar/pegar comandos 
# Ejecutables desactualizados
# Flags inconsistentes
