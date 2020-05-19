#ifndef DOC_H
#define DOC_H 1

#include <memory>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

struct document {
	document(std::string &name) : name_(name), strbuff{}, position{0} {}

	void save_doc(const std::string &name) const;
	void load_doc(const std::string &name);
	void insert_doc(std::string &str);
	void insertIndex_doc(std::string &str, size_t index);
	void delete_doc();
	bool cursorLeft_doc();
	bool cursorRight_doc();
	void print_doc();
	void removeEnd(size_t len, size_t cursor);

	size_t getCursor();
	std::string getElem(size_t index);
	std::string getName();

private:
	std::string name_;
	std::string strbuff;
	size_t position;
};

#endif //DOC_H