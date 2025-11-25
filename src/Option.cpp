#include "Option.h"

Option::Option(string text, bool isCorrect) : id(++nextId), text(text), m_isCorrect(isCorrect) {}

string Option::getText() const { return text; }
bool Option::isCorrect() const { return m_isCorrect; }