#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){
char label[20],opcode[20],operand[20],code[20],flag=0;
FILE *input,*optab,*symtab,*intermediate;
int Locctr,start,length;
input=fopen("input.txt","r");
optab=fopen("optab.txt","r");
symtab=fopen("symtab.txt","w");
intermediate=fopen("intermediate.txt","w");
fscanf(input,"%s\t%s\t%s",label,opcode,operand);
if(strcmp(opcode,"START")==0)
{
Locctr=atoi(operand);
start=Locctr;
fprintf(intermediate,"%d\t%s\t%s\t%s",Locctr,label,opcode,operand);
printf("%d\t%s\t%s\t%s",Locctr,label,opcode,operand);
fscanf(input,"%s\t%s\t%s",label,opcode,operand);
}
else{
Locctr=0;
}
while(strcmp(opcode,"END")!=0){
if(strcmp(label,"**")!=0)
{
fprintf(symtab,"%d\t%s\n",Locctr,label);
}
fscanf(optab,"%s",code);
while(strcmp(code,"END")!=0){
if (strcmp(opcode,code)==0){
Locctr+=3;
break;
}
fscanf(optab,"%s",code);
}
if(strcmp(opcode,"**")!=0)
{
if(strcmp(opcode,"RESW")==0)
{
Locctr+=(3*(atoi(operand)));
}
else if(strcmp(opcode,"WORD")==0){
Locctr+=3;
}
else if(strcmp(opcode,"BYTE")==0){
Locctr++;
}
else if(strcmp(opcode,"RESB")==0){
Locctr+=(atoi(operand));
}
}
else{
printf("error");
flag=1;
break;
}
fprintf(intermediate,"%d\t%s\t%s\t%s",Locctr,label,opcode,operand);
printf("%d\t%s\t%s\t%s",Locctr,label,opcode,operand);
fscanf(input,"%s\t%s\t%s",label,opcode,operand);
}
fprintf(intermediate,"%d\t%s\t%s\t%s",Locctr,label,opcode,operand);
printf("length=%d\n",(Locctr-start));
fclose(optab);
fclose(symtab);
fclose(intermediate);
fclose(input);
}

