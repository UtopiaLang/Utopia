#include <fstream>
#include <iostream>

#include "Program.hpp"

using namespace Utopia;

int main(int num_args, const char** args)
{
	if (num_args != 2)
	{
		std::cout << "Syntax: " << args[0] << " <ul-file>" << std::endl;
		return 1;
	}

	Program p = Program::fromFile(args[1]);

	std::ofstream file("src/main_compiled.cpp");
	file << R"EOC(#include "DataString.hpp"
#include "Program.hpp"

using namespace Utopia;

int main()
{
	Program p{};
)EOC";

	for (const auto& data : p.data)
	{
		file << "p.data.emplace_back(" << data->toCPP() << ");";
	}

	file << "p.ops = {";
	for (size_t i = 0; i < p.ops.size(); i++)
	{
		if (i != 0)
		{
			file << ",";
		}
		file << std::to_string(p.ops.at(i));
	}
	file << "};";

	file << "p.execute();}";
}