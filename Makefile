# Compilador e flags
CC = clang
CFLAGS = -g -Wno-everything -pthread -lm

# Arquivos fonte e headers
SRCS = $(wildcard src/*.c)
HEADERS = $(wildcard src/*.h)

# Nome do executável
TARGET = main
TARGET_DEBUG = main-debug

# Regra padrão
all: $(TARGET)

# Compila versão normal
$(TARGET): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# Compila versão debug
$(TARGET_DEBUG): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -O0 $(SRCS) -o $(TARGET_DEBUG)

# Limpa executáveis
clean:
	rm -f $(TARGET) $(TARGET_DEBUG)
