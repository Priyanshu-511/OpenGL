#include<glad/glad.h>
#include<iostream>
// #include<GL/glew.h>
#include<GLFW/glfw3.h>
using namespace std;

int main(int argc, char** argv){
    glfwInit();

    //configure GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    //create window function
    GLFWwindow* window = glfwCreateWindow(800, 800, "tut1 Windows", NULL, NULL);

    if(window==NULL){
        cout<<"unable to create window:\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    gladLoadGL();
    glViewport(0,0,800,800);
    glClearColor(0.07f,0.13f,0.17f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);

    while(!glfwWindowShouldClose(window)){
        glfwPollEvents();
    }

    glfwDestroyWindow(window);

    glfwTerminate();
    return 0;
}

// run it using the command: g++ tut1.cpp ../glad/src/glad.c -I../glad/include -lglfw -ldl -lGL -o tut1
