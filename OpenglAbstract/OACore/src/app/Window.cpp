#include "ngengine.h"
#include "Window.h"
namespace ngengine {
	namespace app {

		Window::Window(const std::string& title, utils::Size2D size) :
			m_Title(title), m_Size(size){
		}

		Window::~Window() {
			glfwDestroyWindow(m_Window);
		}

		void Window::createWindow() {
			//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
			//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

			m_Window = glfwCreateWindow(m_Size.width, m_Size.height, m_Title.c_str(), nullptr, nullptr);

			glfwSetWindowUserPointer(m_Window, this);
			glfwSetWindowSizeCallback(m_Window, _onResizeCallback);
		}

		void Window::makeContext() {
			if (m_Window != nullptr) {
				glfwMakeContextCurrent(m_Window);
			}
			// TODO: Maybe throw exception
		}

		void Window::setTitle(const std::string& title) {
			m_Title = title;
			glfwSetWindowTitle(m_Window, m_Title.c_str());
		}

		void Window::updateWindow() {
			// TODO: Check if we can avoid using glClear here and let the user decide
			glClear(GL_DEPTH);
			glfwPollEvents();
			glfwSwapBuffers(m_Window);
		}

		void Window::_onResizeCallback(GLFWwindow* window, int width, int height) {
			// TODO: Maybe give the user access to know when the window has changed by using glfwGetWindowUserPointer to (this)
			glViewport(0, 0, width, height);
		}
	}
}