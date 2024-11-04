#include <math.h>

struct route
{
  char ekk[51];
  int mikos;
  int ana;
  int kata;
  int meg;
  int el;
  char term[51];
};

void print1(struct route A[],int i)
{
  int k;
  k=round(A[i].mikos/65.0+A[i].ana/10.0);
  printf("From %s to %s\n",A[i].ekk,A[i].term);
  printf("Uphill %d, Downhill %d\n",A[i].ana,A[i].kata);
  printf("Max altitude %d, Min altitude %d\n",A[i].meg,A[i].el);
  printf("Length %d, Estimated time %d min\n",A[i].mikos,k);   
  printf("\n");  
}

void print2(struct route A[],int i)
{
  int k;
  k=round(A[i].mikos/65.0+A[i].kata/10.0);
  printf("From %s to %s\n",A[i].term,A[i].ekk);
  printf("Uphill %d, Downhill %d\n",A[i].kata,A[i].ana);
  printf("Max altitude %d, Min altitude %d\n",A[i].meg,A[i].el);
  printf("Length %d, Estimated time %d min\n",A[i].mikos,k);   
  printf("\n");
}

void taksinomisi(struct route A[],int n)
{
  int i,j,temp1,temp2,temp3,temp4,temp5;
  char temp6[51],temp7[51];
  for (i=0;i<n-1;i++)
  {
    for (j=0;j<n-1-i;j++)
    {
      if (A[j].mikos<A[j+1].mikos)
      {
        temp1=A[j].mikos;
        A[j].mikos=A[j+1].mikos;
        A[j+1].mikos=temp1; 
        temp2=A[j].ana;
        A[j].ana=A[j+1].ana;
        A[j+1].ana=temp2; 
        temp3=A[j].kata;
        A[j].kata=A[j+1].kata;
        A[j+1].kata=temp3; 
        temp4=A[j].meg;
        A[j].meg=A[j+1].meg;
        A[j+1].meg=temp4; 
        temp5=A[j].el;
        A[j].el=A[j+1].el;
        A[j+1].el=temp5; 
        strcpy(temp6,A[j].ekk);
        strcpy(A[j].ekk,A[j+1].ekk);
        strcpy(A[j+1].ekk,temp6);
        strcpy(temp7,A[j].term);
        strcpy(A[j].term,A[j+1].term);
        strcpy(A[j+1].term,temp7);
      }  
    }
  } 
}

int readFromInput (struct route A[])
{
  int n,i;
  scanf("%d ",&n);
  for (i=0;i<n;i++)
  {
    fgets(A[i].ekk,51,stdin);
    A[i].ekk[strcspn(A[i].ekk,"\n")]='\0';
    scanf("%d %d %d %d %d ",&A[i].mikos,&A[i].ana,&A[i].kata,&A[i].meg,&A[i].el);
    fgets(A[i].term,51,stdin);
    A[i].term[strcspn(A[i].term,"\n")]='\0';
  }
  taksinomisi(A,n);
  return n; 
}

void printData (struct route A[],int n)
{
  int i;
  for (i=0;i<n;i++)
  {
    if (strcmp(A[i].ekk,A[i].term)==0)
      print1(A,i);
    else
    {
      print1(A,i);
      print2(A,i);
    }
  }
}

void findShort (struct route A[],int n)
{
  int L,i;
  scanf("%d",&L);  
  for (i=0;i<n;i++)
  {
    if (A[i].mikos<=L)
    {
      if (strcmp(A[i].ekk,A[i].term)==0)
        print1(A,i);
      else
      {
        print1(A,i);
        print2(A,i);
      }  
    }
  }
}

void findLocation(struct route A[],int n)
{
  int i;
  char B[51];
  fgets(B,51,stdin);
  B[strcspn(B,"\n")]='\0';
  for (i=0;i<n;i++)
  {
    if (strcmp(A[i].ekk,A[i].term)!=0)   
    {  
      if (strcmp(B,A[i].term)==0)
        print2(A,i);
      else if (strcmp(B,A[i].ekk)==0)
        print1(A,i);
    }
    else
    {
      if (strcmp(B,A[i].ekk)==0) 
        print1(A,i);
    }  
  }
}

