#include<stdio.h>

#include<string.h>

#include<stdlib.h>

void mainMenu();
void menu2();
void menu3();
void menu4();
void menu5();
int isReflexive(int n, int matrix[][n]);
int isNonirreflexive(int n, int matrix[][n]);
int isSymmetric(int n, int matrix[][n]);
int isTransitive(int n, int matrix[][n]);
int checkAntisymmetricforall(int n, int matrix[][n]);
int checkAntiSymmetric(int n, int matrix[][n]);
int isAllsymmetric(int n, int matrix[][n]);
int isPoset(int n, int matrix[][n]);
void toReflexive(int n, int matrix[][n]);
void toSymmetric(int n, int matrix[][n]);
void toAllSymmetric(int n, int matrix[][n]);

int main() {
  FILE * fp;
  fp = fopen("SampleInput.csv", "r");
  if (fp == NULL) {
    perror("Failed: ");
    return 1;
  }

  int no_of_websites = -1;

  char buffer[1000];

  while (fgets(buffer, sizeof(buffer), fp)) {
    no_of_websites++;
  }
  int n = no_of_websites;

  int matrix[no_of_websites][no_of_websites];
  int x = 0;
  int y = 0;

  fp = fopen("SampleInput.csv", "r");
  fgets(buffer, sizeof(buffer), fp);

  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    char * token = strtok(buffer, ",");
    y = 0;

    while (token != NULL) {
      if (y == 0) {
        printf("%s", token);
      } else {
        printf("%d", atoi(token));
        matrix[x][y - 1] = atoi(token);

      }
      y++;
      token = strtok(NULL, ",");
    }
    x++;

  }
  printf("\n");
  printf("%d\n", no_of_websites);
  printf("\n");
  for (int i = 0; i < no_of_websites; i++) {
    for (int j = 0; j < no_of_websites; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  fclose(fp);
  printf("\n\n");

  int key;
  mainMenu();
  printf("Please enter the option number you want to exceute\n");
  scanf("%d", & key);

  while (key != 9) {
    switch (key) {
    case 1: {
      int a = isReflexive(n, matrix);
      if (a == 1) {
        printf("YES\n");
      } else {
        printf("NO\n");
        //string nextstep; 
        menu2();
        //scanf("%s", &nextstep);
        //if(nextstep == "YES") 
        {
          //print the graph
        }
      }
    }
    break;
    case 2: {
      int b = isAllsymmetric(n, matrix);
      if (b == 1) {
        printf("YES\n");
      } else {
        printf("NO\n");
        //string nextstep; 
        menu2();
        //scanf("%s", &nextstep);
        //if(nextstep == "YES") 
        {
          //print the graph
        }
      }
    }
    break;
    case 3: {}
    break;
    case 4: {
      int d = isNonirreflexive(n, matrix);
      if (d == 1) {
        printf("YES\n");
      } else {
        printf("NO\n");
      }
    }
    break;
    case 5: {
      int e = checkAntisymmetricforall(n, matrix);
      if (e == 1) {
        printf("YES\n");
      } else {
        printf("NO\n");
      }
    }
    break;
    case 6: {
      int f = checkAntiSymmetric(n, matrix);
      if (f == 1) {
        printf("YES\n");
      } else {
        printf("NO\n");
      }
    }
    break;
    case 7: {}
    break;
    case 8: {
      int g = isPoset(n, matrix);
      if (g == 1) {
        printf("YES\n");
        menu4();
        printf("\n\n");
        printf("Enter what you want to do from menu4");
        int new_key;
        scanf("%d", & new_key);
        switch (new_key) {
        case 1: {}
        break;
        case 2: {}
        break;
        case 3: {}
        break;
        case 4: {}
        break;
        case 5: {}
        break;
        case 6: {}
        break;
        case 7: {}
        break;
        case 8: {
          printf("Enter the option you want to execute from Menu 5");
          int sub_key;
          scanf("%d", & sub_key);
          switch (new_key) {
          case 1: {}
          break;
          case 2: {}
          break;
          case 3: {}
          break;
          case 4: {}
          break;
          default: {
            printf("You have entered an incorrect option number");
          }
          break;
          }
        }
        break;
        case 9: {}
        break;
        default: {
          printf("You have entered an incorrect option number");
        }
        break;
        }

      } else {
        printf("NO\n");
      }
    }
    break;
    default: {
      printf("Incorrect option selected\n");
    }
    break;

    }
    mainMenu();
    printf("\n\n\n\nPlease enter the option number you want to exceute\n");
    scanf("%d", & key);
  }
  printf("Thank You!! :)\n");
  return 0;
}

void mainMenu() {
  printf("MAIN MENU\n\n");
  printf("1. Does every website has a link to itself\n");
  printf("2. Is it possible to always return back to the previous website from the current website in one step?\n");
  printf("3. Does every website has all the links to the websites which are reachable from it?\n");
  printf("4. Does there exist any website that contains a link to itself?\n");
  printf("5. Is it impossible to return to the previous website from the current website in one step?\n");
  printf("6. Is it impossible to return to the previous website from the current website in one step(excluding the cases where the current and previous website is same)?\n");
  printf("7. Is it possible to divide the network into multiple pieces such that every website in a piece is reachable from every other website in that piece?\n");
  printf("8. Is this relation an example of poset?\n");
  printf("9. Exit\n");
}

void menu2() {
  printf("MENU 2\n\n");
  printf(" Do you want to visualise how the network will look if we add minimum links to satisfy the property?");
}

void menu3() {
  printf("MENU 3\n\n");
  printf("Do you want to know the nodes in each piece? \n");
}

void menu4() {
  printf("MENU 4\n\n");
  printf("1. Display the hasse diagram.\n");
  printf("2. Display the website whose link is available in every website.\n");
  printf("3. Display the website which has links of every website.\n");
  printf("4. Display the websites that do not have links to any other website except itself.\n");
  printf("5. Display the websites which can't be reached from any other website except itself.\n");
  printf("6. Given some websites, display the websites which are reachable from all of them. \n");
  printf("7. Given some websites, display the websites from which you can reach all those websites.\n");
  printf("8. Is this relation an example of lattice?\n");
  printf("9. Return to Main Menu \n");
}

void menu5() {
  printf("MENU 5\n\n");
  printf("1. Given two websites A and B, display the website which is reachable by both A and B and can also reach to all such websites that both A and B can reach.\n");
  printf("2. Given two websites A and B, display the website which can reach to both A and B and is also reachable from all such websites which can reach to both  A and B.\n");
  printf("3. Is the lattice distributive?\n");
  printf("4. Return to Menu 4\n");

}

int isReflexive(int n, int matrix[][n]) {
  for (int i = 0; i < n; i++) {
    if (matrix[i][i] != 1) {
      return 0;
    }
  }

  return 1;
}

void toReflexive(int n, int matrix[][n]) {
  for (int i = 0; i < n; i++) {
    matrix[i][i] = 1;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", matrix[i][j]);

    }
    printf("\n");
  }
}

