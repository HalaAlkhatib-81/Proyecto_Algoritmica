# Compilador y opciones
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Archivos fuente
SRCS = algoritmo.cc contpalabras.cc docbase.cc generador1.cc generador2.cc generador21.cc sim_J.cc
EXES = $(SRCS:.cc=.exe)

# Carpeta de generación de archivos
GENERATIONS_DIR = generaciones

# Regla principal
all: $(EXES)

# Regla para compilar cada ejecutable
%.exe: %.cc
	$(CXX) $(CXXFLAGS) -o $@ $<

# Reglas para ejecutar cada programa individualmente
run_a: algoritmo.exe
	./algoritmo.exe

run_cp: contpalabras.exe
	./contpalabras.exe

run_db: docbase.exe
	./docbase.exe

run_g1: generador1.exe
	./generador1.exe

run_g2: generador2.exe
	./generador2.exe

run_g21: generador21.exe
	./generador21.exe

run_simJ: sim_J.exe
	./sim_J.exe

# Regla de limpieza
clean:
	rm -f $(EXES)
	rm -rf $(GENERATIONS_DIR)
	rm -f $(filter-out documento_original.txt stopwords-es.txt, $(wildcard *.txt))

# Regla de ayuda
help:
	@echo "Opciones disponibles:"
	@echo "  make          Compila todos los ejecutables"
	@echo "  make run_a    Ejecuta algoritmo.exe"
	@echo "  make run_cp   Ejecuta contpalabras.exe"
	@echo "  make run_db   Ejecuta docbase.exe"
	@echo "  make run_g1   Ejecuta generador1.exe"
	@echo "  make run_g2   Ejecuta generador2.exe"
	@echo "  make run_g21  Ejecuta generador21.exe"
	@echo "  make run_simJ Ejecuta sim_J.exe"
	@echo "  make clean    Elimina los archivos generados"