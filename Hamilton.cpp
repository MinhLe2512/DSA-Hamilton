#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <string.h>

class hamiltonian
{
public:
	hamiltonian(const std::vector<std::vector<int>> &matrix);
	//void loadGraph(const std::vector<std::vector<int>> &matrix);
	bool hasCycle();
	bool hasPath();

private:
	enum result_t
	{
		FALSE = 0,
		PATH = 1,
		CYCLE = 2,
	};
	result_t recursion(size_t pos);
	bool isSafe(int vertex, size_t pos);

	const std::vector<std::vector<int>> &matrix;
	std::vector<bool> visited;
	std::vector<int> path;
};

hamiltonian::hamiltonian(const std::vector<std::vector<int>> &matrix)
	: matrix(matrix), visited(matrix.size(), false), path(matrix.size(), -1)
{
	path[0] = 0;
	visited[0] = true;
}

// void hamiltonian::loadGraph(const std::vector<std::vector<int>> &matrix)
// {
// 	*this = hamiltonian(matrix);
// }

bool hamiltonian::hasCycle()
{
	bool result = recursion(1) == result_t::CYCLE;
	//reset
	visited = std::vector<bool>(matrix.size(), false);
	return result;
}

bool hamiltonian::hasPath()
{
	bool result = recursion(1) == result_t::FALSE;
	//reset
	visited = std::vector<bool>(matrix.size(), false);
	return result;
}

hamiltonian::result_t hamiltonian::recursion(size_t pos)
{
	if (pos == matrix.size())
	{
		return (matrix[path[pos - 1]][path[0]] != 0)
				   ? result_t::CYCLE
				   : result_t::PATH;
	}
	//search for vertex that haven't in path[]
	for (int vertex = 1; vertex < (int)matrix.size(); vertex++)
	{
		if (isSafe(vertex, pos))
		{
			visited[vertex] = true;
			path[pos] = vertex;
			result_t type = recursion(pos + 1);
			if (type != result_t::FALSE)
				return type;
			//backtrack
			visited[vertex] = false;
			path[pos] = -1;
		}
	}
	return result_t::FALSE;
}

bool hamiltonian::isSafe(int vertex, size_t pos)
{
	//if current vertex is adjacented to the previous vertex in path[]
	if (matrix[path[pos - 1]][vertex] == 0)
		return false;
	return !visited[vertex];
}

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

//DEBUG
#include <limits>
bool readMatrix(std::ifstream &fin, std::vector<std::vector<int>> &matrix)
{
	size_t size;
	if (!(fin >> size))
		return false;
	fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignore description

	matrix.resize(size);
	int buffer;
	for (size_t i = 0; i < size; i++)
	{
		matrix[i].resize(size);
		for (size_t j = 0; j < size && fin >> buffer; j++)
		{
			matrix[i][j] = buffer;
		}
	}
	return true;
}

int main(int argc, const char *argv[])
{
	 /*if (argc != 3)
	 {
	 	std::cout << "Invalid argument.";
	 	return 1;
	 }

	 std::vector<std::vector<int>> gMatrix;
	 if (!readFile(argv[2], gMatrix))
	 {
	 	std::cout << "Read file failed.";
	 	return 1;
	 }

	 hamiltonian check(gMatrix);
	 if (strcmp(argv[1], "-HPath") == 0)
	 {
	 	std::cout << (check.hasPath() ? "Yes" : "No");
	 }
	 else if (strcmp(argv[1], "-HCycle") == 0)
	 {
	 	std::cout << (check.hasCycle() ? "Yes" : "No");
	 }
	 else
	 {
	 	std::cout << "Invalid argument.";
	 	return 1;
	}*/

	//DEBUG
	const char *dir = "C:\\Users\\DELL\\source\\repos\\Project8\\Project8\\test.txt";
	std::ifstream fin(dir);
	if (!fin.is_open())
	{
		std::cout << "Read file failed.";
		return 1;
	}
	std::vector<std::vector<int>> matrix;
	while (readMatrix(fin, matrix))
	{
		hamiltonian ham(matrix);
		std::cout << "Path: " << (ham.hasPath() ? "Yes" : "No");
		std::cout << std::endl;
		std::cout << "Cycle: " << (ham.hasCycle() ? "Yes" : "No");
		std::cout << std::endl
				  << std::endl;
	}
	fin.close();
}