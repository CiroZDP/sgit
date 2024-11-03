windows: main.cpp repo.cpp
	@echo : Compiling your favourite git clone...
	@g++ -o x64/Release/sgit.exe *.cpp
	@echo : Done!
	@echo { Saved in : x64/Release/sgit.exe }

linux: main.cpp repo.cpp
	@echo : Compiling your favourite git clone...
	@g++ -o x64/Release/sgit *.cpp
	@echo : Done!
	@echo { Saved in : x64/Release/sgit }