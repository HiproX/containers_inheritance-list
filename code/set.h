#pragma once
#include "list.h"
#include <iostream>
#include <algorithm>

class Set final : public List
{
private:
// Prohibited methods
	using List::splice;
	using List::merge;
public:
// Constructors & Destructor
	Set(void) throw(std::bad_alloc);
	Set(iterator, iterator) throw(std::bad_alloc);
	Set(const Set&) throw(std::bad_alloc);
	~Set(void);
// Operators
	Set& operator=(const Set&) throw(std::bad_alloc);
	friend std::ostream& operator<<(std::ostream&, const Set&);
// Methods
	void insert(const value_type&) throw(std::bad_alloc);
	bool isContain(const value_type&) const;
	bool isContain(const Set&) const;
// Override methods
	void push_front(const value_type&) throw(std::bad_alloc) override;
	void push_back(const value_type&) throw(std::bad_alloc) override;
	void insert(iterator, const value_type&) throw(std::bad_alloc) override;
// Friends
	friend Set association(const Set&, const Set&) throw(std::bad_alloc);
	friend Set intersection(const Set&, const Set&) throw(std::bad_alloc);
	friend Set difference(const Set&, const Set&) throw(std::bad_alloc);
};