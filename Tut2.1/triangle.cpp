#include "triangle.hpp"

Triangle::Triangle() {
    vertices = {
        glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f), // Bottom left vertex
        glm::vec4(0.5f, -0.5f, 0.0f, 1.0f),  // Bottom right vertex
        glm::vec4(0.0f, 0.5f, 0.0f, 1.0f)    // Top vertex
    };
    colors = {
        glm::vec4(1.0f, 0.5f, 0.0f, 1.0f), // Red
        glm::vec4(1.0f, 0.5f, 0.0f, 1.0f), // Green
        glm::vec4(1.0f, 0.5f, 0.0f, 1.0f)  // Blue
    };
}