#include<stdio.h>

#include<string.h>

#include<stdlib.h>

#include<math.h>

#include<stdbool.h>

#include<unistd.h>

#include<stddef.h>

#define CSV_FILE "temp.csv"
#define SAMPLE_CSV_FILE "SampleInput.csv"

void plot(char * fname);

void mainMenu();
void menu2();
void menu3();
void menu4();
void menu5();

int isReflexive(int n, int matrix[][n]);
int isNonirreflexive(int n, int matrix[][n]);
int isSymmetric(int n, int matrix[][n]);
int isTransitive(int n, int matrix[][n]);

void main_menu7(int n, int matrix[][n]);
void menu3working(int n, int matrix[][n], int order[]);

int checkAntisymmetricforall(int n, int matrix[][n]);
int checkAntiSymmetric(int n, int matrix[][n]);
int isAllsymmetric(int n, int matrix[][n]);
int isPoset(int n, int matrix[][n]);

void toReflexive(int n, int matrix[][n], char * names[]);
void toSymmetric(int n, int matrix[][n], char * names[]);
void toTransitive(int n, int graph[][n], char * names[]);
void toAllSymmetric(int n, int matrix[][n]);
void make_csv(int n, char * names[], int matrix[][n]);
void extractNames(char * line, char * names[], int count);

char * stringTokenizer(char * buffer);

int dfs(int v, int n, int visited[], int matrix[][n]);
void dfs2(int v, int n, int matrix[][n], int visited[], int component[]);

bool isLattice(int n, int matrix[][n]);
int option1(int n, int matrix[][n], int webA, int webB);
int option2(int n, int matrix[][n], int webA, int webB);

