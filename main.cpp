#include<iostream>
#include<string>
#include "sdk/cpp/adder.h"
#include <GLFW/glfw3.h>

int main(){
    GLFWwindow* window;
    /* Init GLFW */
    if (!glfwInit())
        exit(EXIT_FAILURE);

    window = glfwCreateWindow(400, 400, "Boing (classic Amiga demo)", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    std::cout << "Hello World\n";
    std::cout << basicmath::add(2, 2) << std::endl;
    for (;;)
    {

       /* Swap buffers */
       glfwSwapBuffers(window);
       glfwPollEvents();

       /* Check if we are still running */
       if (glfwWindowShouldClose(window))
           break;
    }

    glfwTerminate();
    return 0;
}