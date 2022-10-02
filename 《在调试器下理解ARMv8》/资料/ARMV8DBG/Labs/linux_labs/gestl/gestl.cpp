#include <vector>
#include <map>
#include <list>
#include <string>

using namespace std;

class dog_t
{
protected:
	int    _age;
	string _name;
public:
	dog_t(int age, const char* name)
	{
		_age = age;
		_name = name;
	}
}; 

int main(int argc, char*argv[])
{
	vector<dog_t> vdogs;
	list<dog_t> ldogs;
	map<int, dog_t> mdogs;

	vdogs.push_back(dog_t(0x88, "dahei"));
	vdogs.push_back(dog_t(0x89, "erhei"));
	vdogs.push_back(dog_t(0x8a, "xiaohei"));

	ldogs.push_back(dog_t(0x88, "dahei"));
	ldogs.push_back(dog_t(0x89, "erhei"));
	ldogs.push_back(dog_t(0x8a, "xiaohei"));
	
	mdogs.insert(pair<int, dog_t>(11,dog_t(0x88, "dahei")));
	mdogs.insert(pair<int, dog_t>(22,dog_t(0x89, "erhei")));
	mdogs.insert(pair<int, dog_t>(33,dog_t(0x8a, "xiaohei")));

	return 0;
}