void menu4_1(int n, int matrix[][n], char * names[]);
void menu4_2(int n, int matrix[][n], char * names[]);
void menu4_3(int n, int matrix[][n], char * names[]);
void menu4_4(int n, int matrix[][n], char * names[]);
void menu4_5(int n, int matrix[][n], char * names[]);
void menu4_6(int n, int matrix[][n], int arr[n], char * names[]);
void menu4_7(int n, int matrix[][n], int arr[n], char * names[]);

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

  // string array of website names
  char * website_names[no_of_websites];
  //

  fp = fopen("SampleInput.csv", "r");
  fscanf(fp, "%s", buffer);

  extractNames(buffer, website_names, no_of_websites);

  fgets(buffer, 1000, fp);
  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    char * token = strtok(buffer, ",");
    y = 0;

    while (token != NULL) {
      if (y == 0) {} else {
        matrix[x][y - 1] = atoi(token);
      }
      token = strtok(NULL, ",");
      y++;

    }
    x++;

  }
  fclose(fp);
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
        char nextstep[4];
        menu2();
        printf("\n");
        scanf("%s", & nextstep);
        if (strcmp(nextstep, "YES") == 0) {
          toReflexive(n, matrix, website_names);
        } else {}
      }
    }
    break;
    case 2: {
      int b = isAllsymmetric(n, matrix);
      if (b == 1) {
        printf("YES\n");
      } else {
        printf("NO\n");
        char nextstep[4];
        menu2();
        printf("\n");
        scanf("%s", & nextstep);
        if (strcmp(nextstep, "YES") == 0) {
          toSymmetric(no_of_websites, matrix, website_names);
        } else {}
      }
    }
    break;
    case 3: {
      int c = isTransitive(n, matrix);
      if (c == 1) {
        printf("YES\n");
      } else {
        printf("NO\n");
        char nextstep[4];
        menu2();
        printf("\n");
        scanf("%s", & nextstep);
        if (strcmp(nextstep, "YES") == 0) {
          toTransitive(no_of_websites, matrix, website_names);
        } else {}
      }

    }
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
    case 7: {

    }
    break;
    case 8: {
      int g = isPoset(n, matrix);
      if (g == 1) {
        printf("YES\n");
        menu4();
        printf("\n\n");
        printf("Enter what you want to do from menu4\n");
        int new_key;
        scanf("%d", & new_key);
        switch (new_key) {
        case 1: {
          // display hasse diagram////////////////////
          plot(SAMPLE_CSV_FILE);
        }
        break;
        case 2: {
          menu4_2(no_of_websites, matrix, website_names);
        }
        break;
        case 3: {
          menu4_3(no_of_websites, matrix, website_names);

        }
        break;
        case 4: {
          menu4_4(no_of_websites, matrix, website_names);
        }
        break;
        case 5: {
          menu4_5(no_of_websites, matrix, website_names);
        }
        break;
        case 6: {
          // taking input of array as integer array
          // 1 represents given website to be checked and 0 represents ignoring the website from the check
          int array[no_of_websites];
          for (int i = 0; i < n; i++) {
            scanf("%d", & array[i]);
          }
          menu4_6(no_of_websites, matrix, array, website_names);
        }
        break;
        case 7: {
          // taking input of array as integer array
          // 1 represents given website to be checked and 0 represents ignoring the website from the check
          int array[no_of_websites];
          for (int i = 0; i < n; i++) {
            scanf("%d", & array[i]);
          }
          menu4_7(no_of_websites, matrix, array, website_names);
        }
        break;
        case 8: {
          if (isLattice(no_of_websites, matrix)) {
            printf("Enter the option you want to execute from Menu 5");
            int sub_key;
            scanf("%d", & sub_key);
            switch (new_key) {
            case 1: {
              int webA, webB;
              scanf("%d %d", & webA, & webB);

              option1(no_of_websites, matrix, webA, webB);
            }
            break;
            case 2: {
              int webA, webB;
              scanf("%d %d", & webA, & webB);

              option2(no_of_websites, matrix, webA, webB);
            }
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

void toReflexive(int n, int matrix[][n], char * names[]) {
  for (int i = 0; i < n; i++) {
    matrix[i][i] = 1;
  }
  make_csv(n, names, matrix);
}

void toSymmetric(int n, int matrix[][n], char * names[]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j) {
        if (matrix[i][j] == 1) {
          matrix[j][i] = 1;
        }
      }
    }
  }
  make_csv(n, names, matrix);
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

int isTransitive(int n, int matrix[][n]) {
  int q = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if ((i != j && j != k) && (matrix[i][j] == 1 && matrix[j][k] == 1 && matrix[k][i] == 0))
          q = 0;
      }
    }
  }
  if (q == 0) {
    return 0;
  } else return 1;
}

int checkAntisymmetricforall(int n, int matrix[][n]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] != 0 && matrix[j][i] != 0 && i != j) {
        return 0;
      } else if (i = j) {
        ;
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
  int c = checkAntiSymmetric(n, matrix);

  if (a == 1 && b == 1 && c == 1) {
    return 1;
  } else {
    return 0;
  }
}

void make_csv(int n, char * names[], int matrix[][n]) {

  FILE * fp;
  fp = fopen(CSV_FILE, "w+");
  for (int i = 0; i < n; i++) {
    fprintf(fp, ",%s", names[i]);
    printf("%s\n", names[i]);
  }
  fprintf(fp, "\n");

  for (int i = 0; i < n; i++) {

    fprintf(fp, "%s", names[i]);

    for (int j = 0; j < n; j++) {
      fprintf(fp, ",%d", matrix[i][j]);
    }

    fprintf(fp, "\n");
  }

  fclose(fp);
  plot(CSV_FILE);
}

char * stringTokenizer(char * buffer) {
  int i = 0;
  for (i = 0; i < strlen(buffer); i++) {
    if (buffer[i] == ',') buffer[i] = '\0';
    break;
  }

  char * temp = buffer;
  buffer = buffer + i + 1;
  return temp;
}

void extractNames(char * line, char * names[], int count) {
  int x = 0;
  int len = strlen(line);
  for (int i = 0; i < len; i++) {
    if (line[i] == ',') {
      line[i] = '\0';
    }
  }
  for (int i = 0; i < len; i++) {
    if (line[i] == '\0') {
      names[x] = malloc(100 * sizeof(char));
      strcpy(names[x++], & line[i + 1]);
    }
  }
}

