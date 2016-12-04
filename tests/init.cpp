#include <sort.cpp>
#include <catch.hpp>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

SCENARIO("zzz", "[zzz]")
{
  sort_it("in.txt", "out.txt", 120);
	string *a = new string[21], *b = new string[21];
	bool x = false;
	ifstream f1("out.txt"), f2("test.txt");
	for (int i = 0; i < 21; ++i)
	{
		getline(f1, a[i]);
		getline(f2, b[i]);
	}
	size_t x_ = 0;
	for (int i = 0; i < 21; ++i)
	{
		if (a[i] == b[i]) ++x_;
	}
	if (x_ == 21) x = true;
  REQUIRE(x);
} 