void toSymmetric(int n, int matrix[][n]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j) {
        if (matrix[i][j] == 1) {
          matrix[j][i] = 1;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", matrix[i][j]);

    }
    printf("\n");
  }
}

int isNonirreflexive(int n, int matrix[][n]) {
  for (int i = 0; i < n; i++) {
    if (matrix[i][i] == 1) {
      return 1;
    }
  }

  return 0;
}

void toAllSymmetric(int n, int matrix[][n]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j) {
        matrix[i][j] = 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", matrix[i][j]);

    }
    printf("\n");
  }

}

int isSymmetric(int n, int matrix[][n]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] != matrix[j][i]) {
        return 0;
        break;
      }
    }
  }
  return 1;
}

int isTransitive(int n,int matrix[][n]){
      int q=1;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++)
            {
                if ((i!=j && j!=k) && (matrix[i][j] == 1 && matrix[j][k] == 1 && matrix[k][i] == 0))
                    q=0;
            }
        }
    }
    if(q==0){return 0;}
    else return 1;
    }

int checkAntisymmetricforall(int n, int matrix[][n]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] != 0 && matrix[j][i] != 0) {
        return 0;
      }

    }
  }
  return 1;
}

int checkAntiSymmetric(int n, int matrix[][n]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if ((i != j) && matrix[i][j] != 0 && matrix[j][i] != 0) {
        return 0;
      }
    }
  }
  return 1;
}

int isAllsymmetric(int n, int matrix[][n]) {

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] == 1 && matrix[j][i] == 1) {
        return 1;
      }
    }
  }
  return 0;
}

int isPoset(int n, int matrix[][n]) {
  int a = isReflexive(n, matrix);
  int b = isTransitive(n, matrix);
  int c = checkAntisymmetricforall(n, matrix);

  if (a == 1 && b == 1 && c == 1) {
    return 1;
  } else {
    return 0;
  }
}
