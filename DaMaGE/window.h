#ifndef _WINDOW_H_
#define _WINDOW_H_

namespace dmg
{
	namespace graphics
	{
		class Window
		{
		public:
			Window(const char* name, int width, int height);
			~Window();
			void update() const;
		private:
			const char* m_name;
			int m_width, m_height;

		};
	}
}


#endif //_WINDOW_H_