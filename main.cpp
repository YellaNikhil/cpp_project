#include<iostream>
#include<string>
#include <GLFW/glfw3.h>
#include <CPP_PROJECTConfig.h>
#ifdef USE_ADDER
    #include "adder.h"
#endif

int main(){

    std::cout << "Version: " << CPP_PROJECT_VERSION_MAJOR << "." << CPP_PROJECT_VERSION_MINOR << "\n";

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
#ifdef USE_ADDER
    std::cout << "Using Adder: " << basicmath::add(2.0f, 2.43f) << std::endl;
#else 
    std::cout << "Not using adder: " << 2 + 2 << std::endl;
#endif
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