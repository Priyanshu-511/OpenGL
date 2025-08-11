#include <GL/glew.h>
#include<GLFW/glfw3.h>
#include<iostream>
using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    // Adjust the viewport when the window is resized
    glViewport(0, 0, width, height);
}

int main(int argc, char** argv){
    // Initialize GLFW
    glfwInit();

    // window setup

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL){
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = GL_TRUE; // Allow modern OpenGL features
    if (glewInit() != GLEW_OK) {
        std::cout << "Failed to initialize GLEW" << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        return -1;
    }

    // Set the viewport
    glViewport(0, 0, 800, 600);
    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Process input
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true); // Close window when escape key is pressed
        // Render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // Set clear color
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the color buffer
        // Swap buffers
        glfwSwapBuffers(window);
        // Poll for events
        glfwPollEvents();
    }

    //Terminate GlFW
    glfwTerminate();
    return 0;
}