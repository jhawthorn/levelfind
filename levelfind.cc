#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

#include <sys/types.h>
#include <dirent.h>
#include <cstdio>

using namespace std;

struct ent{
	string name;
	unsigned char type;
	ent(string name, unsigned char type): name(name), type(type){}
	bool operator<(const ent &e) const {
		return name < e.name;
	}
};

string root = "./";
vector<ent> files;

void adddir(string name){
	int oldsize = files.size();
	DIR *dp = opendir((root + name).c_str());
	struct dirent *ep;
	if (dp != NULL){
		while((ep = readdir(dp))){
			if(ep->d_name[0] != '.')
				files.push_back(ent(name + ep->d_name, ep->d_type));
		}
		closedir(dp);
	}else{
		perror("Couldn't open the directory");
	}
	sort(files.begin() + oldsize, files.end());
}

int main(int argc, char *argv[]){
	if(argc == 2){
		root = argv[1];
	}else if(argc != 1){
		cerr << "Usage: levelfind [DIR]" << endl;
		exit(EXIT_FAILURE);
	}
	adddir("");
	for(unsigned int i = 0; i < files.size(); i++){
		ent e = files[i];
		if(e.type & DT_DIR){
			adddir(e.name + "/");
		}
		cout << e.name << endl;
	}
	return 0;
}

