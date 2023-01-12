#ifndef COLOR_H
#define COLOR_H

class Color
{
    public:
        float r, g, b; // Honestly, I don't see a reason to make it private.

        Color(float r, float g, float b);
	    // ~Color();

        float ValidateColorValue(float val);
        void SetRed(float val);
        void SetGreen(float val);
        void SetBlue(float val);
};

#endif
