#ifndef OPTION_H
#define OPTION_H

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

#endif // OPTION_H
