#include<stdio.h>
#include<string.h>
#include<ctype.h>
int isKeyword(char tok[]){
    if(strcmp(tok,"if")==0 || strcmp(tok,"else")==0 || strcmp(tok,"char")==0 || strcmp(tok,"const")==0 ||
    strcmp(tok,"auto")==0 || strcmp(tok,"break")==0 || strcmp(tok,"case")==0 || strcmp(tok,"continue")==0 ||
    strcmp(tok,"default")==0 || strcmp(tok,"do")==0 || strcmp(tok,"double")==0 || strcmp(tok,"enum")==0 ||
    strcmp(tok,"extern")==0 || strcmp(tok,"float")==0 || strcmp(tok,"for")==0 || strcmp(tok,"goto")==0 ||
    strcmp(tok,"int")==0 || strcmp(tok,"long")==0 || strcmp(tok,"register")==0 || strcmp(tok,"return")==0 ||
    strcmp(tok,"short")==0 || strcmp(tok,"signed")==0 || strcmp(tok,"sizeof")==0 || strcmp(tok,"static")==0
    || strcmp(tok,"struct")==0 || strcmp(tok,"switch")==0 || strcmp(tok,"typedef")==0 ||
    strcmp(tok,"union")==0 || strcmp(tok,"unsigned")==0 || strcmp(tok,"void")==0 || strcmp(tok,"volatile")==0
    || strcmp(tok,"while")==0)
    {
        return 1;
    }
    return 0;
}

int isOperator(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='(' || c==')' || c=='[' || c==']' || c=='<' ||
    c=='>' || c=='='){
        return 1;
    }
    return 0;
}

int main(){
    printf("256 - Sreena R \n");
    char s[1000];
    printf("Enter a string : ");
    scanf("%[^\n]s", s);
    char *tok = strtok(s," ");
    while(tok!=NULL){
        if(isKeyword(tok)){
            printf("%s is keyword\n",tok);
        }
        else{
            int flag=0;
            char c = tok[0];
            if(isdigit(c)){
                for(int i=1;i<strlen(tok);i++){
                    if(!isdigit(tok[i])){
                        flag=1;
                        break;
                    }
                }
                if(flag==1){
                    printf("%s is invalid literal\n",tok);
                }
                else{
                    printf("%s is a number\n",tok);
                }  
            }
            else if(isOperator(c)){
                printf("%s is operator\n",tok);
            }
            else if((c>='a' && c<='z') || (c>='A' && c<='Z') || c=='_'){
                printf("%s is an identifier\n",tok);
            }
            else{
                printf("%s is a special charcter\n",tok);
            }
        }
    tok = strtok(NULL," ");
    }
    return 0;
}
