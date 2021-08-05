#include <iostream>
#include <tuple>
#include "MyTuple.h"
//#include "ExampleTuple.h"
//#include "ExampleTuple2.h"

int main()
{
    std::tuple tup = { 125, 123.0, 121.f };


    //MyTuple<int, double, float> t;
   // MyTuple<int, double, float> t;
    //tuple<int, double, float> t(1, 2, 3);

    //tuple<int, double, int> t(12, 2.34, 89);

    //int first = get<0>(t);
    //double second = get<1>(t);
    //int third = get<2>(t);

    //std::cout << first << " " << second << " " << third << std::endl;

    int first = 0;
    float second = 0;
    double third = 0;

    MyTuple<int, float, double> mytuple(1, 1.2f, 2.0);
     first = static_cast<TupleElement<0, int>>(mytuple).get();
     second = static_cast<TupleElement<1, float>>(mytuple).get();
     third = static_cast<TupleElement<2, double>>(mytuple).get();


    std::cout << first << " " << second << " " << third << std::endl;

}
