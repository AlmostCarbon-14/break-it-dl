#include <string.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <errno.h>
#include <stdio.h> 
#include <stdlib.h>


char *build(char *num) {
	char *team = "ProjectTeam", *PjT, *cmd = "git clone git@gizmonic.cs.umd.edu:atm/";
	PjT = (char *) malloc(strlen(num) + strlen(team) + strlen(cmd) + 1);
	PjT[0] = '\0';
	strcat(PjT, cmd);
	strcat(PjT, team);
	strcat(PjT, num);
	return PjT;
}
char *dir(char *num) {
	char *team = "ProjectTeam", *PjT;
	PjT = (char *) malloc(strlen(num) + strlen(team) + 1);
	PjT[0] = '\0';
	strcat(PjT, team);
        strcat(PjT, num);
        return PjT;
}

void call(char *cmd, char *dir){
	char *cd = "cd ", cat[100], lv[100], *vv = "\nrm -r bin\nmake";
	int ret;
	cat[0] = '\0';
	strcat(cat, cd);
	strcat(cat, dir);
	strcat(lv,cat);
	strcat(lv,vv);
	ret = system(cmd);
	if (ret != 0) {
		char rm[100];
		strcat(rm, "rm -rf ");
	       	strcat(rm, dir);	
		system(rm);
		return;
	}
	ret = system(lv);
	if(ret != 0) {
		char rm[100];
                strcat(rm, "rm -rf ");
                strcat(rm, dir);
                system(rm);
                return;
	}
}


int main(int args, char **argc) {
	int team;
	system("ssh-add");
	for (int team = 1; team < 60;team++) {
		char *send = (char *) malloc(100);
		snprintf(send,sizeof(send), "%d", team);
		call(build(send), dir(send));
		free(send);
	}
}
