#pragma once
#include <utility>

template <size_t Index, typename T>
class TupleElement
{
public:
	TupleElement(const T& data) :data(data)
	{
	};

	TupleElement(T&& data) :data(std::move(data))
	{
	};

	~TupleElement() = default;

	T& get() { return data; }

private:
	T data;
};

template <size_t Index, typename T1, typename ... Types>
class IndexedTuple : 
	public TupleElement<Index, T1>,
	public IndexedTuple<Index + 1, Types ...>
{
public:

	IndexedTuple(T1 t1, Types... types) : 
		TupleElement<Index, T1>(t1),
		IndexedTuple<Index + 1, Types...>(types...)
	{
	}

};

template <size_t Index, typename T1>
class IndexedTuple<Index, T1> :
	public TupleElement<Index, T1>
{
public:
	IndexedTuple(T1 t1) :
		TupleElement<Index, T1>(t1)
	{
	}
};

template <typename ... Types>
class MyTuple : public IndexedTuple<0, Types...>
{
public:
	MyTuple(Types... types) : IndexedTuple<0, Types...>(types...)
	{
	}
	~MyTuple() = default;

private:

};

