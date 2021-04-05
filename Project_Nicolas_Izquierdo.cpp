#include <iostream> //Needed for input and output operations
#include <iomanip> //Needed for formatting the output
#include <string> //Needed for using string class
using namespace std;

int main()
{
	int gpuSpeed = 0; //To hold the GPU clock speed value
    int cpuSpeed = 0; //To hold the CPU clock speed value
    int cpuNum = 0; //To hold the number of cores of the processor
    int select = 0; //To hold the user's choice from the resolution question
    int compNum = 0; //To hold  the number of PCs being processed
    double perfScore = 0.0; //To hold the perfomrance score
    string res = "", recQual = ""; //To hold the monitor resolution as well as the recomended graphics quality
    
	cout << "How many computers are being processed? ";
    cin >> compNum; //Read in the user's input for the number of computers being processed
    
    while(compNum <= 0)
    {
    	cout << "You've got to process at least 1 computer!";
    	cout << "How many computers are being processed? ";
    	cin >> compNum;
	}
	
	for(int num = 1; num <= compNum; num++)
	{
    
    	cout << "\nComputer Hardware Graphics Quality Recommendation Tool" << endl;
    
    	cout << "\nPlease enter the clock speed (in Megahertz) of your graphics card: ";
    	cin >> gpuSpeed; //Read in the user's input for clock speed of GPU
    	if(gpuSpeed < 1) //Input validation to confirm the user entered a value
    	{
    		cout << "Invalid graphics card speed entered. Program will terminate." << endl;
    		return 0;
		}
    	
    	cout << "Please enter the clock speed (in Megahertz) of your processor: ";
    	cin >> cpuSpeed; //Read in the user's input for clock speed of CPU
    	if(cpuSpeed < 1) //Input validation to confirm the user entered a value
    	{
    		cout << "Invalid processor speed entered. Program will terminate." << endl;
    		return 0;
		}
    	
    	cout << "Please enter the number of cores in your processor: ";
    	cin >> cpuNum; //Read in the user's input for number of cores of CPU
    	if(cpuNum < 1) //Input validation to confirm the user entered a value
    	{
    		cout << "Invalid number of cores entered. Program will terminate." << endl;
    		return 0;
		}
    	
    	cout << "What is the resolution of your monitor?" << endl;
    	cout << "\t 1. 1280 x 720" << endl;
    	cout << "\t 2. 1920 x 1080" << endl;
    	cout << "\t 3. 2560 x 1440" << endl;
    	cout << "\t 4. 3840 x 2160" << endl;
    	cout << "Please select from the options above: "; //Ask the user to make a choice
    	cin >> select; //Read in the user's input for monitor's resolution
    	
    	//Use if-else-if statement to handle the user's selection
    	if (select == 1)
		{   
    		perfScore = ((5 * gpuSpeed) + (cpuNum * cpuSpeed)) * 1; //Use formula to get the performance score
        	res = "1280 x 720";       
    	}
    	else if (select == 2)
		{            
        	perfScore = ((5 * gpuSpeed) + (cpuNum * cpuSpeed)) * 0.75; //Use different numbers at the end according to multiplier
        	res = "1920 x 1080";    
    	}
    	else if (select == 3)
		{           
        	perfScore = ((5 * gpuSpeed) + (cpuNum * cpuSpeed)) * 0.55;
        	res = "2560 x 1440";           
    	}
    	else if (select == 4)
		{           
        	perfScore = ((5 * gpuSpeed) + (cpuNum * cpuSpeed)) * 0.35;
        	res = "3840 x 2160";       
    	}
    	else
		{
        	cout << "Invalid input. Please enter 1, 2, 3, or 4! Program will terminate.";
        	return 0; //If the choice was not 1, 2, 3, or 4 then the program ends
    	}
    	
    	//Use if-else-if statement to assign recomended graphics quality to its respective performance score
    	if (perfScore > 17000) recQual = "Ultra";
    	else if ((perfScore > 15000) && (perfScore < 17000)) recQual = "High";
    	else if ((perfScore > 13000) && (perfScore < 15000)) recQual = "Medium";
    	else if ((perfScore > 11000) && (perfScore < 13000)) recQual = "Low";
    	else recQual = "Unable to Play";
    	
    	//Display the user's specs as well as performance results
    	cout << "\nComputer Hardware Graphics Quality Recommendation Tool\n" << endl;
    	cout << "GPU Clock Speed: " << gpuSpeed << "MHz" << endl;
    	cout << "CPU Clock Speed: " << cpuSpeed << "MHz" << endl;
    	cout << "Number of Cores: " << cpuNum << endl;
    	cout << "Monitor Resolution: " << res << endl;
    	cout << "Performance score: " << setprecision(2) << fixed << perfScore << endl;
    	cout << "Recommended Graphics Quality: " << recQual << endl;
	}
}//End Main
