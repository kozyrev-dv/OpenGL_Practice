#include "Engine.h"

#include "vao/vaolayout/vertexattribpointer.h"
#include "vao/vaolayout/vaolayout.h"

#include "Shader/shader.h"
#include "Shader/ShaderProgram.h"
#include "SceneObject/SceneObject.h"

void processInput(GLFWwindow* window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

// settings
const unsigned int SCR_WIDTH = 900;
const unsigned int SCR_HEIGHT = 900;

float mixRatio = 0.0f;

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    stbi_set_flip_vertically_on_load(true);

    float triangle_1[] = {
         0.3f,  0.6f,  0.0f,   1.0f,  0.3f,  0.3f,
        -0.7f,  0.6f,  0.0f,   0.9f,  0.4f,  0.2f,
        -0.7f, -0.4f,  0.0f,   0.8f,  0.5f,  0.1f
    };

    unsigned int indices_1[] = {  // note that we start from 0!
        0, 1, 2,   // first triangle
    };

    float triangle_2[] = {

         0.7f,  0.4f, 0.0f,
         0.7f, -0.6f, 0.0f,
        -0.3f, -0.6f, 0.0f,
    };
    unsigned int indices_2[] = {  // note that we start from 0!
        0, 1, 2   // second triangle
    };

    float triangle_3[] = {
       0.7f,  -0.8f, 0.0f,
       0.8f,  -0.7f, 0.0f,
       0.9f,  -0.8f, 0.0f
    };
    unsigned int indices_3[] = {
        0, 1, 2
    };

    VaoLayout vaoLayout1;
    vaoLayout1.Push(VertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0)); // vertices
    vaoLayout1.Push(VertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)))); // Colors

    VaoLayout vaoLayout2;
    vaoLayout2.Push(VertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0));

    VaoLayout vaoLayout3;
    vaoLayout3.Push(VertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0));

    ShaderProgram shaderProg;
    shaderProg.Push(Shader(GL_VERTEX_SHADER, "res/shaders/vertex.shader"));
    shaderProg.Push(Shader(GL_FRAGMENT_SHADER, "res/shaders/fragment.shader"));
    shaderProg.Create();

    ShaderProgram shaderProg2;
    shaderProg2.Push(Shader(GL_VERTEX_SHADER, "res/shaders/vertex2.shader" ));
    shaderProg2.Push(Shader(GL_FRAGMENT_SHADER, "res/shaders/fragment2.shader"));
    shaderProg2.Create();

    ShaderProgram shaderProg3;
    shaderProg3.Push(Shader(GL_VERTEX_SHADER, "res/shaders/vertex3.shader"));
    shaderProg3.Push(Shader(GL_FRAGMENT_SHADER, "res/shaders/fragment3.shader"));
    shaderProg3.Create();

    float angle = 0.0f;
    float angleInc = 0.0001f;

    SceneObject tr_1(triangle_1, sizeof(triangle_1), indices_1, sizeof(indices_1), &vaoLayout1, shaderProg);
    SceneObject tr_2(triangle_2, sizeof(triangle_2), indices_2, sizeof(indices_2), &vaoLayout2, shaderProg2);
    SceneObject tr_3(triangle_3, sizeof(triangle_3), indices_3, sizeof(indices_3), &vaoLayout3, shaderProg3);

    // square 4

    float coords4[] = {
        //vertices          //texture
        0.5f, 0.5f, 0.0f,   0.0f, 0.0f,
        0.5f, 1.0f, 0.0f,   0.0f, 1.0f,
        1.0f, 1.0f, 0.0f,   1.0f, 1.0f,
        1.0f, 0.5f, 0.0f,   1.0f, 0.0f
    };
    unsigned int indices4[] = {
        0, 1, 2, 0, 2, 3
    };

    float textureCoords4[] = {
        0.0f,  0.0f,
        1.0f,  0.0f,
        0.5f,  1.0f
    };

    VaoLayout vaoLayout4;
    vaoLayout4.Push(VertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0)); // vertices
    vaoLayout4.Push(VertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3*sizeof(float)))); // texture

    ShaderProgram shaderProg4;
    shaderProg4.Push(Shader(GL_VERTEX_SHADER, "res/shaders/vertex4.shader"));
    shaderProg4.Push(Shader(GL_FRAGMENT_SHADER, "res/shaders/fragment4.shader"));
    shaderProg4.Create();

    SceneObject square4(coords4, sizeof(coords4), indices4, sizeof(indices4), &vaoLayout4, shaderProg4);

    Texture textureChinese(GL_TEXTURE_2D, "res/textures/chinese.png");
    textureChinese.UseMipmaps(true);
    square4.PushTexture(textureChinese, "textureImage");

    // scquare 5

    float coords5[]{
        //vertices           //texture
        0.5f, -1.0f, 0.0f,   0.0f, 0.0f,
        0.5f, -0.5f, 0.0f,   0.0f, 1.0f,
        1.0f, -0.5f, 0.0f,   1.0f, 1.0f,
        1.0f, -1.0f, 0.0f,   1.0f, 0.0f

    };

    unsigned int indices5[] = {
        0, 1, 2, 0, 2, 3
    };

    float textureCoords5[] = {
        0.0f,  0.0f,
        1.0f,  0.0f,
        0.5f,  1.0f
    };

    VaoLayout vaoLayout5;
    vaoLayout5.Push(VertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0)); // vertices
    vaoLayout5.Push(VertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)))); // texture

    ShaderProgram shaderProg5;
    shaderProg5.Push(Shader(GL_VERTEX_SHADER, "res/shaders/vertex5.shader"));
    shaderProg5.Push(Shader(GL_FRAGMENT_SHADER, "res/shaders/fragment5.shader"));
    shaderProg5.Create();

    SceneObject square5(coords5, sizeof(coords5), indices5, sizeof(indices5), &vaoLayout5, shaderProg5);
    square5.PushTexture(textureChinese, "textureImage1");
    
    Texture textureFace(GL_TEXTURE_2D, "res/textures/facepalm.png");
    textureFace.UseMipmaps(true);
    square5.PushTexture(textureFace, "textureImage2");
    shaderProg5.SetUniform1f("mixRatio", mixRatio);
    

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        GLCall(glClearColor(0.0f, 0.0f, 0.0f, 0.0f));
        GLCall(glClear(GL_COLOR_BUFFER_BIT));

        tr_1.Draw();

        float time = glfwGetTime();
        float redValue = (sin(time) + 1.0f) / 2.0f;
        shaderProg2.SetUniform4f("colorOffset", redValue, 0.0f, 0.0f, 0.0f);
        tr_2.Draw();

        angle += angleInc;
        shaderProg3.SetUniform1f("angle", angle);
        tr_3.Draw();

        square4.Draw();

        shaderProg5.SetUniform1f("mixRatio", mixRatio);
        square5.Draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    tr_1.Delete();
    tr_2.Delete();
    tr_3.Delete();
    square4.Delete();
    square5.Delete();

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        mixRatio = std::min(1.0f, mixRatio + 0.0005f);
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        mixRatio = std::max(0.0f, mixRatio - 0.0005f);
        
}