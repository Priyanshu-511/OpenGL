#include "square.hpp"

square::square() {
    vertices = {
        glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f), // Bottom left
        glm::vec4(0.5f, -0.5f, 0.0f, 1.0f),  // Bottom right
        glm::vec4(0.5f, 0.5f, 0.0f, 1.0f),   // Top right
        glm::vec4(-0.5f, 0.5f, 0.0f, 1.0f)   // Top left
    };

    colors = {
        glm::vec4(1.0f, 0.0f, 0.0f, 1.0f), // Red
        glm::vec4(0.0f, 1.0f, 0.0f, 1.0f), // Green
        glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), // Blue
        glm::vec4(1.0f, 1.0f, 0.0f, 1.0f)  // Yellow
    };

    indices = {
        0, 1, 2, // First triangle (bottom-left, bottom-right, top-right)
        0, 2, 3  // Second triangle (bottom-left, top-right, top-left)
    };
}