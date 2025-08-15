
# Compilador

COMPI = g++

# Las banderas

QFLAGS = -Wall -Wextra -O3

# Directorio de las cabezeras

DIR = -I../libreriasBrigido
TARGET = tree

PRIN = main.cpp


all: $(TARGET)


$(TARGET): $(PRIN)
	$(COMPI) $(QFLAGS) $(DIR) $(PRIN) -o $(TARGET)


clean:
	rm -f ./*.o $(TARGET)


.PHONY: clean all