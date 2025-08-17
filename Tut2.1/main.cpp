#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include "triangle.hpp"

using namespace std;

const char* vertexShaderSource = R"(
#version 330 core
layout (location = 0) in vec4 aPos;
layout (location = 1) in vec4 aColor;
out vec4 ourColor;
void main() {
    gl_Position = aPos;
    ourColor = aColor;
}
)";

const char* fragmentShaderSource = R"(
#version 330 core
in vec4 ourColor;
out vec4 FragColor;
void main() {
    FragColor = ourColor;
}
)";

void checkShaderCompile(GLuint shader) {
    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "Shader compilation failed: " << infoLog << std::endl;
    }
}

void checkProgramLink(GLuint program) {
    GLint success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cout << "Program linking failed: " << infoLog << std::endl;
    }
}

int main(int argc, char** argv){
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    GLFWwindow *window;
    window = glfwCreateWindow(800,600, "shape learning", NULL,NULL);

    if(window == NULL){
        cout << "Failed to create GLFW window" << endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE; // Allow modern OpenGL features
    if (glewInit() != GLEW_OK) {
        cout << "Failed to initialize GLEW" << endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        return -1;
    }

    glViewport(0, 0, 800, 600); // Set the viewport to the size of the window

    Triangle triangle; // Create a Triangle object
    const auto& vertices = triangle.getVertices();
    const auto& colors = triangle.getColors();

    // Create vertex shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    checkShaderCompile(vertexShader);

    // Create fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    checkShaderCompile(fragmentShader);

    // Combine shaders into a program
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    checkProgramLink(shaderProgram);

    // Clean up shaders (we don't need them anymore)
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // Create containers for the triangle's data
    GLuint VAO, VBO[2]; // VAO = Vertex Array Object, VBO = Vertex Buffer Object
    glGenVertexArrays(1, &VAO); // Create 1 VAO
    glGenBuffers(2, VBO); // Create 2 VBOs (one for points, one for colors)

    // Set up the VAO (tells OpenGL how to use our data)
    glBindVertexArray(VAO);

    // Send points to the graphics card
    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec4), vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(glm::vec4), (void*)0);
    glEnableVertexAttribArray(0);

    // Send colors to the graphics card
    glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
    glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(glm::vec4), colors.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(glm::vec4), (void*)0);
    glEnableVertexAttribArray(1);

    // Unbind the VAO
    glBindVertexArray(0);

    while(!glfwWindowShouldClose(window)) {
        // Process input
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true); // Close window when escape key is pressed

        // Render
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set clear color
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the color buffer

        // Draw the triangle
        glUseProgram(shaderProgram); // Use our shaders
        glBindVertexArray(VAO); // Use our triangle's data
        glDrawArrays(GL_TRIANGLES, 0, 3); // Draw 1 triangle (3 points)
        glBindVertexArray(0); // Unbind the VAO

        // Swap buffers
        glfwSwapBuffers(window);
        
        // Poll for events
        glfwPollEvents();
    }

    // Clean up everything
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(2, VBO);
    glDeleteProgram(shaderProgram);
    glfwDestroyWindow(window);

    glfwTerminate();
    return 0;
}