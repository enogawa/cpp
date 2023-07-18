#include "../inc/Harl.hpp"

int main() {
	Harl harl;
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("TEST");
	harl.complain("debug");
	harl.complain("info");

	return 0;
}