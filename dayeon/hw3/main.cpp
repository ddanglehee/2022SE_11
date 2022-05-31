#include <iostream>
#include <fstream>
#include "clothes_shopping_site.h"

#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

void doTask();
void join();
void program_exit();

FILE* in_fp, *out_fp;

int main() {
  FILE* in_fp = fopen(INPUT_FILE_NAME, "r+");
  FILE* out_fp = fopen(OUTPUT_FILE_NAME, "w+");

  doTask();

  return 0;
}

void doTask(){
  
}