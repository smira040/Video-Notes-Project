#ifndef HELPERS_H
#define HELPERS_H

#include <string.h>
#include "globals.h"

/*the sd card will read the folders in the sd card 
    and store the list of image files and audio files
    in arrays for later use
    EX: SD Card structure:
    /videos
        /video1
            image1.bmp
            image2.bmp
            ...
            audio.wav
        /video2
            image1.bmp
            image2.bmp
            ...
            audio.wav

    The program will read the /videos folder, and for each subfolder,
    it will read the image files and audio file, storing them in arrays
*/

void readSDCard();

void playVideo(int videoIndex);

void playAudio(String audioFile);

#endif