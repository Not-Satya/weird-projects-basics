// Guess the number (harmless)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Responses
{
    char Y[200];
}Res;

int main()
{
    Res tr[] = 
    {
        {"Damn!! You're good at this!!"},
        {"You're on fuckin fire! That's correct!"},
        {"Excellent guess! You're spot on!"},
        {"Spotless victory! Well done!"},
        {"Bingo! You're absolutely correct!"},
        {"Hats off to you! You got it!"},
        {"Right on the money! You're correct!"},
        {"Perfecto! You hit the bullseye!"},
        {"What are you! A fuckin guess monster?"},
        {"Bravo! You've got the gift of guessing!"}
    };

    Res fa[] = 
    {
        {"How can someone be so dumb!"},
        {"Why can't you get your shit together?"},
        {"You ILLITERATE son of a bich!!"},
        {"You piece of Shit!!"},
        {"Shut THE FUCK UP!"},
        {"You little shitfucker!"},
        {"Go fuckin die!"},
        {"Your mother should have swallowed you!"},
        {"You should've been inside when the OceanGate imploded"},
        {"Your Stupidass should've never been born!"}
    };

    Res cu[] = 
    {
        {"You DIPSHIT!"},
        {"You DUMBASS!"},
        {"Fuck you!"},
        {"End your life!"},
        {"AHH some end my life!"},
        {"Why is your brain empty?"},
        {"You DIMWIT!!"},
        {"You are the walking ad of condoms!"},
        {"You RETARD!"},
        {"Fuck all this!"}
    };

    Res mo[] = 
    {
        {"Incorrect! You're about as sharp as a butter knife in a drawer full of forks."},
        {"Wrong! Your guesses are as accurate as a blindfolded dart throw."},
        {"Nope! You're as sharp as a beach ball."},
        {"Wrong! You're as smart as a bag of hammers."},
        {"Incorrect! You're as clueless as a goldfish in a desert."},
        {"Nope! Your guesses are as insightful as a fortune cookie without a fortune."},
        {"Wrong! You're about as quick-witted as a sloth on sleeping pills."},
        {"Incorrect! You're as sharp as a marshmallow."},
        {"Nope! You're about as bright as a black hole."},
        {"Nope! Your guesses are as helpful as a parachute made of concrete."}
    };

    Res more[] = 
    {
        {"Higher!"},
        {"A bit higher"},
        {"Higher! Go higher!"},
        {"Go a bit higher"},
        {"Can't you go higher?"},
        {"Go higher you dumb!"},
        {"Higher! Higher! Higher!"},
        {"Push up higher!"},
        {"Look up higher!"},
        {"Go Higher Damn it!"}
    };

    Res less[] = 
    {
        {"Lower!"},
        {"A bit lower"},
        {"Lower! Go lower!"},
        {"Go a bit lower"},
        {"Can't you go lower?"},
        {"Go lower you dumb!"},
        {"Lower! Lower!Lower!"},
        {"Push down lower!"},
        {"Look down lower!"},
        {"Go Lower Damn it!"}
    };

    Res fin[] = 
    {
        {"Finally you did it!"},
        {"Oh God! Finally I've been spared from desparity"},
        {"Finally! Finally! You're through"},
        {"Finally your shitty brain has yielded some gold!"},
        {"Finally your brain's deseart has found an oasis!"},
        {"Well done! Even a broken clock is right twice a day, but you managed to beat its record."},
        {"Hooray! It seems your brain cells finally organized a successful protest and demanded the correct answer."},
        {"Finally! Your thought process finally broke through the traffic jam and arrived at the right conclusion."},
        {"About time! Your mental marathon finally crossed the finish line to the correct solution."},
        {"At last! Your brain cells took a break from the siesta and found the answer."},
        {"What a surprise! Your brain cells finally clocked in and did some overtime to find the answer."}
    };

    int n,a,h,i=1,t=0,n1,n2,n3,n4;

    srand(time(NULL));
    n = rand()%10+1;//Generates a random no btw 1 to 10
    h = n;

    //printf("The number is: %d %s",n, tr[n-1].Y);
    
    //printf("\nThe final number is: %d", n);

    printf("\nHello I'm Elmo:)\n");
    printf("Don't worry I won't harm you!");

    printf("\nI have a number from 1 to 10.\n");
    printf("Can you guess the number?\n");

    while (i>0)
    {
        scanf("%d", &a);
        if (h==a && t<4)
        {
        
            n1 = rand()%10+1;//Generates a random no btw 1 to 10

            printf("%s\n", tr[n1].Y);
            printf("My number was: %d\n", n);
            t++;
            break;
        }
        if (h!=a)
        {
            if (h<a)//Need to go higher
            {
                if ((a-h)<4)
                {
                    n2 = rand()%10+1;//Generates a random no btw 1 to 10

                    printf("%s %s\n", mo[n2].Y, less[n2].Y);
                    t++;
                }
                else 
                {
                    n2 = rand()%10+1;//Generates a random no btw 1 to 10
                
                    n3 = rand()%2;//Generates a random no btw 1 to 0

                    if (n3==0)
                    {
                        printf("%s %s %s\n", cu[n2].Y, fa[n].Y, less[n2].Y);
                    }
                    else if (n3==1)
                    {
                        printf("%s %s %s\n", fa[n2].Y, mo[n].Y, less[n2].Y);
                    }
                    t++;
                }
                
            }
            else if (h>a)
            {
                if ((h-a)<4)
                {
                    n2 = rand()%10+1;//Generates a random no btw 1 to 10

                    printf("%s %s\n", mo[n2].Y, more[n2].Y);
                    t++;
                }
                else 
                {
                    n2 = rand()%10+1;//Generates a random no btw 1 to 10

                    n3 = rand()%2;//Generates a random no btw 1 to 0

                    if (n3==0)
                    {
                        printf("%s %s %s\n", cu[n2].Y, fa[n].Y, more[n2].Y);
                    }
                    else if (n3==1)
                    {
                        printf("%s %s %s\n", fa[n2].Y, mo[n].Y, more[n2].Y);
                    }
                    t++;
                }
            }
            
        }
        if (h==a && t>=4)
        {
            n2 = rand()%10+1;//Generates a random no btw 1 to 10

            printf("%s\n", fin[n2].Y);
            printf("My number was: %d\n", n);
            break;
        }
    }

    if (t>1 && t<4)
    {
        printf("You took %d tries", t);
    }
     else if (t==1)
    {
        printf("1st try Haha!");
    }
    else if (t>=4)
    {
        printf("It took you %d fuckin tries??? WTF!!\n", t+1);
    }
    
    return 0;
}
