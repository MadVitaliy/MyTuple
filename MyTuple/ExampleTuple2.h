#pragma once

template<typename... Args>
struct tuple;

template<typename Head, typename... Tail>
struct tuple<Head, Tail...> : tuple<Tail...>
{
    tuple(Head h, Tail... tail)
        : tuple<Tail...>(tail...), head_(h)
    {}

    typedef tuple<Tail...> base_type;
    typedef Head           value_type;

    base_type& base = static_cast<base_type&>(*this);
    Head       head_;
};

template<>
struct tuple<>
{};

template<int I, typename Head, typename... Args>
struct getter
{
    typedef typename getter<I - 1, Args...>::return_type return_type;
    static return_type get(tuple<Head, Args...> t)
    {
        return getter<I - 1, Args...>::get(t);
    }
};

template<typename Head, typename... Args>
struct getter<0, Head, Args...>
{
    typedef typename tuple<Head, Args...>::value_type return_type;
    static return_type get(tuple<Head, Args...> t)
    {
        return t.head_;
    }
};

template<int I, typename Head, typename... Args>
typename getter<I, Head, Args...>::return_type
get(tuple<Head, Args...> t)
{
    return getter<I, Head, Args...>::get(t);
}

