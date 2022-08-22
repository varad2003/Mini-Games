#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

// void snake_table(int count[],int pos[],int pos1[])
// {
//        printf("\n******** Snake and Ladder ***********************************");
//     printf("\n\n___Lets Have Fun ___");
//     printf("\n\n");
//      printf("\n __Player %d is at___ %d\n\n",1,count[0]);
//      printf("\n __Player %d is at___ %d\n\n",2,count[1]);
//     printf("\n\n");
    
    
//     printf("________._______._______._______.______\n");  
//     printf("|30  %c%c |29  %c%c |28   %c%c|27S  %c%c|26  %c%c|\n",pos[29],pos1[29],pos[28],pos1[28],pos[27],pos1[27],pos[26],pos1[26],pos[25],pos1[25]);
//     printf("|_______|_______|_______|_______|______|                   Press 0 to Exit\n");
//     printf("|21   %c%c|22  %c%c |23  %c%c |24  %c%c |25 %c%c |\n",pos[20],pos1[20],pos[21],pos1[21],pos[22],pos1[22],pos[23],pos1[23],pos[24],pos1[24]);
//     printf("|_______|_______|_______|_______|______|                   Snakes:17==>4 19==>7 21==>9 27==>1\n");
//     printf("|20   %c%c|19   %c%c|18   %c%c|17S  %c%c|16  %c%c|\n",pos[19],pos1[19],pos[18],pos1[19],pos[17],pos1[17],pos[16],pos1[16],pos[15],pos1[15]);
//     printf("|_______|_______|_______|_______|______|                   Ladder:3==>22 5==>8 11==>26 20==>29\n");
//     printf("|11L  %c%c|12  %c%c |13  %c%c |14  %c%c |15 %c%c |\n",pos[10],pos1[10],pos[11],pos1[11],pos[12],pos1[12],pos[13],pos1[13],pos[14],pos1[14]);
//     printf("|_______|_______|_______|_______|______|\n");
//     printf("|10  %c%c |9   %c%c |8   %c%c |7   %c%c |6  %c%c |\n",pos[9],pos1[9],pos[8],pos1[8],pos[7],pos1[7],pos[6],pos1[6],pos[5],pos1[5]);
//     printf("|_______|_______|_______|_______|______|\n");
//     printf("|1  %c%c  |2   %c%c |3L  %c%c |4   %c%c |5L %c%c |\n",pos[0],pos1[0],pos[1],pos1[1],pos[2],pos1[2],pos[3],pos1[3],pos[4],pos1[4]);
//     printf("|_______|_______|_______|_______|______|\n");
// }

