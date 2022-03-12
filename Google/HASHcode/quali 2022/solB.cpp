#include<bits/stdc++.h>
using namespace std;
int n_contributor, n_project;
class contributor {
public:
	string name;
	int skills;
	map<string, int> table; // stores skills and their scores
	contributor() {
		name.clear();
		skills = 0;
		table.clear();
	}
};
class project {
public:
	string name;
	int duration;//D
	int score; // S
	int best_before; // B
	int roles; // R
	vector<string> skill_needed;
	vector<int> skill_level;

	project() {
		duration = 0, score = 0, best_before = 0, roles = 0;
		skill_level.clear();
		skill_needed.clear();
		name.clear();
	}
	void assign(int d, int s, int b, int r, vector<string>&sn, vector<int>&sl,string &n) {
		duration = d;
		score = s;
		best_before = b;
		roles = r;
		skill_level = sl;
		skill_needed = sn;
		name = n;
	}
};
vector<contributor> contributor_list;
vector<project> project_list;

int  main ()
{
	


	cin >> n_contributor >> n_project;
	for (int i = 0; i < n_contributor; i++) {
		contributor obj;
		string name;
		int contributor_skills;
		cin >> name >> contributor_skills;
		obj.name = name;
		obj.skills = contributor_skills;

		for (int j = 0; j < contributor_skills; j++) {
			string skill_name;
			int skill_level;
			cin >> skill_name >> skill_level;
			obj.table[skill_name] = skill_level;
		}
		contributor_list.push_back(obj);
	}

	for (int i = 0; i < n_project; i++) {
		string name; cin >> name;
		int d, s, b, r;
		cin >> d >> s >> b >> r;
		vector<string> sn(r);
		vector<int> sl(r);
		for (int j = 0; j < r; j++) {
			cin >> sn[j] >> sl[j];
		}
		project obj;
		obj.name = name;
		obj.assign(d, s, b, r, sn, sl,name);
		project_list.push_back(obj);
	}

	vector<bool> done(n_project);

	vector<vector<string>> details;
	vector<string> done_projects;
	int it=0;

	
	while (it<1000) // while it's possible to do a project
	{

		int possible = 0;


		vector<vector<string>> candidates;
		for (int i = 0; i < n_project; i++) {
			if(done[i])continue;
			int bad = 0;
		    vector<string> names;

			//cout<<"for project: "<<project_list[i].name<<":\n";

		    vector<bool> busy(n_contributor);

			for(int j=0;j<project_list[i].roles;j++){
				string sk = project_list[i].skill_needed[j];
				int sl = project_list[i].skill_level[j];
				
				bool can=0;



				for(int k=0;k<n_contributor;k++){
					if(busy[k])continue;

					if(contributor_list[k].table[sk] >= sl){
						//cout<<contributor_list[k].name<<" is chosen!\n";
						names.push_back(contributor_list[k].name);
						busy[k]=1;
						can=1;
						//mn = contributor_list[k].table.size();
						break;
					}
				}
				if(can==0){
					bad = 1;
					break;
				}
			}
			if(bad == 0){
				//cout<<project_list[i].name<<endl;
				done_projects.push_back(project_list[i].name);
				details.push_back(names);
				possible=1;
				done[i]=1;
			}
		}
		if(possible==0)break;
		it++;
	}
	cout<<done_projects.size()<<endl;

	for(int i=0;i<done_projects.size();i++){
		cout<<done_projects[i]<<endl;
		for(int j=0;j<details[i].size();j++){
			if(j)cout<<" ";
			cout<<details[i][j];
		}
		cout<<endl;
	}
	return 0;
}