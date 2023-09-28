#include <string>
#include <iostream>

typedef struct s_data
{
	int x_;
	int y_;
} Data;

uintptr_t serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

int main(void)
{
	Data data;
	Data *ret;
	uintptr_t i;

	data.x_ = 4;
	data.y_ = 2;
	i = serialize(&data);
	std::cout << i << std::endl;
	ret = deserialize(i);
	std::cout << ret << std::endl;
	if (&data == ret)
		std::cout << "OK!!!" << std::endl;
	else
		std::cout << "NO!!!" << std::endl;
	return 0;
}
