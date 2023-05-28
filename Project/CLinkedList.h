#pragma once

#include <assert.h> // 예외처리

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
	T	data_;             // 실제 데이터 저장할 변수
	CListNode<T>* p_next_; // 다음 노드의 주소를 저장할 포인터
	CListNode<T>* p_prev_; // 이전 노드의 주소를 저장할 포인터
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

		// 뒤에 추가를 해야하므로 end의 이전 노드를 얻어온다.
		PNODE	p_prev = p_end_->p_prev_;

		// 얻어온 이전 노드와 end 노드 사이에 새로 생성한
		// 노드를 추가한다.
		p_prev->p_next_ = p_node;
		p_node->p_prev_ = p_prev;

		// end노드와 새로 생성한 노드를 연결한다.
		p_node->p_next_ = p_end_;
		p_end_->p_prev_ = p_node;

		++size_;
	}

	void push_front(const T& data)
	{
		PNODE node = new NODE;
		node->data_ = data;
		
		// begin과 begin의 다음 노드 사이에 새로 생성한
		// 노드를 추가한다.
		PNODE	p_next = p_begin_->p_next_;
		
		// 새로 생성한 노드의 다음 노드로 begin의
		// 다음 노드를 준다 begin의 다음 노드의 이전노드로
		// 새로 생성한 노드를 준다.
		node->p_next_ = p_next;
		p_next->p_prev_ = node;

		// begin의 다음 노드로 새로 생성한 노드를 준다
		// 새로 생성한 노드의 이전 노드로 begin을 준다
		p_begin_->p_next_ = node;
		node->p_prev_ = p_begin_;

		++size_;
	}

	void pop_back()
	{
		if (empty())
			assert(false);

		// 가장 마지막 노드를 지워야 하므로 end노드의 이전
		// 노드를 얻어온다
		PNODE p_delete_node = p_end_->p_prev_;

		// 지울 노드의 이전 노드를 얻어온다
		PNODE p_prev = p_delete_node->p_prev_;
		
		// 이전 노드의 다음으로 end를 주고 end의 
		// 이전으로 이전 노드를 준다.
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