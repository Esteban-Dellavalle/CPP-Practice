#include <iostream>
#include <math.h>
#define GRAVITY_OF_EARTH 9.81
#define PI 3.141592


float LaunchSpeed();
float DegreesOfLaunch();
float CalculateProjectileVy(float speed, float degrees);
float CalculateProjectileVx(float speed, float degrees);
float CalculateProjectileTup(float vY);
float CalculateTotalTup(float timeUp);
float CalculateMaxHeigth(float velY);
float CalculateRange(float velX, float totalTimeUp);
char userInput();


int main()
{   
    char userInp;

    userInp = userInput();

    do
    {
        float launchDegrees = DegreesOfLaunch();
        float speedLaunch = LaunchSpeed();
        float vY = CalculateProjectileVy(speedLaunch, launchDegrees);
        float vX = CalculateProjectileVx(speedLaunch, launchDegrees);
        float timeUp = CalculateProjectileTup(vY);
        float totalTup = CalculateTotalTup(timeUp);
        float maxHeight = CalculateMaxHeigth(vY);
        float rangeProjectile = CalculateRange(vX, totalTup);

        std::cout << "Launch degrees: " << launchDegrees << std::endl << "Launch speed: " << speedLaunch << std::endl << "Total time up: " << totalTup << std::endl << "Range of projectile: " << rangeProjectile << std::endl;
        std::cout << "Max Height: " << maxHeight << std::endl;
        userInp = userInput();

    }
    while(userInp == 'y');
    
    std::cout << "Bye." << std::endl;
    
    

    system("pause");
}



float LaunchSpeed()
{
    float launchSpd = 0;
    std::cout << "Enter the launch speed of the projectile: " << std::endl;
    std::cin >> launchSpd;
    return launchSpd;
}

float DegreesOfLaunch()
{
    float degreesLaunch = 0;
    std::cout << "Enter the degrees of the launch: " << std::endl;
    std::cin >> degreesLaunch;
    return degreesLaunch;
}

float CalculateProjectileVy(float speed, float degrees)
{
    float calculateVy = speed * sin (degrees * (PI / 180.0));
    return calculateVy;
}


float CalculateProjectileVx(float speed, float degrees)
{
    float calculateVx = speed * cos (degrees * (PI / 180.0));
    return calculateVx;
}

float CalculateProjectileTup(float vY)
{
    float calculateTup = vY / GRAVITY_OF_EARTH;
    return calculateTup;
}

float CalculateTotalTup(float timeUp)
{
    float calculateTotal = timeUp * 2;
    return calculateTotal;
}

float CalculateMaxHeigth(float velY)
{
    float maxHeigth = (velY * velY) / (2 * GRAVITY_OF_EARTH);
    return maxHeigth;
}

float CalculateRange(float velX, float totalTimeUp)
{
    float totalRange = velX * totalTimeUp;
    return totalRange;
}

char userInput()
{
    char userIn;
    std::cout << "To continue, press y, to exit press x." << std::endl;
    std::cin >> userIn;
    return userIn;
}