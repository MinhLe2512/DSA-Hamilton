#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

class hamiltonian
{
public:
	hamiltonian(const std::vector<std::vector<int>> &);
	bool hasCycle();
	bool hasPath();

private:
	const std::vector<std::vector<int>> matrix;
	std::vector<int> path;
};

bool readFile(const char *dir, std::vector<std::vector<int>> &matrix)
{
	std::ifstream fin(dir);
	if (fin.is_open())
		return false;
	size_t size;
	fin >> size;
	matrix.resize(size, std::vector<int>(size, 0));

	std::string buffer;
	while (std::getline(fin, buffer) && buffer.find("-1") != std::string::npos)
	{
		std::stringstream ss(buffer);
		//vertex1, vertex2, weight
		int input[3];
		for (int i = 0; ss >> input[i] && i < 3; i++)
			;
		//the file vertex count from 1
		matrix[input[0] - 1][input[1] - 1] = input[2];
		matrix[input[1] - 1][input[0] - 1] = input[2];
	}

	fin.close();
	return true;
}

int main(int argc, const char *argv[])
{
	if (argc != 3)
	{
		std::cout << "Invalid argument.";
		return 1;
	}

	std::vector<std::vector<int>> gMatrix;
	if(!readFile(argv[2], gMatrix))
	{
		std::cout << "Read file failed.";
		return 1;
	}

	hamiltonian check(gMatrix);
}