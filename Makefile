.PHONY: build
build:
	clang src/*.c src/*.m SDLGame.app/Contents/Frameworks/libSDL3.0.dylib -o SDLGame.app/Contents/MacOS/game -std=c17 -Iinclude \
		-framework Foundation

run: build
	./SDLGame.app/Contents/MacOS/game