#include <stdio.h>

void GetData(char id[][6],char fname[][20],char lname[][30],char sex[],float gpa[],int depart[],int *cnt)
{
   FILE *inf;
   inf = fopen("student.txt","r");
   fscanf(inf,"%s%s%s %c%f%d",&id[*cnt],&fname[*cnt],&lname[*cnt],&sex[*cnt],&gpa[*cnt],&depart[*cnt]); 
   while(!feof(inf))
   {
      *cnt = *cnt + 1;//(*cnt)++;                 
      fscanf(inf,"%s%s%s %c%f%d",&id[*cnt],&fname[*cnt],&lname[*cnt],&sex[*cnt],&gpa[*cnt],&depart[*cnt]); 
   }
   fclose(inf);  
}


void PrintArray(char id[][6],char fname[][20],char lname[][30],char sex[],float gpa[],int depart[],int cnt)
{
   FILE *out;  
   int i;
   out = fopen("Report.txt","w");
   for(i=0; i<cnt; i++)
   {
     fprintf(out,"%-6s %-10s %-15s %-3c %-5.2f ",id[i],fname[i],lname[i],sex[i],gpa[i]);
     if(depart[i] == 1)
     {
       fprintf(out,"CS\n");           
     }                
     else if(depart[i] == 2)
     {
       fprintf(out,"IT\n");   
     }
     else if(depart[i] == 3)
     {
       fprintf(out,"SE\n");   
     }
   }
   fclose(out);     
}


void CountBySex(char sex[],int depart[],int cnt,int *maleCS, int *femaleCS,int *maleIT,int *famaleIT,int *maleSE,int *femaleSE)
{
   int i;
   for(i=0; i<cnt; i++)
   {
      if(depart[i] == 1)
      {
         if(sex[i] == 'm' || sex[i] == 'M')
           (*maleCS)++;
         else
            (*femaleCS)++; 
      }  
      else if(depart[i] == 2)
      {
         if(sex[i] == 'm' || sex[i] == 'M')
           (*maleIT)++;
         else
            (*famaleIT)++;   
      }  
      else if(depart[i] == 3)
      {
         if(sex[i] == 'm' || sex[i] == 'M')
           (*maleSE)++;
         else
            (*femaleSE)++;       
      }    
   }           
}


void PrintByDepart(char id[][6],char fname[][20],char lname[][30],char sex[],float gpa[],int depart[],int cnt)
{
   FILE *out1,*out2,*out3;
   int i,maleCS=0,femaleCS=0,maleIT=0,femaleIT=0,maleSE=0,femaleSE=0;
   out1 = fopen("CS.txt","w");
   out2 = fopen("IT.txt","w");
   out3 = fopen("SE.txt","w");
   for(i=0; i<cnt; i++)
   {
      if(depart[i] == 1)
      {      
         fprintf(out1,"%-6s %-10s %-15s %-3c %-5.2f \n",id[i],fname[i],lname[i],sex[i],gpa[i]);       
      }   
      else if(depart[i] == 2)
      {
              fprintf(out2,"%-6s %-10s %-15s %-3c %-5.2f \n",id[i],fname[i],lname[i],sex[i],gpa[i]);        
      }        
      else if(depart[i] == 3)
      {
              fprintf(out3,"%-6s %-10s %-15s %-3c %-5.2f \n",id[i],fname[i],lname[i],sex[i],gpa[i]);         
      }               
   }
   CountBySex(sex,depart,cnt,&maleCS,&femaleCS,&maleIT,&femaleIT,&maleSE,&femaleSE);
   fprintf(out1,"Male = %d\n",maleCS);
   fprintf(out1,"Female = %d\n",femaleCS);
   fprintf(out2,"Male = %d\n",maleIT);
   fprintf(out2,"Female = %d\n",femaleIT);   
   fprintf(out3,"Male = %d\n",maleSE);
   fprintf(out3,"Female = %d\n",femaleSE);    
   fclose(out1);
   fclose(out2);
   fclose(out3);
}


int main()
{
   char id[30][6],fname[30][20],lname[30][30],sex[30];
   float gpa[30];
   int depart[30],cnt=0;
   GetData(id,fname,lname,sex,gpa,depart,&cnt);    //call GetData function here
   PrintArray(id,fname,lname,sex,gpa,depart,cnt);  //call PrintArray function here   
   PrintByDepart(id,fname,lname,sex,gpa,depart,cnt);
   return(0);
}
