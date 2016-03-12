#pragma once

#include "ngengine.h"
#include "utils\Size.h"
#include "Window.h"
#include "Dependencies\GLEW\include\GL\glew.h"
#include "Dependencies\GLFW\include\GLFW\glfw3.h"

#define NG_ENGINE_BASE using Application::Application

namespace ngengine {
	namespace app {

		using utils::Size2D;
		using std::string;

		constexpr Size2D DEFAULT_SIZE = Size2D({ 640, 480 });

		constexpr char DEFAULT_TITLE[] = "Opengl Abstract - Made By Naor & Guy";

		class Application {
		public:
			explicit Application(const string&, const Size2D);
			explicit Application(const string& title, int width, int height) : Application(title, Size2D{ width, height }) {}
			explicit Application(const string& title) : Application(title, DEFAULT_SIZE) {}
			explicit Application(const Size2D size) : Application(DEFAULT_TITLE, size) {}
			explicit Application(int width, int height) : Application(DEFAULT_TITLE, Size2D{ width, height }) {}
			explicit Application() : Application(DEFAULT_TITLE, DEFAULT_SIZE) {}
			~Application();

		public:
			virtual void run() final;
			
		public:
			inline const string& getTitle() const { return m_Title; }
			inline const Size2D getWindowSize() const{ return m_Size; }
			void setTitle(const string&);

		protected:
			virtual void render(double) {};
			virtual void update(double) {};
			virtual void startup() {};
			virtual void shutdown() {};

		private:
			string m_Title;
			Size2D m_Size;
			Window m_Window;
		};
	}
}