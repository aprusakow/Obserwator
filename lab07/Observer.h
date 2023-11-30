#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
#include "IObserver.h"
#include "Subject.h"

class Observer : public IObserver {
private:
	std::string message_from_subject_;
	static int static_number_;
	int observer_number_;
	Subject &subject_;
public:
	Observer(Subject &subject) : subject_(subject) {
		this->subject_.Attach(this);
		std::cout << "Observer " << ++Observer::static_number_ << " created" << std::endl;
	}

	~Observer() override {
		std::cout << "Observer " << observer_number_ << ".destroyed" << std::endl;
	}

	void Update(const std::string &message_from_subject) override {
		message_from_subject_ = message_from_subject;
		PrintInfo();
	}

	void RemoveMeFromTheList() {
		subject_.Detach(this);
		std::cout << "Observer " << observer_number_ << " removed from list" << std::endl;
	}

	void PrintInfo() const {
		std::cout << "Observer " << observer_number_ << " received message: " << message_from_subject_ << std::endl;
	}


};

#endif //OBSERVER_H