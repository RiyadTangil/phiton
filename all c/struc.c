#include <stdio.h>
// done
struct Student
{
  char name[100];
  int class;
  int roll;
  struct Date dob;
};
// done
struct Date
{
  int day;
  int month;
  int year;
};
// done
struct Date inputDate()
{
  struct Date date;
  scanf("%d %d %d", &date.day, &date.month, &date.year);
  return date;
}

// done
struct Student inputStudent()
{
  struct Student st;
  printf(" name: ");
  gets(st.name);
  // gets(st.name);
  printf(" class: ");
  scanf("%d", &st.class);
  printf(" Roll: ");
  scanf("%d", &st.roll);
  printf(" DOB: ");
  st.dob = inputDate();

  return st;
}

// done reading
void printfDate(struct Date date)
{
  printf("%d %d %d", date.day, date.month, date.year);
};

void printStudent(struct Student st)
{
  printf("basic info");
  //    printf("%s %d %d %d %d %d\n", st.name, st.class, st.roll, st.dob.day, st.dob.month, st.dob.year);
  printf("%s %d %d \n", st.name, st.class, st.roll);
  printf("DOB");
  printfDate(st.dob);
};
// done

int main()
{
  int n;
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);
  struct Student students[n];
  for (int i = 1; i <= n; i++)
  {
    printf("input student %d info\n", i);
    students[i - 1] = inputStudent();
  }
  for (int i = 0; i <= n; i++)
  {
    printf("Student %d info\n", i);
    printStudent(students[i]);
  }
}
// # include <stdio.h>
// # include <string.h>

// struct Test

// {

//   char str[20];

// };

// int main()

// {

//   struct Test st1, st2;

//   strcpy(st1.str, "PhitronQuiz");

//   st2 = st1;

//   st1.str[0] = 'S';

//   printf("%s",st2.str);

//   return 0;

// }