// taken reference from GFG
int dfs(int v, int n, int visited[], int matrix[][n]) {
  int i;
  visited[v] = 1;
  for (i = 0; i < n; i++) {
    if (matrix[v][i] && !visited[i]) {
      visited[i] = 1;
      dfs(i, n, visited, matrix);
    }
  }
  return *visited;
}
void dfs2(int v, int n, int matrix[][n], int visited[], int component[]) {
  int componentSize = 0;
  component[componentSize] = v;
  componentSize++;
  visited[v] = 1;
  for (int i = 0; i < n; i++) {
    if (matrix[i][v] == 1 && visited[i] == 0) {
      dfs2(i, n, matrix, visited, component);
    }
  }
  return;
}
// taken reference from GFG
void main_menu7(int n, int matrix[][n]) {
  int visited[n];
  for (int i = 0; i < n; i++) {
    visited[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    int temp[n];
    for (int i = 0; i < n; i++) {
      temp[i] = 0;
    }

    if (visited[i] == 0) {
      dfs(i, n, temp, matrix);
    }
    int j = 0;
  }
}
void menu3working(int n, int matrix[][n], int order[]) {
  int componentCount = 0;
  char c;
  printf("Do you want to know node in each piece?\n");
  scanf(" %c", & c);

  if (c == 'y') {
    int visited[n];
    for (int i = 0; i < n; i++) {
      visited[i] = 0;
    }
    int prevCount = -1;
    for (int i = n - 1; i >= 0; i--) {
      int components[n];
      componentSize = 0;
      int v = order[i];
      if (visited[v] == 0) {
        dfs2(v, n, matrix, visited, components);
        componentCount++;
      }
      if (prevCount != componentCount) {
        printf("Component %d consist of nodes:\n", componentCount);
        for (int i = 0; i < componentSize; i++) {
          printf("%d ", components[i]);
        }
        printf("\n");
        prevCount = componentCount;
      }
    }
  }
  return;
}

void menu4_1(int n, int matrix[][n], char * names[]) {
  // display the hasse diagram
}

void menu4_2(int n, int matrix[][n], char * names[]) {
  int arr[n];
  for (int i = 0; i < n; i++) {
    arr[i] = 0;
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      sum = sum + matrix[j][i];
    }
    if (sum == n) {
      arr[i]++;
    }
    sum = 0;
  }
  for (int t = 0; t < n; t++) {
    if (arr[t] == 1) {
      printf("%s\n", names[t]);
    }
  }
}

void menu4_3(int n, int matrix[][n], char * names[]) {
  int arr[n];
  for (int i = 0; i < n; i++) {
    arr[i] = 0;
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      sum = sum + matrix[i][j];
    }
    if (sum == n) {
      arr[i]++;
    }
    sum = 0;
  }
  for (int t = 0; t < n; t++) {
    if (arr[t] == 1) {
      printf("%s\n", names[t]);
    }
  }
}

void menu4_4(int n, int matrix[][n], char * names[]) {
  int arr[n];
  for (int i = 0; i < n; i++) {
    arr[i] = 0;
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j && matrix[i][j] == 1) {
        sum = 1;
        break;
      }
    }
    if (sum == 0) {
      arr[i]++;
    }
    sum = 0;
  }
  for (int t = 0; t < n; t++) {
    if (arr[t] == 1) {
      printf("%s\n", names[t]);
    }
  }
}
void menu4_5(int n, int matrix[][n], char * names[]) {
  int arr[n];
  for (int i = 0; i < n; i++) {
    arr[i] = 0;
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j && matrix[j][i] == 1) {
        sum = 1;
        break;
      }
    }
    if (sum == 0) {
      arr[i]++;
    }
    sum = 0;
  }
  for (int t = 0; t < n; t++) {
    if (arr[t] == 1) {
      printf("%s\n", names[t]);
    }
  }
}

