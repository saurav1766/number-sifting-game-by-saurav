#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>#include <stdio.h>
#include <conio.h>
char input();
int result(int x[4][4]);
int display(int c[4][4],int move);
int swapping(char ,int b[4][4],int mv);
void marix(int );
void matrix(int newar[][4])
{
    int i,j,temp,a[16];

        int index=0;

  srand(time(NULL));
    for(i=0;i<16;i++)
    {
    float r = (float)rand() / (float)RAND_MAX;
    temp= 1+r * (16-1);
      for(j=0;j<=i;j++)
      {
          if(temp==a[j])
            break;
      }
      if(i==j-1)
        a[i]=temp;
      else
        i--;

    }
    for(i=0;i<16;i++)
        printf("%d ",a[i]);

printf("\n");
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                    if(a[index]==16){
                        newar[i][j]=' ';
                    }
                    else{
                newar[i][j]=a[index];
                    }
                index++;
            }
        }
         for(i=0;i<4;i++)
       {
         for(j=0;j<4;j++)
          {
           if(newar[i][j]==32)
            printf("| %c ",newar[i][j]);
           else
           { printf("| %d",newar[i][j]);
               if(newar[i][j]<=9){
           printf(" ");
               }

           }
       }
       printf("\n");
    }
}

int main()
{
  int i,j,r,temp,a[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,' '};
  int mv=11;
  int c[4][4];
  char marrow,k,ch;
  while(1)
  {
      system("cls");
  system("COLOR 0a");
  printf("                              ***RULE OF THIS GAME***\n\n");
  printf("1. you can move only one move at a time.\n ");
  printf("        move up   : by pressing 'w'\n");
  printf("         move left : by pressing 'a'\n");
  printf("         move right: by pressing 's'\n");
  printf("         move down : by pressing 'z'\n");
  printf("2. you can move number at empty position only.\n\n");
  printf("3. for each valid move : your total number of move will decreased by 1.\n");
  printf("4. winning situation : number in 4*4 matrix should be in order from  1 to 15.\n\n");
  printf("                        WINNING SITUATION\n");



for(i=0;i<4;i++)
    {
      for(j=0;j<4;j++)
       {
           if(a[i][j]==32)
            printf("| %c ",a[i][j]);
           else
           { printf("| %d",a[i][j]);
               if(a[i][j]<=9){
           printf(" ");
               }

           }
       }
       printf("\n");
    }
    printf("5. you can exit the game at any time by pressing  'e'.\n");
    printf("press any key to start...");
    getch();
    matrix(c);
    system("cls");
    for(i=0;i<4;i++)
    {
      for(j=0;j<4;j++)
       {
           if(c[i][j]==32)
            printf("| %c ",c[i][j]);
           else
           { printf("| %d",c[i][j]);
               if(c[i][j]<=9){
           printf(" ");
               }

           }
       }
       printf("\n");
    }


    for(i=0;i<=10;i++)
    {
     marrow=input();
     r=swapping(marrow,c,mv-i);
     if(r==1||r==2)
        break ;
    }
    if(r==0)
        printf("                         YOU LOSE\n\n\n");
        printf(" DO YOOU WANT TO PLAY AGAIN THEN PRESS 'y' FOR YES AND 'n' FOR NO");
        ch=getch();
        if(ch!='y')
            break;


  }
}


char input()
{
    char ch;
    ch=getch();

}
int swapping(char arw,int b[4][4],int m)
{
    int i,j,l,c,temp;

  if(arw=='a')
  {
       temp=0;
    for(i=0;i<4;i++)
    {
      for(j=0;j<4;j++)
       {
         if(b[i][j]==' ')
          {

            temp=b[i][j];
            b[i][j]=b[i][j-1];
            b[i][j-1]=temp;
          }
       }
     }
     l=display(b,m-1);
     return l;
  }
  else if(arw=='w')
  {
       temp=0;
    for(i=0;i<4;i++)
    {
      for(j=0;j<4;j++)
       {
         if(b[i][j]==' ')
          {

            temp=b[i][j];
            b[i][j]=b[i-1][j];
            b[i-1][j]=temp;
          }
       }
     }
    l=display(b,m-1);
     return l;
  }
  else if(arw=='s')
  {
       temp=0;
    for(i=0;i<4;i++)
    {
      for(j=0;j<4;j++)
       {
         if(b[i][j]==' ')
          {

            temp=b[i][j];
            b[i][j]=b[i][j+1];
            b[i][j+1]=temp;
            break;
          }
       }
     }
     l=display(b,m-1);
     return l;
  }
  else if(arw=='z')
  {
      temp=0;
    for(i=0;i<4;i++)
    {
      for(j=0;j<4;j++)
       {
         if(b[i][j]==' ')
          {

            temp=b[i][j];
            b[i][j]=b[i+1][j];
            b[i+1][j]=temp;
            c=1;
            break;
          }
      }
      if(c==1)
        break;
    }
    c=0;
     l=display(b,m-1);
     return l;
  }
  else if(arw=='e')
    return 2;
}
int display(int c[4][4],int move)
{
    int i,j,k;
    int a[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,' '};
    system("cls");
    printf("\n");
    for(i=0;i<4;i++)
    {
      for(j=0;j<4;j++)
       {
           if(c[i][j]==32)
            printf("| %c ",c[i][j]);
           else
           { printf("| %d",c[i][j]);
               if(c[i][j]<=9)
                {
                  printf(" ");
                }
            }
       }
       printf("\n");
    }
    printf(" REMAINING MOVES  : %d",move--);
    printf("\n\n");
   k=result(c);
   return k;
}
int result(int x[4][4])
{
    int a[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,' '};
    int i,j,rs,r=0;
    for(i=0;i<4;i++)
    {
      for(j=0;j<4;j++)
       {
           if(a[i][j]==x[i][j])
               r=r+1;
           else
           {
             rs=0;
             break;
           }
       }
       if(rs==0)
        break;
    }
    if(r==16)
        {
            printf("     \n\n\n                 YOU WON\n\n\n");
            return 1;
        }
        else
            return 0;
            printf(" DO YOOU WANT TO PLAY AGAIN THEN PRESS 'y' FOR YES AND 'n' FOR NO");
}