int tic_tac()
{
    int i=0;
    int ret[9]={0,0,0,0,0,0,0,0,0};
    int count=0;
    char c[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
    int adr;
    char p[2]={'O','X'};
   
    while (i<2)
    {
        printf("\n\n\t\t________________ Tic Tac Toe ______________________\n\n\n");
         printf("\n\t\t\t O - player 1    X- player 2\n\n");
        printf("\n\t\t\tPlayer %d turn\n\n\n",i+1);
      
       printf("\t\t\t   |1  %c   |2  %c   |3  %c   |\n",c[0],c[1],c[2]);
       printf("\t\t\t___|_______|_______|_______|___\n");
       printf("\t\t\t   |4  %c   |5  %c   |6  %c   |\n",c[3],c[4],c[5]);
       printf("\t\t\t___|_______|_______|_______|___\n");
       printf("\t\t\t   |7  %c   |8  %c   |9  %c   |\n",c[6],c[7],c[8]);
       printf("\t\t\t   |       |       |       |   \n");

           if((c[0]==c[1] && c[0]==c[2] && c[0]!=' ') || (c[3]==c[4] && c[3]==c[5] && c[3]!=' ') || (c[6]==c[7] && c[6]==c[8] && c[6]!=' '))
       {
           printf("\n\t\t\t___ Player %d won ___\n",(i+1)%2+1);
           printf("\n\t\t\t*** Game over ***\n\n");
           return 0;
       }
        else if((c[0]==c[4] && c[0]==c[8] && c[0]!=' ') || (c[2]==c[4] && c[2]==c[6] && c[2]!=' '))
       {
           printf("\n\t\t\t___ Player %d won ___\n",(i+1)%2+1);
           printf("\n\t\t\t*** Game over ***\n\n");
           return 0;
       }
        else if((c[0]==c[3] && c[0]==c[6] && c[0]!=' ') || (c[1]==c[4] && c[1]==c[7] && c[1]!=' ') || (c[2]==c[5] && c[2]==c[8] && c[2]!=' '))
       {
           printf("\n\t\t\t___ Player %d won ___\n",(i+1)%2+1);
           printf("\n\t\t\t*** Game over ***\n\n");
           return 0;
       }

        if(count==9)
       {
           printf("\n\t\t\t**** Draw ****");
           printf("\n\t\t\tGame Over\n\n");
           break;
       }
        jump:
       printf("\n\n\t\t\tEnter adress :");
       scanf("%d",&adr);
       if(adr<1 || adr>9)
       {
           printf("\n\t\t\tEnter proper adress\n");
           goto jump;
       }
               if(ret[adr-1]!=0)
               {
                   printf("\n\t\t\tAlready filled\n");
                   goto jump;
               }
               c[adr-1]=p[i];
               count++;
               ret[adr-1]+=1;
         
 
       i=(i+1)%2;
       system("cls");
     
    }  
    return 0;
}


int dice()
{
    srand(time(0));
    int d=(rand() % 6) + 1;
    return d;
}

int score(int n,int dice){
   int s1=17,s2=19,s3=21,s4=27;  //Snakes Position
   int l1=3,l2=5,l3=11,l4=20;   //Ladder position
   n+=dice;
   if(n>30){
       return n-dice;
   }
   if(n==17 || n==19 || n==21 || n==27)
   {
       printf("\n\nOpps its Snake\n\n");
   }
   if(n==3 || n==5 || n==11 || n==20)
   {
       printf("\n\nCongrats its Ladder\n\n");
   }
   switch (n)
   {
       case 3:
       n=22;
       break;
       
       case 5:
       n=8;
       break;
       
       case 11:
       n=26;
       break;
       
       case 17:
       n=4;
       break;
       
       case 19:
       n=7;
       break;
       
       case 20:
       n=29;
       break;
       
       case 21:
       n=9;
       break;
       
       case 27:
       n=1;
       break;
       
   }
   return n;
}

int snake_ladder()
{
int d=6;             // Dice counter
    int i=0;
    int m;               // Any key to continue program
   // int co=0;
    int count[2]={0,0};  // Player position
    int arr[6][5]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
    char pos[30]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char p[]={'O','X'};  // Player 1- O  Player 2- X
    int temp[]={0,0};
    char pos1[30]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
     
    xyz:


    printf("\n******** Snake and Ladder ***********************************");
    printf("\n\n___Lets Have Fun ___");
    printf("\n\n");
     printf("\n __Player %d is at___ %d\n\n",1,count[0]);
     printf("\n __Player %d is at___ %d\n\n",2,count[1]);
    printf("\n\n");
    
    
    printf("________._______._______._______.______\n");  
    printf("|30  %c%C |29  %c%c |28   %c%c|27S  %c%c|26  %c%c|\n",pos[29],pos1[29],pos[28],pos1[28],pos[27],pos1[27],pos[26],pos1[26],pos[25],pos1[25]);
    printf("|_______|_______|_______|_______|______|                   Press 0 to Exit\n");
    printf("|21   %c%c|22  %c%c |23  %c%c |24  %c%c |25 %c%c |\n",pos[20],pos1[20],pos[21],pos1[21],pos[22],pos1[22],pos[23],pos1[23],pos[24],pos1[24]);
    printf("|_______|_______|_______|_______|______|                   Snakes:17==>4 19==>7 21==>9 27==>1\n");
    printf("|20   %c%c|19   %c%c|18   %c%c|17S  %c%c|16  %c%c|\n",pos[19],pos1[19],pos[18],pos1[19],pos[17],pos1[17],pos[16],pos1[16],pos[15],pos1[15]);
    printf("|_______|_______|_______|_______|______|                   Ladder:3==>22 5==>8 11==>26 20==>29\n");
    printf("|11L  %c%c|12  %c%c |13  %c%c |14  %c%c |15 %c%c |\n",pos[10],pos1[10],pos[11],pos1[11],pos[12],pos1[12],pos[13],pos1[13],pos[14],pos1[14]);
    printf("|_______|_______|_______|_______|______|\n");
    printf("|10  %c%c |9   %c%c |8   %c%c |7   %c%c |6  %c%c |\n",pos[9],pos1[9],pos[8],pos1[8],pos[7],pos1[7],pos[6],pos1[6],pos[5],pos1[5]);
    printf("|_______|_______|_______|_______|______|\n");
    printf("|1  %c%c  |2   %c%c |3L  %c%c |4   %c%c |5L %c%c |\n",pos[0],pos1[0],pos[1],pos1[1],pos[2],pos1[2],pos[3],pos1[3],pos[4],pos1[4]);
    printf("|_______|_______|_______|_______|______|\n");
    
    
    while(count[i%2]<30)
    {    
        printf("\nEnter any number except 0 for rollig dice :");

        jump:

        scanf("%d",&m);
        if(m==0){printf("\n\n____Game Over____"); return 0;}
        if(m!=0){
            
     
       d=dice();
       printf("\n%d",d);
       count[i%2]=score(count[i%2],d);
    
       if(count[i%2]==30)
       {
           system("cls");
           if(i%2==0)
           {
               pos[temp[0]]=' ';
               pos[29]=p[0];
           }
           else
           {
               pos1[temp[1]]=' ';
               pos1[29]=p[1];
           }

    printf("\n******** Snake and Ladder ***********************************");
    printf("\n\n___Lets Have Fun ___");
    printf("\n\n");
     printf("\n __Player %d is at___ %d\n\n",1,count[0]);
     printf("\n __Player %d is at___ %d\n\n",2,count[1]);
    printf("\n\n");
    
    
    printf("________._______._______._______.______\n");  
    printf("|30  %c%C |29  %c%c |28   %c%c|27S  %c%c|26  %c%c|\n",pos[29],pos1[29],pos[28],pos1[28],pos[27],pos1[27],pos[26],pos1[26],pos[25],pos1[25]);
    printf("|_______|_______|_______|_______|______|                   Press 0 to Exit\n");
    printf("|21   %c%c|22  %c%c |23  %c%c |24  %c%c |25 %c%c |\n",pos[20],pos1[20],pos[21],pos1[21],pos[22],pos1[22],pos[23],pos1[23],pos[24],pos1[24]);
    printf("|_______|_______|_______|_______|______|                   Snakes:17==>4 19==>7 21==>9 27==>1\n");
    printf("|20   %c%c|19   %c%c|18   %c%c|17S  %c%c|16  %c%c|\n",pos[19],pos1[19],pos[18],pos1[19],pos[17],pos1[17],pos[16],pos1[16],pos[15],pos1[15]);
    printf("|_______|_______|_______|_______|______|                   Ladder:3==>22 5==>8 11==>26 20==>29\n");
    printf("|11L  %c%c|12  %c%c |13  %c%c |14  %c%c |15 %c%c |\n",pos[10],pos1[10],pos[11],pos1[11],pos[12],pos1[12],pos[13],pos1[13],pos[14],pos1[14]);
    printf("|_______|_______|_______|_______|______|\n");
    printf("|10  %c%c |9   %c%c |8   %c%c |7   %c%c |6  %c%c |\n",pos[9],pos1[9],pos[8],pos1[8],pos[7],pos1[7],pos[6],pos1[6],pos[5],pos1[5]);
    printf("|_______|_______|_______|_______|______|\n");
    printf("|1  %c%c  |2   %c%c |3L  %c%c |4   %c%c |5L %c%c |\n",pos[0],pos1[0],pos[1],pos1[1],pos[2],pos1[2],pos[3],pos1[3],pos[4],pos1[4]);
    printf("|_______|_______|_______|_______|______|\n");

    // printf("\n\t\t __Player %d is at___ %d\n\n",1,count[0]);
    // printf("\n\t\t __Player %d is at___ %d\n\n",2,count[1]);
    // printf("\n\n");

    //     printf("\t\t________._______._______._______.______\n");  
    // printf("\t\t\t\t|30  %c%C |29  %c%c |28   %c%c|27S  %c%c|26  %c%c|\n",pos[29],pos1[29],pos[28],pos1[28],pos[27],pos1[27],pos[26],pos1[26],pos[25],pos1[25]);
    // printf("\t\t\t\t|_______|_______|_______|_______|______|                   Press 0 to Exit\n");
    // printf("\t\t\t\t|21   %c%c|22  %c%c |23  %c%c |24  %c%c |25 %c%c |\n",pos[20],pos1[20],pos[21],pos1[21],pos[22],pos1[22],pos[23],pos1[23],pos[24],pos1[24]);
    // printf("\t\t\t\t|_______|_______|_______|_______|______|                   Snakes:17==>4 19==>7 21==>9 27==>1\n");
    // printf("\t\t\t\t|20   %c%c|19   %c%c|18   %c%c|17S  %c%c|16  %c%c|\n",pos[19],pos1[19],pos[18],pos1[19],pos[17],pos1[17],pos[16],pos1[16],pos[15],pos1[15]);
    // printf("\t\t\t\t|_______|_______|_______|_______|______|                   Ladder:3==>22 5==>8 11==>26 20==>29\n");
    // printf("\t\t\t\t|11L  %c%c|12  %c%c |13  %c%c |14  %c%c |15 %c%c |\n",pos[10],pos1[10],pos[11],pos1[11],pos[12],pos1[12],pos[13],pos1[13],pos[14],pos1[14]);
    // printf("\t\t\t\t|_______|_______|_______|_______|______|\n");
    // printf("\t\t\t\t|10  %c%c |9   %c%c |8   %c%c |7   %c%c |6  %c%c |\n",pos[9],pos1[9],pos[8],pos1[8],pos[7],pos1[7],pos[6],pos1[6],pos[5],pos1[5]);
    // printf("\t\t\t\t|_______|_______|_______|_______|______|\n");
    // printf("\t\t\t\t|1  %c%c  |2   %c%c |3L  %c%c |4   %c%c |5L %c%c |\n",pos[0],pos1[0],pos[1],pos1[1],pos[2],pos1[2],pos[3],pos1[3],pos[4],pos1[4]);
    // printf("\t\t\t\t|_______|_______|_______|_______|______|\n");
       
          printf("\n\n\n!!_____ Player %d won_____\n\n\n!! _____Game Over_____ !!",i%2+1);
          break;
       }
       else
       {
          printf("\n __Player %d is at___ %d\n\n",i%2+1,count[i%2]);
          if(i%2==0 && pos[count[i%2]-1]!='O')
          {
              pos[temp[0]]=' ';
              pos[count[i%2]-1]=p[0];
              temp[0]=count[i%2]-1;
          }
          else if(i%2==1 && pos1[count[i%2]-1]!='X')
          {
               pos1[temp[1]]=' ';
              pos1[count[i%2]-1]=p[1];
              temp[1]=count[i%2]-1;
          }

       }
     
        }
        if(d==6)
        {
            printf("\n___Extra chance__\n");
            goto jump;   // Line 114 
        }
      i++;
    //  co=co+1;
      printf("Press any key for next turn ");
      getch();
    system("cls");
      goto xyz;    // Line 84
    }

    return 0;
}

int main()
{
    system("cls");
    int opt;
    abc:
    printf("\n\nWhich game do you want to play ?\n");
    printf("\n1. Snake And Ladder");
    printf("\n2. Tic Tac Toe\n");
    printf("3. Exit\n");
    xyz:
    printf("\nEnter option :");
    scanf("%d",&opt);
    if(opt==1)
    {
        system("cls");
        snake_ladder();
    }
    else if(opt==2){
        system("cls");
        tic_tac();
    }
    else if(opt==3)
    {
        printf("\nSuccesfully Exited\n\n");
        return 0;

    }
    else{
        printf("\nEnter proper option\n");
        goto xyz;
    }
    printf("\nEnter any key to back :");
    getch();
    system("cls");
    goto abc;
    return 0;
}