void menu4_6(int n, int matrix[][n], int arr[n], char * names[]) {
  int arr1[n];
  for (int i = 0; i < n; i++) {
    if (arr[i] == 1) {
      arr1[i] = 1;
    } else arr1[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    if (arr[i] == 1) {
      for (int j = 0; j < n; j++) {
        arr1[j] = arr1[j] * matrix[i][j];
      }
    }
  }
  for (int t = 0; t < n; t++) {
    if (arr[t] == 1) {
      printf("%s\n", names[t]);
    }
  }
}

void menu4_7(int n, int matrix[][n], int arr[n], char * names[]) {
  int arr1[n];
  for (int i = 0; i < n; i++) {
    arr1[i] = 1;
  }
  for (int i = 0; i < n; i++) {
    if (arr[i] == 1) {
      for (int j = 0; j < n; j++) {
        arr1[j] = arr1[i] * matrix[j][i];
      }
    }
  }
  for (int t = 0; t < n; t++) {
    if (arr[t] == 1) {
      printf("%s\n", names[t]);
    }
  }
}
void printSolution(int n, int reach[][n]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j)
        printf("1 ");
      else
        printf("%d ", reach[i][j]);
    }
    printf("\n");
  }
}

void toTransitive(int n, int graph[][n], char * names[]) {
  int reach[n][n], i, j, k;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      reach[i][j] = graph[i][j];
  for (k = 0; k < n; k++) {
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        reach[i][j] = reach[i][j] ||
          (reach[i][k] && reach[k][j]);
      }
    }
  }
  for (int i = 0; i, n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        reach[i][j] = 1;
      }
    }
  }
  make_csv(n, names, reach);
}

// void toHasse(int n, char * names[], int matrix[][n]){
//   // remove reflexive 
//   // remove symmetric
//   make_csv(n, names, matrix);

// checking if lattice
bool isLattice(int n, int matrix[][n]) {
  int b[n][n];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      b[i][j] = matrix[i][j];

  // finding least upper bound
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++) {

      int temp[n];

      for (int k = 0; k < n; k++)
        temp[k] = (int)(b[i][k] && b[j][k]);
      int count = 0;
      for (int k = 0; k < n; k++) {
        int intBool = 1;
        for (int l = 0; l < n; l++)
          if (temp[l] != b[k][l]) {
            intBool = 0;
          }
        if (intBool == 1)
          count++;
      }
      if (count != 1)
        return false;
    }

  // finding greatest lower bound
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++) {

      int temp[n];

      for (int k = 0; k < n; k++)
        temp[k] = (int)(b[k][i] && b[k][j]);
      int count = 0;
      for (int k = 0; k < n; k++) {
        int intBool = 1;
        for (int l = 0; l < n; l++)
          if (temp[l] != b[l][k]) {
            intBool = 0;
          }
        if (intBool == 1)
          count++;
      }
      if (count != 1)
        return false;
    }

  return true;

}

int option1(int n, int matrix[][n], int webA, int webB) {

  webA = webA - 1;
  webB = webB - 1;

  int b[n][n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      b[i][j] = matrix[i][j];

  int temp[n];

  for (int k = 0; k < n; k++)
    temp[k] = (int)(b[webA][k] && b[webB][k]);

  for (int k = 0; k < n; k++) {

    int intBool = 1;

    for (int l = 0; l < n; l++)

      if (temp[l] != b[k][l]) {
        intBool = 0;
      }
    if (intBool == 1)
      return k + 1;
  }
}

int option2(int n, int matrix[][n], int webA, int webB) {

  webA = webA - 1;
  webB = webB - 1;

  int b[n][n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      b[i][j] = matrix[i][j];

  int temp[n];

  for (int k = 0; k < n; k++)
    temp[k] = (int)(b[k][webA] && b[k][webB]);

  for (int k = 0; k < n; k++) {

    int intBool = 1;

    for (int l = 0; l < n; l++)
      if (temp[l] != b[l][k]) {
        intBool = 0;
      }
    if (intBool == 1)
      return k + 1;
  }
  return 0;
}

void plot(char * fname){
    int pid;
    if((pid = fork())==0){
        if(execlp("python", "python","visualise.py",fname,(char*)NULL)==-1){
        	execlp("python3", "python3","visualise.py",fname,(char*)NULL);
        };
    }
    exit(0);
}
