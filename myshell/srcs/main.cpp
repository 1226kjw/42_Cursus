#include <sys/wait.h>
#include <sys/stat.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unistd.h>
#include <cstring>
#include <cerrno>
#define COLOR_BLUE "\033[1;34m"
#define COLOR_RESET "\033[0m"
#define SHELL "myshell"
using namespace std;

map<string, string> envm;
int	ret = 0;

char **vec2cstr(vector<string> s)
{
	char **arr = new char*[s.size() + 1];
	for (int i = 0; i < s.size(); i++)
		arr[i] = strdup(s[i].c_str());
	arr[s.size()] = 0;
	return arr;
}

void deletearr(char **arr)
{
	for (int i = 0; arr[i]; i++)
		delete[] arr[i];
	delete[] arr;
}

vector<string> split(string line, string divide)
{
	if (divide.size() == 0)
	{
		vector<string> v(1, string(line));
		return v;
	}
	int i,j;
	char quot = 0;
	vector<string> v;
	for (i=0,j=0; j < line.size();)
	{
		if (!quot && line.substr(j, divide.size()) == divide)
		{
			if (j - i > 0)
				v.push_back(line.substr(i, j - i));
			j += divide.size();
			i = j;
		}
		else
			j++;
		if (!quot && (line[j] == '\'' || line[j] == '\"'))
			quot = line[j];
		else if (quot && line[j] == quot)
			quot = 0;
	}
	if (i < line.size())
		v.push_back(line.substr(i));
	return v;
}

string git_check(void)
{
	string gitinfo = " ";
	if (access(".git", F_OK) == -1)
		return "";
	return gitinfo;
}

int run_cmd(string cmd)
{
	int status;
	vector<string> pipe_split = split(cmd, "|");

	char **cmd_arr = vec2cstr(split(cmd, " "));
	pid_t pid = fork();
	if (pid == 0)
	{
		if (execvp(cmd_arr[0], cmd_arr) == -1)
		{
			if (errno == 2)
			{
				cout << SHELL << ": command not found: " << cmd_arr[0] << endl;
				exit(127);
			}
			else
				cout << strerror(errno) << endl;
			exit(errno);
		}
	}
	else
	{
		wait(&status);
		deletearr(cmd_arr);
		return WEXITSTATUS(status);
	}
	return 0;
}

int main(int argc, char **argv, char **envp)
{
	string line;
	for (int i = 0; envp[i]; i++)
	{
		string t(envp[i]);
		int m = t.find("=");
		envm[t.substr(0, m)] = t.substr(m+1);
	}
	while (1)
	{
		char *cwd = getcwd(0, 0);
		cout << COLOR_BLUE << cwd << COLOR_RESET << git_check() << "$ ";
		getline(cin, line);
		if (cin.eof() || line == "exit")
			exit(0);
		vector<string> v = split(line, ";");
		for (auto i: v)
		{
			vector<string> w = split(i, "&&");
			for (auto j: w)
			{
				ret = run_cmd(j);
				cout << ret << endl;
				if (ret != 0)
					break ;
			}
		}
	}

}
