

#include<iostream>


bool glob_check(const char *glob);
bool glob_match(const char *str, const char *glob);



struct LabelPath {
	SString label;
	SString path;
	SString filename;

	LabelPath(): label(), path() { }
	LabelPath(SString d, SString r, bool file_set);

	void show() {
		std::cerr <<label.c_str() <<" " <<path.c_str() <<"\n";
	}

	bool operator<(const LabelPath &other) const;
	bool operator==(const LabelPath &other) const;
};


class Project {

	PropSetFile propFile;

	SString name;

	std::list<LabelPath> ruleInclude;
	std::list<LabelPath> ruleExclude;

	void ProcessXxclude(const char * prop_type, std::list<LabelPath> &prop_list);
	void FillFiles(SString label, FilePath dir, SString glob, bool recursive);
public:
	bool opened;
	GUI::gui_string msg;

	FilePath basePath;
	std::vector<LabelPath> files;

	Project() : opened(false) {}
	~Project() {}

	bool open(FilePath _propFile);
	bool close();


	void Populate();


};