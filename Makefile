# Compilador y opciones
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Archivos fuente
SRCS = algoritmo.cc contpalabras.cc docbase.cc generador1.cc generador2.cc generador21.cc similitud_Jaccard.cc
EXES = $(SRCS:.cc=.exe)

# Carpeta de generación de archivos
GENERATIONS_DIR = generaciones

# Regla principal
all: $(EXES)

# Regla para compilar cada ejecutable
%.exe: %.cc
	$(CXX) $(CXXFLAGS) -o $@ $<

# Reglas para ejecutar cada programa individualmente
run_algoritmo: algoritmo.exe
	./algoritmo.exe

run_contpalabras: contpalabras.exe
	./contpalabras.exe

run_docbase: docbase.exe
	./docbase.exe

run_generador1: generador1.exe
	./generador1.exe

run_generador2: generador2.exe
	./generador2.exe

run_generador21: generador21.exe
	./generador21.exe

run_similitud: similitud.exe
	./similitud.exe

# Regla de limpieza
clean:
	rm -f $(EXES)
	rm -rf $(GENERATIONS_DIR)
