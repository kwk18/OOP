#ifndef REDACTOR_H
#define REDACTOR_H 1

#include <stack>
#include <string>
#include <memory>
#include <iostream>

#include "cmd.h"
#include "doc.h"

struct editor {

	editor() : doc{nullptr}, memory{} {}

	void insert(std::string &str);
	void delete_();
	void cursorLeft();
	void cursorRight();
	void create(std::string &name);
	void save();
	void load(std::string &name);
	void print();
	void undo();

private:
	std::shared_ptr<document> doc;
	std::stack<std::shared_ptr<command>> memory;
};

#endif //REDACTOR_H