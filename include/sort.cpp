#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct s_i
{
	string s;
	ifstream *f;
	s_i(const string& s_,ifstream* f_) : s(s_), f(f_){}
	bool operator < (const s_i& s_i_) const
	{
		return (s > s_i_.s);
	}
};

void sort_it(const string input_name, const string output_name, const unsigned long int mem_size)
{
	ifstream fin(input_name);
	if (!fin.is_open()) throw("file_not_open");
	ofstream fout(output_name);
	size_t k = 0;
	while (!fin.eof())
	{
		ofstream fout_(to_string(k + 1) + ".txt");
		vector<string> v; string s;
		for (unsigned long int size = 0; (size + sizeof(string)) <= mem_size; size += sizeof(string))
		{
			getline(fin, s);
			v.push_back(s);
		}
		sort(v.begin(), v.end());
		for (auto i : v)
		{
			if (i != "") fout_ << i<<endl;
		}
		++k;
		fout_.close();
	}
	fin.close();
	priority_queue<s_i> pq;
	for (size_t i = 0; i < k; ++i)
	{
		ifstream* f_ = new ifstream(to_string(i + 1) + ".txt");
		string str;
		getline(*f_, str);
		s_i si(str, f_);
		pq.push(si);
	}
	while (!pq.empty())
	{
		s_i si = pq.top();
		pq.pop();
		if (si.s != "")
		{
			fout << si.s;
			fout << endl;
		}
		if (!(*si.f).eof())
		{
			getline(*si.f, si.s);
			pq.push(si);
		}
		else
		{
			(*(si.f)).close();
		}
	}
	for (size_t i = 0; i < k; ++i)
	{
		remove((to_string(i + 1) + ".txt").c_str());
	}
	fout.close();
}
