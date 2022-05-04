#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>

void fill_map_with_zeros(char *map, int height, int width)
{
    int i, j;
    for (i = 0; i < height; i++)
        for (j = 0; j < width; j++)
            *((map + i * width) + j) = 176;
}

void print_map(char *map, int height, int width)
{
    system("cls");
    char width_char = 'A';

    printf("  ");

    for(int i = 0; i < 10; i++) // 0 - 9
   {
        printf("%d ", i );
    }

    printf("\n");

    int i, j;
    for (i = 0; i < height; i++)
    {
        printf("%c ", width_char); // A - J
        width_char++;

        for (j = 0; j < width; j++)
            printf("%c ", *((map + i * width) + j));
        printf("\n");
    }
}

// bad shot -> ASCII = 176
// good shot -> ASCII = 178
// no shot -> '0'

void create_ship (int user_index, char *map, int map_height, int map_width, int ship_length, int ship_count)
{

    for(int k=0; k<ship_count; k++)
    {
        printf("USER %d \n", user_index);
        bool correct = true;
        bool repeat = true;

        while(repeat || !correct)
        {
            char input[2];
            printf("enter the place of start of the ship \n");
            scanf("%s",input);

            int height = 0;
            int width = 0;

            if(toupper(input[0]) >= 'A' && toupper(input[0]) <= 'J' )
            {
                if(input[1] >= '0' && input[1] <= '9' )
                {
                    correct = true;
                }
                else
                {
                    correct = false;
                }
            }
            else
            {
                correct = false;
            }

            if(correct)
            {
                switch(toupper(input[0]))
                {
                case 'A':
                    height=0;
                    break;
                case 'B':
                    height=1;
                    break;
                case 'C':
                    height=2;
                    break;
                case 'D':
                    height=3;
                    break;
                case 'E':
                    height=4;
                    break;
                case 'F':
                    height=5;
                    break;
                case 'G':
                    height=6;
                    break;
                case 'H':
                    height=7;
                    break;
                case 'I':
                    height=8;
                    break;
                case 'J':
                    height=9;
                    break;

                }

                switch(input[1])
                {
                case '0':
                    width=0;
                    break;
                case '1':
                    width=1;
                    break;
                case '2':
                    width=2;
                    break;
                case '3':
                    width=3;
                    break;
                case '4':
                    width=4;
                    break;
                case '5':
                    width=5;
                    break;
                case '6':
                    width=6;
                    break;
                case '7':
                    width=7;
                    break;
                case '8':
                    width=8;
                    break;
                case '9':
                    width=9;
                    break;


                }

                ////printf("\n %d \n", *((map + height * map_width) + width));
               ///// Sleep(1500);
                if( *((map + height * map_width) + width) == -2)
                {
                    repeat = true;
                }
                else // place is empty
                {
                    repeat = false;

                    //////
                    bool incorrect_char=true;
                    while(incorrect_char)
                    {
                        fflush(stdin);
                        char inputchar;
                        printf("Put direction of your ship with %d length\n Put: W/S/A/D \n",ship_length);
                        scanf("%c",&inputchar);

                        if(inputchar=='w' || inputchar=='W'||inputchar=='s' || inputchar=='S'||inputchar=='a' || inputchar=='A'||inputchar=='d' || inputchar=='D')
                        {
                            if(toupper(inputchar)=='W')
                            {

                                for(int i= 0 ; i<ship_length; i++)
                                {
                                   if( *((map + (height-i) * map_width) + width) == -2)
                                   {
                                       repeat=true;
                                        incorrect_char=false;
                                   }
                                   else
                                   {
                                       repeat=false;
                                   }
                                }

                            }
                            if(toupper(inputchar)=='S')
                            {

                                for(int i= 0 ; i<ship_length; i++)
                                {
                                    ////*((map + (height+i) * map_width) + width) = -2;
                                     if( *((map + (height+i) * map_width) + width) == -2)
                                   {
                                       repeat=true;
                                       incorrect_char=false;
                                   }
                                   else
                                   {
                                       repeat=false;
                                   }
                                }

                            }
                            if(toupper(inputchar)=='A')
                            {

                                for(int i= 0 ; i<ship_length; i++)
                                {
                                    ////*((map + height * map_width) + (width-i)) = -2;
                                     if( *((map + height * map_width) + (width-i)) == -2)
                                   {
                                       repeat=true;
                                        incorrect_char=false;
                                   }
                                   else
                                   {
                                       repeat=false;
                                   }
                                }

                            }
                            if(toupper(inputchar)=='D')
                            {

                                for(int i= 0 ; i<ship_length; i++)
                                {
                                    /////*((map + height * map_width) + (width+i)) = -2;
                                     if( *((map + height * map_width) + (width+i)) == -2)
                                   {
                                       repeat=true;
                                        incorrect_char=false;
                                   }
                                   else
                                   {
                                       repeat=false;
                                   }
                                }

                            }
                            if(repeat == false)
                            {
                            incorrect_char=false;
                            if(toupper(inputchar)=='W')
                            {

                                for(int i= 0 ; i<ship_length; i++)
                                {
                                    *((map + (height-i) * map_width) + width) = -2;
                                }

                            }
                            if(toupper(inputchar)=='S')
                            {

                                for(int i= 0 ; i<ship_length; i++)
                                {
                                    *((map + (height+i) * map_width) + width) = -2;
                                }

                            }
                            if(toupper(inputchar)=='A')
                            {

                                for(int i= 0 ; i<ship_length; i++)
                                {
                                    *((map + height * map_width) + (width-i)) = -2;
                                }

                            }
                            if(toupper(inputchar)=='D')
                            {

                                for(int i= 0 ; i<ship_length; i++)
                                {
                                    *((map + height * map_width) + (width+i)) = -2;
                                }

                            }
                            else
                            {
                                printf("Put direction of your ship : W/S/A/D");

                            }
                            }
                            else{
                                printf("Area is busy, try again\n");
                            }

                        }
                    }

                }

                print_map(map, map_height, map_width);

                if(repeat)
                {
                    printf(" \n THIS PLACE IS BUSY. TRY AGAIN \n");
                }
            }
            else
            {
                print_map(map, map_height, map_width);
                printf(" \n INCORRECT INPUT. TRY AGAIN \n");
            }

        }

    }






}



