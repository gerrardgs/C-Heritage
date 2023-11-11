#include <stdio.h>

int main()
{
    FILE *FileBaru;
    char IsiFile[1000];

    FileBaru = fopen("savetwo.txt", "r");
    if (FileBaru == NULL)
    {
      printf ("FILENYA GAADA!!!");
    }
    else
    {
        while (fgets(IsiFile, sizeof(IsiFile), FileBaru))
      {
        printf("%s", IsiFile);
      }
    fclose(FileBaru);
    }
}
