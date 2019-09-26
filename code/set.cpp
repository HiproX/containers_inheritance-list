#include "set.h"

Set::Set(void)
	throw(std::bad_alloc)
	: List{} {};

Set::Set(iterator begin, iterator end)
	throw(std::bad_alloc)
	: List{ begin, end } {};

Set::Set(const Set &other)
	throw(std::bad_alloc)
	: List{ other } {};

Set::~Set(void) = default;

Set& Set::operator=(const Set &other)
	throw(std::bad_alloc)
{
	this->List::operator=(other);
	return *this;
}

std::ostream& operator<<(std::ostream &os, const Set &rhs)
{
	for (auto it = rhs.cbegin(); it != rhs.cend(); ++it)
	{
		os << *it << ' ';
	}
	return os;
}

void Set::insert(const Set::value_type &item)
	throw(std::bad_alloc)
{
	if (!this->isContain(item))
	{
		auto it = this->List::begin();
		for (; it != this->List::end(); ++it)
		{
			if (item < *it)
			{
				break;
			}
		}
		if (it == this->List::begin())
		{
			this->List::push_front(item);
		}
		else
		{
			this->List::insert(--it, item);
		}
	}
}

bool Set::isContain(const Set::value_type &item) const
{
	return (this->List::cend() != this->List::find(item));
}

bool Set::isContain(const Set &other) const
{
	for (auto ot = other.cbegin(); ot != other.cend(); ++ot)
	{
		if (!this->isContain(*ot))
		{
			return false;
		}
	}
	return true;
}

Set association(const Set &lhs, const Set &rhs)
	throw(std::bad_alloc)
{
	Set res{ lhs };
	for (auto it = rhs.cbegin(); it != rhs.cend(); ++it)
	{
		res.insert(*it);
	}
	return res;
}

Set intersection(const Set &lhs, const Set &rhs)
	throw(std::bad_alloc)
{
	Set res{};
	for (auto it = lhs.cbegin(); it != lhs.cend(); ++it)
	{
		if (rhs.isContain(*it))
		{
			res.insert(*it);
		}
	}
	return res;
}

Set difference(const Set &lhs, const Set &rhs)
	throw(std::bad_alloc)
{
	Set res{};
	for (auto it = lhs.cbegin(); it != lhs.cend(); ++it)
	{
		if (!rhs.isContain(*it))
		{
			res.insert(*it);
		}
	}
	return res;
}

void Set::push_front(const value_type &value)
	throw(std::bad_alloc)
{
	if (!this->isContain(value))
	{
		List::Node *new_Node = new List::Node(value);
		new_Node->prev = nullptr;
		new_Node->next = Head;
		Head->prev = new_Node;
		Head = new_Node;
		head = iterator{ Head };
		++count;
	}
}

void Set::push_back(const value_type &value)
	throw(std::bad_alloc)
{
	if (!this->isContain(value))
	{
		if (!this->List::length())
		{
			this->List::push_front(value);
		}
		else
		{
			List::Node *new_Node = new List::Node{ value };
			List::Node *prevel = Tail->prev;
			prevel->next = new_Node;
			new_Node->prev = prevel;
			new_Node->next = Tail;
			Tail->prev = new_Node;
			++count;
		}
	}
}

void Set::insert(iterator it, const value_type &value)
	throw(std::bad_alloc)
{
	if (!this->isContain(value))
	{
		List::Node *el = it.elem;
		if (it == --end())
		{
			this->List::push_back(value);
		}
		else
		{
			List::Node *nextel = it.elem->next;
			List::Node *p = new List::Node{ value };
			p->next = nextel;
			p->prev = el;
			nextel->prev = p;
			el->next = p;
			++count;
		}
	}
}