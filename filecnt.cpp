//============================================================================
// Name        : ProgrammingAssignment1.cpp
// Author      : Eldyn Castillo
// Date        : 02/25/2020
// Description : Recursively walks through a path and counts number of files, size of the files and number of directories.
//============================================================================
//extra comment here
#include <iostream>
#include <experimental/filesystem>
#include "version.h"
//new comment
using namespace std;
namespace fs = std::experimental::filesystem;
void recursive_walk(string);
static double version = 1.2;
int main(int argc, char* argv[]) {
	displayVersion(version);
	string path;
	if(argv[1] == NULL)
	{
		cout <<"error" << endl;
		exit(EXIT_FAILURE);
	}
	recursive_walk(argv[1]);
	return 0;
}

void recursive_walk(string pathstr)
{

	auto directoryIter = fs::recursive_directory_iterator(pathstr);
	int countdirs = 0;
	int countfiles = 0;
	int numbytes = 0;
	for(auto &e: directoryIter)
	{
		if(fs::is_directory(e))
		{
			countdirs++;
		}
		else if(fs::is_regular_file(e))
		{
			numbytes+= fs::file_size(e);
			countfiles++;
		}

	}

	cout << "The total number of directories in directory" << pathstr << " is: "<< countdirs << '\n';
	cout << "The total number of files in directory" << pathstr << " is: "<< countfiles << '\n';
	cout << "The total number of bytes occupied by all files in directory " << pathstr << " is: " << numbytes << endl;


}
