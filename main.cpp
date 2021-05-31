#include <iostream>

void printArray(int array[][5], std::string label)
{
    std::cout << label << ":\n";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << array[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

int getIntegerFromKeyboard(std::string label, int min, int max)
{
    int value = 0;
    std::cout << label << "\n";
    do
    {
        std::cin >> value;
        if (value < min || value > max)
            std::cout << "Bad input. Please enter the integer from " << min << " to " << max << ". Try again.\n";
    } while (value < min || value > max);

    return value;
}

void enterTheHeightMap(int heightMap[][5])
{
    // If height is zero, than all elements in sector (from 0 to 9) will be 0;
    // If height is 10, than all elements in sector (from 0 to 9) will be 1;
    std::cout << "Please enter the height map (value 0-10 for each sector one by one):\n";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            heightMap[i][j] = getIntegerFromKeyboard("", 0, 10);
        }
    }
}

void initializeLandscape(int heightMap[][5], int landscape[][5][10])
{
    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 5; x++)
        {
            for (int z = 0; z < heightMap[y][x]; z++)
            {
                landscape[y][x][z] = 1;
            }
        }
    }
}

void horSlice(int slice[][5], int landscape[][5][10], int height)
{
    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 5; x++)
        {
            slice[y][x] = landscape[y][x][height - 1];
        }
    }
}

int main() {

    //Use for fast height map test: 1 2 3 4 5 6 7 10 9 1 2 3 4 5 6 10 8 9 1 0 3 4 5 6 7
    int heightMap[5][5];
    enterTheHeightMap(heightMap);
    printArray(heightMap, "Height map you've entered");

    int landscape[5][5][10] = {0};
    initializeLandscape(heightMap, landscape);

    //Height is entering from 1 to 10 to make it more convenient and align with height map values.
    //Task was to make it from 0 to 9, but 1 to 10 is more transparent.
    int height = getIntegerFromKeyboard("Please enter the height for slice (1 - 10)", 1, 10);

    int slice[5][5];
    horSlice(slice, landscape, height);
    printArray(slice, "Horizontal slice at height " + std::to_string(height));

    return 0;
}