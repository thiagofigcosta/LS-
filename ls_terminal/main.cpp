#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define def_n_words 10
#define def_string 100

using namespace std;

char input[def_string];
char words[def_string][def_n_words];
int idx_words;

void start(){
cout    <<"#####################"<<endl
        <<"#*  * **** *  *  ** #"<<endl
        <<"#** * *  * ** * *  *#"<<endl
        <<"#* ** **** * ** *  *#"<<endl
        <<"#*  * *  * *  *  ** #"<<endl
        <<"#####################"<<endl;
cout<<"digite um commando:"<<endl;
cin.getline(input,def_string);
}

void split(){ //divide os comandos
    char temp[def_string];
    int i,idx=0;
    idx_words=0;
    for (i=0; i<=strlen(input); i++){
        if (input[i] == ' '||input[i] == NULL) {
            strcpy(words[idx_words],temp);
           memset(temp, 0, def_string);
           if(idx>0){idx_words++;}
           idx=0;
        }else{
            char aux[1];
            temp[idx]=input[i];
            idx++;
        }
    }
}
void wait_out(){

}
void exec_prog(int arg){ //roda os outro programas
    switch(arg){
        case 1:
            system("ls_soma.exe");
            wait_out();
        break;
    }
}
void txtio(int arg, int id, int num_words){ //grava os arquivos de entrada e saida
    switch(arg){
    case 0: //write
    FILE *in_file;
		in_file =fopen("in.txt", "w");

		if (!in_file)
			return;

			fprintf(in_file,"%d\n",id);
            char srttemp[def_string];
			for (int i=1; i<=num_words; i++){
                strcpy(srttemp,words[i]);
                fprintf(in_file,"%s\n",srttemp);
			}
		fclose(in_file);
    break;
    case 1://read
        FILE *out_file;
    		char buf[1000];

    		out_file =fopen("input.txt","r");
    		if (!out_file)
        		return;

    		while (fgets(buf,1000, out_file)!=NULL)
        		printf("%s",buf);

		fclose(out_file);
		exec_prog(id);
    break;

    }
}

void process(){//processa os comandos
    if (!strcmp(words[0],"help")){
        cout<<"commandos:"<<endl
            <<"help"<<endl
            <<"soma %f %f ... %f"<<endl;
    }else if(!strcmp(words[0],"soma")){ //id 1
        txtio(0,1,idx_words);
    }

    else{//erro
        cout<<"commando desconhecido "<<words[0]<<endl;
        getchar(); //system pause
        void start();
    }
}

int main()
{
    system("COLOR 0A");//cor verde
    setlocale (LC_ALL, "Portuguese"); //permite acentos
    start();
    split();
    process();
    for (int i=0;i<def_n_words;i++)
        if(words[i]!="")
            cout<<endl<<words[i];
    return 0;
}

