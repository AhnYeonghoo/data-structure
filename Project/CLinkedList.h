#pragma once

#include <assert.h> // ����ó��

template<typename T>
class CListNode
{
	template<typename T>
	friend class CLinkedList;
	
	template<typename T>
	friend class CListIterator;

private:
	CListNode()
	{
		p_next_ = nullptr;
		p_prev_ = nullptr;
	}
	
	~CListNode()
	{}

private:
	T	data_;             // ���� ������ ������ ����
	CListNode<T>* p_next_; // ���� ����� �ּҸ� ������ ������
	CListNode<T>* p_prev_; // ���� ����� �ּҸ� ������ ������
};

template<typename T>
class CListIterator
{
	template<typename T>
	friend class CLinkedList;

public:
	CListIterator()
	{
		p_node_ = nullptr;
	}

	~CListIterator()
	{}

private:
	typedef CListNode<T>* PNODE;
	
private:
	PNODE p_node_;

public:
	bool operator== (const CListIterator<T>& iter)
	{
		return p_node_ == iter.p_node_;
	}

	bool operator!= (const CListIterator<T>& iter)
	{
		return p_node_ != iter.p_node_;
	}
	
	void operator++ ()
	{
		p_node_ = p_node_->p_next_;
	}

	void operator-- ()
	{
		p_node_ = p_node_->p_prev_;
	}

	T& operator * ()
	{
		return p_node_->data_;
	}
};

template<typename T>
class CLinkedList
{
public:
	CLinkedList()
	{
		p_begin_ = new NODE();
		p_end_ = new NODE();
		
		p_begin_->p_next_ = p_end_;
		p_end_->p_prev_ = p_begin_;

		size_ = 0;
	}
	
	~CLinkedList()
	{
		clear();
		delete p_begin_;
		delete p_end_;
	}

private:
	typedef CListNode<T>	NODE;
	typedef CListNode<T>*	PNODE;

	PNODE	p_begin_;
	PNODE	p_end_;
	int		size_;

public:
	void push_back(const T& data)
	{
		PNODE	p_node = new NODE;
		p_node->data_ = data;

		// �ڿ� �߰��� �ؾ��ϹǷ� end�� ���� ��带 ���´�.
		PNODE	p_prev = p_end_->p_prev_;

		// ���� ���� ���� end ��� ���̿� ���� ������
		// ��带 �߰��Ѵ�.
		p_prev->p_next_ = p_node;
		p_node->p_prev_ = p_prev;

		// end���� ���� ������ ��带 �����Ѵ�.
		p_node->p_next_ = p_end_;
		p_end_->p_prev_ = p_node;

		++size_;
	}

	void push_front(const T& data)
	{
		PNODE node = new NODE;
		node->data_ = data;
		
		// begin�� begin�� ���� ��� ���̿� ���� ������
		// ��带 �߰��Ѵ�.
		PNODE	p_next = p_begin_->p_next_;
		
		// ���� ������ ����� ���� ���� begin��
		// ���� ��带 �ش� begin�� ���� ����� ��������
		// ���� ������ ��带 �ش�.
		node->p_next_ = p_next;
		p_next->p_prev_ = node;

		// begin�� ���� ���� ���� ������ ��带 �ش�
		// ���� ������ ����� ���� ���� begin�� �ش�
		p_begin_->p_next_ = node;
		node->p_prev_ = p_begin_;

		++size_;
	}

	void pop_back()
	{
		if (empty())
			assert(false);

		// ���� ������ ��带 ������ �ϹǷ� end����� ����
		// ��带 ���´�
		PNODE p_delete_node = p_end_->p_prev_;

		// ���� ����� ���� ��带 ���´�
		PNODE p_prev = p_delete_node->p_prev_;
		
		// ���� ����� �������� end�� �ְ� end�� 
		// �������� ���� ��带 �ش�.
		p_prev->p_next_ = p_end_;
		p_end_->p_prev_ = p_prev;

		delete p_delete_node;

		--size_;
	}

	void pop_front()
	{
		if (empty())
			assert(false);
		
		PNODE p_delete_node = p_begin_->p_next_;
		PNODE p_next = p_delete_node->p_next_;
		
		p_next->p_prev_ = p_begin_;
		p_begin_->p_next_ = p_next;

		delete p_delete_node;

		--size_;
	}

	T front() const
	{
		if (empty())
			assert(false);
		
		return p_begin_->p_next_->data_;
	}

	T back() const
	{
		if (empty())
			assert(false);
		
		return p_end_->p_prev_->data_;
	}

	void clear()
	{
		PNODE	p_node = p_begin_->p_next_;

		while (p_node != p_end_)
		{
			PNODE	p_next = p_node->p_next_;

			delete p_node;

			p_node = p_next;
		}
		
		size_ = 0;

		p_begin_->p_next_ = p_end_;
		p_end_->p_prev_ = p_begin_;
	}

	int size() const
	{
		return size_;
	}

	bool empty() const
	{
		return size_ == 0;
	}



};