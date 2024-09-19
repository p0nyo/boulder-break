#include <stdio.h>
#include <string.h>

void InitialiseStory(char* paragraph)
{
    char story[2000] = "YOU ARE STUCK IN A CAVE!!! In order to escape, you must \npush boulders to make safe passageway over large holes \nand collect treasure on your way!";
    strcpy(paragraph, story);
}

int main() {

    char story[2000];
    InitialiseStory(story);
    printf("%s\n", story);

}