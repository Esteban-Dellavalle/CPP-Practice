#include <iostream>
#include <math.h>
#define GRAVITY_OF_EARTH 9.81
#define PI 3.141592


double LaunchSpeed();
double DegreesOfLaunch();
double CalculateProjectileVy(double speed, double degrees);
double CalculateProjectileVx(double speed, double degrees);
double CalculateProjectileTup(double vY);
double CalculateTotalTup(double timeUp);
double CalculateMaxHeigth(double velY);
double CalculateRange(double velX, double totalTimeUp);
char userInput();


int main()
{   
    char userInp;
    userInp = userInput();

    while(userInp != 'y' && userInp != 'x')
    {
        
        std::cout << "Try again." << std::endl;
        userInp = userInput();
                        
    }
    if(userInp == 'x')
    {
        std::cout << "Bye." << std::endl;
    }
    
            while(userInp == 'y')
            {
            double launchDegrees = DegreesOfLaunch();
            double speedLaunch = LaunchSpeed();
            double vY = CalculateProjectileVy(speedLaunch, launchDegrees);
            double vX = CalculateProjectileVx(speedLaunch, launchDegrees);
            double timeUp = CalculateProjectileTup(vY);
            double totalTup = CalculateTotalTup(timeUp);
            double maxHeight = CalculateMaxHeigth(vY);
            double rangeProjectile = CalculateRange(vX, totalTup);

            std::cout << "Launch degrees: " << launchDegrees << std::endl << "Launch speed: " << speedLaunch << std::endl << "Total time up: " << totalTup << std::endl << "Range of projectile: " << rangeProjectile << std::endl;
            std::cout << "Max Height: " << maxHeight << std::endl;
            userInp = userInput();
            if(userInp == 'x')
            {
                std::cout << "Bye." << std::endl;
            }
            
    }
   
    
    system("pause");
}



double LaunchSpeed()
{
    double launchSpd = 0;
    std::cout << "Enter the launch speed of the projectile: " << std::endl;
    std::cin >> launchSpd;
    return launchSpd;
}

double DegreesOfLaunch()
{
    double degreesLaunch = 0;
    std::cout << "Enter the degrees of the launch: " << std::endl;
    std::cin >> degreesLaunch;
    return degreesLaunch;
}

double CalculateProjectileVy(double speed, double degrees)
{
    double calculateVy = speed * sin (degrees * (PI / 180.0));
    return calculateVy;
}


double CalculateProjectileVx(double speed, double degrees)
{
    double calculateVx = speed * cos (degrees * (PI / 180.0));
    return calculateVx;
}

double CalculateProjectileTup(double vY)
{
    double calculateTup = vY / GRAVITY_OF_EARTH;
    return calculateTup;
}

double CalculateTotalTup(double timeUp)
{
    double calculateTotal = timeUp * 2;
    return calculateTotal;
}

double CalculateMaxHeigth(double velY)
{
    double maxHeigth = (velY * velY) / (2 * GRAVITY_OF_EARTH);
    return maxHeigth;
}

double CalculateRange(double velX, double totalTimeUp)
{
    double totalRange = velX * totalTimeUp;
    return totalRange;
}

char userInput()
{
    char userIn;
    std::cout << "To continue, press y, to exit press x." << std::endl;
    std::cin >> userIn;
    return userIn;
}