bool shoot(int user_index,char *map,int map_height, int map_width, char *map_shots)
{

        system("cls");
        printf("USER %d \n", user_index);
        bool correct = true;
        bool repeat = true;

        while(repeat || !correct)
        {
            char input[2];

            print_map(map_shots, map_height, map_width);

    printf("USER %d \n", user_index);
            printf("Put place of the shot \n");
            scanf("%s",input);

            int height = 0;
            int width = 0;

            if(toupper(input[0]) >= 'A' && toupper(input[0]) <= 'J' )
            {
                if(input[1] >= '0' && input[1] <= '9' )
                {
                    correct = true;
                }
                else
                {
                    correct = false;
                }
            }
            else
            {
                correct = false;
            }

            if(correct)
            {
                switch(toupper(input[0]))
                {
                case 'A':
                    height=0;
                    break;
                case 'B':
                    height=1;
                    break;
                case 'C':
                    height=2;
                    break;
                case 'D':
                    height=3;
                    break;
                case 'E':
                    height=4;
                    break;
                case 'F':
                    height=5;
                    break;
                case 'G':
                    height=6;
                    break;
                case 'H':
                    height=7;
                    break;
                case 'I':
                    height=8;
                    break;
                case 'J':
                    height=9;
                    break;

                }

                switch(input[1])
                {
                case '0':
                    width=0;
                    break;
                case '1':
                    width=1;
                    break;
                case '2':
                    width=2;
                    break;
                case '3':
                    width=3;
                    break;
                case '4':
                    width=4;
                    break;
                case '5':
                    width=5;
                    break;
                case '6':
                    width=6;
                    break;
                case '7':
                    width=7;
                    break;
                case '8':
                    width=8;
                    break;
                case '9':
                    width=9;
                    break;


                }

                if(correct)
                {


    if( *((map + height * map_width) + width) == -2)
    {
        printf("HIT");
        *((map_shots + height * map_width) + width) = 'X';
        return true;
    }
    else
    {

    printf("MISS");
    *((map_shots + height * map_width) + width) = '0';

    return false ;
    }
                }
            }
        }
}

void game(char *map_user1, char *map_user2, int height, int width,char *map_shots1, char *map_shots2)
{
    int  user1_score = 0;
    int  user2_score = 0;
    const int SCORE_TO_WIN = 6;

    // 5 points = WIN
    do
    {

        printf("\nUSER (1)  score: %d",user1_score);
        printf("\nUSER (2) score: %d",user2_score);
          Sleep(1500);
        while(shoot(1, map_user2, height, width, map_shots1)) // user1 shoots user2
        {
            user1_score++;
        printf("\nUSER (1)  score: %d",user1_score);
        printf("\nUSER (2) score: %d",user2_score);
            Sleep(1500);
            if(user1_score == SCORE_TO_WIN)
        {
            printf("\nPLAYER 1 WON");
             Sleep(1500);
            exit(0);
        }
        }

        while(shoot(2, map_user1, height, width, map_shots2)) // user2 shoots user1
        {

           user2_score++;

           printf("\nUSER (1)  score: %d",user1_score);
          printf("\nUSER (2) score: %d",user2_score);
            Sleep(1500);
            if(user2_score == SCORE_TO_WIN)
        {
            printf("\nPLAYER 2 WON");
             Sleep(1500);
            exit(0);
        }
        }
    }while(user2_score!=SCORE_TO_WIN);



}


int main()
{
    const int WIDTH = 10;
    const int HEIGHT = 10;

    char user1_map[HEIGHT][WIDTH];
    char user2_map[HEIGHT][WIDTH];

    char user1_shots[HEIGHT][WIDTH];
    char user2_shots[HEIGHT][WIDTH];

    fill_map_with_zeros(user1_map, HEIGHT, WIDTH);
    fill_map_with_zeros(user2_map, HEIGHT, WIDTH);
    fill_map_with_zeros(user1_shots, HEIGHT, WIDTH);
    fill_map_with_zeros(user2_shots, HEIGHT, WIDTH);

// USER 1
    print_map(user1_map, HEIGHT, WIDTH);
    //create_ship(1,user1_map,HEIGHT,WIDTH,1,4);
    //create_ship(1,user1_map,HEIGHT,WIDTH,2,3);
    create_ship(1,user1_map,HEIGHT,WIDTH,3,2);
    //create_ship(1,user1_map,HEIGHT,WIDTH,4,1);
//USER 2
    print_map(user2_map, HEIGHT, WIDTH);
    //create_ship(2,user2_map,HEIGHT,WIDTH,1,4);
    //create_ship(2,user2_map,HEIGHT,WIDTH,2,3);
    create_ship(2,user2_map,HEIGHT,WIDTH,3,2);
    //create_ship(2,user2_map,HEIGHT,WIDTH,4,1);

    game(user1_map,user2_map,HEIGHT,WIDTH, user1_shots, user2_shots);

    return 0;
}
