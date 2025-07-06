# Compilador a utilizar
CC = gcc
# Flags de compilación: -g para debug, -Wall para warnings, -Iinclude para buscar cabeceras
CFLAGS = -g -Wall -Iinclude -std=c11 -lm

# Directorios
SRCDIR = src
INCDIR = include
BUILDDIR = build
TARGET = $(BUILDDIR)/c_llm

# Archivos fuente
SOURCES = $(SRCDIR)/tensor.c $(SRCDIR)/main.c
# Archivos objeto correspondientes
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SOURCES))

# Regla por defecto: compila todo
all: $(TARGET)

# Regla para crear el ejecutable final
$(TARGET): $(OBJECTS)
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -o $@ $^

# Regla para compilar cada archivo .c en un .o
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar los archivos compilados
clean:
	rm -rf $(BUILDDIR)

# Regla para ejecutar
run: all
	./$(TARGET)

.PHONY: all clean run
