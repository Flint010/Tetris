
add_executable(tetris
				main.cpp
				Game.h
				Game.cpp
				Board.h
				Board.cpp
				Tetramino.h				
				Tetramino.cpp				
)

find_package(SFML COMPONENTS graphics REQUIRED)

target_link_libraries(tetris PRIVATE sfml-graphics)

