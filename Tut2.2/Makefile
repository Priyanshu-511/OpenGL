CXX = g++
CXXFLAGS = -Wall -g -std=c++11
LIBS = -lGL -lGLEW -lglfw

SRCS = main.cpp triangle.cpp colour.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = triangle_app

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(EXEC)
