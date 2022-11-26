#include <iostream>
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


const GLint WIDTH = 800, HEIGHT = 600;

int main()
{
    //Initialize GLFW

    if (!glfwInit())
    {
        printf("GLFW fail !!");
        glfwTerminate();
        return 1;
    }

    // SetUp GLFW window properties
    //OpenGl version

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test", NULL, NULL);

    if (!mainWindow)
    {
        printf("GLFW window fail !!");
        return 1;
    }

    //Get buffer size information

    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

    //Set context for GLEW to use

    glfwMakeContextCurrent(mainWindow);

    //Allow modern extension features
    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK)
    {
        printf("Glew fail !!");
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
        return 1;

    };

    //Setup Viewport size

    glViewport(0, 0, bufferWidth, bufferHeight);

    //MainLoop
    while (!glfwWindowShouldClose(mainWindow))
    {
        // Get + Handle user inputs events
        glfwPollEvents();

        // Clear window
        glClearColor(1.0f,1.0f,0,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(mainWindow);

    }


    return 0;
}
