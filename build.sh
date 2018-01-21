clang -o test.exe \
	-I./include -I./SDL2/include \
	src/*.c test/*.c \
	-L./SDL2/lib/x64 \
	-lSDL2main -lSDL2 
