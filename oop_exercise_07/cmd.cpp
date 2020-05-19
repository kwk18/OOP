#include "cmd.h"

InsertCmd::InsertCmd(std::shared_ptr<document> &doc, size_t len, size_t cursor) {
	doc_ = doc;
	len_ = len;
	cursor_ = cursor;
}

void InsertCmd::undoThis() {
	doc_->removeEnd(len_, cursor_);
}

DeleteCmd::DeleteCmd(std::string str, size_t index, std::shared_ptr<document> &doc) {
	str_ = str;
	index_ = index;
	doc_ = doc;
}

void DeleteCmd::undoThis() {
	doc_->insertIndex_doc(str_, index_);
}