/*Goals
    Implement modifiable perlin noise generator
    Implement modifiable noise based terrain generator
    Learn to read from external files
    Implement terrain and noise generator reading from external file
    Implement a ascii based world display that only displays world around player
    Implement player movement, falling, and collision

  Some Optional Stuff(prob not)
    Mining and/or building
*/

#include <iostream>
#include <array>

const int worldBoundX {96};
const int worldBoundY {64};
int worldVoxData [worldBoundX] [worldBoundY];
int worldPerlinData [worldBoundX];

const int worldHeightMax {48};
const int worldHeightMin {24};
const int worldHeightMid {32};

const int worldMaxClimb {5};
const double worldAveClimb {1.2};

struct voxData{
    int voxID {-1};
    bool isSolid;
    bool isSoft;
    char renderChar;
    bool notMinable {false};
};

double perlinWeightGen ();
void worldTerminalRender (int playerPos[], voxData voxel[]);
void playerLogic ();

int main () {
    #pragma region //block data
    voxData voxVoid;
    voxVoid.voxID = 0;
    voxVoid.isSolid = false;
    voxVoid.isSoft = false;
    voxVoid.renderChar = ' ';
    
    voxData voxDirt;
    voxDirt.voxID = 1;
    voxDirt.isSolid = true;
    voxDirt.isSoft = true;
    voxDirt.renderChar = 'd';
    
    voxData voxGrass;
    voxGrass.voxID = 2;
    voxGrass.isSolid = true;
    voxGrass.isSoft = true;
    voxGrass.renderChar = 'D';
    
    voxData voxStone;
    voxStone.voxID = 3;
    voxStone.isSolid = true;
    voxStone.isSoft = false;
    voxStone.renderChar = 's';

    voxData voxBorder;
    voxBorder.voxID = 3;
    voxBorder.isSolid = true;
    voxBorder.isSoft = false;
    voxBorder.renderChar = 'L';
    voxBorder.notMinable = true;
    
    #pragma endregion

    voxData voxel [5] {voxVoid, voxDirt, voxGrass, voxStone, voxBorder};
    double perlinWorldWeight [worldBoundY] {};
    int playerPos [2] {30, 30};//current numbers are placeholders

    for (int i = 0; i < worldHeightMin; i++) {
        perlinWorldWeight[i] = -1;
    }
    for (int i = worldHeightMax + 1; i < worldBoundY; i++) {
        perlinWorldWeight[i] = 1;
    }
    for (int i = worldHeightMin + 1; i < worldHeightMax; i++) {
        perlinWorldWeight[i] = 0;
    }

    worldTerminalRender (playerPos, voxel);

    return 0;
}

double perlinWeightGen () {
    
    return 0;
}

void worldTerminalRender (int playerPos[], voxData voxel[]) {
    for (int y = playerPos[1]+12; y > 0; y--){
        for (int x = playerPos[0]-12; x > 13; x++) {
            std::cout << worldVoxData[x][y];
        }
        std::cout << '\n';
    }
    for (int x = playerPos[0]-12; x < 0; x++) {
        std::cout << worldVoxData[x][playerPos[1]];
    }
    std::cout << "P";
    for (int x = playerPos[0]+1; x < 13; x++) {
        std::cout << worldVoxData[x][playerPos[1]];
    }
    std::cout << '\n';
    for  (int y = playerPos[1]-1; y > -13; y--){
        for (int x = playerPos[0]-12; x > 13; x++) {
            std::cout << worldVoxData[x][y];
        }  
        std::cout << '\n';
    }
    return;
}

void playerLogic () {

    return;
}