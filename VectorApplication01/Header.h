#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

class A {
	int m_id = 0;
	static inline size_t generator = 505;
public:
	A(int id) : m_id(id) {
		std::cout << "Normal constructor with ID: " << m_id << ".\n";
	}

	A() : m_id(generator++) {
		std::cout << "Default constructor " << m_id << ".\n";
	}

	A(const A& source) {
		m_id = source.m_id;
		std::cout << "Copy constructor " << m_id << ".\n";
	}

	A& operator=(const A& source) {
		m_id = source.m_id;
		std::cout << "Assignment operator for source value " << source.m_id << ".\n";
		return *this;
	}
	~A() {
		std::cout << "Destructor of class " << m_id << ".\n";
	};

	const int id() const {
		return this->m_id;
	}
};


