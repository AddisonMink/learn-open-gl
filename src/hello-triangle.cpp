#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

const char *vertexShaderSource =
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

const char *orangeFragmentShaderSource =
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\0";

const char *greenFragmentShaderSource =
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(0.0f, 1.0f, 0.0f, 1.0f);\n"
    "}\0";

int main()
{
#pragma region GLFW_GLAD_BOILERPLATE
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
#pragma endregion

    // Create a vertex shader.
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);

    // Compile the vertex shader and check for errors.
    glCompileShader(vertexShader);
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
    }

    // Create an orange fragment shader.
    unsigned int orangeFragmentShader;
    orangeFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(orangeFragmentShader, 1, &orangeFragmentShaderSource, NULL);

    // Compile the orange fragment shader and check for errors.
    glCompileShader(orangeFragmentShader);
    glGetShaderiv(orangeFragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(orangeFragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT_ORANGE::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
    }

    // Create a green fragment shader.
    unsigned int greenFragmentShader;
    greenFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(greenFragmentShader, 1, &greenFragmentShaderSource, NULL);

    // Compile the orange fragment shader and check for errors.
    glCompileShader(greenFragmentShader);
    glGetShaderiv(greenFragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(greenFragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT_GREEN::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
    }

    // Create orange shader program.
    unsigned int orangeShaderProgram = glCreateProgram();
    glAttachShader(orangeShaderProgram, vertexShader);
    glAttachShader(orangeShaderProgram, orangeFragmentShader);
    glLinkProgram(orangeShaderProgram);

    // Check for linking errors.
    glGetProgramiv(orangeShaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(orangeShaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM_ORANGE::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
    }

    // Create green shader program.
    unsigned int greenShaderProgram = glCreateProgram();
    glAttachShader(greenShaderProgram, vertexShader);
    glAttachShader(greenShaderProgram, greenFragmentShader);
    glLinkProgram(greenShaderProgram);

    // Check for linking errors.
    glGetProgramiv(greenShaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(greenShaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM_GREEN::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
    }

    // Left triangle.
    float leftTriangleVertices[] = {
        -0.75, 0.75, 0.0,  // top left
        -0.75, -0.75, 0.0, // bottom left
        0.0, -0.75, 0.0    // bottom right
    };

    unsigned int leftVBO;
    glGenBuffers(1, &leftVBO);

    unsigned int leftVAO;
    glGenVertexArrays(1, &leftVAO);
    glBindVertexArray(leftVAO);

    glBindBuffer(GL_ARRAY_BUFFER, leftVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(leftTriangleVertices), leftTriangleVertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    // Right triangle.
    float rightTriangleVertices[] = {
        0.0, 0.75, 0.0,  // top left
        0.0, -0.75, 0.0, // bottom left
        0.75, -0.75, 0.0 // bottom right
    };

    unsigned int rightVBO;
    glGenBuffers(1, &rightVBO);

    unsigned int rightVAO;
    glGenVertexArrays(1, &rightVAO);
    glBindVertexArray(rightVAO);

    glBindBuffer(GL_ARRAY_BUFFER, rightVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(rightTriangleVertices), rightTriangleVertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(orangeShaderProgram);
        glBindVertexArray(leftVAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glUseProgram(greenShaderProgram);
        glBindVertexArray(rightVAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}