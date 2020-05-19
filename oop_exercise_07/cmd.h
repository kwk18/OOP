#ifndef CMD_H
#define CMD_H 1

#include "doc.h"

struct command {
	virtual void undoThis() = 0;
	virtual ~command() = default;

protected:
	std::shared_ptr<document> doc_;
};

struct InsertCmd : command {
	InsertCmd(std::shared_ptr<document> &doc, size_t len, size_t cursor);

	void undoThis() override;

private:
	size_t len_;
	size_t cursor_;
};

struct DeleteCmd : command {
	DeleteCmd(std::string str, size_t index, std::shared_ptr<document> &doc);

	void undoThis() override;

private:
	std::string str_;
	size_t index_;
};

#endif //CMD_H