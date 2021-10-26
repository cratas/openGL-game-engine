#include "WindowInitializer.h"

WindowInitializer* WindowInitializer::instance = 0;

/// <summary>
/// private constructor of WindowInitializer class
/// </summary>
WindowInitializer::WindowInitializer()
{
	window;

	glfwSetErrorCallback(this->error_callback);
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		exit(EXIT_FAILURE);
	}

	/* //inicializace konkretni verze
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE,
	GLFW_OPENGL_CORE_PROFILE);  //*/

	this->window = glfwCreateWindow(800, 600, "ZPG PROJECT", NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	// start GLEW extension handler
	glewExperimental = GL_TRUE;
	glewInit();

	this->getVersionInfo();

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	float ratio = width / (float)height;
	glViewport(0, 0, width, height);
}

/// <summary>
/// public function to create singleton instance of WindowInitializer class
/// </summary>
/// <returns>WindowInitializer* class instnace</returns>
WindowInitializer* WindowInitializer::getInstance()
{
	if (instance == NULL)
	{
		instance = new WindowInitializer();
	}
	return instance;
}

/// <summary>
/// getter of GLFWwindow object
/// </summary>
/// <returns>GLFWwindow* window</returns>
GLFWwindow* WindowInitializer::getWindow()
{
	return this->window;
}

/// <summary>
/// function used at class constuctor which makes code more readable
/// </summary>
void WindowInitializer::error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

/// <summary>
/// function used at class constuctor which makes code more readable, prints version info
/// </summary>
void WindowInitializer::getVersionInfo()
{
	// get version info
	printf("OpenGL Version: %s\n", glGetString(GL_VERSION));
	printf("Using GLEW %s\n", glewGetString(GLEW_VERSION));
	printf("Vendor %s\n", glGetString(GL_VENDOR));
	printf("Renderer %s\n", glGetString(GL_RENDERER));
	printf("GLSL %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	int major, minor, revision;
	glfwGetVersion(&major, &minor, &revision);
	printf("Using GLFW %i.%i.%i\n", major, minor, revision);
}
