CXX = g++
CXXFLAGS = -Wall -g -std=c++11
LIBS = -lGL -lGLEW -lglfw
INCLUDE = -I/usr/include -I/usr/local/include # Adjust paths as needed
LDFLAGS = -L/usr/lib -L/usr/local/lib # Adjust paths as needed

SRCS = main.cpp triangle.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = triangle_app

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $<

clean:
	rm -f $(OBJS) $(EXEC)