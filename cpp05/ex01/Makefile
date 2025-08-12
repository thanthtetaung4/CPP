CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Target executable
TARGET = bureaucratform
# Source files
SRCS = main.cpp Bureaucrat.cpp Form.cpp
# Object files
OBJS = $(SRCS:.cpp=.o)

# Default rule to build the executable
all: $(TARGET)

# Rule to link object files into the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove generated files
clean:
	rm -f $(OBJS)

# Full clean rule to remove everything
fclean: clean
	rm -f $(TARGET)

# Recompile everything
re: fclean all

.PHONY: all clean fclean re
