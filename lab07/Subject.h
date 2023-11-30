#ifndef SUBJECT_H
#define SUBJECT_H

#include <iostream>
#include <list>
#include <string>
#include "ISubject.h"
#include "IObserver.h"

class Subject : public ISubject {
public:
	virtual ~Subject() {
		std::cout << "Subject destructor called. Notifying observers..." << std::endl;
		std::list<IObserver *>::iterator iterator = list_observer_.begin();
		while (iterator != list_observer_.end()) {
			(*iterator)->Update(message_);
			++iterator;
		}
	}

	void Attach(IObserver *observer) override {
		list_observer_.push_back(observer);
	}

	void Detach(IObserver *observer) override {
		list_observer_.remove(observer);
	}

	void Notify() override {
		std::list<IObserver *>::iterator iterator = list_observer_.begin();
		while (iterator != list_observer_.end()) {
			(*iterator)->Update(message_);
			++iterator;
		}
	}

	void CreateMessage(const std::string &message = "Empty") {
		this->message_ = message;
		Notify();
	}

private:
	std::list<IObserver *> list_observer_;
	std::string message_;
};

#endif //SUBJECT_H