#include <string>

using namespace std;

class Option {
		int id;
		string text;
		bool m_isCorrect;
		inline static int nextId = 1;

		public:
		Option(string text, bool isCorrect);

		string getText() const;
		bool isCorrect() const;
};