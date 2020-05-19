#include "redactor.h"
#include "doc.h"
#include "cmd.h"

void editor::insert(std::string &str) {
	if (doc == nullptr) {
		std::cout << "No document\n";
		return;
	}
	std::shared_ptr<command> cmd = std::shared_ptr<command>(new InsertCmd(doc, str.size(), doc->getCursor()));
	doc->insert_doc(str);
	memory.push(cmd);
	std::cout << "Insert - OK\n";
}

void editor::delete_() {
	if (doc == nullptr) {
		std::cout << "No document\n";
		return;
	}
	size_t index = doc->getCursor();
	if (index == 0) {
		std::cout << "Empty document\n";
		return;
	}
	std::shared_ptr<command> cmd = std::shared_ptr<command>(new DeleteCmd(doc->getElem(index - 1), index - 1, doc));
	doc->delete_doc();
	memory.push(cmd);
    std::cout << "Delete - OK\n";
}

void editor::cursorLeft() {
	if (doc == nullptr) {
		std::cout << "No document\n";
		return;
	}
	doc->cursorLeft_doc();
    std::cout << "Left - OK\n";
}

void editor::cursorRight() {
	if (doc == nullptr) {
		std::cout << "No document\n";
		return;
	}
	doc->cursorRight_doc();
    std::cout << "Right - OK\n";
}

void editor::create(std::string &name) {
	doc = std::make_shared<document>(name);
    std::cout << "Create - OK\n";
}


void editor::save() {
	if (doc == nullptr) {
		std::cout << "No document\n";
		return;
	}
	std::string name = doc->getName();
	doc->save_doc(name);
    std::cout << "Save - OK\n";
}

void editor::load(std::string &name) {
	try {
		doc = std::make_shared<document>(name);
		doc->load_doc(name);
		while (!memory.empty()) {
			memory.pop();
		}
        std::cout << "Load - OK\n";
	} catch (std::runtime_error &err) {
		std::cout << err.what();
	} 
}

void editor::print() {
    if (doc == nullptr) {
        std::cout << "No document\n";
        return;
    }
	doc->print_doc();
}

void editor::undo() {
	if (memory.empty()) {
		throw std::logic_error("History is empty\n");
	}
	std::shared_ptr<command> last = memory.top();
	last->undoThis();
	memory.pop();
    std::cout << "Undo - OK\n";
}