#include <stdio.h>

#include "boost/filesystem.hpp"
#include <iostream>

using namespace boost::filesystem;

bool find_file(const path & dir_path,         // in this directory,
			   const std::string & file_name, // search for this name,
			   path & path_found)             // placing path here if found
{
	if(!exists( dir_path )) 
		return false;

	directory_iterator end_itr;
	for(directory_iterator itr( dir_path ); itr != end_itr; ++itr)
	{
		if(is_directory(itr->status()))
		{
			if(find_file(itr->path(), file_name, path_found))
				return true;
		}
		else if(itr->path().filename() == file_name) // see below
		{
			path_found = itr->path();
			return true;
		}
	}
	return false;
}

int main(int argc, char **argv)
{
	printf("SO TERRIBLE\n");

	path whereWasIt;
	if(find_file(".", "terrible.cpp", whereWasIt))
	{
		printf("Found some terrible code here: %s\n", whereWasIt.c_str());
	}
	return 0;
}
