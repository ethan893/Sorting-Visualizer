#include <vector>
#include <iostream>
#include <random>
#include <SDL2/SDL.h>
#include <ranges>
#include <algorithm>
using namespace std;

void draw(vector<int> vectorImagery, SDL_Renderer* renderer, int red, int blue)
{
        int index = 0;
        for (int i : vectorImagery)
        {
                if (index == red)
                SDL_SetRenderDrawColor(renderer,255,0,0,255);
                else if (index == blue)
                SDL_SetRenderDrawColor(renderer,0,0,255,255);
                else
                SDL_SetRenderDrawColor(renderer,255,255,255,255);

                SDL_RenderDrawLine(renderer,index,99,index, i);
                index+=1;
        }

}

void BubbleSort(vector<int> vectorImagery, SDL_Renderer* renderer)
{
        // put bubble sort algorithm in here
for(int i = 0; i < vectorImagery.size(); ++i)
        {
                for(int j = 0; j < vectorImagery.size()-i; ++j) 
                {
                        if(vectorImagery[j] < vectorImagery[j+1])
                        {
                                // creates the list from largest -> smallest, so that SDL can render
                                // the images from smallest -> largest, using bubble sort
                                int temp = vectorImagery[j];
                                vectorImagery[j] = vectorImagery[j+1];
                                vectorImagery[j+1] = temp;
                        }
                        
                        SDL_SetRenderDrawColor(renderer,0,0,0,255);
                        SDL_RenderClear(renderer);
                        // uses the draw method to show the red and blue (j, j+1) on the screen
                        // and sorts them from right (smallest) to left (largest) on screen
                        draw(vectorImagery,renderer,j,j+1);

                        // Renders the images, and then creates a delay of 5 ms before returning
                        SDL_RenderPresent(renderer);
                        SDL_Delay(5);
                }
        }
}

void InsertionSort(vector<int> vectorImagery, SDL_Renderer* renderer)
{
for(int i = 0; i < vectorImagery.size(); ++i)
{
        int key = vectorImagery[i];
        int j = i - 1;
        // Making the list largest -> smallest so screen displays smallest (left) to largest (right)
        while(j >= 0 && vectorImagery[j] < key)
        {
                vectorImagery[j+1] = vectorImagery[j];
                j = j - 1;
        }
        vectorImagery[j+1] = key;
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);
        // uses the draw method to show the red and blue (i, j) on the screen
        // and sorts them from right (smallest) to left (largest) on screen
        draw(vectorImagery,renderer,i,j);
        // Renders the images, and then creates a delay of 100 ms before returning to allow the viewer to
        // see what is happening
        SDL_RenderPresent(renderer);
        SDL_Delay(100);
}
}
void selectionSort(vector<int> vectorImagery, SDL_Renderer* renderer)
{
        for(int i = 0; i < vectorImagery.size()-1; ++i)
        {
                int minimum = i;
                for (int j = i+1; j < vectorImagery.size(); ++j)
                {
                        // Makes the list from largest to smallest so that the program
                        // can show the sorting from smallest (left) to greatest (right)
                        if(vectorImagery[j] > vectorImagery[minimum])
                        {
                                minimum = j;
                        }

                SDL_SetRenderDrawColor(renderer,0,0,0,255);
                SDL_RenderClear(renderer);
                // uses the draw method to show the red and blue (i, j) on the screen
                // and sorts them from right (smallest) to left (largest) on screen
                draw(vectorImagery,renderer,i,j);
                // Renders the images, and then creates a delay of 5 ms before returning to allow the viewer to
                // see what is happening
                SDL_RenderPresent(renderer);
                SDL_Delay(5);
                             int temp = vectorImagery[minimum];
                             vectorImagery[minimum] = vectorImagery[i];
                             vectorImagery[i] = temp;
                }
        }
        for(auto k : vectorImagery)
        {
                cout << k << " ";
        }
}






int main(int argc, char *argv[])
{
        random_device rd;
        uniform_int_distribution d(1,99);
        vector<int> vectorImagery;

        // Populate the vector with random numbers
        for(int i = 0; i < 100; ++i)
        {
                vectorImagery.push_back(d(rd));
        }
        // Create the window and renderer
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
        SDL_CreateWindowAndRenderer(100*10, 100*10, 0, &window, &renderer);
        SDL_RenderSetScale(renderer,10,10);
        string x;
        cout << "Sorting algorithms, please type the letter next to the sorting algorithm you want to see: Bubble sort (B), Insertion sort (I), Selection Sort(S)";
        cin >> x;
        if(x == "B" || x == "b")
        BubbleSort(vectorImagery,renderer);
        else if(x == "I" || x == "i")
        InsertionSort(vectorImagery,renderer);
        else if(x == "S" || x == "s")
        selectionSort(vectorImagery,renderer);
        return 0;
}
