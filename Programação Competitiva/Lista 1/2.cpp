#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool slump(char *string, int *aux){
  if ((string[*aux] == 'D' || string[*aux] == 'E') && string[++*aux] == 'F'){
    *aux += 1;
    while (string[*aux] == 'F'){
      *aux += 1;
    } 
    if(string[*aux] == 'G')
        return true;
    else if (string[*aux] == 'D' || string[*aux] == 'E')
      slump(string, aux);
  }
  else
    return false;
}

bool slimp(char *string, int *aux){
  if (string[*aux] == 'A'){
    *aux += 1;
    if (string[*aux] == 'H')
      return true;

    while(string[*aux] == 'B' || string[*aux] == 'D' || string[*aux] == 'E'){
      if (string[*aux] == 'B'){
        *aux += 1;
        if(slimp(string, aux)){
          *aux += 1;
          if (string[*aux] == 'C')
            return true;
          else
            return false;
        }        
      }
      else {
        if(slump(string, aux)){
          *aux += 1;
          if (string[*aux] == 'C')
            return true;
          else
            return false;
        }
      }
    }
  }
  else
    return false;
}

bool slurpy(char *string){
  int aux = 0;
  bool slimp_aux;
  slimp_aux = slimp(string, &aux);
  if(slimp_aux){
    aux += 1;
    if (slump(string, &aux)){
      if(!string[++aux])
        return true;
    }
  }
  return false;
}


int main(int argc, char const *argv[]){
  int n;
  scanf("%i", &n);
  char *line;

  printf("SLURPYS OUTPUT\n");
  for(int i=0; i<n; i++){
    scanf("%s", line);
    if (slurpy(line))
      printf("YES\n");
    else
      printf("NO\n");
  }
  printf("END OF OUTPUT\n");

  return 0;
}