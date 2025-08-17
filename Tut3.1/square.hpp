#ifndef __SQUARE_HPP__
#define __SQUARE_HPP__

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/vec4.hpp>
#include <vector>

class square {
protected:
    std::vector<glm::vec4> vertices;
    std::vector<glm::vec4> colors;
    std::vector<unsigned int> indices; // Added indices for triangles
public:
    square();
    const std::vector<glm::vec4>& getVertices() const { return vertices; }
    const std::vector<glm::vec4>& getColors() const { return colors; }
    const std::vector<unsigned int>& getIndices() const { return indices; } // Getter for indices
};

#endif