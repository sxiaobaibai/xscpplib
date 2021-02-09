#ifndef XS_STACK_H
# define XS_STACK_H
# include <iostream>

template<typename T>
struct ListNode
{
	ListNode(T val):val_(val),next(nullptr), prev(nullptr){};
	T val_;
	ListNode *next;
	ListNode *prev;
};

template<typename T>
class xs_stack
{
 public:
	xs_stack()
	:size_(0)
	{
	}
	size_t size(){return size_;};
	void pop();
	void push(T val);
	T top();
	~xs_stack()
	{
		while (size_ > 0)
		{
			pop();
		}
	}

 private:
	T val_;
	ListNode<T> *list_;
	size_t size_;
};

template<typename T>
void xs_stack<T>::pop()
{
	if (size_ <= 0)
		return ;
	--size_;
	if (size_ == 0)
	{
		delete list_;
		list_ = nullptr;
	}
	else
	{
		list_ = list_->prev;
		delete list_->next;
		list_->next = nullptr;
	}
};

template<typename T>
void xs_stack<T>::push(T val)
{
	if (!list_)
	{
		list_ = new ListNode<T>(val);
	}
	else
	{
		list_->next = new ListNode<T>(val);
		list_->next->prev = list_;
		list_ = list_->next;
	}
	++size_;
};

template<typename T>
T xs_stack<T>::top()
{
	return list_->val_;
};

#endif
