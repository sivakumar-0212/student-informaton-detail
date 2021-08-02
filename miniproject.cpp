#include<stdio.h>
#include<stdlib.h>
struct student
{
 int rollno;
 char name[30];
 int phone;
 char gender[10];
 int scham;
}s[20];
int insert(int no){
	FILE *fp;
	int i;
	fp=fopen("student.txt","w");
	if(fp==NULL){
		printf("\n file opening error");
		return 0;
	}
	for(i=0;i<no;i++){
       printf("\nEnter detail of student -- %d\n",i+1);
       printf("Name  ");
       scanf("%s",s[i].name);
       printf("rollno ");
       scanf("%d",&s[i].rollno);
	   printf("Phone no  ");
       scanf("%d",&s[i].phone);
       printf("gender  ");
       scanf("%s",s[i].gender);
       printf("scholarship amount  ");
       scanf("%d",&s[i].scham);
       fprintf(fp,"%s %d %d %s %d\n",s[i].name,s[i].rollno,s[i].phone,s[i].gender,s[i].scham);
	}
	fclose(fp);
}
int display(){
	FILE *fp1;
	int i=0,con;
	fp1=fopen("student.txt","r");
	int found=0,rno;
	if(fp1==NULL){
		printf("\n file opening error");
		return 0;
	}
	printf("enter the rollno of the student to be display  :");
	scanf("%d",&rno);
	while(1){
		fscanf(fp1,"%s %d %d %s %d",&s[i].name,&s[i].rollno,&s[i].phone,&s[i].gender,&s[i].scham);
		if(s[i].rollno==-1){
			break;
		}
		if(s[i].rollno==rno){
			found=1;
			printf("\nNAME : %s",s[i].name);
            printf("\nROLLNO : %d",s[i].rollno);
            printf("\nPHONE NO : %ld",s[i].phone);
            printf("\nGENDER : %s",s[i].gender);
            printf("\nSCHOLARSHIP AMOUNT : %d\n\n",s[i].scham);
		}
		i++;
	}
	if(found==0){
		printf("\n record not found");
	}
	printf("\nwhether you want to display any other record(0/1)   ");
	scanf("%d",&con);
	if(con==1){
		display();
	}
	fclose(fp1);
	return 0;
}
int  scholar(){
	FILE *fp1;
	int i=0;
	fp1=fopen("student.txt","r");
	while(!feof(fp1)){
	fscanf(fp1,"%s %d %d %s %d",&s[i].name,&s[i].rollno,&s[i].phone,&s[i].gender,&s[i].scham);
		if(s[i].scham>50000){
			printf("\n%s  :Excellent",s[i].name);
		}
		else if(s[i].scham>30000&&s[i].scham<=50000){
			printf("\n%s : verygood",s[i].name);
		}
		else if(s[i].scham>=10000&&s[i].scham<=30000){
			printf("\n%s : Good\n",s[i].name);
		}
	}
	fclose(fp1);
}
int deldetail(){
	FILE *fp1,*fp2;
	int found=0,rno;
	int i=0;
	fp1=fopen("student.txt","r");
	if(fp1==NULL){
		printf("\n file opening error");
		return 0;
	}
	fp2=fopen("temp.txt","w");
	if(fp2==NULL){
		printf("\n file opening error");
		return 0;
	}
	printf("\n Enter the roll number of the student whose record to be deleted  ");
	scanf("%d",&rno);
	while(1){
		fscanf(fp1,"%s %d %s %d",&s[i].name,&s[i].phone,s[i].gender,&s[i].scham);
		if(s[i].rollno==-1){
			break;
		}
		if(s[i].rollno==rno){
			found=1;

		}
		else if(s[i].rollno!=rno){

			fprintf(fp2,"%s %d %d %s %d",s[i].name,s[i].rollno,s[i].phone,s[i].gender,s[i].scham);

		}
		i++;
	}
	fprintf(fp2,"%d",-1);
	fclose(fp1);
	fclose(fp2);
	if(found!=0){
		fp1=fopen("student.txt","w");
		if(fp1==NULL){
			printf("\n file opening error");
		    return 0;
		}
		fp2=fopen("temp.txt","r");
		if(fp2==NULL){
			printf("\n file opening error");
		    return 0;
		}
		while(1){
			fscanf(fp2,"%d",s[i].rollno);
			if(s[i].rollno==-1)
			break;
			fscanf(fp2,"%s %d %d %s %d",&s[i].name,&s[i].rollno,&s[i].phone,&s[i].gender,&s[i].scham);
			fprintf(fp1,"%s %d %d %s %d",s[i].name,s[i].rollno,s[i].phone,s[i].gender,s[i].scham);
		}
		i++;
		printf("\n record deleted successfully");
	}
	else{
		printf("\n record not found");
	}
	fprintf(fp1,"%d",-1);
    fclose(fp1);
	fclose(fp2);
	remove("student.txt");
	rename("temp.txt","student.txt");
	return 0;
}
int main(){
	int c,no,emp;
 do
 {
  printf("\n\t---Select your choice---------\n");
  printf("\n\t1. INSERT\n\t2. DISPLAY\n\t3. Scholar\n\t4.DELETE\n\t5.Exit");
  printf("\n\n------------------------------------------\n");
  printf("\nEnter your choice:");
  scanf("%d", &c);
  printf("\n");
  switch (c)
  {
  case 1:
   printf("\nenter no of students   :");
   scanf("%d",&no);
   insert(no);
   break;
  case 2:
    display();
   break;
  case 3:
   scholar();
   break;
  case 4:
   deldetail();
   break;
  case 5:
   printf("exit");
}
}while(c!=5);
return 0;
}
