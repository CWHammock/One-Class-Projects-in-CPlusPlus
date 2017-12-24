/*Filename: sortInput.cpp
created by: Warren Hammock
date: 2/22/16
purpose: takes a text file and outputs different text file with all words in alphabetical order.
addition files: none

*/
#include<iostream> //user input
#include<fstream> //file input/output
#include<string>  //string class
#include<cstdlib>



void splitThreeWay(std::ifstream& fileIn);  //splits text into three files alphabetically (1st file a thru h, second h thru r, ect.)
void sortFilesFirst(std::ofstream& fileOut); //puts first file into array, sorts them, output to main output file.
void sortFilesSecond(std::ofstream& fileOut); //puts second file into array, sorts them, output to main out file after first file output.
void sortFilesThird(std::ofstream& fileOut);

int main()
{
    std::ifstream inFile;
    std::ofstream outFileSorted;
    std::string dataOut;
    char initialFile[25];
    char sortedName[25];
    //gets name of main input file and allows user to name main output file.
    std::cout << "\t---------------Put Text In Alphabetical Order----------------\n";
    std::cout << std::endl;
    std::cout << "Enter a file to input: ";
    std::cin >> initialFile;
    std::cout << std::endl;
    std::cout << "Enter filename of the sorted file: ";
    std::cin >> sortedName;



    //open main output file
    inFile.open(initialFile, std::ios::in);
    if(inFile.fail())
    {
        std::cout << "input file failed to load!!!!!!";
        exit(1);
    }
    //open main output file
    outFileSorted.open(sortedName, std::ios::out | std::ios::trunc);
    if(outFileSorted.fail())
    {
        std::cout << "input file failed to load!!!!!!";
        exit(1);
    }

    splitThreeWay(inFile);
    inFile.close();     //close main input file.  no longer needed.
    sortFilesFirst(outFileSorted);
    sortFilesSecond(outFileSorted);
    sortFilesThird(outFileSorted);
    std::remove ("dataOut1.txt"); //remove all three files used for sorting
    std::remove ("dataOut2.txt");
    std::remove ("dataOut3.txt");
    outFileSorted.close(); //close main output file.  program closing


    return 0;

}
//takes main input as parameter and sorts file into three smaller files sorted by: first is a thru h, second i thru r, third is s thru z.
void splitThreeWay(std::ifstream& fileIn)
{
    std::ofstream outFile1;
    std::ofstream outFile2;
    std::ofstream outFile3;
    std::string wordDivide;
    outFile1.open("dataOut1.txt", std::ios::trunc);
    if(outFile1.fail())
    {
        std::cout << "output file not found";
        exit(1);
    }
    outFile2.open("dataOut2.txt", std::ios::trunc);
    if(outFile2.fail())
    {
        std::cout << "output file not found";
        exit(1);
    }
    outFile3.open("dataOut3.txt", std::ios::trunc);
    if(outFile3.fail())
    {
        std::cout << "output file not found";
        exit(1);
    }
    while (! fileIn.eof())
	{
		getline(fileIn, wordDivide, ' ');
		if (wordDivide == " ")
        {
            wordDivide = "";
        }
		else if (wordDivide <= "h")
        {
            outFile1 << wordDivide << " ";
        }
        else if (wordDivide <= "r")
        {
            outFile2 << wordDivide << " ";
        }
        else
        {
            outFile3 << wordDivide << " ";
        }
	}
	outFile1.close();
    outFile2.close();
    outFile3.close();
}
//takes first temp file, puts in array and sorts alphabetically.  puts output into main output file.
void sortFilesFirst(std::ofstream& outStream)
{
    std::ifstream outFile1;

    outFile1.open("dataOut1.txt", std::ios::in);
    if(outFile1.fail())
    {
        std::cout << "output file not found";
        exit(1);
    }
    std::string inputArray[1000];
    int i = 0;
    int counter = 0;


    while (! outFile1.eof())
    {
        std::string word;
        getline(outFile1, word, ' ');
        inputArray[i] = word;
        i++;
        counter++;
    }

    for (int y = 0; y < counter; y++)
    {
        for (int k = 1; k < counter; k++)
        {
            if (inputArray[y] < inputArray[k]) {
                std::string tmp = inputArray[y];
                inputArray[y] = inputArray[k];
                inputArray[k] = tmp;
                }
        }
    }


    for (int x = 0; x < counter; x++)
    {
        outStream << inputArray[x] << " ";
    }


}
//takes second temp file, puts in array and sorts alphabetically.  puts output into main output file.
void sortFilesSecond(std::ofstream& outStream)
{
    std::ifstream outFile2;

    outFile2.open("dataOut2.txt", std::ios::in);
    if(outFile2.fail())
    {
        std::cout << "output file not found";
        exit(1);
    }
    std::string inputArray[1000];
    int i = 0;
    int counter = 0;


    while (! outFile2.eof())
    {
        std::string word;
        getline(outFile2, word, ' ');
        inputArray[i] = word;
        i++;
        counter++;
    }

    for (int y = 0; y < counter; y++)
    {
        for (int k = 1; k < counter; k++)
        {
            if (inputArray[y] < inputArray[k]) {
                std::string tmp = inputArray[y];
                inputArray[y] = inputArray[k];
                inputArray[k] = tmp;
                }
        }
    }


    for (int x = 0; x < counter; x++)
    {
        outStream << inputArray[x] << " ";
    }


}
//takes third temp file, puts in array and sorts alphabetically.  puts output into main output file.
void sortFilesThird(std::ofstream& outStream)
{
    std::ifstream outFile3;

    outFile3.open("dataOut3.txt", std::ios::in);
    if(outFile3.fail())
    {
        std::cout << "output file not found";
        exit(1);
    }
    std::string inputArray[1000];
    int i = 0;
    int counter = 0;


    while (! outFile3.eof())
    {
        std::string word;
        getline(outFile3, word, ' ');
        inputArray[i] = word;
        i++;
        counter++;
    }

    for (int y = 0; y < counter; y++)
    {
        for (int k = 1; k < counter; k++)
        {
            if (inputArray[y] < inputArray[k]) {
                std::string tmp = inputArray[y];
                inputArray[y] = inputArray[k];
                inputArray[k] = tmp;
                }
        }
    }


    for (int x = 0; x < counter; x++)
    {
        outStream << inputArray[x] << " ";
    }


}






