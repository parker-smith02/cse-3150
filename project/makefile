CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11

SRC = ECTextViewImp.cpp ECEditorTest.cpp Document.cpp Command.cpp KeyObservers.cpp
OBJ = $(SRC:.cpp=.o)

editor: $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -arch x86_64 -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJ) editor
