#include "Person.pb.h"
#include "MyTest.h"
#include <string>
void MyTest::test()
{
	Person p;
	Family f;

	p.set_id(10);
	p.set_age(23);
	p.set_sex("man");
	p.set_name("Wang");

	//将message Address嵌套后, 可以使用Person对象调用Address对象
	p.mutable_addr()->set_addr("Henan");
	p.mutable_addr()->set_num(1001);

	//Person使用枚举
	p.set_color(Green);

	f.add_name();
	f.set_name(0, "Xu");
	f.add_name("Li");
	f.add_name("Zhang");


	//序列化, 二进制格式
	std::string output;
	p.SerializeToString(&output);

	std::string output_f;
	f.SerializeToString(&output_f);





	//反序列化, 存储到新的对象中
	Person pp;
	Family ff;
	pp.ParseFromString(output);
	ff.ParseFromString(output_f);

	std::cout << pp.id() << " ";
	std::cout << pp.sex() << " ";
	std::cout << pp.name() << " ";
	std::cout << pp.age() << "\n";

	std::cout << pp.addr().addr() << " ";
	std::cout << pp.addr().num() << "\n";

	std::cout << "Family: ";
	for (int i = 0; i < ff.name_size(); i++)
	{
		std::cout << ff.name(i) << " ";
	}
	std::cout << "\n";

	std::cout << p.color() << "\n";
}
