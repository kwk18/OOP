#include "doc.h"

void document::save_doc(const std::string &name) const {
	std::ofstream file{name};
	if (!file) {
		throw std::runtime_error("ERROR : File isn't opened\n");
	}
	file << position << " "; 
	file << strbuff;
}

void document::load_doc(const std::string &name) {
	std::ifstream file{name};
	if (!file) {
		throw std::runtime_error("ERROR : File isn't opened\n");
	}
	file >> position;
	strbuff.clear();
	file >> strbuff;
	name_ = name;
}

void document::insert_doc(std::string &str) {
	strbuff.insert(position, str);
	position += str.size();
}

void document::insertIndex_doc(std::string &str, size_t index) {
	strbuff.insert(index, str);
	position++;
}

void document::delete_doc() {
	strbuff.erase(position - 1, 1);
	position--;
}

bool document::cursorLeft_doc() {
	if (position == 0) {
		return false;
	}
	position--;
	return true;
}

bool document::cursorRight_doc() {
	if (position == strbuff.size()) {
		return false;
	}
	position++;
	return true;
}

void document::print_doc() {
	std::cout << strbuff << "\n";
}

void document::removeEnd(size_t len, size_t cursor) {
	strbuff.erase(cursor, len);
	position = cursor;
}

size_t document::getCursor() {
	return position;
}

std::string document::getElem(size_t index) {
	std::string str;
	str += strbuff[index];
	return str;
}

std::string document::getName() {
	return name_;
}