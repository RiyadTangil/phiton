#include <stdio.h>

int main()
{
    //test c

   /**  xGiven = xGiven + .5 ;

  if ( sLeave > tReturn){
      tReturn = tReturn + 24 ;

      xGiven >= sLeave   &&  xGiven < tReturn ? printf( "Yes" ) : printf( "No" );
    }

    else {
       xGiven >= sLeave  &&  xGiven < tReturn ? printf( "Yes" ) : printf( "No" );
    }

     float sLeave , tReturn, xGiven ,i, result;
  scanf( "%f %f %f", &sLeave, &tReturn,&xGiven );



  for(i=sLeave;i<=tReturn;i++){
    printf("%f",i);
     if(i==xGiven){
            result=1;

     }

  }
    if( result==1){
          printf("Yes");
     }

     else{
            printf("No");
     }**/
  // test -D
//   int num, i, number_of_D = 0, number_of_A = 0;
//      char ch;
//   scanf("%d\n", & num);
//      char name[num];
//   scanf("%s", name);

// size_t length = strlen(name);
//   for (i = 0; i < length; i++) {

//     if (name[i] == 65) {
//       number_of_A++;
//     }
//     else if (name[i] == 68) {
//       number_of_D++;
//     }
//   }
//   if (number_of_A > number_of_D) {
//     printf("Anton");
//   }
//   else if (number_of_A < number_of_D) {
//     printf("Danik");
//   }
//   else if (number_of_A == number_of_D) {
//     printf("Friendship");
//   }

    // test -E
  // int sec1, meater1, rest1, sec2, meater2, rest2, duration, duration1 = 0, duration2 = 0, tak_meater = 0, aoki_meater = 0;
  // scanf("%d %d %d %d %d %d %d", & sec1, & meater1,& rest1,& sec2, & meater2,& rest2,& duration);

  // while (duration1 <= duration) {
  //   const my_meaters = duration1 + sec1;
  //   if (my_meaters > duration) {
  //     const rest_meaters = duration - duration1;
  //     tak_meater = tak_meater + (rest_meaters * meater1);
  //   }

  //   else { tak_meater = tak_meater + (sec1 * meater1); }
  //   duration1 = duration1 + sec1 + rest1;
  // }
  // while (duration2 <= duration) {
  //   const my_meaters = duration2 + sec2;
  //   if (my_meaters > duration) {
  //     const rest_meaters = duration - duration2;
  //     aoki_meater = aoki_meater + (rest_meaters * meater2);
  //   }

  //   else { aoki_meater = aoki_meater + (sec2 * meater2); }
  //   duration2 = duration2 + sec2 + rest2;
  // }
  // if (tak_meater > aoki_meater) {
  //   printf("Takahashi");
  // }
  // else if (tak_meater < aoki_meater) {
  //   printf("Aoki");
  // }
  // else if (tak_meater == aoki_meater) {
  //   printf("Draw");
  // }


    //problem -f
   int num1, num2, i, j, p = 1;
    scanf("%d %d", &num1, &num2);
    for (i = 1; i <= num1; i++)
    {
        for (j = 1; j <= num2; j++)
        {
            if (i % 2 != 0)
            {
                printf("#");
                if (p == 1&&j== 1)
                {
                    p = 0;
                }
                else if (p == 0&&j== 1)
                {
                    p = 1;
                }
            }
            else
            {
                if (p == 0 && j != num2)
                {
                    printf(".");
                }
                else if (p == 0 && j == num2)
                {
                    printf("#");
                }
                else if (p == 1 && j == 1)
                {
                    printf("#");
                }
                else if (p == 1 && j != 1)
                {
                    printf(".");
                }
            }
        }

        printf("\n");
    }


    //G

    //     int  num1,num2,result;
    // scanf("%d %d",&num1,&num2);
    // result = num2-num1;
    // if(result>0){
    //     printf("%d",result+1);
    // }
    // else{
    //     printf("%d",0);
    // }

    //test h
    //   int num1,i;
    // scanf("%d",&num1);
    // for(i=1;i<=num1;i++){

    //      if(i%2!=0 &&num1!=i ){
    //     printf("I hate that ");

    //         }
    //            else if(i%2!=0 &&num1==i ){
    //     printf("I hate it");

    //         }
    //           else if(i%2==0 &&num1!=i ){
    //     printf("I love that ");

    //         }
    //            else if(i%2==0 &&num1==i ){
    //     printf("I love it");

    //         }
    // }

    //test I
    //       int num1;
//     scanf("%d",&num1);
//    if(num1>=0&& num1<40){
//     printf("%d",40-num1);
//    }
//      else if(num1>=40&& num1<70){
//     printf("%d",70-num1);
//    }
//     else if(num1>=70&& num1<90){
//      printf("%d",90-num1);
//    }
//      else if(num1>=90){
//     printf("expert");
//    }


    //test j


    // int num1, num2, num3, givern_number;
    // scanf("%d", &givern_number);
    // num1 = givern_number;
    // num2 = (givern_number % 100);
    // num3 = givern_number % 10;
    // while (num2 >= 10)
    // {
    //     num2 = num2 / 10;
    // }
    // while (num1 >= 10)
    // {
    //     num1 = num1 / 10;
    // }

    // const totle1 = num1 * 100 + num2 * 10 + num3;
    // const totle2 = num2 * 100 + num3 * 10 + num1;
    // const totle3 = num3 * 100 + num1 * 10 + num2;

    // printf("%d", totle1 + totle2 + totle3);

    // problem - 2
  /** int n,room1,room2;
      int empty_room=0;
      int j;
       scanf("%d",&n);
       for (j = 1; j <= n; j++) {
          scanf("%d %d",&room1,&room2);
          if(room1+2<=room2){
              empty_room++;
          }

        }
        printf("%d",empty_room);**/

    // no-1


  // int person, gift, givern, totla, totla_given;
  // int i, j = 1;
  // scanf("%d %d %d", & person, & gift, & givern);
  // totla_given = givern - 1;
  // for (i = 1; i <= gift; i++) {
  //   if (totla_given >= person) {
  //     totla_given = 0;
  //   }

  //   totla_given++;
  // }
  // printf("%d", totla_given);




    return 0;
}
