.PHONY: build
build:
	clang src/*.c src/*.m SDLGame.app/Contents/Frameworks/libSDL3.0.dylib SDLGame.app/Contents/Frameworks/libSDL3_gfx.1.dylib -o SDLGame.app/Contents/MacOS/game -std=c17 -Iinclude \
		-framework Foundation -Wl,-headerpad_max_install_names
	install_name_tool -add_rpath @executable_path/../Frameworks SDLGame.app/Contents/MacOS/game

run: build
	./SDLGame.app/Contents/MacOS/game