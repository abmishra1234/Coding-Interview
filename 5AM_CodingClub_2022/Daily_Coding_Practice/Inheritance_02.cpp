using namespace std;
#if 0
#include<iostream>
#include<string>

class Father
{
private:
	string eye_color;
	string hair_color;
public:
	Father() = default;
	Father(string ec, string hc) : eye_color(ec), hair_color(hc) {}
	void FatherTraits()
	{
		cout << "Eye Color : " << eye_color << endl;
		cout << "hair Color : " << hair_color << endl;
	}
};

class Son : public Father {
private:
	string name;
public:
	Son() = default;
	Son(string ec, string hc, string name) : Father(ec, hc), name(name) {}
	void Son_traits()
	{
		FatherTraits();
		cout << "name : " << name << endl;
	}
};

class Daughter : public Father {
private:
	string name;
public:
	Daughter() = default;
	Daughter(string ec, string hc, string name) : Father(ec, hc), name(name) {}
	void Daughter_traits()
	{
		FatherTraits();
		cout << "name : " << name << endl;
	}
};


int main()
{
	Son son("Brown", "Black", "Ralph");
	son.Son_traits();

	Daughter da("Green", "Golden", "Rapunzel");
	da.Daughter_traits();

	return 0;
}
#endif // 0
