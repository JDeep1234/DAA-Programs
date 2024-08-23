// This is a code to read the number of disks and out put the moves to be made to complete the tower of hanoi problem

#include <stdio.h>
#include <stdlib.h>

void towerOfHanoi(int diskNum, char sourceTower[], char tempTower[], char destinationTower[])
{
    if (diskNum == 1)
        printf("\nDisk %d is moved from %s to %s\n", diskNum, sourceTower, destinationTower);

    else
    {
        towerOfHanoi(diskNum - 1, sourceTower, destinationTower, tempTower);
        printf("\nDisk %d is moved from %s to %s\n", diskNum, sourceTower, destinationTower);
        towerOfHanoi(diskNum - 1, tempTower, sourceTower, destinationTower);
    }
}

int main()
{
    int diskNum;
    char sourceTower[10], tempTower[10], desitinationTower[10];
    printf("\nEnter the number of disks: ");
    scanf("%d", &diskNum);
    printf("\nEnter the name of Source Tower: ");
    scanf("%s", sourceTower);
    printf("\nEnter the name of Destination Tower: ");
    scanf("%s", desitinationTower);
    printf("\nEnter the name of Temporary Tower: ");
    scanf("%s", tempTower);
    towerOfHanoi(diskNum, sourceTower, tempTower, desitinationTower);
    return 0;
}