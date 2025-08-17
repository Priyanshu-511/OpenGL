#ifndef _TRIANGLE_HPP_
#define _TRIANGLE_HPP_ 

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "glm/vec4.hpp"
#include <iostream>
#include <vector>

class Triangle {
    protected:
        std::vector<glm::vec4> vertices; //vertices of triangle
        std::vector<glm::vec4> colors; //colors of triangle vertices
    public:
        Triangle(); // Constructor declaration
        const std::vector<glm::vec4>& getVertices() const { return vertices; }
        const std::vector<glm::vec4>& getColors() const { return colors; }
};

#endif