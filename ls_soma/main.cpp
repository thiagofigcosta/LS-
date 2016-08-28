#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define mainID 1
#define def_n_words 10
#define def_string 100
using namespace std;

char words[def_string][def_n_words];
float args[def_n_words],result;
int id;
int idx_words=0;
char str_process[def_string];

void read(){//le as entradas
FILE *in_file;
    		char buf[1000];

    		in_file =fopen("in.txt","r");
    		if (!in_file)
        		return;

    		while (fgets(buf,1000, in_file)!=NULL){
        		strcpy(words[idx_words],buf);
        		idx_words++;
            }

		fclose(in_file);
}

void write(int arg){//escreve o resultado
  switch(arg){
    case -1:
    //escreve erro no arquivo out

FILE *out_file;
		out_file =fopen("out.txt", "w");

		if (!out_file)
			return;

			fprintf(out_file,"%d\n",-1);
                	fprintf(out_file,"%s\n","error";
			
		fclose(out_file);
    break;
    case 1:
        //escreve o resultado

FILE *out_file;
		out_file =fopen("out.txt", "w");

		if (!out_file)
			return;

			fprintf(out_file,"%d\n",id);
                fprintf(out_file,"%f\n",result);
			
		fclose(out_file);
    break;
  }
}


void process(int step){//cria o arquivo do processo
  memset(str_process, 0, def_string);
  switch(step){
    case 1:
        for(int i=0;i<=idx_words;i++)
            //str_process+=words[i]+"+";
        //str_process[strlen(str_process)-1]='=';
        //str_process+=; // resultado
    break;
    }
}
void calc(){//calc
    result=0;
    for(int i=0;i<=idx_words;i++)
        result+=args[i];

    process(1);
    write(1);
}

void wrt_process(int step){
  switch(step){
    case 1:
        //escreve um passo
    break;
}
}

void decrypt(){//converte words para int e float
    id=atoi(words[0]);

    for(int i=0;i<=idx_words;i++)
    args[i]=atof(words[i]);

    if(id==1){
        calc();
    }else{
        write(-1);
    }
}

int main()
{
    read();
    return 0;
}