void findUpHill(struct route A[],int n)
{
  int i;
  for (i=0;i<n;i++)
  {
    if (A[i].ana>A[i].kata)
      print1(A,i);
    else if (A[i].ana<A[i].kata)
      print2(A,i);
  }
}

void findDownHill(struct route A[],int n)
{
  int i;
  for (i=0;i<n;i++)
  {
    if (A[i].ana>A[i].kata)
      print2(A,i);
    else if (A[i].ana<A[i].kata)
      print1(A,i);
  }
}

void findAltitude(struct route A[],int n)
{
  int i,min,max;
  scanf("%d %d",&min,&max);
  for (i=0;i<n;i++)
  {
    if (min<=A[i].el && max>=A[i].meg)
    {
      if (strcmp(A[i].ekk,A[i].term)==0)
        print1(A,i);
      else
      {
        print1(A,i);
        print2(A,i);
      }    
    }
  }
}

void findTimely(struct route A[],int n)
{
  int i,t;
  float ti,tia;
  scanf("%d",&t);
  for (i=0;i<n;i++)
  {
    ti=A[i].mikos/65.0+A[i].ana/10.0;
    tia=A[i].mikos/65.0+A[i].kata/10.0;
    if (strcmp(A[i].ekk,A[i].term)==0)
    {
      if (ti<=t)
        print1(A,i);
    }
    else
    {
      if (ti<=t)
        print1(A,i);
      if (tia<=t)
        print2(A,i);
    }
  }
}

int readFromFile (struct route A[])
{
  int n,i,k;
  char s[15];
  FILE *fp;
  fgets(s,15,stdin);
  s[strcspn(s,"\n")]='\0';
  fp=fopen(s,"r");
  if (fp!=NULL)
  {
    fscanf(fp,"%d ",&n);
    for (i=0;i<n;i++)
    {
      fgets(A[i].ekk,51,fp);
      A[i].ekk[strcspn(A[i].ekk,"\n")]='\0';
      fscanf(fp,"%d %d %d %d %d ",&A[i].mikos,&A[i].ana,&A[i].kata,&A[i].meg,&A[i].el);
      fgets(A[i].term,51,fp);
      A[i].term[strcspn(A[i].term,"\n")]='\0';   
    }
    fclose(fp);
    taksinomisi(A,n);
  }
  else
    printf("Error opening file");
  return n;
}

void saveData(struct route A[],int n)
{
  int i,k;
  char s[15];
  FILE *fp;
  fgets(s,15,stdin);
  s[strcspn(s,"\n")]='\0';
  fp=fopen(s,"w");
  if (fp!=NULL)
  {
    fscanf(fp,"%d ",&n);
    for (i=0;i<n;i++)
    {
      if (strcmp(A[i].ekk,A[i].term)==0)
      {  
        k=round(A[i].mikos/65.0+A[i].ana/10.0);
        fprintf(fp,"From %s to %s\n",A[i].ekk,A[i].term);
        fprintf(fp,"Uphill %d, Downhill %d\n",A[i].ana,A[i].kata);
        fprintf(fp,"Max altitude %d, Min altitude %d\n",A[i].meg,A[i].el);
        fprintf(fp,"Length %d, Estimated time %d min\n",A[i].mikos,k);   
        fprintf(fp,"\n");    
      }
      else
      {
        k=round(A[i].mikos/65.0+A[i].ana/10.0);
        fprintf(fp,"From %s to %s\n",A[i].ekk,A[i].term);
        fprintf(fp,"Uphill %d, Downhill %d\n",A[i].ana,A[i].kata);
        fprintf(fp,"Max altitude %d, Min altitude %d\n",A[i].meg,A[i].el);
        fprintf(fp,"Length %d, Estimated time %d min\n",A[i].mikos,k);   
        fprintf(fp,"\n");     
        k=round(A[i].mikos/65.0+A[i].kata/10.0);
        fprintf(fp,"From %s to %s\n",A[i].term,A[i].ekk);
        fprintf(fp,"Uphill %d, Downhill %d\n",A[i].kata,A[i].ana);
        fprintf(fp,"Max altitude %d, Min altitude %d\n",A[i].meg,A[i].el);
        fprintf(fp,"Length %d, Estimated time %d min\n",A[i].mikos,k);   
        fprintf(fp,"\n");
      }
    }
  }
  else
    printf("Error opening file");
}